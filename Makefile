
# Compiler
CXX = g++

# Flags
CXXFLAGS = -std=c++11 -Wall

# Output executable
TARGET = parser

# Object files
OBJS = main.o parser.o scanner.o

# Default rule
all: $(TARGET)

# Link
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile rules
main.o: main.cpp parser.h scanner.h token.h
	$(CXX) $(CXXFLAGS) -c main.cpp

parser.o: parser.cpp parser.h token.h scanner.h
	$(CXX) $(CXXFLAGS) -c parser.cpp

scanner.o: scanner.cpp scanner.h token.h
	$(CXX) $(CXXFLAGS) -c scanner.cpp

# Clean
clean:
	rm -f *.o $(TARGET)