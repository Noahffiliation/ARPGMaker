from distutils.core import setup, Extension

# Compile and link all parts together
module = Extension('ARPGMaker',
                   sources = ['extend.cpp', 'engine/render.cpp', 'engine/Entity.cpp', 'engine/inputs.cpp', 'engine/main.cpp', 'engine/Map.cpp', 'engine/Music.cpp', 'engine/Sound.cpp', 'engine/Tile.cpp', 'engine/collisions.cpp'],
                   include_dirs = ['/usr/include/SFML/'],
                   extra_compile_args = ['-std=c++11'],
                   extra_link_args = ['-lsfml-graphics', '-lsfml-window', '-lsfml-system',
                                      '-lsfml-audio'],
                   language = 'c++')

# Build module
setup(name = 'ARPGMaker', 
      version = '1.0',
      description = 'This is the ARPGMaker package',
      ext_modules = [module])
