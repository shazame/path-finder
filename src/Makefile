project=PathFinder

CPPFLAGS=-I.
CXXFLAGS=-Wall -Wextra -ggdb
LDFLAGS=-lncurses

SRCDIR=.
SRC=$(wildcard $(SRCDIR)/*.cpp)
OBJ=$(SRC:.cpp=.o)

.PHONY: all depend clean

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
	${MAKE} -C gtest clean

mrproper: clean
	@ rm -f $(project)
	${MAKE} -C gtest mrproper

