
/*
  EstoyVivo - RETO 0 - Taller Arduino Basics I

  Ripolab Hacklab Noviembre 2017

  by @akirasan
  ripolab.org

*/

#define PIN_LED_INTERNO 13
#define PIN_SENSOR 2

// Creamos una variable para leer y almacenar el valor de nuestro sensor
int valor_sensor;

// Rutina de configuración
void setup() {

  // Definimos el pin 13 de salida, ya que vamos a escribir valores de 0 y 1
  pinMode(PIN_LED_INTERNO, OUTPUT);

  // Definimos el pin 2 de entrada, por donde vamos a recibir información del sensor
  pinMode(PIN_SENSOR, INPUT);


  // Iniciamos la comunicación por el puerto estandar
  // y definimos la velocidad de comunicación
  Serial.begin(115200);

  // Hacemos un "println" = "imprimir texto y retorno de linea"
  Serial.println("Comenzamos el programa!!!");
}


// Rutina del loop
void loop() {

  Serial.print("Leyendo el valor del sensor...: ");

  valor_sensor = digitalRead(PIN_SENSOR);

  delay(500);
  
  Serial.println(valor_sensor);
}



