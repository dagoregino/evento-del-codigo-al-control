// ==========================================
// SEMÁFORO CON ESP32
// ==========================================

// Pines donde están conectados los LEDs
const int ROJO = 25;
const int AMARILLO = 26;
const int VERDE = 27;


// ==========================================
// CONFIGURACIÓN INICIAL
// ==========================================

void setup() {

  // Configuramos los LEDs como salidas
  pinMode(ROJO, OUTPUT);
  pinMode(AMARILLO, OUTPUT);
  pinMode(VERDE, OUTPUT);

}


// ==========================================
// PROGRAMA PRINCIPAL
// ==========================================

void loop() {

  // ----------------------------------------
  //  ROJO
  // ----------------------------------------
  digitalWrite(ROJO, HIGH);
  digitalWrite(AMARILLO, LOW);
  digitalWrite(VERDE, LOW);

  delay(3000);  // Esperar 3 segundos


  // ----------------------------------------
  //  AMARILLO
  // ----------------------------------------
  digitalWrite(ROJO, LOW);
  digitalWrite(AMARILLO, HIGH);
  digitalWrite(VERDE, LOW);

  delay(1000);  // Esperar 1 segundo


  // ----------------------------------------
  //  VERDE
  // ----------------------------------------
  digitalWrite(ROJO, LOW);
  digitalWrite(AMARILLO, LOW);
  digitalWrite(VERDE, HIGH);

  delay(3000);  // Esperar 3 segundos


  // ----------------------------------------
  //  AMARILLO
  // ----------------------------------------
  digitalWrite(ROJO, LOW);
  digitalWrite(AMARILLO, HIGH);
  digitalWrite(VERDE, LOW);

  delay(2000);  // Esperar 1 segundo


  // Después de esto, loop() vuelve automáticamente al principio
}
