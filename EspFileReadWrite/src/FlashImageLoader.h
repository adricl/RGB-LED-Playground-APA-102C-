/*
  FlashImageLoader.h - Library for loading and saving images to flash
*/
#ifndef FlashImageLoader_h
#define FlashImageLoader_h

#include "Arduino.h"
#include "FS.h"

class FlashImageLoader
{
  public:
    FlashImageLoader();
    int load(String filename);
    bool next();
    unsigned int getNext();
    void save(String filename);
  private:
    File _file;
};

#endif
