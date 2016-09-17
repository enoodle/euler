
CXX = g++
CXXFLAGS = -pedantic-errors -Wall -std=c++11 -g
DEBUG_FLAG = -g
COMP_FLAG = -c

LIBRARIES = math algorithms
LIBS = $(foreach lib,$(LIBRARIES),$(lib)/$(lib).a)
EXEC = p66 p68 p71 p70 p72 p73 p75 p78 p80 p84 p85 p531
OBJS = $(addsuffix .o,$(EXEC))

SUBDIRS = math algorithms

all: $(EXEC)

$(EXEC): %: %.o $(LIBS)
	$(CXX) $(CXXFLAGS) $< -o $@ -static $(foreach lib, $(LIBRARIES),-L $(lib) -l:$(lib).a) -lmpfr -lgmp

.PHONY: clean
clean:
	rm $(OBJS) $(EXEC)

.PHONY: subdirs $(SUBDIRS)
subdirs: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@

$(LIBS): subdirs

p66.o: p66.cpp math/pcf.h math/gcf.h math/math_objects.h math/sequence.h
p68.o: p68.cpp

# DO NOT DELETE
