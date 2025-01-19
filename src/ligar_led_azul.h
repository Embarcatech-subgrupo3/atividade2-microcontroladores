#include <stdio.h>
#include "pico/stdlib.h"

#define LED_VERDE 11
#define LED_AZUL 12
#define LED_VERMELHO 13

// Liga o LED azul e desliga os outros LEDs
void ligar_led_azul()
{
    gpio_put(LED_VERDE, 0);
    gpio_put(LED_AZUL, 1);
    gpio_put(LED_VERMELHO, 0);
    printf("LED azul aceso.\n");
}
