#ifndef MUSIC_H
#define MUSIC_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Map.h"
#include "memory.h"
#include "Entity.h"

extern unsigned int currentID;

class Music {
    public:
        Music();
        void setMusicFilePath(char *fileName);
        int openMusicFile(char *fileName);
        void playMusic();
        void pauseMusic();
        void stopMusic();
        void setMusicLoop(int setting);
        void setMusicVolume(unsigned int vol);
        void setMusicPitch(double pitch);
        int getMusicStatus(int ID);

        int id;
        char *filePath;
        sf::Music music;
};

int createMusic(char *fileName);
void playMusic(int ID);
void pauseMusic(int ID);
void stopMusic(int ID);
void setMusicLoop(int ID, int setting);
void setMusicVolume(int ID, unsigned int vol);
void setMusicPitch(int ID, int pitch);
int getMusicStatus(int ID);
Music* getMusicByID(int ID);

#else
class Music;
std::list<Music*> musicList;
#endif
