
#include "OledDisplay.h"
// These constants won't change. They're used to give names to the pins used:
const int analogInPin = PB_0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = PB_4; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
static char buffInfo[128];
void setup() {
  // initialize serial communications at 115200 bps:
  Serial.begin(115200);
  analogReadResolution(12);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  snprintf(buffInfo, sizeof(buffInfo), " Analog Read \r\n  12 Bits\r\nSensor: %d \r\nOutput: %d %", sensorValue, outputValue); 
  Screen.print(0, buffInfo, 1);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(400);
}
