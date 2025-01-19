#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "./src/Desligar_LEDs.h"
#include "./src/acender_todos_LEDs.h"
#include "./src/ligar_led_verde.h"
#include "./src/ligar_led_azul.h"
#include "./src/ligar_led_vermelho.h"
#include "./src/Buzzer.h"

#define LED_VERDE 11
#define LED_AZUL 12
#define LED_VERMELHO 13

#define N 10

int main()
{
    stdio_init_all();

    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);

    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);

    printf("\n");
    printf("Opções válidas: ");
    printf("AZUL, VERMELHO, VERDE, BRANCO, OFF, BUZZER\n");

    char arr[N];
    while (1)
    {
        fgets(arr, N, stdin);
        arr[strcspn(arr, "\n")] = 0; // substituir enter por null character

        if (strcmp(arr, "AZUL") == 0)
            ligar_led_azul();
        
        else if (strcmp(arr, "VERMELHO") == 0)
            ligar_led_vermelho();
        
        else if (strcmp(arr, "VERDE") == 0)
            ligar_led_verde();

        else if (strcmp(arr, "BRANCO") == 0)
        {
            todos();
            printf("Todos LEDs acesos.\n");
        }
        else if (strcmp(arr, "OFF") == 0)
        {
            desligar(); // desliga todos os LEDs
            printf("Todos LEDs desligados.\n");
        }
        else if (strcmp(arr, "BUZZER") == 0)
        {   
            printf("Buzzer tocando.\n");
            buzzer();
        }
        else
            printf("Opção inválida.\n");
    }
}