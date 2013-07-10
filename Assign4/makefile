## makefile of the project
CC = g++

## for c compiler
# compilation flags
CFLAGS = -Wall -g

## for c++ compiler
# compilation flags
CXXFLAGS = -fPIC -Wall -g

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


## for the dynamic checker
DCHECKER = valgrind
DCHECK_MEM = --leak-check=full --track-origins=yes --read-var-info=yes --malloc-fill=0xFF --log-file=$@.mem.log
DCHECK_PTR = --tool=exp-ptrcheck --enable-sg-checks=yes --log-file=$@.ptr.log

##-----------------------------------------------------------------

SRCS = bst.cc test_BST.cc

## Replacement marco:  $(nameset:string1=string2)
## for each name in nameset, replace contained string1 by string2
OBJS = $(SRCS:.cc=.o)

EXE = main

all:	$(EXE)
	@echo all done.

$(EXE):	$(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)


## automatic variables of makefile
%.o: %.c
	$(CC) -c $(CPPFLAGS) $(CXXFLAGS) -o $@ $<


## declare "phony" non-file target (except for the special target  "all")
.PHONY:	clean  dcheck

clean:
	$(RM) $(OBJS) $(EXE)


$(warning now we check the ifeq)
ifeq ($(MAKECMDGOALS),dcheck)
ifeq ("$(wildcard $(EXE))","")
$(error Run the 'make all' first before dynamic checking )
endif
endif

dcheck: $(EXE)
	@echo "1) checking memory..."
	$(DCHECKER) $(DCHECK_MEM) ./$<
	@echo "2) checking pointer..."
	$(DCHECKER) $(DCHECK_PTR) ./$<

## end of makefile