/*
  Brazoled - RETO 2 - Taller Arduino Basics I

  Ripolab Hacklab Noviembre 2017

  by @akirasan
  ripolab.org
*/

#include <Servo.h>

// Definimos los dos Servos que vamos a utilizar:
// ...uno para el TILT --> Parte superior
// ...otro para el PAN --> Parte inferior

Servo servo_tilt;
Servo servo_pan;

// Definimos los pines que vamos a utilizar para controlar nuestros Servos
// Nos inventamos dos "definiciones" para hacer referencia los pines 2 y 3

#define PIN_SERVO_TILT 2
#define PIN_SERVO_PAN 3

#define PIN_LED1 9
#define PIN_LED2 10

void setup() {

  // Configuramos los pines para cada servo con el metodo "attach"
  servo_tilt.attach(PIN_SERVO_TILT);  //servo superior
  servo_pan.attach(PIN_SERVO_PAN);    //servo inferior

  // Activamos la iluminación de los LEDs
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  digitalWrite(PIN_LED1, 110);
  digitalWrite(PIN_LED2, 110);
}


// Función para controlar el angulo de giro del TILT
void mover_servo_tilt(int angulo) {
  servo_tilt.write(angulo);
}


// Función para controlar el angulo de giro del PAN
void mover_servo_pan(int angulo) {
  servo_pan.write(angulo);
}


//======= BONUS EXTRA
void mover_servo_tilt_lento(int angulo, int velocidad) {
  
  int angulo_actual = servo_tilt.read();

  if (angulo_actual > angulo) {
    for (int i = angulo_actual; i > angulo; i--) {
      servo_tilt.write(i);
      delay(velocidad);
    }
  }
  else {
    for (int i = angulo_actual; i <= angulo; i++) {
      servo_tilt.write(i);
      delay(velocidad);
    }
  }
}
//=======


void loop() {
  mover_servo_tilt(0);
  mover_servo_pan(0);
  delay(1000);
  mover_servo_tilt(45);
  mover_servo_pan(20);
  delay(1000);
}
