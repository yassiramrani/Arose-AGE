int brightness = 0;
char t,c;
int i=0;
#include <Servo.h>
Servo myservo;

#include<SoftwareSerial.h>
SoftwareSerial BluetoothSerial(1,0);
void setup()
{
 
 pinMode(0,OUTPUT);
 pinMode(2,INPUT);
pinMode(3,OUTPUT);
 pinMode(1,INPUT);
  pinMode(7,OUTPUT);
 pinMode(13,OUTPUT);
  BluetoothSerial.begin(9600);
  myservo.attach(5);
  myservo.write(90);
  Serial.begin(9600);
}

void loop()
{
    if(BluetoothSerial.available()){
  t = (char) BluetoothSerial.read();
  Serial.println(t);}
 if(t=='1'){  
 
  while(i==0){
     BluetoothSerial.flush();
 if(BluetoothSerial.available()){
  t = (char) BluetoothSerial.read();
  Serial.println(t);}
  if(t=='3'){
  
   myservo.write(150);}
  
  if(t=='4'){
  
    myservo.write(90);
  }
  if(t=='5'){
     myservo.write(30);
  }
  if(t=='6'){
    i=1;
  }
  }


 }
t='2';
if(t=='2'){
  // humidite
  if (digitalRead(8) == LOW) {
    myservo.write(60);
    digitalWrite(7, HIGH);
    delay(1000);
    digitalWrite(7, LOW);
  } else if (digitalRead(9) == LOW) {
    myservo.write(90);
    digitalWrite(7, HIGH);
    delay(1000);
    digitalWrite(7, LOW);  
  } else if (digitalRead(10) == LOW) {
    myservo.write(120);
    digitalWrite(7, HIGH);
    delay(1000);
    digitalWrite(7, LOW);
  } else {
    myservo.write(0);
    digitalWrite(7, LOW);
  }

 // lumiere
 
  int x = analogRead(A0);
  Serial.println(x);
  if (x ==0) {
    digitalWrite(13, HIGH);
  } 
  else {
    digitalWrite(13, LOW);
  }
   // niveau d'eau
  int y = digitalRead(2);
  if (y == HIGH) {
    digitalWrite(3, HIGH);
  } else {
    digitalWrite(3, LOW);
  }

}
}
