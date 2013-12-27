SRC_DIR=..
TEST_DIR=.
BIN_DIR=../../bin/gtest
$(shell mkdir -p $(BIN_DIR))
GTEST_DIR=gtest-1.6.0

CPPFLAGS=-I${GTEST_DIR}/include -I${SRC_DIR}
CXXFLAGS=-Wall -Wextra -ggdb
LDFLAGS=-lpthread

LIBGTEST=libgtest_main.a

TEST=$(wildcard $(TEST_DIR)/*.cpp)
BIN=$(TEST:$(TEST_DIR)/%.cpp=$(BIN_DIR)/%)

.PHONY: test runtest looptest clean mrproper

test: $(BIN)

${LIBGTEST}: ${GTEST_DIR}
	g++ -I${GTEST_DIR}/include -I${GTEST_DIR} -c ${GTEST_DIR}/src/gtest-all.cc
	g++ -I${GTEST_DIR}/include -I${GTEST_DIR} -c ${GTEST_DIR}/src/gtest_main.cc
	ar -rv ${LIBGTEST} gtest-all.o gtest_main.o

${GTEST_DIR}:
	wget http://googletest.googlecode.com/files/$@.zip
	unzip -q $@.zip

$(BIN_DIR)/mapTest: ${SRC_DIR}/tile.o
$(BIN_DIR)/mazeTest: ${SRC_DIR}/map.o ${SRC_DIR}/tile.o

$(BIN_DIR)/%Test: %Test.cpp ${SRC_DIR}/%.o $(LIBGTEST)
	${CXX} ${CPPFLAGS} ${CXXFLAGS} $^ -o $@ ${LDFLAGS}

looptest: $(BIN)
	@for FILE in $(BIN); do                                   \
		$$FILE --gtest_repeat=10000 --gtest_throw_on_failure; \
	done

runtest: $(BIN)
	@for FILE in $(BIN); do \
		$$FILE;             \
	done

clean:
	@ rm -f $(GTEST_DIR).zip ${LIBGTEST} gtest-all.o gtest_main.o

mrproper: clean
	@ rm -f $(BIN)
	@ rm -rf $(GTEST_DIR)
	@ rmdir --ignore-fail-on-non-empty $(BIN_DIR)
