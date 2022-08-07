TARGET:= PC
all: ${TARGET}

${TARGET}: ${TARGET}.cpp
	g++ -o $@ $< -lpthread -std=c++2a

clean:
	rm -rf ${TARGET}
