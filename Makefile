NAME = Stack

CC = clang
OPT = -O2
VERSION = -std=c11

FLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors -Wpedantic
WARNINGS = -Wno-incompatible-pointer-types
UNUSED_WARNINGS = -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-extra-semi
REMOVE_WARNINGS = -Wno-int-conversion
NIX_LIBS = -shared -fPIC
OSX_LIBS = -c

INPUTFILES = src/$(NAME)/*.c
#INPUT = src/$(NAME).c
OUTPUT = $(NAME)

TESTFILES = ../src/$(NAME)/*.c
TESTINPUT = $(NAME).spec.c
TESTOUTPUT = spec_results
TESTDEPS = ../libs/Vector/export/Vector.so

all: default

make_export:
	$(RM) -r export && mkdir export

copy_headers:
	mkdir export/$(NAME) && mkdir export/$(NAME)/headers
	cp src/$(NAME)/headers/* export/$(NAME)/headers/
	cp src/$(NAME).h export/

extract_deps:
	llvm-ar -x libs/Vector/export/*.so

default: make_export
	$(CC) $(OPT) $(VERSION) $(FLAGS) $(WARNINGS) $(REMOVE_WARNINGS) $(UNUSED_WARNINGS) $(LIBS) -o $(OUTPUT) $(INPUT) $(INPUTFILES) $(DEPS)
	mv $(OUTPUT) export/

lib: $(shell uname)

Darwin: make_export copy_headers extract_deps
	$(CC) $(OPT) $(VERSION) $(FLAGS) $(WARNINGS) $(REMOVE_WARNINGS) $(UNUSED_WARNINGS) $(OSX_LIBS) $(INPUTFILES)
	llvm-ar -rcs $(OUTPUT).so *.o
	mv $(OUTPUT).so export/
	$(RM) -r *.o

Linux: make_export copy_headers extract_deps
	$(CC) $(OPT) $(VERSION) $(FLAGS) $(WARNINGS) $(REMOVE_WARNINGS) $(UNUSED_WARNINGS) $(NIX_LIBS) -o $(OUTPUT).so $(INPUTFILES) *.o
	$(RM) -r *.o
	mv $(OUTPUT).so export/

test:
	cd spec && $(CC) $(OPT) $(VERSION) $(HEADERS) $(FLAGS) $(WARNINGS) $(REMOVE_WARNINGS) $(UNUSED_WARNINGS) -Wno-implicit-function-declaration $(LIBS) -o $(TESTOUTPUT) $(TESTFILES) $(TESTINPUT) $(TESTDEPS)
	@echo
	./spec/$(TESTOUTPUT)

spec: test

clean:
	$(RM) -r spec/$(TESTOUTPUT)
	$(RM) -r export

