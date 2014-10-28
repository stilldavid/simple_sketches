// pressure resistor example
#include <SoftwareSerial.h>

SoftwareSerial display(3, 2);

char lightstring[10];
int light;

void setup()
{
  Serial.begin(9600);  // Start serial for output

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
  light = analogRead(0);

  Serial.println(light);
  sprintf(lightstring, "%4d", light);

  display.write("light: ");
  display.write(lightstring);

  display.write(254); // move cursor to beginning of first line
  display.write(128);

  delay(100);
}

