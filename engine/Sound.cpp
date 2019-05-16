#include "Sound.h"

// Create a Sound object
Sound::Sound() {

}

// Set a Sound's file source
void Sound::setSoundFilePath(char *fileName) {
    filePath = fileName;
}

// Associate a Sound with a file
int Sound::loadSoundFile(char *fileName) {
    if (!buffer->loadFromFile(filePath)) {
        loadedBuff = false;
        std::cout << "    loadSoundFile FAILED" << std::endl;
        return -1;
    }

    sound.setBuffer(*buffer);
    loadedBuff = true;
    return 1;
}

// Set the SOund buffer
void Sound::setBuffer(sf::SoundBuffer *buffer) {
    sound.setBuffer(*buffer);
    loadedBuff = true;
}

// Play the Sound object
void Sound::playSound() {
    sound.play();
}

// Pause the Sound object
void Sound::pauseSound() {
    sound.pause();   
}

// Stop the Sound object
void Sound::stopSound() {
    sound.stop();
}

// Set the Sound's loop
void Sound::setSoundLoop(int setting) {
    if (setting == 1){
        sound.setLoop(true);
    } else {
        sound.setLoop(false);
    }
}

// Set the Sound's volume
void Sound::setSoundVolume(unsigned int vol) {
    sound.setVolume(vol);
}

// Set the Sound's pitch
void Sound::setSoundPitch(double pitch) {
    sound.setPitch(pitch);
}

// Get the Sound buffer
sf::SoundBuffer* Sound::getBuffer() {
    return buffer;
}

// Check if the buffer is loaded
int Sound::loadedBuffer() {
    if (loadedBuff) return 1;
    else return 0;
}

// Get the Sound's status
int Sound::getSoundStatus() {
    return sound.getStatus();
}

// C++ wrappers
int createSound(char *fileName, int giveBuffer) {
    Sound *sound = new Sound();
    sound->id = currentID;
    sound->setSoundFilePath(fileName);
    soundList.push_front(sound);
    if (giveBuffer > 0) {
        sound->loadSoundFile(fileName);
    } else {
        sound->loadedBuff = false;
    }
    return currentID++;
}

void setBuffer(int ID, int bufferID) {
    getSoundByID(ID)->setBuffer(getSoundByID(bufferID)->getBuffer());
}

void playSound(int ID) {
    getSoundByID(ID)->playSound();
}

void pauseSound(int ID) {
    getSoundByID(ID)->pauseSound();
}

void stopSound(int ID) {
    getSoundByID(ID)->stopSound();
}

void setSoundLoop(int ID, int setting) {
    getSoundByID(ID)->setSoundLoop(setting);
}

void setSoundVolume(int ID, unsigned int vol) {
    getSoundByID(ID)->setSoundVolume(vol);
}

void setSoundPitch(int ID, double pitch) {
    getSoundByID(ID)->setSoundPitch(pitch/100.0);
}

int getSoundStatus(int ID) {
    return getSoundByID(ID)->getSoundStatus();
}

// Get Sound by ID
Sound* getSoundByID(int ID) {
    for(std::list<Sound*>::iterator it=soundList.begin(); it != soundList.end(); ++it) {
        if((*it)->id == ID) {
            return *it;
        }
    }
    std::cout << "FAILED TO FIND REQUESTED ID" << std::endl;
    return NULL;
}
