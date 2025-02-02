#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define LED_RED 11
#define LED_GREEN 12
#define LED_BLUE 13
#define BUTTON_A 5
#define BUTTON_B 6
#define LED_MATRIX 7

#define NUM_LEDS 25  // Matriz 5x5 de LEDs WS2812

Adafruit_NeoPixel matrix = Adafruit_NeoPixel(NUM_LEDS, LED_MATRIX, NEO_GRB + NEO_KHZ800);

volatile int numero_atual = 0;
volatile bool atualizar_display = false;

void IRAM_ATTR incrementarNumero() {
    numero_atual = (numero_atual + 1) % 10;
    atualizar_display = true;
}

void IRAM_ATTR decrementarNumero() {
    numero_atual = (numero_atual - 1 + 10) % 10;
    atualizar_display = true;
}

void setup() {
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);
    pinMode(BUTTON_A, INPUT_PULLUP);
    pinMode(BUTTON_B, INPUT_PULLUP);
    
    attachInterrupt(digitalPinToInterrupt(BUTTON_A), incrementarNumero, FALLING);
    attachInterrupt(digitalPinToInterrupt(BUTTON_B), decrementarNumero, FALLING);

    matrix.begin();
    matrix.show();
}

void loop() {
    piscarLedVermelho();
    if (atualizar_display) {
        atualizarDisplay();
        atualizar_display = false;
    }
}

void piscarLedVermelho() {
    static unsigned long lastToggle = 0;
    static bool estado = false;
    if (millis() - lastToggle >= 100) { // 5 vezes por segundo
        lastToggle = millis();
        estado = !estado;
        digitalWrite(LED_RED, estado);
    }
}

void atualizarDisplay() {
    matrix.clear();
    // Exibir número na matriz 
    for (int i = 0; i < NUM_LEDS; i++) {
        if ((i / 5) == numero_atual) {
            matrix.setPixelColor(i, matrix.Color(255, 255, 255));
        }
    }
    matrix.show();
}