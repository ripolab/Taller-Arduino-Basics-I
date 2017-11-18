#include <Stepper.h>

#include <Ethernet.h>
#include <Dns.h>
#include <EthernetServer.h>
#include <EthernetClient.h>
#include <Dhcp.h>
#include <EthernetUdp.h>


/*
  #RETO 1. Escaparate Interactivo

  Ripolab Hacklab Noviembre 2017

  by @akirasan
  ripolab.org

*/

// Incluimos la librería para controlar motores del tipo paso a paso
#include <Stepper.h>

// Incluimos la librería para controla el sensor de ultrasonidos
#include <Ultrasonic.h>


// Numero de pasos por revolucion interna del motor de 4 pasos
// 32 pasos =  1:63.68395 giro (reductora)
// 2038 pasos = 360 giro completo
#define PASOS_POR_REVOLUCION_INTERNO 32

// Creamos nuestra instancia/definicion de nuestro motor
// IN1 --> PIN 2
// IN2 --> PIN 3
// IN3 --> PIN 4
// IN4 --> PIN 5
// La declaracion de los pines tiene que ser IN1, IN3, IN2, IN5
Stepper motor(PASOS_POR_REVOLUCION_INTERNO, 2, 4, 3, 5);

// Nuestro sensor ultrasonido
// PIN8 --> Trigger
// PIN9 --> Echo
Ultrasonic sensor_ultrasonido(8, 9);

int distancia;


void setup() {

  Serial.begin(115200);
}


void loop() {

  Serial.print("Distancia en CM: ");
  distancia = sensor_ultrasonidos.distanceRead();
  Serial.println(distancia);
  delay(10)

  // Activar motor cuando detecta algún objeto a alguna distancia

  if ((distancia > 0) & (distancia < 50)) {
    // Una vuelta completa
    motor.setSpeed(500);
    motor.step(2038);
  }
}

