<p align="center">
  <img src="./assets/ras_logo.jpeg" alt="Logo IEEE RAS CUC" width="300"/>
</p>

# Del Código al Control: Introducción a la Programación de Microcontroladores

> **Taller práctico e iniciativa de formación técnica impulsada por el capítulo estudiantil IEEE Robotics and Automation Society (RAS) – Universidad de la Costa (CUC).**

Este repositorio reúne el material técnico, esquemáticos y código fuente desarrollados durante el taller **"Del código al control: introducción a la programación de microcontroladores"**, utilizando el microcontrolador **ESP32** y la plataforma de simulación **Wokwi**.

El contenido está diseñado para guiar al estudiante desde la sintaxis básica y lógica digital hasta el manejo de entradas analógicas, comunicación serie e integración de buses I2C para telemetría en tiempo real.

---

## Temario del Taller

1. **Sistemas de Control, Entorno Wokwi y Estructura C++:** Configuración del entorno de desarrollo, ciclo de ejecución (`setup()` y `loop()`), variables y sintaxis básica.
2. **Entradas/Salidas Digitales y Temporización:** Manejo de pines digitales, estados lógicos y pausas no bloqueantes/temporización.
3. **Entradas/Salidas Analógicas, Consola Serial y Lógica Condicional:** Conversión analógica-digital (ADC), monitoreo de variables por el puerto serie y toma de decisiones condicionales.
4. **Librerías, Comunicación I2C y Procesamiento de Datos:** Importación de librerías externas, protocolo de comunicación I2C y procesamiento/mapeo de datos para despliegue visual.

---

## Material de Apoyo

* 📄 **Diapositivas del Taller:** [Descargar Presentación (PDF)](https://raw.githubusercontent.com/dagoregino/evento-del-codigo-al-control/main/assets/del_codigo_al_control.pdf)

## Estructura del Repositorio

```text
.
├── assets/
│   ├── ras_logo.jpeg
│   └── del_codigo_al_control.pdf
├── Reto_1/
│   ├── README.md
│   ├── conexiones.png
│   ├── diagram.json
│   └── sketch.ino
├── Reto_2/
│   ├── README.md
│   ├── conexiones.png
│   ├── diagram.json
│   └── sketch.ino
├── Reto_3/
│   ├── README.md
│   ├── conexiones.png
│   ├── diagram.json
│   └── sketch.ino
└── README.md
