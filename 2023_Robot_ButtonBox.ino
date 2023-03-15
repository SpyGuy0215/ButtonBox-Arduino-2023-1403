#include <Adafruit_NeoPixel.h>

#define cubeButton     3
#define coneButton     2

#define coneWire       5
#define cubeWire       6

#define LED_PIN        11
#define NUMPIXELS      1

String botMode = "CONE";

Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_RGB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);

  pinMode(cubeButton, INPUT_PULLUP);
  pinMode(coneButton, INPUT_PULLUP); 
  pinMode(LED_PIN, OUTPUT);

  pinMode(coneWire, OUTPUT);
  pinMode(cubeWire, OUTPUT);

  Serial.println("Button Box Arduino Initialized");
  Serial.print("Button box is starting in ");
  Serial.print(botMode);
  Serial.println(" mode");
  Serial.println("Suprathik Vinayakula is the best Electrical captain of all time");
  Serial.print("Shashank made this LED and Arduino thing btw");

  pixels.begin();

  pixels.clear(); 

}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(cubeButton) == LOW){
    botMode = "CUBE";
  }
  else if(digitalRead(coneButton) == LOW){
    botMode = "CONE";
  }

  if(botMode == "CONE"){
    digitalWrite(coneWire, LOW);
    digitalWrite(cubeWire, HIGH);
  }
  else if(botMode == "CUBE"){
    digitalWrite(cubeWire, LOW);
    digitalWrite(coneWire, HIGH);
  }


  if(botMode == "CONE"){
    pixels.setPixelColor(0, pixels.Color(255, 255, 0));
    pixels.show();
  }
  else if(botMode == "CUBE"){
    pixels.setPixelColor(0, pixels.Color(255, 0, 255));
    pixels.show();
  }
  else{
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));
    pixels.show();
  }

}
