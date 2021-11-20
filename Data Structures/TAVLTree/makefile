all: indev threading

ifneq ($(DEBUG), 1)
	DEBUG=0
endif

indev:
	cd tests/indev && make DEBUG=$(DEBUG)

threading:
	cd tests/threading && make DEBUG=$(DEBUG)

.PHONY: clean

clean:
	cd tests/indev && make clean DEBUG=$(DEBUG)
	cd tests/threading && make clean DEBUG=$(DEBUG)
