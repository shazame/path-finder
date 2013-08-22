CC=g++
CPPFLAGS=-I.
CXXFLAGS=-Wall -Wextra -ggdb
LDFLAGS=

SRCDIR=.
SRC=$(wildcard $(SRCDIR)/*.cpp)
BIN=$(SRC:.cpp=)

.PHONY: all clean

all: $(BIN)

test:
	$(MAKE) -C gtest

runtest:
	$(MAKE) -C gtest runtest

%.o: %.cpp

clean:
	@ rm -f $(BIN) *~
