##by @bnatalha.

# - - - - - - - - - - - - - - - - - - - -
# - - ---------- VARIABLES ---------- - -
# - - - - - - - - - - - - - - - - - - - -

# Compilation flags
#CPPFLAGS += -Wall -ansi -std=c++11 -pedantic -O0
# For debugging
CPPFLAGS += -Wall -ansi -std=c++11 -pedantic -O0 -g

# include directory
INC =-I include


# - - - - - - - - - - - - - - - - - - - -
# - - ----------- TARGETS ----------- - -
# - - - - - - - - - - - - - - - - - - - -

# ================ PHONY =================
.PHONY: all init val clean docs test vai

# ================= ALL ==================
# Creates everything that is needed in order to compile, compiles and then deletes the .o files
all: init bin/Programa_1 clean

# Creates the 'bin' folder at the current directory if there's no other folder with this name on it.
init:
	mkdir -p bin

# ============ DOCUMENTATION ==============
# Creates the 'docs' folder at the current directory if there's no other folder with this name on it.
# Generates .html documentation via doxygen at the folder 'docs'
docs: Doxyfile
	mkdir -p docs ;\
	doxygen	

# ============== VALGRIND =================
# Runs valgrind with 'bin/Programa_1'
val1:
	valgrind --leak-check=yes bin/Programa_1

# Runs valgrind with 'bin/Programa_2'
val1:
	valgrind --leak-check=yes bin/Programa_2

# ============== EXECUTABLES ==============
# For Programa_1:
bin/Programa_1: bin/main_1.o bin/palindromo.o
	g++ $^ -o $@

# For Programa_2:
bin/Programa_2: bin/main_2.o
	g++ $^ -o $@

# ================ OBJECTS ================
# For Programa_1:
bin/main_1.o: src/Programa_1/main_1.cpp
	g++ $(CPPFLAGS) $< $(INC)/Programa_1 -c -o $@

bin/palindromo.o: src/Programa_1/palindromo.cpp
	g++ $(CPPFLAGS) $< $(INC)/Programa_1 -c -o $@

# For Programa_2:
bin/main_2.o: src/Programa_2/main_2.cpp
	g++ $(CPPFLAGS) $< $(INC)/Programa_2 -c -o $@

# ================ CLEANER ================
# Removes objects
clean:
	$(RM) bin/*.o