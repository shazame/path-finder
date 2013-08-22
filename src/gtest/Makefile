SRC_DIR=..
TEST_DIR=.
GTEST_DIR=gtest-1.6.0

CPPFLAGS=-I${GTEST_DIR}/include -I${SRC_DIR}
CXXFLAGS=-Wall -Wextra -ggdb
LDFLAGS=-lpthread

LIBGTEST=libgtest_main.a

TEST=$(wildcard $(TEST_DIR)/*.cpp)
BIN=$(TEST:.cpp=)

.PHONY: all test clean

all: ${LIBGTEST} test

test: $(BIN)

${LIBGTEST}:
	g++ -I${GTEST_DIR}/include -I${GTEST_DIR} -c ${GTEST_DIR}/src/gtest-all.cc
	g++ -I${GTEST_DIR}/include -I${GTEST_DIR} -c ${GTEST_DIR}/src/gtest_main.cc
	ar -rv ${LIBGTEST} gtest-all.o gtest_main.o

%Test: %Test.cpp ${SRC_DIR}/%.cpp ${SRC_DIR}/%.hpp
	${CXX} ${CPPFLAGS} ${CXXFLAGS} $^ ${LIBGTEST} -o $@ ${LDFLAGS}

runtest: $(BIN)
	@for FILE in $(BIN); do \
		$$FILE;             \
	done

clean:
	rm -f gtest-all.o gtest_main.o *~

mrproper: clean
	rm -f $(BIN) ${LIBGTEST}
