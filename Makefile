# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#  -std=c++14 enables C++14 standard
#   For older versions of g++  -std=c++14 needs to replaced with -std=c++1y
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

all:  
	$(CC) $(CFLAGS) -o $(TARGET_MB) MB_distances.cpp
	$(CC) $(CFLAGS) -o $(TARGET_MB_distances) MB_distances.cpp

clean: 
	$(RM) $(TARGET_MB) $(TARGET_MB_distances) *.o *~
