#ifndef TILE_H
#define TILE_H

class Tile {
    public:
        Tile(int size, unsigned int ID);
        void setTexture(char *filePath);
        void setTypeID(unsigned int typeID);
        int size;
        unsigned int ID;
        unsigned int typeID;
        char *texture;
};

#else
class Tile;
#endif
