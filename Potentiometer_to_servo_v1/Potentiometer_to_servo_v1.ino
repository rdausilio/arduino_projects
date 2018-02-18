
#include <Servo.h>
/******************************************/
Servo myservo;

const int analogPin = A0;//the analog input pin attach to
int inputValue = 0;//variable to store the value coming from sensor
int outputValue = 0;//variable to store the output value
/******************************************/
void setup()
{
  Serial.begin(9600);
  
  myservo.attach(9);
  myservo.write(outputValue);
}
/******************************************/
void loop()
{
  inputValue = analogRead(analogPin);//read the value from the sensor
  outputValue = map(inputValue,0,1023,0,180);//Convert from 0-1023 proportional to the number of a number of from 0 to 180
  //Serial.println();
  //Serial.print(outputValue);
  //Serial.print(" Degrees");
  delay(150);

  myservo.write(outputValue);
  
}
/*******************************************/
