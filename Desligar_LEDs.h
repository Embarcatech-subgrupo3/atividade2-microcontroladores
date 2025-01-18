#include <stdio.h>
#include "pico/stdlib.h"

// Pinos dos LEDs RGB
#define LED_RED 11
#define LED_GREEN 12
#define LED_BLUE 13

// Configurando os LEDs como saída
void configurar_leds() {
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_put(LED_RED, 1);  // Inicialmente ligado

    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_put(LED_GREEN, 1);  // Inicialmente ligado

    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_put(LED_BLUE, 1);  // Inicialmente ligado
}

// Função para desligar os LEDs específico
void desligar_led(int led) {
    gpio_put(led, 0);  // Apaga o LED
}

int main() {
    // Inicializa o sistema
    stdio_init_all();
    configurar_leds();

    printf("Bem-vindo! Digite 1 para desligar todos os LEDs:\n");

    while (true) {
        int opcao;
        printf("Digite sua escolha: ");
        scanf("%d", &opcao);  // Lê a entrada do usuário

        switch (opcao) {
            case 1:
                printf("Desligando os LEDs...\n");
                desligar_led(LED_RED);
                desligar_led(LED_GREEN);
                desligar_led(LED_BLUE);
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    }

    return 0;
}
