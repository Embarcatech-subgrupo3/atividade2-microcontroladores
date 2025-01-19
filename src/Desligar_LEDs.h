#include <stdio.h>
#include "pico/stdlib.h"

#define LED_VERDE 11
#define LED_AZUL 12
#define LED_VERMELHO 13

// Função para desligar os LEDs específico
void desligar_led(int led)
{
    gpio_put(led, 0); // Apaga o LED
}

int desligar()
{
    desligar_led(LED_VERDE);
    desligar_led(LED_AZUL);
    desligar_led(LED_VERMELHO);

    return 0;
}
