
CXX = g++
CXXFLAGS = -pedantic-errors -Wall -std=c++11 -g
LIBRARY = math.a
DEBUG_FLAG = -g
COMP_FLAG = -c
ARFLAGS = rvs


MODULES = pcf gcf math_objects sequence gcd primes
MODULES_OBJ = $(addsuffix .o,$(MODULES))
.PHONY: MODULES


math.a: $(MODULES_OBJ)
	$(AR) $(ARFLAGS) $@ $^

.PHONY: clean
clean:
	rm $(OBJS) $(EXEC) $(MODULES_OBJ) $(LIBRARY)

SUBDIRS = tests
.PHONY: subdirs $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

# DO NOT DELETE

gcd.o: gcd.cpp gcd.h base_definitions.h
gcf.o: gcf.cpp gcf.h math_objects.h base_definitions.h sequence.h gcd.h
math_objects.o: math_objects.cpp math_objects.h base_definitions.h \
 sequence.h gcd.h
pcf.o: pcf.cpp pcf.h gcf.h math_objects.h base_definitions.h sequence.h \
 gcd.h
primes.o: primes.cpp primes.h math_objects.h base_definitions.h \
 sequence.h gcd.h
sequence.o: sequence.cpp sequence.h
