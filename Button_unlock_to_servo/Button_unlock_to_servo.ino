#include <Servo.h>

//TODO
//get the buzzer to work properly


/******************************************/

//servo
Servo myservo;

//buttons
const int buttonPin1 = 12; //The button on the right
const int buttonPin2 = 11; //The button on the left

int val = 0;
int bs1 = 0; //current state of the button
int bS1 = 0; //previous state of the button

int bs2 = 0; //current state of the button
int bS2 = 0; //previous state of the button

int pwcount = 0; //the number of button presses
int combination[2] = {1, 2}; //the combination
int userInput[2]; //the user's input

//buzzer
int buzzer = 8; //the buzzer

//potentiometer
const int analogPin = A0;//the analog input pin attach to
int inputValue = 0;//variable to store the value coming from sensor
int outputValue = 0;//variable to store the output value
/******************************************/
void setup()
{
  Serial.begin(9600);

  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buzzer, OUTPUT);
  myservo.attach(9);
  myservo.write(outputValue);

}
/******************************************/
void loop()
{
  inputValue = analogRead(analogPin);//read the value from the sensor
  outputValue = map(inputValue, 0, 1023, 0, 180); //Convert from 0-1023 proportional to the number of a number of from 0 to 180
  //Serial.println();
  //Serial.print(outputValue);
  //Serial.print(" Degrees");
  //delay(150);

  //  myservo.write(outputValue);

  digitalWrite(buzzer, OUTPUT);
  static int pushCounter = 0;
  bs1 = digitalRead(buttonPin1);
  bs2 = digitalRead(buttonPin2);

  if (bs1 != bS1) {
    if (bs1 == HIGH) {
      pwcount = pwcount + 1;
      Serial.println(pwcount);
      digitalWrite(buzzer, OUTPUT);
      delay(10);
      if (val == 0) {
        val = 1;
      }
    }
  }
  bS1 = bs1;

  if (bs2 != bS2) {
    if (bs2 == HIGH) {
      pwcount = pwcount + 1;
      Serial.println(pwcount);
      digitalWrite(buzzer, HIGH);
      delay(10);
      if (val == 1) {
        val = 2;
      }
    }
    bS2 = bs2;
  }

  if (val == 2 && pwcount == 2) {
    val = 0;
    pwcount = 0;
    Serial.println("Right");
    myservo.write(outputValue);
    delay(7);
    // You can't keep the servo moving here...fix this so that it can be kept going for a few seconds
    
  }

  else if (val != 2 && pwcount == 2) {
    val = 0;
    pwcount = 0;
    Serial.println("Wrong.");
  }
}


