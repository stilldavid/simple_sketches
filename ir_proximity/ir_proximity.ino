// PIR example
#include <SoftwareSerial.h>

SoftwareSerial display(3, 2);

const int irPin = A0;

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

  int val = analogRead(irPin);
  Serial.println(val);

  if(val < 100)
    display.write("Proximity Alert!");
  else
    display.write("All Clear       ");

  delay(100);
}

