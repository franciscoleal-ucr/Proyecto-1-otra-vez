TARGET = tree

CCX = g++
CFLAGS = -Wall -g

LINKER = g++
LFLAGS = -I.

SRCDIR = src
OBJDIR = build
BINDIR = bin
INCDIR = include

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(INCDIR)/*.h)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
rm = rm -f


all: $(BINDIR)/$(TARGET)


$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $(OBJECTS) $(LFLAGS) -o $@
	@echo "Linker done"


$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CCX) $(CFLAGS) -I$(INCDIR) -c $< -o $@
	@echo "Compiling done"


clean:
	@$(rm) $(OBJECTS)
	@$(rm) $(OBJDIR)/*.o
	@$(rm) $(BINDIR)/$(TARGET)


.PHONY: all clean
