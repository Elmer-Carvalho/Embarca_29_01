#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

#define PIN_LED_G 11
#define PIN_LED_B 12
#define PIN_LED_R 13
#define PIN_BUTTON 5

// 1 - Todos leds ligados 2 - Apenas 2 leds 3 - Apenas 1 led.
volatile uint8_t estado = 0;
// Desligado será 0 e Ligado será 1
volatile uint8_t led_ligado = 0;

// Protótipos
void iniciar_pinos();
void button_irq_callback(uint gpio, uint32_t events);
int64_t led_callback(alarm_id_t id, void *user_data);

int main()
{
    stdio_init_all();

    iniciar_pinos();

     gpio_set_irq_enabled_with_callback(PIN_BUTTON, GPIO_IRQ_EDGE_FALL, true, &button_irq_callback);

    while (true) {

    }
}

void iniciar_pinos() {
    gpio_init(PIN_LED_R);
    gpio_init(PIN_LED_B);
    gpio_init(PIN_LED_G);
    gpio_init(PIN_BUTTON);

    gpio_set_dir(PIN_LED_R, GPIO_OUT);
    gpio_set_dir(PIN_LED_B, GPIO_OUT);
    gpio_set_dir(PIN_LED_G, GPIO_OUT);
    gpio_set_dir(PIN_BUTTON, GPIO_IN);

    gpio_pull_up(PIN_BUTTON);
}


void button_irq_callback(uint gpio, uint32_t events) {
    if (!led_ligado) {
        led_ligado = 1;
        gpio_put(PIN_LED_R, true);
        gpio_put(PIN_LED_B, true);
        gpio_put(PIN_LED_G, true);
        add_alarm_in_ms(3000, &led_callback, NULL, false);
    }
}

int64_t led_callback(alarm_id_t id, void *user_data) {
    switch (estado)
    {
    case 0:
        gpio_put(PIN_LED_R, false);
        estado++;
        add_alarm_in_ms(3000, led_callback, NULL, false);
        break;
    case 1:
        gpio_put(PIN_LED_B, false);
        estado++;
        add_alarm_in_ms(3000, led_callback, NULL, false);
        break;
    case 2:
        gpio_put(PIN_LED_G, false);
        estado = 0;
        led_ligado = 0;
        break;
    default:
        break;
    }
}
