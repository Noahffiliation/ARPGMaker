#include "Music.h"

// Create Music object
Music::Music() {

}

// Associate a Music object with a file
void Music::setMusicFilePath(char *fileName) {
    filePath = fileName;
}

// Open the music file
int Music::openMusicFile(char *fileName) {
    if (!music.openFromFile(fileName)) {
        std::cout << "    Music::openMusicFile FAILED" << std::endl;
        return -1;
    }
    return 1;
}

// Play the Music
void Music::playMusic() {
    music.play();   
}

// Pause the Music
void Music::pauseMusic() {
    music.pause();   
}

// Stop the Music
void Music::stopMusic() {
    music.stop();   
}

// Set the Music to loop
void Music::setMusicLoop(int setting) {
    if (setting == 1) {
        music.setLoop(true);
    } else {
        music.setLoop(false);
    }
}

// Set a Music's volume
void Music::setMusicVolume(unsigned int vol) {
    music.setVolume(vol);
}

// Set a Music's pitch
void Music::setMusicPitch(double pitch) {
    music.setPitch(pitch);
}

// Get Music status
int Music::getMusicStatus(int ID) {
    return music.getStatus();
}

// C++ wrappers
int createMusic(char *fileName) {
    Music *music = new Music();
    music->id = currentID;
    music->openMusicFile(fileName);
    music->setMusicFilePath(fileName);
    musicList.push_front(music);
    return currentID++;
}

void playMusic(int ID) {
    getMusicByID(ID)->playMusic();
}

void pauseMusic(int ID) {
    getMusicByID(ID)->pauseMusic();
}

void stopMusic(int ID) {
    getMusicByID(ID)->stopMusic();
}

void setMusicLoop(int ID, int setting) {
    getMusicByID(ID)->setMusicLoop(setting);
}

void setMusicVolume(int ID, unsigned int vol) {
    getMusicByID(ID)->setMusicVolume(vol);
}

void setMusicPitch(int ID, int pitch) {
    getMusicByID(ID)->setMusicPitch(pitch/100.0);
}

int getMusicStatus(int ID) {
    return getMusicByID(ID)->getMusicStatus(ID);
}

// Get Music object by ID
Music* getMusicByID(int ID) {
    for(std::list<Music*>::iterator it=musicList.begin(); it != musicList.end(); ++it) {
        if((*it)->id == ID) {
            return *it;
        }
    }
    std::cout << "FAILED TO FIND REQUESTED ID" << std::endl;
    return NULL;
}
