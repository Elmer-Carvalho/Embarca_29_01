#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

#define PIN_LED_G 11
#define PIN_LED_B 12
#define PIN_LED_R 13

// Vermelho será 0, Amarelo será 1 e Verde será 2
volatile uint8_t estado = 0;

// Protótipos
void iniciar_pinos();
bool mudar_cor(struct repeating_timer *t);


int main()
{
    stdio_init_all();

    iniciar_pinos();

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, mudar_cor, NULL, &timer);

    while (true) {
        printf("Estado atual do Semáforo: %i\n", estado);
        sleep_ms(1000);
    }
}

void iniciar_pinos() {
    gpio_init(PIN_LED_R);
    gpio_init(PIN_LED_B);
    gpio_init(PIN_LED_G);

    gpio_set_dir(PIN_LED_R, GPIO_OUT);
    gpio_set_dir(PIN_LED_B, GPIO_OUT);
    gpio_set_dir(PIN_LED_G, GPIO_OUT);
}

bool mudar_cor(struct repeating_timer *t) {
    gpio_put(PIN_LED_R, false);
    gpio_put(PIN_LED_G, false);
    gpio_put(PIN_LED_B, false);

    switch (estado) {
        case 0:
            gpio_put(PIN_LED_R, true);
            break;
        case 1: {
            //gpio_put(PIN_LED_R, true);
            //gpio_put(PIN_LED_G, true);
            gpio_put(PIN_LED_B, true);
        }
            break;
        case 2:
            gpio_put(PIN_LED_G, true);
            break;    
        default:
            break;
    }
    estado = (estado + 1) % 3;
    printf("SEMAFORO: %i", estado);
}


