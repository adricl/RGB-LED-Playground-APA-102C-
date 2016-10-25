
#include "FlashImageLoader.h"

FlashImageLoader::FlashImageLoader()
{
  if (SPIFFS.begin()){
    Serial.println("\nFile System Mounted");
  }
  else {
    Serial.println("File System Failed");
    SPIFFS.format();
    return;
  }
}

int FlashImageLoader::load(String filename)
{
  _file = SPIFFS.open(filename, "w+");
}

bool FlashImageLoader::next()
{

}
unsigned int FlashImageLoader::getNext()
{

}

void FlashImageLoader::save(unsigned int colour)
{
  unsigned char byteArray[2];
  byteArray[0] = (colour >> 16) & 0xFF;
  byteArray[1] = (colour >> 8) & 0xFF;
  byteArray[2] = colour & 0xFF;

  _file.write(byteArray, 3 * sizeof(char));
}
