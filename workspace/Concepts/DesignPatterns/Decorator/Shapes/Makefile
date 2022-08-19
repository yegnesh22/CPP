TARGET := ShapesTest

all: $(TARGET)

$(TARGET): test/Main.cpp include/Shapes.h
	g++ -Iinclude --std=c++2a -o $@ $^

clean:
	rm -rf $(TARGET)

