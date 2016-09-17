
CXX = g++
CXXFLAGS = -pedantic-errors -Wall -std=c++11
LIBRARY = algorithms.a
DEBUG_FLAG = -g
COMP_FLAG = -c


MODULES = binary_search
MODULES_OBJ = $(addsuffix .o,$(MODULES))
.PHONY: MODULES


$(LIBRARY): $(MODULES_OBJ)
	$(AR) $(ARFLAGS) $@ $^

.PHONY: clean
clean:
	rm $(OBJS) $(EXEC) $(MODULES_OBJ) $(LIBRARY)

SUBDIRS = tests
.PHONY: subdirs $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

