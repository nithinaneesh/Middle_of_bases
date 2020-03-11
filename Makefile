# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#  -std=c++17 enables C++17 standard
#
# for C CC=gcc and for C++  CC = g++
CC = g++
CFLAGS  = -g -std=c++17 -Wall 
TARGET_MB = Middle_base
TARGET_MB_distances = MB_distances

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
default: all

all: Middle_base MB_distances

Middle_base:
	$(CC) $(CFLAGS) -o $(TARGET_MB) Middle_base.cpp
	
MB_distances:
	$(CC) $(CFLAGS) -o $(TARGET_MB_distances) MB_distances.cpp

clean: 
	$(RM) $(TARGET_MB) $(TARGET_MB_distances) *.o *~
