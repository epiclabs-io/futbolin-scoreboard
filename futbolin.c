/*
  CustomCharacter.ino
  2013 Copyright (c) Seeed Technology Inc.  All right reserved.

  Author:Loovee
  2013-9-18

  Grove - Serial LCD RGB Backlight demo.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <Wire.h>
#include "rgb_lcd.h"
#include <NewPing.h>

#define TRIGGER_PIN1  12  
#define ECHO_PIN1     11
#define TRIGGER_PIN2  9
#define ECHO_PIN2     10    
#define MAX_DISTANCE 200
#define OUT_VCC_PIN  7

#define MAX_ITERATIONS_CALCULATE_DISTANCE 500

rgb_lcd lcd;

int buttonState = LOW, newButtonState = 0;        // variable for reading the pushbutton status
int num1 = 0;               // local score
int num2 = 0;               // visitor score
const int buttonPin = 6;    // the number of the pushbutton pin

// Sonar1
int distance1;
int referenceDistance1 = 0;
int sumDistances1 = 0;
int counter1 = 0;

// Sonar2
int distance2;
int referenceDistance2 = 0;
int sumDistances2 = 0;
int counter2 = 0;

NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE);

byte oneLeftTop[8] = {
  0b00000,
  0b00011,
  0b00111,
  0b01111,
  0b00001,
  0b00001,
  0b00001,
  0b00001
};

byte oneLeftBottom[8] = {
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b01111,
  0b00000
};

byte oneRightTop[8] = {
  0b00000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000
};

byte oneRightBottom[8] = {
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b11110,
  0b00000
};

void setup() 
{
    // set up the lcd's number of columns and rows:
    lcd.begin(16, 2);

    // initialize the pushbutton pin as an input:
    pinMode(buttonPin, INPUT);

    // Set output of PIN to have another VCC
    pinMode(OUT_VCC_PIN, OUTPUT);
    digitalWrite(OUT_VCC_PIN, HIGH);  

    /*lcd.createChar(0, oneLeftTop);
    lcd.createChar(1, oneLeftBottom);
    lcd.createChar(2, oneRightTop);
    lcd.createChar(3, oneRightBottom);

     lcd.setCursor(0, 0);
     lcd.write((unsigned char) 0);
     lcd.write(2);
     lcd.setCursor(0, 1);
     lcd.write(1);
     lcd.write(3);*/
    
    cleanScreen();
    buttonState = digitalRead(buttonPin);   
}

void loop() 
{
    if (counter1 < MAX_ITERATIONS_CALCULATE_DISTANCE) {
      lcd.setCursor(0, 1);
      lcd.print("LOADING");
      calculateReferenceDistance();
      counter1++;
      counter2++;
    } else if (counter1 == MAX_ITERATIONS_CALCULATE_DISTANCE) {
      cleanRow(1);
      counter1++;
      counter2++;
      /*lcd.setCursor(0, 1);
      lcd.print(referenceDistance1);

      lcd.setCursor(10, 1);
      lcd.print(referenceDistance2);*/
    }else {
      lcd.setCursor(0, 0);
      delay(10);
      checkButton();
      checkSonar();
    }
    
}

void calculateReferenceDistance() {
    distance1 = sonar1.ping_cm();
    sumDistances1 = sumDistances1 + distance1;
    referenceDistance1 = sumDistances1/counter1;

    distance2 = sonar2.ping_cm();
    sumDistances2 = sumDistances2 + distance2;
    referenceDistance2 = sumDistances2/counter2;
}

void checkSonar() {
    //distance1 = sonar1.ping_cm();
    distance2 = sonar2.ping_cm();
    /*if (distance1 < referenceDistance1) {
       lcd.print(++num1);
       delay(1000);
     }*/ 
     if (distance2 < referenceDistance2) {
       lcd.print(++num2);
       delay(1000);
     }
    
     
}

void checkButton() {
    // read the state of the pushbutton value:
    newButtonState = digitalRead(buttonPin);
    // check if the pushbutton is pressed.
    // if it is, the buttonState is HIGH:
    if (newButtonState == HIGH && buttonState == LOW) {
        cleanScreen();
    }
    buttonState = newButtonState;
}

void cleanScreen() {
    // initialize scoreboard to 0 - 0
    num1 = 0;
    num2 = 0;
    for (int i = 0; i < 16; i++) {
      lcd.setCursor(i, 0);
      lcd.print(" ");
    }
    lcd.setCursor(0, 0);
    lcd.print(num1);
    lcd.setCursor(3, 0);
    lcd.print("-");
    lcd.setCursor(5, 0);
    lcd.print(num2);
  
}

void cleanRow(int row) {
    // initialize scoreboard to 0 - 0
    for (int i = 0; i < 16; i++) {
      lcd.setCursor(i, row);
      lcd.print(" ");
    }  
}