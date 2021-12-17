TARGET:= map

OBJS:= map.o \
	person.o

all: $(TARGET)

$(TARGET): $(OBJS)
	g++ -o $@ $^

%.o: %.cpp
	g++ -c $^

clean:
	rm -f *.o
	rm -f $(TARGET)
