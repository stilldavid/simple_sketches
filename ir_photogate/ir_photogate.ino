// PIR example
#include <SoftwareSerial.h>

SoftwareSerial display(3, 2);

const int irPin = A5;

void setup()
{
  pinMode(irPin, INPUT);

  display.begin(9600);
  Serial.begin(9600);
  delay(500);

  display.write(254); // move cursor to beginning of first line
  display.write(128);

  display.write("                "); // clear display
  display.write("                ");
}

void loop()
{
  display.write(254); // move cursor to beginning of first line
  display.write(128);

  int val = digitalRead(irPin);

  if(val)
    display.write("All Clear       ");
  else
    display.write("Gate Obstructed!");

  delay(50);
}

