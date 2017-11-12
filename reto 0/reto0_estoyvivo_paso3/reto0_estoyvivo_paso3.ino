
/*
  EstoyVivo - RETO 0 - Taller Arduino Basics I

  Ripolab Hacklab Noviembre 2017

  by @akirasan
  ripolab.org

*/

// DEFINE funciona como un sustituto de "palabra" por "valor"
// Definimos el número del pin interno de Ardunino, por defecto es el 13
#define PIN_LED_INTERNO 13
#define PIN_LED_EXTERNO 11  // Pin PWM

// Definimos una variable con valores enteros de: -32.768 a 32.767
// Y la inicializamos con valor 0
int contador = 0;

// Rutina de configuración
void setup() {

  // Definimos el pin 13 de salida, ya que vamos a escribir valores de 0 y 1
  pinMode(PIN_LED_INTERNO, OUTPUT);

  // Definimos el pin 11 de salida, ya que vamos a escribir valores entre 0 y 1024
  pinMode(PIN_LED_EXTERNO, OUTPUT);
}


// Rutina del loop
void loop() {

  // Iniciamos "contador" a 1, y mientras "contador" sea mas pequeño o igual a 2:
  // aumentamos +1 la variable "contador" --> contador++ => contador = contador + 1
  for (contador = 1; contador <= 2; contador++) {

    // Escribimos un valor DIDITAL HIGH = 1 = 5v = LED encendido, en el pin 13
    digitalWrite(PIN_LED_INTERNO, HIGH);
    // Esperamos 1 segundo
    delay(1000);
    // Escribimos un valor DIDITAL LOW = 0 = 0v = LED apagado, en el pin 13
    digitalWrite(PIN_LED_INTERNO, LOW);
    // Esperamos 1 segundo
    delay(1000);
  }

  // Iniciamos "contador" a 1, y mientras "contador" sea mas pequeño o igual a 2:
  // aumentamos +1 la variable "contador" --> contador++ => contador = contador + 1
  for (contador = 1; contador <= 2; contador++) {

    // Escribimos un valor ANALOG 110 = 2,15v = LED encendido, en el pin 11
    analogWrite(PIN_LED_EXTERNO, 110);
    // Esperamos 1 segundo
    delay(1000);
    // Escribimos un valor ANALOG 0 = 0v = LED apagado, en el pin 11
    analogWrite(PIN_LED_EXTERNO, 0);
    // Esperamos 1 segundo
    delay(1000);
  }
}



