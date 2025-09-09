# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall

# Executable name
TARGET = main

# Default rule: compile
all: $(TARGET)

$(TARGET): main.cpp src/koch.hpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET)

# Run with custom argument: make run ARG=4
run: $(TARGET)
	./$(TARGET) $(ARG)

# Test rule with predefined argument
test: $(TARGET)
	./$(TARGET) 4

# Clean compiled files
clear:
	rm -f $(TARGET)
