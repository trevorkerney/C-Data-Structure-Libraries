CC=g++
VERS=-std=c++17
CXXWARN=
CXXFLAGS=

BINDIR=../../bin/indev
CXXFLAGS+=-D_DEBUG -g

ifeq ($(OS),Windows_NT)
	MKBINDIR=if not exist "$(BINDIR)" mkdir "$(BINDIR)"
	XX=.exe
	CLEAN=if exist "$(BINDIR)" del /Q "$(BINDIR)"
else
	MKBINDIR=mkdir -p $(BINDIR)
	XX=
	CLEAN=-rm $(BINDIR)/*
endif

all: $(BINDIR) $(BINDIR)/indev

$(BINDIR)/indev: $(BINDIR)/main.o
	$(CC) $(CXXFLAGS) -o $@$(XX) $^

$(BINDIR)/main.o: main.cpp ../../inc/TVector.h
	$(CC) -c $(CXXFLAGS) $(VERS) $(CXXWARN) -o $@ $<

.PHONY: $(BINDIR) clean

$(BINDIR):
	${MKBINDIR}

clean:
	${CLEAN}
