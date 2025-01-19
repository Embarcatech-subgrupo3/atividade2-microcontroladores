#include <stdio.h>
#include "pico/stdlib.h"

#define LED_VERDE 11
#define LED_AZUL 12
#define LED_VERMELHO 13

// Liga o LED vermelho e desliga os outros LEDs
void ligar_led_vermelho()
{
    gpio_put(LED_VERDE, 0);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERMELHO, 1);
    printf("LED vermelho aceso.\n");
}
