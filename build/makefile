CC=g++
SRCDIR = ../code/
OBJDIR = obj/
OUTPUT_FILE = ../game
OUTPUT_FILE_DBG = ../gameDbg
CFLAGS = -std=c++11 -Wall -Werror

_INC = ../code 
_LIB = X11 GL pthread

_SRCS = $(wildcard $(SRCDIR)*.cpp ) \
		$(wildcard $(SRCDIR)Graphics/*.cpp ) \
		$(wildcard $(SRCDIR)Game/*.cpp ) \
		$(wildcard $(SRCDIR)Input/*.cpp )

DEPS =  $(wildcard $(SRCDIR)*.h ) \
		$(wildcard $(SRCDIR)Graphics/*.h ) \
		$(wildcard $(SRCDIR)Game/*.h ) \
		$(wildcard $(SRCDIR)Input/*.h )

INC = $(_INC:%=-I%)
LIB = $(_LIB:%=-l%)
OBJ = $(_SRCS:$(SRCDIR)%.cpp=$(OBJDIR)%.o )

$(OBJDIR)%.o: $(SRCDIR)%.cpp $(DEPS) prepareDir
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

main: $(OBJ)
	$(CC) $(CFLAGS) $(INC) $^ -o $(OUTPUT_FILE) $(LIB)
prepareDir:
	python prepareObjDir.py

debug: CFLAGS += -DDEBUG -g
debug: OUTPUT_FILE = $(OUTPUT_FILE_DBG)
debug: main
