all: igen avx noavx

avx: avx-test.cpp a.o b.o
	g++ --std=c++2a -O0 -g -pg -mavx2 $^ -o $@

igen: generate_input.o
	g++ --std=c++2a -O0 -pg -o $@ $^
	./igen

noavx: avx-test.cpp a.o b.o
	g++ --std=c++2a -O0 -g -pg $^ -o $@

%.o: %.cpp
	g++ --std=c++2a -O0 -g -c -pg $^

clean:
	rm -rf avx noavx *gmon* *.txt igen *.o
