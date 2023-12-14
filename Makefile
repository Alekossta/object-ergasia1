# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -g

# Include directory
INCLUDES = -Iinclude

# Source, object, and dependency directories
SRCDIR = src
OBJDIR = obj
DEPDIR = dep

# Output binary
TARGET = main

# Source and object files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
DEPS = $(patsubst $(SRCDIR)/%.cpp, $(DEPDIR)/%.d, $(SOURCES))

# Default target
all: $(TARGET)

# Linking the target executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Compiling source files into object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(DEPDIR)/%.d | $(OBJDIR) $(DEPDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Creating object and dependency directories
$(OBJDIR) $(DEPDIR):
	mkdir -p $@

# Generating dependency files
$(DEPDIR)/%.d: $(SRCDIR)/%.cpp | $(DEPDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -MM -MT $(@:$(DEPDIR)/%.d=$(OBJDIR)/%.o) $< -MF $@

# Including the dependency files
-include $(DEPS)

# Clean rule
clean:
	rm -f $(TARGET) $(OBJECTS) $(DEPS)

# Phony targets
.PHONY: all clean
