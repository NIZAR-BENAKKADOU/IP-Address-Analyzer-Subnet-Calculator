CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
TARGET   = network.exe
SOURCES  = main.cpp ip_utils.cpp subnet.cpp display.cpp
OBJECTS  = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Dependencies
main.o:      main.cpp ip_utils.h subnet.h display.h
ip_utils.o:  ip_utils.cpp ip_utils.h
subnet.o:    subnet.cpp subnet.h
display.o:   display.cpp display.h

clean:
	del /Q $(OBJECTS) $(TARGET) 2>nul

.PHONY: all clean
