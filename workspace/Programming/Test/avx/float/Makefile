all: igen avx noavx

avx: avx-test.cpp a.o b.o
	g++ -O0 -pg -mavx2 $^ -o $@

igen: generate_input.o
	g++ -O0 -pg -o $@ $^
	./igen

noavx: avx-test.cpp a.o b.o
	g++ -O0 -pg $^ -o $@

%.o: %.cpp
	g++ -O0 -c -pg $^

clean:
	rm -rf avx noavx *gmon* *.txt igen *.o
