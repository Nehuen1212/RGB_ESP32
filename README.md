# RGB_ESP32

Una librería ligera y sencilla para controlar LEDs RGB en placas ESP32 utilizando PWM (Pulse Width Modulation). Esta librería permite configurar colores, ajustar el brillo y controlar la polaridad de los LEDs de manera eficiente.

## Características

- **Control de color RGB**: Establece colores personalizados con valores de 0-255 para rojo, verde y azul.
- **Control de brillo**: Ajusta el brillo del LED de 0% a 100%.
- **Polaridad reversible**: Soporte para LEDs con polaridad invertida.
- **Integración con SinricPro**: Compatible con SinricPro para control remoto vía app o voz (Alexa, Google Home).
- **Resolución configurable**: Ajusta la resolución del PWM (por defecto 8 bits).
- **Estructura Color**: Incluye una estructura `Color` para manejar colores de forma estructurada.

## Instalación

1. Clona o descarga este repositorio.
2. Copia los archivos `RGB_ESP32.h` y `RGB_ESP32.cpp` a la carpeta `lib` de tu proyecto PlatformIO.
3. Incluye la librería en tu código: `#include "RGB_ESP32.h"`

## Uso Básico

```cpp
#include <Arduino.h>
#include "RGB_ESP32.h"

// Inicializa el LED RGB en los pines 12 (Rojo), 5 (Verde), 4 (Azul)
RGB_LED rgb(12, 5, 4);

void setup() {
    rgb.init();  // Inicializa el PWM
    rgb.setColor(255, 0, 0);  // Rojo
    delay(1000);
    rgb.setColor(0, 255, 0);  // Verde
    delay(1000);
    rgb.setColor(0, 0, 255);  // Azul
}

void loop() {
    // Tu código aquí
}
```

## Uso con Control de Brillo

```cpp
RGB_LED rgb(12, 5, 4, 8, 2);  // Pin 2 para control de brillo

void setup() {
    rgb.init();
    rgb.setBrightness(50);  // 50% de brillo
    rgb.setColor(255, 255, 255);  // Blanco
}
```

## Integración con SinricPro

Esta librería es compatible con SinricPro para control inteligente. Consulta el archivo `main.cpp` en el ejemplo para ver una implementación completa.

## Métodos Disponibles

### Constructor
- `RGB_LED(int RedPin, int GreenPin, int BluePin, int res = 8, int brightnessPin = -1)`

### Inicialización
- `void init()`: Inicializa los canales PWM.

### Control de Color
- `void setColor(int rojo, int verde, int azul)`: Establece el color y lo guarda.
- `void setColor(Color color)`: Establece el color usando la estructura Color.
- `void setColorNoSave(int rojo, int verde, int azul)`: Establece el color sin guardarlo.

### Control de Estado
- `void on()`: Enciende el LED con el último color guardado.
- `void off()`: Apaga el LED.

### Control de Brillo
- `void setBrightness(int brightness)`: Establece el brillo (0-100).
- `void setBrightness()`: Aplica el brillo actual.
- `void addBrightness(int add)`: Aumenta el brillo.
- `void lowerBrightness(int low)`: Reduce el brillo.

### Otras Funciones
- `void reversePolarity()`: Invierte la polaridad de los colores.

## Estructura Color

```cpp
struct Color {
    int red, green, blue;
    Color();
    Color(int r, int g, int b);
    void invertColor();
};
```

## Requisitos

- Placa ESP32
- Arduino IDE o PlatformIO
- LEDs RGB (comunes ánodo o cátodo)

## Licencia

Este proyecto está bajo la Licencia MIT. Consulta el archivo LICENSE para más detalles.

## Contribuciones

¡Las contribuciones son bienvenidas! Si encuentras un error o tienes una mejora, abre un issue o envía un pull request.

## Autor

Nehuen Paglia - tizianopaglia@outlook.es