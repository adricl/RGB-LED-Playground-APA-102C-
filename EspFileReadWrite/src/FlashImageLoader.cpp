
#include "FlashImageLoader.h"

FlashImageLoader::FlashImageLoader()
{
  if (SPIFFS.begin()){
    Serial.println("\nFile System Mounted");
  }
  else {
    Serial.println("File System Failed");
    return;
  }
}

int FlashImageLoader::load(String filename)
{

  SPIFFS.open(filename, "r");

}
