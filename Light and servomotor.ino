#include <Servo.h>
#define RELAY1  7 
#define RELAY2  4   

Servo myservo; 
int pos = 0;

void setup() {
  Serial.begin(9600);
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);       

  myservo.attach(2);
}

void loop() {
   digitalWrite(RELAY1,0); 
   digitalWrite(RELAY2,0);// Turns ON Relays 1
   Serial.println("Light ON");
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees// in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
  delay(10000);
  //delay(32400000);
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);            // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }

   digitalWrite(RELAY1,1);          // Turns Relay Off
   digitalWrite(RELAY2,1);
   Serial.println("Light OFF");
  delay(10000);
  //delay(54000000);
}