//Code taken from Arduio LCD tutorial and button tutorial with my own added things as well


// include the library code:
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

char* insultStrings[] = {"You're a cunt.", "Yeah good one.", "Your mom smells.", "Fail.",
                         "No.", "Hey fuck you.", "You asshat.", "You toad.", "Booo :(", "You suck."
                        };

long randomNum;

const int buttonPin = 7;

int buttonState = 0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  randomSeed(analogRead(0));
  pinMode(buttonPin, INPUT);
}


void loop() {

  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    lcd.clear();
    lcd.setCursor(0, 0);
    randomNum = random(9);
    lcd.print(insultStrings[randomNum]);
    delay(3000);
  }
  else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Hit the button");
    delay(100);
  }
}
