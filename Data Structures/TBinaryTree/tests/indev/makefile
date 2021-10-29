NAME=indev
CC=g++
VERS=-std=c++17
CXXWARN=
CXXFLAGS=

ifeq ($(DEBUG), 1)
	BINDIR=bin/debug
	CXXFLAGS+=-D_DEBUG -g
else
	BINDIR=bin/release
	CXXWARN+=-Wall -Wextra -Wdeprecated
endif

ifeq ($(OS),Windows_NT)
	MKBINDIR=if not exist "$(BINDIR)" mkdir "$(BINDIR)"
	XX=.exe
	CLEAN=if exist "$(BINDIR)" del /Q "$(BINDIR)"
else
	MKBINDIR=mkdir -p $(BINDIR)
	XX=
	CLEAN=rm -rf $(BINDIR)
endif

all: $(BINDIR) $(BINDIR)/$(NAME)

$(BINDIR)/$(NAME): $(BINDIR)/main.o
	$(CC) $(CXXFLAGS) $(VERS) $(CXXWARN) -o $@$(XX) $^

$(BINDIR)/main.o: main.cpp ../../inc/TBinaryTree.h
	$(CC) -c $(CXXFLAGS) $(VERS) $(CXXWARN) -o $@ $<

.PHONY: $(BINDIR) clean

$(BINDIR):
	${MKBINDIR}

clean:
	${CLEAN}
