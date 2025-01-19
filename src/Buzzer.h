#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include <string.h>

// Definindo o pino do buzzer
#define BUZZER 21

// Função que liga o buzzer por 2 segundos
void buzzer_tone(int frequencia, int duracao)
{
    int delay = 1000000 / (frequencia * 2);
    int ciclos = (frequencia * duracao) / 1000;

    for (int i = 0; i < ciclos; i++)
    {
        gpio_put(BUZZER, 1);
        sleep_us(delay);
        gpio_put(BUZZER, 0);
        sleep_us(delay);
    }
}

void buzzer()
{   
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
    gpio_put(BUZZER, 0); // Inicialmente desligado
    buzzer_tone(1000, 2000);
}