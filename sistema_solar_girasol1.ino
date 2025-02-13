#include <Servo.h>

Servo servoPanel;
int grados = 0;
#define este A0
#define oeste A1

void setup() {
  Serial.begin(9600);
  servoPanel.attach(9);
  servoPanel.write(grados);
}

void loop() {
  int valorEste = analogRead(este);
  int valorOeste = analogRead(oeste);

  Serial.print("Valor Este: ");
  Serial.println(valorEste);
  Serial.print("Valor Oeste: ");
  Serial.println(valorOeste);

  moverServo(valorEste, valorOeste);

  delay(500); 
}

void moverServo(int valorEste, int valorOeste) {
  int diferencia = abs(valorOeste - valorEste);

  if (diferencia > 20) {  
    if (valorOeste > valorEste && grados > 0) {  
      grados -= 5;  
    } 
    else if (valorEste > valorOeste && grados < 180) {  
      grados += 5; 
    }

    servoPanel.write(grados);
    Serial.print("Posición del panel: ");
    Serial.print(grados);
    Serial.println("°");
  }
}
