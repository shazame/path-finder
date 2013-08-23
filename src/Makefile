CPPFLAGS=-I.
CXXFLAGS=-Wall -Wextra -ggdb
LDFLAGS=

SRCDIR=.
SRC=$(wildcard $(SRCDIR)/*.cpp)
OBJ=$(SRC:.cpp=.o)

.PHONY: all depend clean

all: $(OBJ)

depend: .depend

.depend: $(SRC)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^ > ./.depend;

include .depend

%.o:
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $^

test: $(OBJ)
	$(MAKE) -C gtest

runtest:
	$(MAKE) -C gtest runtest

clean:
	@ rm -f *~
	${MAKE} -C gtest clean

mrproper: clean
	@ rm -f $(OBJ) *.gch .depend
	${MAKE} -C gtest mrproper

