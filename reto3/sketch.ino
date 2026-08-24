// ==========================================
// RADAR DE DISTANCIA
// ==========================================


// ==========================================
// LIBRERÍAS
// ==========================================

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


// ==========================================
// CONFIGURACIÓN DE LA PANTALLA OLED
// ==========================================

#define ANCHO_PANTALLA 128
#define ALTO_PANTALLA 64

Adafruit_SSD1306 pantalla(
  ANCHO_PANTALLA,
  ALTO_PANTALLA,
  &Wire,
  -1
);


// ==========================================
// PINES
// ==========================================

// Sensor ultrasónico
const int TRIG = 26;
const int ECHO = 27;

// LED de alerta
const int LED_ALERTA = 25;


// ==========================================
// CONFIGURACIÓN DEL SISTEMA
// ==========================================

// Distancia donde comienza la alerta
const int UMBRAL = 70;

// Distancia máxima que vamos a representar
const int DISTANCIA_MAXIMA = 400;


// ==========================================
// CONFIGURACIÓN INICIAL
// ==========================================

void setup() {

  // Sensor ultrasónico
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  // LED
  pinMode(LED_ALERTA, OUTPUT);

  // Monitor Serie
  Serial.begin(115200);

  // Iniciar pantalla OLED
  pantalla.begin(
    SSD1306_SWITCHCAPVCC,
    0x3C
  );

  // Limpiar pantalla
  pantalla.clearDisplay();

  // Color del texto
  pantalla.setTextColor(SSD1306_WHITE);

  // Mensaje inicial
  pantalla.setTextSize(1);
  pantalla.setCursor(20, 25);
  pantalla.println("Iniciando radar...");

  pantalla.display();

  delay(2000);
}


// ==========================================
// PROGRAMA PRINCIPAL
// ==========================================

void loop() {

  // ----------------------------------------
  // 1. ENVIAR EL PULSO ULTRASÓNICO
  // ----------------------------------------

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);


  // ----------------------------------------
  // 2. MEDIR EL ECO
  // ----------------------------------------

  long tiempo = pulseIn(ECHO, HIGH);


  // ----------------------------------------
  // 3. CONVERTIR EL TIEMPO A DISTANCIA
  // ----------------------------------------

  long distancia = tiempo / 58;


  // ----------------------------------------
  // 4. LIMITAR LA DISTANCIA
  // ----------------------------------------

  if (distancia > DISTANCIA_MAXIMA) {
    distancia = DISTANCIA_MAXIMA;
  }


  // ----------------------------------------
  // 5. CALCULAR EL BRILLO DEL LED
  // ----------------------------------------
  // 0 cm   = 255
  // 400 cm = 0

  int brillo = map(
    distancia,
    0,
    DISTANCIA_MAXIMA,
    255,
    0
  );


  // ----------------------------------------
  // 6. APLICAR PWM AL LED
  // ----------------------------------------

  analogWrite(LED_ALERTA, brillo);


  // ----------------------------------------
  // 7. CALCULAR LA BARRA
  // ----------------------------------------
  // Cerca = barra vacía
  // Lejos = barra llena

  int barra = map(
    distancia,
    0,
    DISTANCIA_MAXIMA,
    0,
    100
  );


  // ----------------------------------------
  // 8. MOSTRAR EN EL MONITOR SERIE
  // ----------------------------------------

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.print(" cm");

  Serial.print(" | Brillo LED: ");
  Serial.println(brillo);


  // ----------------------------------------
  // 9. PREPARAR LA OLED
  // ----------------------------------------

  pantalla.clearDisplay();


  // Título
  pantalla.setTextSize(1);
  pantalla.setCursor(20, 0);
  pantalla.println("RADAR");


  // Mostrar distancia
  pantalla.setTextSize(2);
  pantalla.setCursor(10, 15);
  pantalla.print(distancia);
  pantalla.println(" cm");


  // ----------------------------------------
  // 10. DIBUJAR LA BARRA
  // ----------------------------------------

  // Marco de la barra
  pantalla.drawRect(
    10,
    42,
    108,
    10,
    SSD1306_WHITE
  );


  // Relleno de la barra
  pantalla.fillRect(
    14,
    45,
    barra,
    4,
    SSD1306_WHITE
  );


  // ----------------------------------------
  // 11. COMPROBAR EL UMBRAL
  // ----------------------------------------

  if (distancia < UMBRAL) {

    // Objeto demasiado cerca

    pantalla.setTextSize(1);
    pantalla.setCursor(35, 55);
    pantalla.println("ALERTA!");

  }


  // ----------------------------------------
  // 12. ACTUALIZAR LA PANTALLA
  // ----------------------------------------

  pantalla.display();


  // Esperar antes de la siguiente medición

  delay(200);
}
