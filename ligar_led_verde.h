#include <stdio.h>
#include "pico/stdlib.h"

#define LED_VERDE 11
#define LED_AZUL 12
#define LED_VERMELHO 13

void init_leds()
{
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_put(LED_VERDE, 0);

    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_put(LED_AZUL, 0);

    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_put(LED_VERMELHO, 0);
}

// Liga o LED verde e desliga os outros LEDs
void ligar_led_vermelho()
{
    gpio_put(LED_VERDE, 1);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERMELHO, 0);
    printf("LED verde aceso. Outros LEDs apagados.\n");
}
