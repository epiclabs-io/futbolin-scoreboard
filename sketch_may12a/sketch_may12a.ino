/*
  ColorduinoPlasma - Plasma demo using Colorduino Library for Arduino
  Copyright (c) 2011 Sam C. Lin lincomatic@hotmail.com ALL RIGHTS RESERVED
  
  based on  Color cycling plasma
    Version 0.1 - 8 July 2009
    Copyright (c) 2011 Sam C. Lin.  All Rights Reserved
    Copyright (c) 2009 Ben Combee.  All right reserved.
    Copyright (c) 2009 Ken Corey.  All right reserved.
    Copyright (c) 2008 Windell H. Oskay.  All right reserved.
  
  This demo is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  
  This demo is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
  
  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <Colorduino.h>
#include <numbers.h>
#include <stdlib.h>
#include <time.h>

// the number of the pushbutton pin
const int buttonPin = 2;

int RECEIVER_PIN1 = A4;
int RECEIVER_PIN2 = A5;

unsigned int value1 = 0;
unsigned int value2 = 0;

unsigned int referenceLight1 = 0;
unsigned int referenceLight2 = 0;

unsigned long sumReferenceLight1 = 0;
unsigned long sumReferenceLight2 = 0;

unsigned int counterIterations = 0;

int homeColor[3] = {255, 255, 255};
int awayColor[3] = {255, 0, 0};
int textColor[3] = {128, 255, 0};
int dashColor[3] = {0, 255, 128};

int home = 0;
int away = 0;
int localOffset = 0;
int awayOffset = 5;
int maxGoals = 10;

bool end = false;
bool goal = false;

// variable for reading the pushbutton status
long buttonTimer = 0;
long longPressTime = 250;

boolean buttonActive = false;
boolean longPressActive = false;

#define MAX_ITERATIONS_CALCULATE_DISTANCE 500

void setup() {
  Serial.begin(9600);
  Colorduino.Init(); // initialize the board
  
  // compensate for relative intensity differences in R/G/B brightness
  // array of 6-bit base values for RGB (0~63)
  // whiteBalVal[0] = red
  // whiteBalVal[1] = green
  // whiteBalVal[2] = blue
  unsigned char whiteBalVal[3] = {36,63,63}; // for LEDSEE 6x6cm round matrix
  Colorduino.SetWhiteBal(whiteBalVal);
  
  // to adjust white balance you can uncomment this line
  // and comment out the plasma_morph() in loop()
  // and then experiment with whiteBalVal above
  // Colorduino.ColorFill(255,255,255);
  Colorduino.attachbackgroundcolor(backgroundcolor);

  pinMode(RECEIVER_PIN1, INPUT);
  pinMode(RECEIVER_PIN2, INPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  while(!end) { 
     backgroundcolor();
     Colorduino.FlipPage();
     // checkButton();
     if (counterIterations < MAX_ITERATIONS_CALCULATE_DISTANCE) {
       // Colorduino.Scroll_Text("Loading...", 50, textColor);
       // Colorduino.FlipPage();
       calculateReferenceLight();
       // counterIterations++;
       Serial.println(counterIterations);
     } else if (counterIterations == MAX_ITERATIONS_CALCULATE_DISTANCE) {
       referenceLight1 = sumReferenceLight1 / counterIterations;
       referenceLight2 = sumReferenceLight2 / counterIterations;
       counterIterations++;
       Serial.println(counterIterations);
     } else {
       value1 = analogRead(RECEIVER_PIN1);
       value2 = analogRead(RECEIVER_PIN2);
       Serial.println(referenceLight1);
       Serial.println(value1);
       Serial.println(referenceLight2);
       Serial.println(value2);
       if (value1 > referenceLight1 * 1.2 ) {
         if (goal == true) {
          counterIterations = 400;
          goal = false;
         }
         goal = true;
         Serial.println("GOAL 1");
         home++;
         Colorduino.Scroll_Text("Goal", 50, textColor);
         Colorduino.FlipPage();
         checkAggregate();
         delay(1000);
       } else if (value2 > referenceLight2 * 1.2) {
         if (goal == true) {
          counterIterations = 400;
          goal = false;
         }
         goal = true;
         Serial.println("GOAL 2");
         away++;
         Colorduino.Scroll_Text("Goal", 50, textColor);
         Colorduino.FlipPage();
         checkAggregate();
         delay(1000);
       } else {
          goal = false;
       }
       printScoreBoard();
     }
  }
}

void checkButton() {
  // read the state of the pushbutton value:
  if (digitalRead(buttonPin) == HIGH) {
        if (buttonActive == false) {
            buttonActive = true;
            buttonTimer = millis();
        }
        if ((millis() - buttonTimer > longPressTime) && (longPressActive == false)) {
            longPressActive = true;
            home++;
        }
    } else {
        if (buttonActive == true) {
            if (longPressActive == true) {
                longPressActive = false;
            } else {
                if (home > 0) {
                  home--; 
                }
            }
            buttonActive = false;
        }
    }
}

void printScoreBoard() {
  createNumber(numbers[home], localOffset, homeColor);
  createNumber(numbers[away], awayOffset, awayColor);
  createDash();
  Colorduino.FlipPage();
}

void checkAggregate() {
  if (home == 6) {
    homeWin();
  } else if (away == 6) {
    awayWin();
  } else if (home == 5 && away == 5){
    tie();
  }
}

void tie() {  
  Colorduino.Scroll_Text("EMPATE!", 50, dashColor);
  Colorduino.FlipPage();
  delay(1500);
}

void homeWin() {
  end = true;
  while(end) {
    String homeS = String(home);
    String awayS = String(away);
    Colorduino.Scroll_Text("RM wins " + homeS + "-" + awayS, 50, homeColor);
    Colorduino.FlipPage();
    delay(500);
    resetScoreboard();
  }
}

void awayWin() {
  end = true;
  while(end) {
    String homeS = String(home);
    String awayS = String(away);
    Colorduino.Scroll_Text("ATM wins " + awayS + "-" + homeS, 50, awayColor);
    Colorduino.FlipPage();
    delay(500);
    resetScoreboard();
  }
}

void createNumber(int numbers[5][3], int offset, int color[3]) {
  for(int i = 0; i < 5; i++) {
      for(int j = 0; j < 3; j++) {
        if (numbers[i][j] == 1) {
          Colorduino.SetPixel(j + offset, 7 - i, color[0], color[1], color[2]); 
        }
      }
    }
}

void createDash() {
  Colorduino.SetPixel(3, 5, 0, 255, 128);
  Colorduino.SetPixel(4, 5, 0, 255, 128);
}

void backgroundcolor() {
  Colorduino.ColorFill(0, 0, 0);
}

void resetScoreboard() {
  home = 0;
  away = 0;
  end = false;
}



void calculateReferenceLight() {
 value1 = analogRead(RECEIVER_PIN1);
 Serial.print("R1: ");
 Serial.println(value1);
 sumReferenceLight1 = sumReferenceLight1 + value1;
 value2 = analogRead(RECEIVER_PIN2);
 sumReferenceLight2 = sumReferenceLight2 + value2;
 Serial.print("R2: ");
 Serial.println(value2);
 counterIterations++;
}

