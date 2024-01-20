.PHONY: build clean

build:
	touch extend.cpp; rm -f ARPGMaker.cpython-310-x86_64-linux-gnu.so; python3 setup.py build; mv build/lib.linux-x86_64-3.10/ARPGMaker.cpython-310-x86_64-linux-gnu.so .; mv ARPGMaker.cpython-310-x86_64-linux-gnu.so ARPGMaker.so; cp ARPGMaker.so demos/ARPGMaker.so

clean:
	rm -f ARPGMaker.so;
