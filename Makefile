# vim: set noet 
CC=clang++-7
#CLANGVERSION = $(shell clang++ --version | grep ^gcc | sed 's/^.* //g')
CFLAGS = -g

ifeq (, $(shell which clang++-7))
 CC = clang++
endif

ifeq (, $(shell which clang++))
 CC = gcc
endif

CFLAGS=-I. -I./include -pthread -std=c++17
OUTDIR=build
SOURCES=main.cpp 
#src/file.cpp src/locale.cpp src/reader.cpp src/vscan.cpp
EXE=console-out-format
# strip the src/ from the sources 
#SOURCESNOFOLDERS=main.cpp $(patsubst src/%.cpp, %.cpp, $(SROUCES))
OBJ=$(patsubst %.cpp, $(OUTDIR)/%.o, $(SOURCES))

all: build $(EXE)

# $@ is a variable for whatever is on left of rule
# $^ is first thing on right of it, I guess $> is the rest?

$(EXE): $(OBJ) 
	$(CC) $(CFLAGS) -o $@ $^ lib/libscn.a lib/libfmt.a

$(OUTDIR)/%.o : %.cpp 
	$(CC) $(CFLAGS) -c -o $@ $< 

build:
	@echo Going with compiler $(CC)
	@mkdir -p build

cleanvs: clean
	@rm -rf .vs

clean:
	@rm -rf build
	@rm -f console-out-format
	@rm -f console-out-format.exe
	@rm -f console-out-format.pdb

cleanlibs:
	@rm build/*.o
	
