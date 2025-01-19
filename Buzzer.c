#include <stdio.h>
#include "pico/stdlib.h"

// Definindo o pino do buzzer
#define BUZZER_PIN 21

// Inicializando o buzzer
void init_buzzer()
{
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);
}

// Função que liga o buzzer por 2 segundos
void ligar_buzzer()
{
    gpio_put(BUZZER_PIN, 1); // Liga o buzzer
    printf("Buzzer ligado\n");
    sleep_ms(2000); // Aguarda 2 segundos
    gpio_put(BUZZER_PIN, 0); // Desliga o buzzer
}

int main()
{
    stdio_init_all();
    ativar_buzzer();
    
    char comando [10]; // Variável para receber o comando

    printf("Digite \"BUZZER\" para ligar o Buzzer: \n"); // Mensagem inicial

    while (1) 
    {
        if (fgets(comando, sizeof(comando), stdin))  // Lê o comando via UART
        {   
            comando[strcspn(comando, "\n")] = 0;    // Remove o caractere de nova linha (\n)

            if (strcmp(comando, "BUZZER") == 0) 
            {
                init_buzzer();        
            } 
        }
    }
    return 0;
}