CXX=g++
CXXFLAGS=-std=c++11
CXXLDFLAGS=-pthread
SRCS=$(wildcard *.cc)
PROGS=$(SRCS:.cc=)

all:$(PROGS)
$(PROGS):%:%.cc
	$(CXX) $^ -g -o $@ $(CXXFLAGS) $(CXXLDFLAGS)

.PHONY:clean
clean:
	rm -f $(PROGS)
