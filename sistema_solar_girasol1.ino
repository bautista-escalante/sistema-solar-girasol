#include <SoftwareSerial.h>
#include <Servo.h>

Servo servoPanel; 
int grados = 0;
int rendimiento = 0;

void setup() {
  Serial.begin(9600);
  servoPanel.attach(9); 
}

void loop() {
  
  	rendimiento = obtenerRendimiento();
	Serial.print(rendimiento);
  	Serial.println("%");
  
	moverServo();
    Serial.print(grados);
    Serial.println(" Grados");
  	
}

int obtenerRendimiento() {
  int valor = analogRead(A5);
  float voltaje = valor * (5.0 / 1023.0);
  return map(voltaje, 0, 5, 0, 100);
}

void moverServo(){
  if(rendimiento < 80){
    
    grados += 10;
  	servoPanel.write(grados); 
    delay(1000);
  }
  if(grados > 90){
  	servoPanel.write(0);
    grados = 0;
  }
}
