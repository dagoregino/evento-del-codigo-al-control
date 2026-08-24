// ==========================================
// MONITOREO TÉRMICO CON SENSOR NTC
// ==========================================


// ==========================================
// CONFIGURACIÓN DE PINES
// ==========================================

const int NTC = 34;
const int LED_ALERTA = 25;


// ==========================================
// UMBRAL DE ALERTA
// ==========================================

// Si la lectura del NTC es inferior a este valor,se encenderá el LED.

const int UMBRAL = 2000;


// ==========================================
// CONFIGURACIÓN INICIAL
// ==========================================

void setup() {

  // Configuramos el LED como salida
  pinMode(LED_ALERTA, OUTPUT);

  // Iniciamos la comunicación con el Monitor Serie
  Serial.begin(115200);

}


// ==========================================
// PROGRAMA PRINCIPAL
// ==========================================

void loop() {

  // ----------------------------------------
  // 1. LEER EL SENSOR NTC
  // ----------------------------------------

  int lecturaNTC = analogRead(NTC);


  // ----------------------------------------
  // 2. MOSTRAR LA LECTURA
  // ----------------------------------------

  Serial.print("Lectura NTC: ");
  Serial.println(lecturaNTC);


  // ----------------------------------------
  // 3. COMPROBAR EL UMBRAL
  // ----------------------------------------

  if (lecturaNTC < UMBRAL) {

    // La lectura esta fuera del límite
    // Encendemos la alerta

    digitalWrite(LED_ALERTA, HIGH);

    Serial.println("ALERTA: Temperatura alta");

  }

  else {

    // La lectura está dentro del límite
    // Apagamos la alerta

    digitalWrite(LED_ALERTA, LOW);

    Serial.println("Temperatura normal");

  }


  // Esperamos un momento antes de realizar una nueva lectura

  delay(500);
}
