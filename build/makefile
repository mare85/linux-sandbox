CC=g++
SRCDIR = ../code/
OBJDIR = obj/
OUTPUT_FILE = ../game
CFLAGS = -std=c++11 -Wall -Werror

_INC = ../code 
_LIB = X11 GL pthread
_DEPS = \
	Graphics/GdiContext.h

_SRCS = $(wildcard $(SRCDIR)*.cpp ) \
		$(wildcard $(SRCDIR)Graphics/*.cpp )

DEPS =  $(wildcard $(SRCDIR)*.h ) \
		$(wildcard $(SRCDIR)Graphics/*.h )

INC = $(_INC:%=-I%)
LIB = $(_LIB:%=-l%)
OBJ = $(_SRCS:$(SRCDIR)%.cpp=$(OBJDIR)%.o )

$(OBJDIR)%.o: $(SRCDIR)%.cpp $(DEPS) prepareDir
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

main: $(OBJ)
	$(CC) $(CFLAGS) $(INC) $^ -o $(OUTPUT_FILE) $(LIB)
prepareDir:
	python prepareObjDir.py


