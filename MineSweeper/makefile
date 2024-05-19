# Compiler settings
CXX = g++
CXXFLAGS = -std = c++11 - Wall - Wextra - pedantic

# Source files
SOURCES = Board.cpp Box.cpp DirectionUtils.cpp Game.cpp GameLoop.cpp InputManager.cpp MineSweeper.cpp PositionUtils.cpp

# Object files
OBJECTS = $(SOURCES:.cpp = .o)

# Executable name
EXECUTABLE = minesweeper

# Default target
all : $(EXECUTABLE)

# Linking
$(EXECUTABLE) : $(OBJECTS)
$(CXX) $(CXXFLAGS) $(OBJECTS) - o $(EXECUTABLE)

# Compilation
% .o: % .cpp
$(CXX) $(CXXFLAGS) - c $ < -o $@

	# Clean target
	clean :
rm - f $(OBJECTS) $(EXECUTABLE)

# Phony targets
.PHONY: all clean