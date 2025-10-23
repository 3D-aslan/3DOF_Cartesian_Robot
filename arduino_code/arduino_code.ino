#include <AFMotor.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>

String readString;

int btnx1 = 0;

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
AF_Stepper motorx(220, 1);
Adafruit_StepperMotor *myMotory = AFMS.getStepper(200, 1);
Adafruit_StepperMotor *myMotorz = AFMS.getStepper(200, 2);


  int dly = 20;

  int x = 0;
  int y = 0;
  int z = 0;
  int times = 1;
  int i=0;
  int gecicix =0;
  int geciciy =0;
  int geciciz =0;
  
  int cikartx = 0;
  int cikarty = 0;
  int cikartz = 0;
  int k = 1;
  int delayhizi = 1;
 
 
 
void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Stepper test!");
 
  
  pinMode(btnx1, INPUT);    // button as input
  digitalWrite(btnx1, HIGH); // turns on pull-up resistor after input
  


 AFMS.begin();

motorx.setSpeed(120);  
myMotory->setSpeed(255);
myMotorz->setSpeed(255);

  

}
 
void loop() {
  if (Serial.available()){

for (int bekletum = 1; bekletum > 0 ; bekletum=bekletum) {
  Serial.println("tumbekliyor"); //

    int sec = Serial.read();
    if (sec == 'k'){
      x=0;
      gecicix=9999;
      cikartx=9999;
      y=0;
      geciciy=9999;
      cikarty=9999;
      z=0;
      geciciz=9999;
      cikartz=9999;
    }
    if (sec == 'x'){
      for (int bekle = 1; bekle >0 ; bekle==bekle){/////////////
        while (Serial.available()) {       
        char c = Serial.read();;  //gets one byte from serial buffer
        readString += c; //makes the String readString
        delay(50);  //slow looping to allow buffer to fill with next character
         }
         if (readString.length() >0) {
         x = readString.toInt();  //convert readString into a number
         //Serial.println(x); //so you can see the integer
         readString="";
         }
       Serial.print(" serial read x = ");
       Serial.println(x);
       delay(dly);
       int secc = Serial.read();
       if (secc == 'c'){////////////
        //x=x*25;
        bekle=-1;
        }
      }
    }


    else if (sec == 'y'){
      for (int bekle = 1; bekle >0 ; bekle==bekle){/////////////
        while (Serial.available()) {
        char c = Serial.read( );  //gets one byte from serial buffer
        readString += c; //makes the String readString
        delay(50);  //slow looping to allow buffer to fill with next character
         }
         if (readString.length() >0) {
         y = readString.toInt();  //convert readString into a number
         //Serial.println(x); //so you can see the integer
         readString="";
         }
       Serial.print(" serial read y = ");
       Serial.println(y);
       delay(dly);
       if (Serial.read() == 'c'){////////////
        //y=y*25;
        bekle=-1;
        }
      }
    }


    else if (sec == 'z'){
      for (int bekle = 1; bekle >0 ; bekle==bekle){/////////////
        while (Serial.available()) {
        char c = Serial.read( );  //gets one byte from serial buffer
        readString += c; //makes the String readString
        delay(50);  //slow looping to allow buffer to fill with next character
         }
         if (readString.length() >0) {
         z = readString.toInt();  //convert readString into a number
         //Serial.println(x); //so you can see the integer
         readString="";
         }
       Serial.print(" serial read z = ");
       Serial.println(z);
       delay(dly);
       if (Serial.read() == 'c'){////////////
        //z=z*25;
        bekle=-1;
        }
      }
    }


if (sec == 'v'){////////////
        bekletum=-1;
        }
        delay(dly);
}//bekletum
    
    
  }
  Serial.print(" x = ");
  Serial.print(x);
  Serial.print(" y = ");
  Serial.print(y);
  Serial.print(" z = ");
  Serial.print(z);
  Serial.println();
  
  k=1;
  cikartx = gecicix;
  
  if (x > gecicix){///////////////////////////xxxxxxxxxxxx
    for (i=0 ; i<(x-cikartx)*times ; i++ ){
    
      Serial.println("calısması lazım");
      motorx.step(25, FORWARD, DOUBLE); 
      delay(delayhizi);
             while(digitalRead(btnx1) == LOW){
             motorx.step(25, BACKWARD, DOUBLE);
             Serial.println("Emergency");
             i=(x-cikartx)*times;
             delay(10);}
       if (k = 1){
       gecicix = x;
       k = 0;
      }
    }
    }
  k=1;
  if (x+1 < gecicix){

      for (i=0 ; i<(cikartx-x)*times ; i++ ){
    Serial.println("calısması lazım");
    motorx.step(25, BACKWARD, DOUBLE);
    delay(delayhizi);
             while(digitalRead(btnx1) == LOW){
             motorx.step(25, FORWARD, DOUBLE);
             Serial.println("Emergency");
             i=(cikartx-x)*times;
             delay(10);}    
    if (k = 1){
      gecicix = x;
      k = 0;
      }
    }
 }
  k=1;
  cikarty = geciciy;
    if (y > geciciy){///////////////////////////yyyyyyyyyyyy
    for (i=0 ; i<(y-cikarty)*times ; i++ ){
      Serial.println("calısması lazım");
      myMotory->step(25, FORWARD, DOUBLE);
      delay(delayhizi);
             while(digitalRead(btnx1) == LOW){
             myMotory->step(25, BACKWARD, DOUBLE);
             Serial.println("Emergency");
             i=(y-cikarty)*times;
             delay(10);}      
      if (k = 1){
       geciciy = y;
       k = 0;
      }
    }
    
  }
  k=1;
  if (y+1 < geciciy){

          for (i=0 ; i<(cikarty-y)*times ; i++ ){
    Serial.println("calısması lazım");
    myMotory->step(25, BACKWARD, DOUBLE);
    delay(delayhizi);
             while(digitalRead(btnx1) == LOW){
             myMotory->step(25, FORWARD, DOUBLE);
             Serial.println("Emergency");
             i=(cikarty-y)*times;
             delay(10);}    
    if (k = 1){
      geciciy = y;
      k = 0;
      }
    }
  }
    
  k=1;
  cikartz = geciciz;
  if (z > geciciz){///////////////////////////zzzzzzzzzzzzzzz
    for (i=0 ; i<(z-cikartz)*times ; i++ ){
      Serial.println("calısması lazım");
      myMotorz->step(25, FORWARD, DOUBLE);
      delay(delayhizi);
             while(digitalRead(btnx1) == LOW){
             myMotorz->step(25, BACKWARD, DOUBLE);
             Serial.println("Emergency");
             i=(z-cikartz)*times;
             delay(10);}      
      if (k = 1){
       geciciz = z;
       k = 0;
      }
    }
    
  }
  k=1;
  if (z+1 < geciciz){
    for (i=0 ; i<(cikartz-z)*times ; i++ ){
     Serial.println("calısması lazım");
     myMotorz->step(25, BACKWARD, DOUBLE);
     delay(delayhizi);
             while(digitalRead(btnx1) == LOW){
             myMotorz->step(25, FORWARD, DOUBLE);
             Serial.println("Emergency");
             i=(cikartz-z)*times;
             delay(10);}      
    if (k = 1){
      geciciz = z;
      k = 0;
      }
    }
  }

 motorx.release();
 myMotory->release();
 myMotorz->release();
  delay(dly);
}
