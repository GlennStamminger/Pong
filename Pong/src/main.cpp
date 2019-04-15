#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

#include <Arduino.h>
#include <PinChangeInt.h>
#include "BoxObject.h"
#include "BallObject.h"
#include "Location.h"

//Display pins.
#define OLED_RESET (4)
#define SCL (A5)
#define SDA (A4)

//Button pins.
#define LEFTDOWNPIN (2)
#define LEFTUPPIN (3)
#define RIGHTDOWNPIN (10)
#define RIGHTUPPIN (11)

Adafruit_SH1106 display(OLED_RESET);

//Object locations.
Location leftBoxLocation = (Location){BOX_BORDER_DISTANCE, BOX_STARTING_POSITION};
Location rightBoxLocation = (Location){display.width() - BOX_BORDER_DISTANCE, BOX_STARTING_POSITION};
Location ballLocation = (Location){display.width()/2, display.height()/2};

//Objects.
BoxObject leftBox = BoxObject(leftBoxLocation, display, BOX_BOX_WIDTH, BOX_BOX_HEIGHT);
BoxObject rightBox = BoxObject(rightBoxLocation, display, BOX_BOX_WIDTH, BOX_BOX_HEIGHT);
BallObject ball = BallObject(display, BALL_RADIUS);

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
    if(leftUp)
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
    if(leftDown)
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
  //Check if down button for the left box is pressed.
  if(digitalRead(RIGHTDOWNPIN) == HIGH)
  {
    //Set the correlating bool to true and the opposite to false.
    rightDown = true;
    if(rightUp)
    {
      rightUp = false;
    }
  }
  //If the button is not pressed set the correlating bool to false.
  else
  {
    rightDown = false;
  }
}

void RightMoveUp()
{
  //Check if the up button for the left box is pressed.
  if(digitalRead(RIGHTUPPIN) == HIGH)
  {
    //Set the correlating bool to true and the opposite to false.
    rightUp = true;
    if(rightDown)
    {
      rightDown = false;
    }
  }
  //If the button is not pressed set the correlating bool to false.
  else
  {
    rightUp = false;
  }
}

void MoveBoxes()
{
  //Check left box movement.
  if(leftDown)
  {
    leftBox.MoveDown();
  }
  else if(leftUp)
  {
    leftBox.MoveUp();
  }

  //Check right box movement.
  if(rightDown)
  {
    rightBox.MoveDown();
  }
  else if(rightUp)
  {
    rightBox.MoveUp();
  }
}

void setup() {
  //Set pins.
  pinMode(LEFTDOWNPIN, INPUT_PULLUP);
  pinMode(LEFTUPPIN, INPUT_PULLUP);
  pinMode(RIGHTDOWNPIN, INPUT_PULLUP);
  pinMode(RIGHTUPPIN, INPUT_PULLUP);

  //External interrupts.
  attachInterrupt(digitalPinToInterrupt(LEFTDOWNPIN), &LeftMoveDown, CHANGE);
  attachInterrupt(digitalPinToInterrupt(LEFTUPPIN), &LeftMoveUp, CHANGE);

  //Pin change interrupts.
  attachPinChangeInterrupt(RIGHTDOWNPIN, RightMoveDown, CHANGE);
  attachPinChangeInterrupt(RIGHTUPPIN, RightMoveUp, CHANGE);

  //Initiate and clear display.
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
}

void loop() {
  //Clear the old display.
  display.clearDisplay();
  //Check for new movement input for the boxes.
  MoveBoxes();
  //Move the ball.
  ball.Move();
  //Check for box collision.
  ball.DetectLeftBoxContact(leftBox.location.Ypos, leftBox.location.Ypos + leftBox.height, leftBox.location.Xpos + leftBox.width);
  ball.DetectRightBoxContact(rightBox.location.Ypos, rightBox.location.Ypos + rightBox.height, rightBox.location.Xpos);
  //Redraw all objects.
  leftBox.Draw();
  rightBox.Draw();
  ball.Draw();
  //Update the screen.
  display.display();
}