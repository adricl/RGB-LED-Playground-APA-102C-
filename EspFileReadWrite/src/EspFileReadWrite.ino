#include "FS.h"
#include "graphic.h"

void setup (){
  Serial.begin(57600);
  if (SPIFFS.begin()){
    Serial.println("\nFile System Mounted");
  }
  else {
    Serial.println("File System Failed");
    return;
  }
  FSInfo fs_info;
  SPIFFS.info(fs_info);
  Serial.printf("Total kBytes: %d\n", (fs_info.totalBytes/1000));
  Serial.printf("Total Used Bytes: %d\n", fs_info.usedBytes);
  Serial.printf("Total BlockSize: %d\n", fs_info.blockSize);
  Serial.printf("Total pageSize: %d\n", fs_info.pageSize);


  File f;
  f = SPIFFS.open("/file1.txt", "w");
  if (!f){
    Serial.println("file open failed");
    return;
  }
  Serial.printf("Size of array %d\n", sizeof(array1));

  unsigned char byteArray[2];
  unsigned int currVal = 0;
  unsigned int recon = 0;
  for(int i = 0; i < sizeof(array1)/sizeof(int); i++){
    currVal = array1[i];
    byteArray[0] = (currVal >> 16) & 0xFF;
    byteArray[1] = (currVal >> 8) & 0xFF;
    byteArray[2] = currVal & 0xFF;

    f.write(byteArray, 3 * sizeof(char));
  }

  f.flush();
  f.close();
  Serial.println("File Written\n");
  Serial.printf("Total kBytes: %d\n", (fs_info.totalBytes/1000));

}

  f = SPIFFS.open("/file1.txt", "r");
  Serial.printf("File Size Bytes: %d\n", f.size());
  Serial.printf("Array Size: %d\n", f.size()/3);

  int chars = 0;
  unsigned int builtVal = 0;
  while(f.available()){
    unsigned char val = f.read();

    switch (chars) {
      case 0:
        builtVal |= (unsigned int)val << 16;
        chars++;
        break;
      case 1:
        builtVal |= (unsigned int)val << 8;
        chars++;
        break;
      case 2:
        builtVal |= (unsigned int)val;
        chars = 0;
        builtVal = 0;
        break;
    }
  }

}

void loop(){

}
