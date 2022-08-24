# AZK_Bluetooth
Bluetooth Macropad -- Keymaps *Configurable over Wifi AP* \****Coming Soon\****

<Br>

## Code References:
-- Only problem is that this guy just made some random bit/byte level system to store keymaps in EEPROM, he should have used C structs stored in EPPROM so he didnt have to waste time making his own data structure to store --
https://github.com/aziddy/manykey_firmware_arduino
https://github.com/epbarger/manykey_writer

<Br>

## Installing ESP32 Boards into Arduino IDE 
Library Link:
https://dl.espressif.com/dl/package_esp32_index.json

Board: Wemos Lolin32

Tutorial:
https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/


<Br>

## ESP32 Bluetooth Library into Arduino IDE 

https://github.com/T-vK/ESP32-BLE-Keyboard

This library is used for BLE HID with your ESP32. This is not availble in the library manager so it needs to be installed from Github

Follow the instructions in the README in that Git Repo to install the Library for your Arduino IDE
