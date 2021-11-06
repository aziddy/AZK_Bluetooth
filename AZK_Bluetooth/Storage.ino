/*
 * Non-Volatile/Presistant Storage of keymaps 
 * Make sure to store higher level data structures like 
 * C structs or JSON strings 
 * (dont just make your own bit/byte level system to store keymaps, this is the 
 * shit way the guy who made MANYKEY did)
 */

 StaticJsonDocument<1024> doc;

 struct SPIFFSaveData {
  boolean macroMode; // 1
  boolean ledLights; // 1
  int buttonCount; // 2
  byte buttonPins[BUTTON_COUNT]; // 16
  byte keyData[BUTTON_COUNT][MAX_CHARS_PER_BUTTON]; // 16*25 = 400
};

SPIFFSaveData spiffsSaveData = {
  true,
  false,
  BUTTON_COUNT,
  {},
  {},
};

void spiffsSetup(){
  SPIFFS.begin(true);
}

void spiffsTestMain(){
  
}

void spiffsWrite(){
  File keyFile = SPIFFS.open("/keyFile.json", FILE_WRITE);
  keyFile.print("flump");
}


// Will be deleted
void TESTfilljson (){
  for (byte i = 0; i < BUTTON_COUNT; i++) {
    keyData[i][0] = 97 + i;
  }

  memcpy(spiffsSaveData.buttonPins, buttonPins, sizeof(buttonPins));
  memcpy(spiffsSaveData.keyData, keyData, sizeof(keyData));
}
