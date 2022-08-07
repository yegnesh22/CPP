all: minEff

clean:
	rm -rf *.o minEff

minEff: Solution.o
	g++ -g -o $@ $^

%.o: %.cpp
	g++ -g -c $^
