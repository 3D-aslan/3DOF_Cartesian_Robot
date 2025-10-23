import processing.serial.*;   
import controlP5.*;
Serial port;

ControlP5 cp5;

String textValue = "";
String xdeger, ydeger, zdeger;

int delay = 200;

void setup() {
  
  port = new Serial(this, "COM3", 9600);
 
  size(400,400);
  
  PFont font = createFont("arial",20);
  
  cp5 = new ControlP5(this);
  
  cp5.addTextfield("x")
     .setPosition(20,100)
     .setSize(40,40)
     .setFont(font)
     .setFocus(true)
     .setColor(color(255,0,0))
     .setAutoClear(false)
     ;
  cp5.addTextfield("y")
     .setPosition(70,100)
     .setSize(40,40)
     .setFont(createFont("arial",20))
     .setAutoClear(false)
     ;
  cp5.addTextfield("z")
     .setPosition(120,100)
     .setSize(40,40)
     .setFont(font)
     .setFocus(true)
     .setColor(color(255,0,0))
     .setAutoClear(false)
     ;
  cp5.addBang("gonder")
     .setPosition(170,100)
     .setSize(40,40)
     .getCaptionLabel().align(ControlP5.CENTER, ControlP5.CENTER)
     ;
  cp5.addBang("Calibration")
     .setPosition(170,200)
     .setSize(60,40)
     .getCaptionLabel().align(ControlP5.CENTER, ControlP5.CENTER)
     ;
     
   
  textFont(font);
}



void draw() { 

  background(0);
  fill(255);
  text("1 = 1 milimetre", 30,60);
  text(textValue, 30,30);

}



public void gonder() {
  xdeger = cp5.get(Textfield.class,"x").getText();
  port.write('x');
  delay(delay);
  port.write(0);
  port.write(xdeger);
  println(xdeger);
  delay(delay);
  port.write('c');
  
  ydeger = cp5.get(Textfield.class,"y").getText();
  port.write('y');
  delay(delay);
  port.write(0);
  port.write(ydeger);
  println(ydeger);
  delay(delay);
  port.write('c');
  
  zdeger = cp5.get(Textfield.class,"z").getText();
  port.write('z');
  delay(delay);
  port.write(0);
  port.write(zdeger);
  println(zdeger);
  delay(delay);
  port.write('c');
  
  delay(delay);
  port.write('v');
  
  println("gonderildi");
  
  //cp5.get(Textfield.class,"x").clear(); //gonderlidiye basınca yazıyı siliyor
  //cp5.get(Textfield.class,"y").clear();
  //cp5.get(Textfield.class,"z").clear();
 
}

public void Calibration() {
  port.write('k');
  delay(delay);
  port.write('v');
  }

void controlEvent(ControlEvent theEvent) {
  if(theEvent.isAssignableFrom(Textfield.class)) {
    println("controlEvent: accessing a string from controller '"
            +theEvent.getName()+"': "
            +theEvent.getStringValue()
            );
   port.write(theEvent.getStringValue());
   int aci = int(theEvent.getStringValue());  
   println("aci = "+aci); //////////////////////////////////////////////////////////
   
  }
}


public void aci(String theText) {
  // automatically receives results from controller input
  println("a textfield event for controller 'aci' : "+theText);
}
