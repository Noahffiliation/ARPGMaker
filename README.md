<h3 align="center">ARPGMaker</h3>

---

<p align="center"> ARPGMaker is a Python module that provides functionality for creating 2D action games using a custom C++ engine.
    <br>
</p>

## Table of Contents
- [About](#about)
- [Getting Started](#getting_started)
- [Usage](#usage)
- [Built Using](#built_using)
- [Authors](#authors)
- [Acknowledgments](#acknowledgement)

## About <a name = "about"></a>
ARPGMaker is a C++ game engine that compiles into a Python module for creating 2D action video games. It is built with the idea of having efficient and complex game subsystems in C++ but with the ease of programming the game itself in Python.

## Getting Started <a name = "getting_started"></a>
These instructions will get you a copy of the project up and running on your local machine for development purposes.

### Prerequisites
What things you need to install the software and how to install them.

- [Python](https://www.python.org/downloads/) and `python3-dev`
- [SFML](https://www.sfml-dev.org/tutorials/2.5)
```
sudo apt-get install make gcc g++ python3 python3-dev libsfml-dev
```

## Usage <a name="usage"></a>
Use the ARPGMaker Python module by building it and writing your game in Python and importing the ARPGMaker module.

Build the ARPGMaker module:
```
make build
```
Building the module involves using `setup.py` to link and compile the module with SFML, resulting in `ARPGMaker.so`, which is importable in a Python file.

Clear the ARPGMaker module
```
make clean
```

## Built Using <a name = "built_using"></a>
- [SFML](https://www.sfml-dev.org/tutorials/2.5) - Graphics and audio

## Authors <a name = "authors"></a>
- [@Noahffiliation](https://github.com/Noahffiliation) - Initial work
- [@alecells123](https://github.com/alecells123) - Idea & Inital work
- [@ashmag00](https://github.com/ashmag00) - Initial work

See also the list of [contributors](https://github.com/Noahffiliation/ARPGMaker/contributors) who participated in this project.

## Acknowledgements <a name = "acknowledgement"></a>
- Thanks to Taylor University computer science class COS 370 - Game Engine Architecture for the project and inspiration
