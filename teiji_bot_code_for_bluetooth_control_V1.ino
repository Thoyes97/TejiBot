char t;
 
void setup() {
    pinMode(6, OUTPUT);
pinMode(13,OUTPUT);   //in1 neg motors forward
pinMode(12,OUTPUT);   //in2 pos motors reverse
pinMode(11,OUTPUT);   //right motors forward
pinMode(10,OUTPUT);   //right motors reverse
pinMode(6, OUTPUT);

Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            //move forward(all motors rotate in forward direction)
 digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  analogWrite(6, 255);
}
 
else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
  
  
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  analogWrite(6, 255);
}
 
else if(t == 'L'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(11,HIGH);
}
 
else if(t == 'R'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(13,HIGH);
}

else if(t == 'W'){    //turn led on or off)
  digitalWrite(9,HIGH);
}
else if(t == 'w'){
  digitalWrite(9,LOW);
}
 
else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
}
