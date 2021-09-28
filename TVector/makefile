all: indev

ifneq ($(DEBUG), 1)
	DEBUG=0

indev:
	cd tests/indev && make DEBUG=$(DEBUG)

.PHONY: clean

clean:
	cd tests/indev && make clean
