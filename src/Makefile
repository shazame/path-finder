CPPFLAGS=-I.
CXXFLAGS=-Wall -Wextra -ggdb
LDFLAGS=-lncurses

SRCDIR=.
SRC=$(wildcard $(SRCDIR)/*.cpp)
OBJ=$(SRC:.cpp=.o)

BINDIR=../bin
$(shell mkdir -p $(BINDIR))

project=$(BINDIR)/PathFinder

.PHONY: all runtest depend clean mrproper

all: $(project)

$(project): $(OBJ)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $^ $(LDFLAGS)

depend: .depend

.depend: $(SRC)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^ > ./.depend;

include .depend

%.o:
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $<

test: $(OBJ)
	$(MAKE) -C gtest

runtest:
	$(MAKE) -C gtest runtest

clean:
	@ rm -f $(OBJ) *.gch .depend *~
	@ ${MAKE} -C gtest clean

mrproper: clean
	@ rm -f $(project)
	@ ${MAKE} -C gtest mrproper
	@ rmdir --ignore-fail-on-non-empty $(BINDIR)
