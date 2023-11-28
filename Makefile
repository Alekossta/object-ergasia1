# Compiler
CXX := g++

# Source files
SRCS := Person.cpp Secretary.cpp main.cpp

# Object files
OBJS := Person.o Secretary.o main.o

# Executable name
TARGET := main

# Valgrind options
VALGRIND_OPTIONS := --leak-check=full --show-leak-kinds=all

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Rule to build object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Valgrind target
valgrind: $(TARGET)
	valgrind $(VALGRIND_OPTIONS) ./$(TARGET)

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)
