CC = g++

TARGET = main

DEBUG = -g
CFLAGS = -Wall $(DEBUG) 

SRC_DIR = src
OBJ_DIR = obj
RES_DIR = res
TARGET_DIR = bin

OBJS = $(addprefix $(OBJ_DIR)/, solver.o grid.o ruleset.o)
TEST_OBJS = $(addprefix $(OBJ_DIR)/, grid_tests.o solver_tests.o)

all : main unittests

main : directories $(OBJS) $(OBJ_DIR)/gridmaster.o
	$(CC) $(CFLAGS) $(OBJS) $(OBJ_DIR)/gridmaster.o -o $(TARGET_DIR)/main

directories:
	@mkdir -p $(TARGET_DIR)
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/gridmaster.o:  gridmaster.cpp
	$(CC) $(CFLAGS) -c gridmaster.cpp -o $(OBJ_DIR)/gridmaster.o

$(OBJ_DIR)/%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c -o $@ $<

# Test targets
GTEST_DIR=$(RES_DIR)/googletest-release-1.7.0

unittests : $(OBJ_DIR)/gtest.o $(TEST_OBJS)
	$(CC) -isystem ${GTEST_DIR}/include -pthread unittests.cpp $(OBJ_DIR)/libgtest.a $(OBJS) $(TEST_OBJS) -o $(TARGET_DIR)/unittests

$(OBJ_DIR)/solver_tests.o : solver_tests.cpp $(OBJ_DIR)/solver.o
	$(CC) -isystem ${GTEST_DIR}/include -pthread -c solver_tests.cpp -o $(OBJ_DIR)/solver_tests.o

$(OBJ_DIR)/grid_tests.o : grid_tests.cpp $(OBJ_DIR)/grid.o 
	$(CC) -isystem ${GTEST_DIR}/include -pthread -c grid_tests.cpp -o $(OBJ_DIR)/grid_tests.o

# Google Test framework
$(OBJ_DIR)/gtest.o : 
	$(CC) -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) -pthread -c ${GTEST_DIR}/src/gtest-all.cc -o $(OBJ_DIR)/gtest.o
	ar -rv $(OBJ_DIR)/libgtest.a $(OBJ_DIR)/gtest.o

# Clean
clean:
	rm -r $(TARGET_DIR)
	rm -r $(OBJ_DIR)
	rm -f *.o
	echo Cleaned

