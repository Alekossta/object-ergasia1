# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -g

# Define the include directory
INCLUDES = -I include 

# Define the source directory
SRCDIR = src

# Define the object directory
OBJDIR = obj

# Define the output binary
TARGET = main

# Define source files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# Define object files
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=%.o)

# Rule for making the actual target
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJECTS)

# Rule for making the object files
%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Define a clean rule
clean:
	rm -f $(TARGET) $(OBJECTS) *.d

# Define a rule for rebuilding
rebuild: clean $(TARGET)

# Include dependencies if they exist
-include $(OBJECTS:.o=.d)

# Rule to generate a file of dependencies (use g++ -MM)
%.d: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -MM $< -MF $@
