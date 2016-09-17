
CXX = g++
CXXFLAGS = -pedantic-errors -Wall -std=c++11 -I ..
DEBUG_FLAG = -g
COMP_FLAG = -c

MODULES = gcf gcd primes pythagorean
TESTS = $(addsuffix _test,$(MODULES))
OBJS = $(addsuffix .o,$(TESTS))

LIB = math.a

all: $(TESTS)

$(TESTS): %: %.o ../$(LIB)
	$(CXX) $(CXXFLAGS) $< -o $@ -L.. -static -l:$(LIB) -lmpfr -lgmp

.PHONY: clean
clean:
	rm $(OBJS) $(TESTS)

.PHONY: libdir $(LIB)
../$(LIB): 
	$(MAKE) -C ../

gcf_test.o: gcf_test.cpp ../gcf.h ../math_objects.h ../sequence.h \
 ../pcf.h ../gcf.h ../gcd.h
gcd_test.o: gcd_test.cpp ../gcd.h ../math_objects.h ../sequence.h
primes_test.o : primes_test.cpp ../primes.h
pythagorean_test.o: pythagorean_test.cpp ../pythagorean_tree.h \
 ../base_definitions.h ../math_objects.h ../sequence.h ../gcd.h 
