all: inputgen rabbithole
SOBJS := Solution.o input.o

inputgen: inputgen.o
	g++ -o inputgen inputgen.o
	./inputgen

rabbithole: $(SOBJS)
	g++ -o rabbithole $(SOBJS)

%.o: %.cpp
	g++ -g -c -o $@ $^

clean:
	rm -rf *.o inputgen rabbithole
