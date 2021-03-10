.PHONY: build clean

build:
	touch extend.cpp; rm -f ARPGMaker.cpython-37m-x86_64-linux-gnu.so; python3.9 setup.py build; mv build/lib.linux-x86_64-3.9/ARPGMaker.cpython-39-x86_64-linux-gnu.so .; mv ARPGMaker.cpython-39-x86_64-linux-gnu.so ARPGMaker.so; cp ARPGMaker.so demos/ARPGMaker.so

clean:
	rm -f ARPGMaker.so;
