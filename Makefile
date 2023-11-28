# Makefile for C++ project

# Compiler
CXX := g++

# Source files
SRCS := Person.cpp Secretary.cpp main.cpp

# Object files
OBJS := Person.o Secretary.o main.o

# Executable name
TARGET := main

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Rule to build object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)
