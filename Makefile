
SOURCEDIR := $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))/build
SOURCES   := $(shell find $(SOURCEDIR) -name '*.cpp')

clean:
	-[ -e build/out ] && rm -f build/out
	-[ -e out ] && rm -f out
	-[ -e build/rpi ] && rm -rf build/rpi
virtual.build:
	mkdir -p build
	make -B clean

	cp -r rpi build
	cp entry.cpp build/
	rm -rf build/rpi/local

	make -B virtual.compile
virtual.compile:
	g++ -o build/out -DVIRTUAL -I./build $(SOURCES)
	cp build/out .
virtual.run:
	make -B virtual.build
	./out

local.build:
	mkdir -p build
	make -B clean

	cp -r rpi build
	cp entry.cpp build/
	rm -rf build/rpi/virtual

	make -B local.compile
local.compile:
	g++ -o build/out -I./build $(SOURCES)
	cp build/out .
local.run:
	make -B local.build
	./out