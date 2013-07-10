## makefile of the project
CC = gcc

## for c compiler
# compilation flags
CFLAGS = -Wall -g

## for c++ compiler
# compilation flags
CXXFLAGS = 

## for the preprocessor, 
# define any directories for header files other than /usr/include
# define any macros 
# e.g. CPPFLAGS = -DDEBUG=1 -I/home/newinc -I../include
CPPFLAGS = -I.


## for the linker
# define any paths for searching libraries other than /usr/lib
# or define linking flags
# e.g. LDFLAGS = -L/home/newlib -L../lib
LDFLAGS = 

# define any external libraries for linking into executable
# e.g. LDLIBS = -lmylib -lm
LDLIBS =

## for the cleaner
RM = rm -f
##-----------------------------------------------------------------

SRCS = bst.c test_bst.c

## Replacement marco:  $(nameset:string1=string2)
## for each name in nameset, replace contained string1 by string2
OBJS = $(SRCS:.c=.o)

EXE = main

all:	$(EXE)
	@echo all done.

$(EXE):	$(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)


## automatic variables of makefile
%.o: %.c
	$(CC) -c $(CPPFLAGS) $(CPFLAGS) -o $@ $<


## declare "phony" non-file target (except for "all" special case)
.PHONY:	clean

clean:
	$(RM) $(OBJS) $(EXECUTABLE)


## end of makefile