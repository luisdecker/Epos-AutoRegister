TEST_FILES=$(wildcard *_test.cc)
OBJS=$(TEST_FILES:_test.cc=)
TO_RUN=$(OBJS:%=test-%)
TO_CLEAN=$(OBJS:%=clean-%)
CXXFLAGS=-DSIMULATE -std=c++11 -Wall 

all: $(OBJS)

clean-%:
	rm -Rvf $(subst clean-,,$@)_test
clean: $(TO_CLEAN)

%: clean-% %.h
	$(CXX) $(CXXFLAGS) -o $@_test $@_test.cc

test-%: %
	./$(subst test-,,$@)_test


test: $(TO_RUN)
