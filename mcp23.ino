#include <Adafruit_MCP23X17.h>

const int LED_PIN[] = {0, 1, 2, 3, 4, 5, 6, 7};
const int BUTTON_PIN[] = {8, 9, 10, 11, 12, 13, 14, 15};
Adafruit_MCP23X17 mcp;

void setup() {
  Serial.begin(9600);
  if (!mcp.begin_I2C()) {
    Serial.println("Error.");
    while (1);
  }

  for (int i = 0; i < 8; i++) {
    mcp.pinMode(LED_PIN[i], OUTPUT);
  }

  for (int i = 0; i < 8; i++) {
    mcp.pinMode(BUTTON_PIN[i], INPUT_PULLUP);
  }
}

void loop() {
  for (int i = 0; i < 8; i++) {
    if (mcp.digitalRead(BUTTON_PIN[i]) == LOW) {
      mcp.digitalWrite(LED_PIN[i], HIGH);
    } else {
      mcp.digitalWrite(LED_PIN[i], LOW);
    }
  }
}
