# Reto 1: Control de un Semáforo

### Planteamiento del Reto
Diseñar y programar la secuencia de control de un semáforo de tres tiempos utilizando pines de salida digital en el ESP32.

---

### Requerimientos del Sistema

* **Luz Verde:** Encendida durante 3 segundos (paso libre).
* **Luz Amarilla:** Encendida durante 1 segundo (transición/advertencia).
* **Luz Roja:** Encendida durante 3 segundos (alto total).

---

### Objetivo Técnico
Aplicar la configuración de pines digitales con `pinMode()`, el cambio de estados lógicos mediante `digitalWrite()` y la gestión de pausas temporales con `delay()`.

---

### Conexiones de Hardware

> **Nota:** Cada LED debe tener su propia resistencia de 220 Ω conectada en serie para limitar la corriente.

| Dispositivo | Pin del Componente | Conexión en ESP32 / Alimentación |
| :--- | :--- | :--- |
| **LED Rojo** | Ánodo (+) | GPIO 25 (con Resistencia 220 Ω) |
| | Cátodo (-) | GND |
| **LED Amarillo** | Ánodo (+) | GPIO 26 (con Resistencia 220 Ω) |
| | Cátodo (-) | GND |
| **LED Verde** | Ánodo (+) | GPIO 27 (con Resistencia 220 Ω) |
| | Cátodo (-) | GND |

#### Enlace Wokwi:
https://wokwi.com/projects/473251545960984577

#### Diagrama de Conexión:
```text
  [ ESP32 ]
   ├── GPIO 25 ─── [Resistencia 220 Ω] ─── ( + ) LED Rojo ( - ) ─── GND
   ├── GPIO 26 ─── [Resistencia 220 Ω] ─── ( + ) LED Amarillo ( - ) ─── GND
   └── GPIO 27 ─── [Resistencia 220 Ω] ─── ( + ) LED Verde ( - ) ─── GND
