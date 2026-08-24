# Reto 3: Radar de Distancia y Telemetría Visual

### Planteamiento del Reto
Diseñar un radar de distancia en tiempo real que mida la cercanía de un objeto con un sensor ultrasónico y muestre la telemetría en una pantalla OLED.

---

### Requerimientos del Sistema

* **Medición:** Enviar un pulso de disparo, medir el tiempo de retorno del eco con `pulseIn()` y convertir o reescalar el valor mediante la función `map()`.
* **Visualización:** Importar las librerías necesarias con `#include` y mostrar la distancia medida en la pantalla OLED a través del bus I2C.
* **Alerta:** Utilizar una estructura condicional `if / else` para encender un LED y desplegar un aviso en pantalla si el objeto supera el umbral de distancia de seguridad.

---

### Objetivo Técnico
Integrar librerías externas, comunicación por bus I2C, medición de tiempos de pulso y procesamiento de datos para el desarrollo de un sistema de telemetría visual autónomo.

---

### Conexiones de Hardware

> **Nota:** La pantalla OLED opera a 3.3V, mientras que el sensor ultrasónico HC-SR04 requiere alimentación de 5V. El LED de alerta debe incluir su resistencia de 220 Ω en serie.

| Dispositivo | Pin del Componente | Conexión en ESP32 / Alimentación |
| :--- | :--- | :--- |
| **Sensor HC-SR04** | VCC | 5V |
| | GND | GND |
| | TRIG | GPIO 26 |
| | ECHO | GPIO 27 |
| **Pantalla OLED I2C** | VCC | 3.3V |
| | GND | GND |
| | SDA | GPIO 21 |
| | SCL | GPIO 22 |
| **LED de Alerta** | Ánodo (+) | GPIO 25 (con Resistencia 220 Ω) |
| | Cátodo (-) | GND |

#### Diagrama de Conexión:
```text
  [ ESP32 ]
   ├── 5V ──────── ( VCC ) Sensor HC-SR04
   ├── 3.3V ────── ( VCC ) Pantalla OLED
   ├── GND ─────── ( GND ) Sensor HC-SR04 / Pantalla OLED / LED
   │
   ├── GPIO 26 ─── ( TRIG ) Sensor HC-SR04
   ├── GPIO 27 ─── ( ECHO ) Sensor HC-SR04
   │
   ├── GPIO 21 ─── ( SDA )  Pantalla OLED
   ├── GPIO 22 ─── ( SCL )  Pantalla OLED
   │
   └── GPIO 25 ─── [Resistencia 220 Ω] ─── ( + ) LED Alerta ( - ) ─── GND
