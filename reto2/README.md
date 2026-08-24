# Reto 2: Sistema de Monitoreo de Temperatura

### Planteamiento del Reto
Diseñar un sistema de monitoreo térmico con un sensor NTC que active una alerta automática ante un incremento de temperatura.

---

### Requerimientos del Sistema

* **Lectura:** Capturar el valor analógico del sensor NTC mediante la función `analogRead()`.
* **Supervisión:** Enviar la lectura obtenida al Monitor Serie usando `Serial.println()`.
* **Alerta:** Utilizar una estructura condicional `if / else` para encender un LED si la lectura supera el umbral límite configurado y mantenerlo apagado en caso contrario.

---

### Objetivo Técnico
Aplicar lecturas del conversor analógico-digital (ADC), visualización de datos en tiempo real mediante comunicación serie y toma de decisiones condicionales para el control de salidas.

---

### Conexiones de Hardware

> **Nota:** El LED de alerta debe contar con su propia resistencia de 220 Ω en serie para limitar la corriente.

| Componente | Pin de Señal / Ánodo (+) | Alimentación / Cátodo (-) |
| :--- | :---: | :---: |
| **Sensor NTC** | GPIO 34 (Salida) | VCC (3.3V) / GND |
| **LED de Alerta** | GPIO 25 (con Resistencia 220 Ω) | GND |

#### Diagrama de Conexión:
```text
  [ ESP32 ]
   ├── 3.3V ────── ( VCC ) Sensor NTC
   ├── GPIO 34 ─── ( OUT ) Sensor NTC
   ├── GND ─────── ( GND ) Sensor NTC
   │
   └── GPIO 25 ─── [Resistencia 220 Ω] ─── ( + ) LED Alerta ( - ) ─── GND
