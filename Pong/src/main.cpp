#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

#include <Arduino.h>
#include "BoxObject.h"
#include "Location.h"

//Reset value for the oled display.
#define OLED_RESET (4)

//Button pins.
#define LEFTDOWNPIN (2)
#define LEFTUPPIN (3)

Adafruit_SH1106 display(OLED_RESET);

//Object locations.
Location leftBoxLocation = (Location){DEFAULT_BORDER_DISTANCE, DEFAULT_STARTING_POSITION};
Location rightBoxLocation = (Location){display.width() - DEFAULT_BORDER_DISTANCE, DEFAULT_STARTING_POSITION};

//Box objects.
BoxObject leftBox = BoxObject(leftBoxLocation, display, DEFAULT_BOX_WIDTH, DEFAULT_BOX_HEIGHT);
BoxObject rightBox = BoxObject(rightBoxLocation, display, DEFAULT_BOX_WIDTH, DEFAULT_BOX_HEIGHT);

/*gooi een capacitor tussen de buttons
een smoothing capacitor/ceramic capacitor*/

//Box movement bools.
bool leftDown = false;
bool leftUp = false;
bool rightDown = false;
bool rightUp = false;

//Functions.
void LeftMoveDown()
{
  //Check if down button for the left box is pressed.
  if(digitalRead(LEFTDOWNPIN) == HIGH)
  {
    //Set the correlating bool to true and the opposite to false.
    leftDown = true;
    if(leftUp == true)
    {
      leftUp = false;
    }
  }
  //If the button is not pressed set the correlating bool to false.
  else
  {
    leftDown = false;
  }
}

void LeftMoveUp()
{
  //Check if the up button for the left box is pressed.
  if(digitalRead(LEFTUPPIN) == HIGH)
  {
    //Set the correlating bool to true and the opposite to false.
    leftUp = true;
    if(leftDown = true)
    {
      leftDown = false;
    }
  }
  //If the button is not pressed set the correlating bool to false.
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
  //Set pins and attach interrupt functions to them.
  pinMode(LEFTDOWNPIN, INPUT_PULLUP);
  pinMode(LEFTUPPIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(LEFTDOWNPIN), &LeftMoveDown, CHANGE);
  attachInterrupt(digitalPinToInterrupt(LEFTUPPIN), &LeftMoveUp, CHANGE);
  //Initiate and clear display.
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
}

void loop() {
  //Clear the old display.
  display.clearDisplay();
  //Check for new movement input for the boxes.
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
  //Redraw and display the boxes.
  leftBox.Draw();
  rightBox.Draw();
  display.display();
}
