// Sonar example
#include <SoftwareSerial.h>

SoftwareSerial display(3, 2);

const int pwPin = 7; 
long pulse, inches, cm;
char cmstring[10];

void setup()
{
  pinMode(pwPin, INPUT);

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

  pulse = pulseIn(pwPin, HIGH);

  //147uS per inch
  inches = pulse / 147;

  //change inches to centimetres
  cm = inches * 2.54;

  Serial.println(pulse);

  sprintf(cmstring, "%3d", cm);
 
  display.write("distance: ");
  display.write(cmstring);
  display.write("cm");

  delay(100);
}

