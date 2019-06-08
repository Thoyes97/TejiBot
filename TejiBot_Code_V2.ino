//This code version hass al aspects of the functionality working sans steering controls for right and returning to the middle

char t;
#include <Servo.h> // include servo library

Servo servoMotor;       // creates an instance of the servo object to control a servo
int servoPin = 4 ;      // Control pin for servo motor
int servoAngle = 40;

const int BLUETOOTH_TX = 0;
const int BLUETOOTH_RX = 1;
void setup() {
  pinMode(6, OUTPUT);   //Enable A
  pinMode(13, OUTPUT);  //in1 neg motors 
  pinMode(12, OUTPUT);  //in2 pos motors
  pinMode(11, OUTPUT);  //in3 pos motors
  pinMode(10, OUTPUT);  //in4 neg motors
  pinMode(5, OUTPUT);   //Enable B
  pinMode(3, OUTPUT);   //front motor voltage variation

  servoMotor.attach(servoPin);  // attaches the servo on pin 2 to the servo object
  Serial.begin(9600);

}

void loop() {
  if (Serial.available()) {
    t = Serial.read();
    Serial.println(t);
  }
 
  if (t == 'F') {          //move forward(all motors rotate in forward direction)
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    analogWrite(6, 255);
  }

  else if (t == 'B') {    //move reverse (all motors rotate in reverse direction)
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    analogWrite(6, 255);
  }

  else if (t == 'L') {    //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
   analogWrite(11, 150);
   digitalWrite(10,LOW);
   analogWrite(3, 95);
  }

  else if (t == 'R') {    //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
 digitalWrite(11, LOW);
 digitalWrite(10, HIGH);
analogWrite(3,59);
  }

  if (t == 'G') {          //move forward(all motors rotate in forward direction)
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    analogWrite(6, 255);
    analogWrite(11, 150);
   digitalWrite(10,LOW);
   analogWrite(3, 95);
  }

  else if (t == 'I') {    //move reverse (all motors rotate in reverse direction)
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    analogWrite(6, 255);

    digitalWrite(11, LOW);
 digitalWrite(10, HIGH);
analogWrite(3,59);
  }

  else if (t == 'H') {    //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
 digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    analogWrite(6, 255);
    analogWrite(11, 150);
   digitalWrite(10,LOW);
   analogWrite(3, 95);
  }

  else if (t == 'J') {    //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    analogWrite(6, 255);
    digitalWrite(11, LOW);
 digitalWrite(10, HIGH);
analogWrite(3,59);
  }

  else if (t == 'W') {  //turn led on or off)
   // place servo code here
       servoAngle = 85;
      servoMotor.write(servoAngle);
    }
    else if (t == 'w') {
      //place servo code here
      servoAngle = 40;
      servoMotor.write(servoAngle);
    }
    else if (t == 'S') {    //STOP (all motors stop)
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
    }
  }
