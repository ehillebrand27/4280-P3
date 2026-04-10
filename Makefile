

# Compiler
CXX = g++

# Flags
CXXFLAGS = -std=c++11 -Wall

# Output executable
TARGET = P3

# Object files (UPDATED: added testTree.o)
OBJS = main.o parser.o scanner.o testTree.o

# Default rule
all: $(TARGET)

# Link step
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile main
main.o: main.cpp parser.h scanner.h token.h testTree.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Compile parser
parser.o: parser.cpp parser.h token.h scanner.h node.h
	$(CXX) $(CXXFLAGS) -c parser.cpp

# Compile scanner
scanner.o: scanner.cpp scanner.h token.h
	$(CXX) $(CXXFLAGS) -c scanner.cpp

# Compile tree printer 
testTree.o: testTree.cpp testTree.h node.h
	$(CXX) $(CXXFLAGS) -c testTree.cpp

# Clean
clean:
	rm -f *.o $(TARGET)