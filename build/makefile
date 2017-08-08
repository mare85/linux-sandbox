CC=g++
SRCDIR = ../code/
INCLUDES = $(SRCDIR) 
LIBS = X11 GL
INC = $(INCLUDES:%=-I%)
LIB = $(LIBS:%=-l%)
CFLAGS = -std=c++11 -Wall -Werror
OUTPUT_FILE = ../game
main: $(SRCDIR)/main.cpp
	$(CC) $(CFLAGS) $(INC) $(SRCDIR)main.cpp -o $(OUTPUT_FILE) $(LIB)
