#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

#include <Arduino.h>
#include "BoxObject.h"
#include "Location.h"

#define OLED_RESET 4
#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 

Adafruit_SH1106 display(OLED_RESET);

//LOCATIONS
Location leftBoxLocation = (Location){DEFAULT_BORDER_DISTANCE, DEFAULT_STARTING_POSITION};
Location rightBoxLocation = (Location){display.width() - DEFAULT_BORDER_DISTANCE, DEFAULT_STARTING_POSITION};

//BOXES
BoxObject leftBox = BoxObject(leftBoxLocation, display, DEFAULT_BOX_WIDTH, DEFAULT_BOX_HEIGHT);
BoxObject rightBox = BoxObject(rightBoxLocation, display, DEFAULT_BOX_WIDTH, DEFAULT_BOX_HEIGHT);


//BUTTONPINS
const int leftDownPin = 2;
const int leftUpPin = 3;

//BOOLS
volatile bool leftDown = false;
volatile bool leftUp = false;
volatile bool rightDown = false;
volatile bool rightUp = false;

//FUNCTIONS
void LeftMoveDown()
{
  leftUp = false;
  leftDown = !leftDown;
}

void LeftMoveUp()
{
  leftDown = false;
  leftUp = !leftUp;
}

void RightMoveDown()
{
  rightUp = false;
  rightDown = !rightDown;
}

void RightMoveUp()
{
  rightDown = false;
  rightUp = !rightUp;
}

void setup() {
  pinMode(leftDownPin, INPUT_PULLUP);
  pinMode(leftUpPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(leftDownPin), &LeftMoveDown, CHANGE);
  attachInterrupt(digitalPinToInterrupt(leftUpPin), &LeftMoveUp, CHANGE);
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
}

void loop() {
  display.clearDisplay();
  if(leftDown && leftUp)
  {
    leftDown = false;
    leftUp = false;

    rightDown = false;
    rightUp = false;
  }
  else if(leftDown && !leftUp)
  {
    leftBox.MoveDown();
    rightBox.MoveUp();
  }
  else if(!leftDown && leftUp)
  {
    leftBox.MoveUp();
    rightBox.MoveDown();
  }
  else
  {}
  leftBox.Draw();
  rightBox.Draw();
  display.display();
}
