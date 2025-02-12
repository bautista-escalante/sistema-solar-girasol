#include <SoftwareSerial.h>
#include <Servo.h>

Servo servoPanel;
int grados = 0;
int rendimientoOeste;
int rendimientoEste;
#define este A0
#define oeste A1

void setup() {
  Serial.begin(9600);
  servoPanel.attach(9);
}

void loop() {

  int valorEste = analogRead(este);
  rendimientoEste = map(valorEste, 0, 512, 0, 100);
  //Serial.print("valor este: ");
  //Serial.println(valorEste);
  Serial.print("rendimiento este; ");
  Serial.print(rendimientoEste);
  Serial.println("%");

  int valorOeste = analogRead(oeste);
  rendimientoOeste = map(valorOeste, 0, 512, 0, 100);
  //Serial.print("valor oeste: ");
  //Serial.println(valorOeste);
  Serial.print("rendimiento oeste: ");
  Serial.print(rendimientoOeste);
  Serial.println("%");

  moverServo();
}

void moverServo() {
  int diferencia = abs(rendimientoOeste < rendimientoEste);
  if (diferencia < 5) {
    if (rendimientoOeste < rendimientoEste) {
      grados += 10;
    } else {
      grados -= 10;
    }
    servoPanel.write(grados);
    if (rendimientoOeste < 80 && rendimientoEste < 80 || grados > 180 || grados < 0) {
      servoPanel.write(0);
      grados = 0;
    }
    Serial.print("la posicion del panel es de ");
    Serial.print(grados);
    Serial.println(" Grados");
    Serial.println("---------------------------");
    delay(1500);
  }
}
