# 1. Variables
CXX = clang++
CXXFLAGS = -std=c++17 -Wall

# 2. File lists
SRCS =  MineSweeper.cpp Game.cpp GameLoop.cpp PositionUtils.cpp InputManager.cpp DirectionUtils.cpp Box.cpp Board.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = MineSweeper.exe

# 3. Final build rule
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# 4. Clean up build artifacts
clean:
	del /Q *.o *.exe
