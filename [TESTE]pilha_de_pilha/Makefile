##by @bnatalha.

# - - - - - - - - - - - - - - - - - - - -
# - - ---------- VARIABLES ---------- - -
# - - - - - - - - - - - - - - - - - - - -

# Compilation flags
CPPFLAGS += -Wall -ansi -std=c++11 -pedantic -O0

# For debugging
#CPPFLAGS += -Wall -ansi -std=c++11 -pedantic -O0 -g

# include directory
INC =-I inc


# - - - - - - - - - - - - - - - - - - - -
# - - ----------- TARGETS ----------- - -
# - - - - - - - - - - - - - - - - - - - -
#
# ================ PHONY =================
.PHONY: all init val clean docs go

# ================= ALL ==================
all: init bin/a clean

init:
	mkdir -p bin

# ============ DOCUMENTATION ==============
docs: Doxyfile
	mkdir -p docs ;\
	doxygen	

# ============== VALGRIND =================
val:
	valgrind --leak-check=yes bin/a

# ============== EXECUTABLES ==============
bin/a: bin/a.o
	g++ $^ -o $@

# ================ OBJECTS ================
bin/a.o: src/a.cpp
	g++ $(CPPFLAGS) $< $(INC) -c -o $@

# ================ CLEANER ================
# Removes objects
clean:
	$(RM) bin/*.o

# ================ EXECUTE ================
vai:
	bin/a