#ifndef SOUND_H
#define SOUND_H

#include <SFML/Audio.hpp>
#include <iostream>
#include "memory.h"

extern unsigned int currentID;

class Sound {
    public:
        Sound();
        ~Sound() {
            delete buffer;
        }
        void setSoundFilePath(char *fileName);
        int loadSoundFile(char *fileName);
        void setBuffer(sf::SoundBuffer *buffer);
        void playSound();
        void pauseSound();
        void stopSound();
        void setSoundLoop(int setting);
        void setSoundVolume(unsigned int vol);
        void setSoundPitch(double pitch);
        sf::SoundBuffer* getBuffer();
        int loadedBuffer();
        int getSoundStatus();

        int id;
        char *filePath;
        sf::SoundBuffer *buffer = new sf::SoundBuffer;
        sf::Sound sound;
        bool loadedBuff;
};

int createSound(char *fileName, int giveBuffer);
void setBuffer(int ID, int bufferID);
void playSound(int ID);
void pauseSound(int ID);
void stopSound(int ID);
void setSoundLoop(int ID, int setting);
void setSoundVolume(int ID, unsigned int vol);
void setSoundPitch(int ID, double pitch);
int getSoundStatus(int ID);
Sound* getSoundByID(int ID);

#else
class Sound;
#endif
