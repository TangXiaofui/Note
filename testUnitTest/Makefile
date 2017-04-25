include /home/txh/Github/handy/config.mk

CFLAGS += -I. $(PLATFORM_CCFLAGS) $(OPT)
CXXFLAGS += -I. $(PLATFORM_CXXFLAGS) $(OPT)

LDFLAGS += $(PLATFORM_LDFLAGS)
LIBS += $(PLATFORM_LIBS)

LIBRARY = /home/txh/Github/handy/libhandy.a

TEST_SOURCES = $(shell find ./ -name '*.cc')
TEST_OBJECTS = $(TEST_SOURCES:.cc=.o)

test: $(TEST_OBJECTS) $(LIBRARY)
	$(CXX) $^ -o $@ $(LDFLAGS) $(LIBS)
	ctags -R
	cscope -Rbq
.cc.o:
	$(CXX) -g $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o test cscope.*
