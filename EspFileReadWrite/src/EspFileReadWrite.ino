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
  for(int i = 0; i < sizeof(array1)/sizeof(int); i++){
    f.printf("%06x", array1[i]);
  }

  f.flush();
  f.close();
  Serial.println("File Written\n");
  Serial.printf("Total kBytes: %d\n", (fs_info.totalBytes/1000));

  f = SPIFFS.open("/file1.txt", "r");
  Serial.printf("File Size Bytes: %d\n", f.size());
  Serial.printf("Array Size: %d\n", f.size()/6);
  int chars = 0;
  int count = 0;
  while(f.available()){
    Serial.write(f.read());

    if (chars > 4)
    {
      Serial.print(", 0x");
      chars = 0;
      count++;
    }
    else
    {
      chars++;
    }

  }
  Serial.printf("\n\n Count: %d", count);

}

void loop(){

}
