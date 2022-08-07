RELEASE := Debug/src

OBJDIR := $(RELEASE)
OBJS := $(OBJDIR)/Solution.o \
	$(OBJDIR)/main.o
SRCDIR := src
TARGET := $(OBJDIR)/BricksTest
INCDIR := include

all: $(OBJDIR) $(TARGET)

clean:
	rm -rf $(OBJDIR)/*.o
	rm -rf $(TARGET)
	rm -rf $(OBJDIR)

$(TARGET): $(OBJS)
	g++ -o $(TARGET) $(OBJS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:$(SRCDIR)/%.cpp
	g++ -o $@ -c -fPIC -I$(INCDIR)  $<

