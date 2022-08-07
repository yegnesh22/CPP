srcdir := src
objdir := build
target := $(objdir)/PoolerTest
includedir := include
testsdir := $(srcdir)/Tests
tests:= $(objdir)/Base1Tests.o \
	$(objdir)/Base2Tests.o \
	$(objdir)/ByteTypeTests.o \
	$(objdir)/DerivedTests.o \
	$(objdir)/FixedStringTypeTests.o \
	$(objdir)/PointerTypeTests.o \
	$(objdir)/StructPointTypeTests.o \
       	$(objdir)/Tests.o

cppflags:= -I$(includedir)

all:$(objdir) $(target)

$(target): $(tests)
	g++ -o $@ $(tests)

$(objdir)/%.o: $(testsdir)/%.cpp $(includedir)/Tests/%.h $(includedir)/Pool.h $(includedir)/ExampleClasses.h
	g++ -g -c -fPIC -o $@ $(cppflags) $<

$(objdir):
	mkdir -p $(objdir)

clean:
	rm -rf $(objdir)
