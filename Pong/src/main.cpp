#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

#include <Arduino.h>
#include "BoxObject.h"
#include "Location.h"

#define OLED_RESET (4)
#define LOGO16_GLCD_HEIGHT (16) 
#define LOGO16_GLCD_WIDTH  (16) 

//BUTTONPINS
#define LEFTDOWNPIN (2)
#define LEFTUPPIN (3)

Adafruit_SH1106 display(OLED_RESET);

//LOCATIONS
Location leftBoxLocation = (Location){DEFAULT_BORDER_DISTANCE, DEFAULT_STARTING_POSITION};
Location rightBoxLocation = (Location){display.width() - DEFAULT_BORDER_DISTANCE, DEFAULT_STARTING_POSITION};

//BOXES
BoxObject leftBox = BoxObject(leftBoxLocation, display, DEFAULT_BOX_WIDTH, DEFAULT_BOX_HEIGHT);
BoxObject rightBox = BoxObject(rightBoxLocation, display, DEFAULT_BOX_WIDTH, DEFAULT_BOX_HEIGHT);

//gooi een capacitor tussen de buttons smoothing capacitor/ceramic capacitor

//BOOLS
bool leftDown = false;
bool leftUp = false;
bool rightDown = false;
bool rightUp = false;

//FUNCTIONS
void LeftMoveDown()
{
  if(digitalRead(LEFTDOWNPIN) == HIGH)
  {
    leftDown = true;
    if(leftUp == true)
    {
      leftUp = false;
    }
  }
  else
  {
    leftDown = false;
  }
}

void LeftMoveUp()
{
  if(digitalRead(LEFTUPPIN) == HIGH)
  {
    leftUp = true;
    if(leftDown = true)
    {
      leftDown = false;
    }
  }
  else
  {
    leftUp = false;
  }
}

void RightMoveDown()
{
  
}

void RightMoveUp()
{
  
}

void setup() {
  pinMode(LEFTDOWNPIN, INPUT_PULLUP);
  pinMode(LEFTUPPIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(LEFTDOWNPIN), &LeftMoveDown, CHANGE);
  attachInterrupt(digitalPinToInterrupt(LEFTUPPIN), &LeftMoveUp, CHANGE);
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
}

void loop() {
  display.clearDisplay();
  if(leftDown)
  {
    leftBox.MoveDown();
    rightBox.MoveUp();
  }
  else if(leftUp)
  {
    leftBox.MoveUp();
    rightBox.MoveDown();
  }
  leftBox.Draw();
  rightBox.Draw();
  display.display();
}
