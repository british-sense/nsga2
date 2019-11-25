CXX = clang++
TARGET = nsga2
CXXFLAGS = -std=c++17 -Wall -O3 -mtune=native -march=native
SRCS = main.cpp

$(TARGET):
	$(CXX) $(SRCS) -o $(TARGET) $(CXXFLAGS)

clean:
	rm -f $(TARGET)