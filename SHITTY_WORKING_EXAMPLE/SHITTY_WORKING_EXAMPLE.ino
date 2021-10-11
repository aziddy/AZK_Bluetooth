/**
 * This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete
 */
#include <BleKeyboard.h>

BleKeyboard bleKeyboard("BLE-K YYZ286", "Alex-Zidros");

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 25;     // the number of the pushbutton pin

int buttonState = 0;  


#define DEBOUNCE_DELAY 10
#define BUTTON_COUNT 8
int buttonPins[] = {36, 39, 33, 34, 25, 26, 14, 12};
// buttonReadings
int buttonReadings[] = {0, 0, 0, 0, 0, 0, 0, 0};
// State
bool state[] = {0, 0, 0, 0, 0, 0, 0, 0};
// lastTime
unsigned long lastTime[] = {0, 0, 0, 0, 0, 0, 0, 0};
// Latched
bool latched[] = {0, 0, 0, 0, 0, 0, 0, 0};
// lastReading
bool lastReading[] = {0, 0, 0, 0, 0, 0, 0, 0};



void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE!");
  // initialize the pushbutton pin as an input:
  for(int x = 0; x < BUTTON_COUNT; x++){
    pinMode(buttonPins[x], INPUT_PULLUP);
  }
  bleKeyboard.begin();
}



void loop() {
  if(bleKeyboard.isConnected()) {
    updateButtons();
  }
}

void updateButtons() {
  for (byte i = 0; i < BUTTON_COUNT; i++){
     // update button readings
    buttonReadings[i] = !digitalRead(buttonPins[i]);
    if (buttonReadings[i] != lastReading[i]) {
      lastTime[i] = millis();
    }

    // press/release buttons
    if ((millis() - lastTime[i]) > DEBOUNCE_DELAY){
      state[i] = buttonReadings[i];
      if (state[i] && !latched[i]) {
        pressChars(i);
        latched[i] = true;
      } else if (!state[i] && latched[i]) {
      //  releaseChars(buttons[i]);
        latched[i] = false;
      }
    }

    // update last reading
    lastReading[i] = buttonReadings[i];
    
  }
}

void pressChars(int button){
  if(button == 0){
  //  bleKeyboard.print("0");
  } else if (button == 1){
   // bleKeyboard.print("1");
  } else if (button == 2){
    //bleKeyboard.print("2");
  } else if (button == 3){
   // bleKeyboard.print("3");
  } else if (button == 4){
    bleKeyboard.press(KEY_LEFT_GUI);
    bleKeyboard.press('2');
    delay(20);
    bleKeyboard.releaseAll();
  } else if (button == 5){
    bleKeyboard.press(KEY_LEFT_GUI);
    bleKeyboard.press('z');
    delay(20);
    bleKeyboard.releaseAll();
  } else if (button == 6){
        bleKeyboard.press(KEY_LEFT_GUI);
    bleKeyboard.press('4');
    delay(20);
    bleKeyboard.releaseAll();
  } else if (button == 7){
    bleKeyboard.press(KEY_LEFT_GUI);
    bleKeyboard.press('5');
    delay(20);
    bleKeyboard.releaseAll();
  }
}
