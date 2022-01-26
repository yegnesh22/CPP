OBJDIR:= .
SRCDIR:= .
INCDIR:= ../include

OBJS:= $(OBJDIR)/BasicSolution.o \
	$(OBJDIR)/OptimalSolution.o \
	$(OBJDIR)/SolutionBase.o \
	$(OBJDIR)/Tree.o \
	$(OBJDIR)/main.o


APP:= $(OBJDIR)/AllElemBST

CPPFLAGS:= -I $(INCDIR)

all: $(APP)

$(APP): $(OBJS)
	g++ -o $(APP) $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(INCDIR)/%.h
	g++ -g -c -fPIC $(CPPFLAGS) $<


clean:
	rm -rf $(APP)
	rm -rf *.o
