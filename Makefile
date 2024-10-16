.PHONY: build clean

build:
	touch extend.cpp; rm -f ARPGMaker.cpython-312-x86_64-linux-gnu.so; python3 setup.py build; mv build/lib.linux-x86_64-cpython-312/ARPGMaker.cpython-312-x86_64-linux-gnu.so .; mv ARPGMaker.cpython-312-x86_64-linux-gnu.so ARPGMaker.so; cp ARPGMaker.so demos/ARPGMaker.so

clean:
	rm -f ARPGMaker.so;
