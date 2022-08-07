${TARGET}: ${TARGET}.o
	g++ -pg -o $@ $^

%.o: %.cpp
	g++ -pg -c -fPIC -o $@ $^

clean:
	rm -rf ${TARGET}.o ${TARGET}

