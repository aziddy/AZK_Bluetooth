/*
 * CODE when the board is running as just a 
 * bluetooth macropad/keyboard
 */
 
#define BUTTON_COUNT 8
#define MAX_CHARS_PER_BUTTON 25

byte buttonPins[] = {17, 16, 2, 15, 25, 26, 14, 12};
byte keyData[BUTTON_COUNT][MAX_CHARS_PER_BUTTON];
