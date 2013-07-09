CC      = g++
CFLAGS  = -c -Wall -O -ggdb
LDFLAGS =

EXECUTABLE=main

all: $(EXECUTABLE)

$(EXECUTABLE): test_expression.o
	$(CC) -o $@ $^ $(LDFLAGS)

test_expression.o: test_expression.cc Expression.h
	$(CC) $(CFLAGS) $<

.PHONY: cleanObj cleanAll

cleanObj:
	rm *.o

cleanAll: cleanObj
	rm $(EXCUTABLE)


#--------------------------
# makefile example
#-------------------------
#all: $(SOURCES) $(EXECUTABLE)
	
#SOURCES=main.cpp hello.cpp factorial.cpp
#OBJECTS=$(SOURCES:.cpp=.o)

#$(EXECUTABLE): $(OBJECTS) 
#	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

#.cpp.o:
#	$(CC) $(CFLAGS) $< -o $@
