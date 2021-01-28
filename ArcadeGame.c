// include the library code:
#include <LiquidCrystal.h>
#include "OneMsTaskTimer.h"


//initialize buzzer
const int buzzer = P5_2;


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(P6_7, P2_3, P2_6, P2_4, P5_6, P6_6);


enum PlayerActionsStates {PlayActionInit, GameStart, WaitingForAction, MoveForward, MoveBack, Jump};
PlayerActionsStates playerActionState;


enum ScreenStates {screenInit, DrawScreen, GameOver, Restart};
ScreenStates screenState;


//struct for heroPos and obstacle
typedef struct xy_struct{
  int x;
  int y;
} XY;


int obstaclePosition = 16;
XY heroPos;


void setupArcadeGame() {
    Serial.begin(9600);


  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  //title screen and countdown for initial game start
  delay(500);
  lcd.setCursor(0, 0);
  lcd.print("   Hero Runner  ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("        3       ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  tone(buzzer, 2000, 100);
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("        2       ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  tone(buzzer, 1500, 100);
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("        1       ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
   tone(buzzer, 1000, 100);
  delay(1000);
  clearScreen();


}




void loopArcadeGame() {
  delay(10);  
}