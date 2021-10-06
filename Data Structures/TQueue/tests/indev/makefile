CC=g++
VERS=-std=c++17
CXXWARN=
CXXFLAGS=

BINDIR=../../bin/indev
CXXFLAGS+=-D_DEBUG -g

ifeq ($(OS),Windows_NT)
	MKBINDIR=if not exist "$(BINDIR)" mkdir "$(BINDIR)"
	EXECEXT=.exe
	CLEAN=if exist "$(BINDIR)" del /Q "$(BINDIR)"
else
	MKBINDIR=mkdir -p $(BINDIR)
	EXECEXT=
	CLEAN=-rm $(BINDIR)/*
endif

all: $(BINDIR) $(BINDIR)/indev

$(BINDIR)/indev: $(BINDIR)/main.o
	$(CC) $(CXXFLAGS) -o $@$(EXECEXT) $^

$(BINDIR)/main.o: main.cpp ../../inc/TQueue.h
	$(CC) -c $(CXXFLAGS) $(VERS) $(CXXWARN) -o $@ $<

.PHONY: $(BINDIR) clean

$(BINDIR):
	${MKBINDIR}

clean:
	${CLEAN}
