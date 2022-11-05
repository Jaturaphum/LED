#include "pico/stdlib.h"
#include "hardware/adc.h"
#include <stdio.h>

int main() {
    int deley = 2000;
    const uint RED_PIN = 11;
    const uint YELLOW_PIN = 12;
    const uint GREEN_PIN = 13;
    const uint ADC_LIGHT = 26;
    uint [] = {RED_PIN, YELLOW_PIN, GREEN_PIN};
    stdio_init_all();
    adc_init();
    adc_gpio_init(ADC_LIGHT);
    adc_select_input(0);
    for (int i = 0; i < 3; i++) {
    gpio_init(light_leve[i]);
    gpio_set_dir(light_leve[i], GPIO_OUT);
    }

uint i = 0;
while (true) {
    const float conversion_factor = 100.0f / (1 << 12);
    uint16_t result = adc_read();
    float val = result * conversion_factor;
    printf("Raw value: 0x%03x, light percent: %f %\n", result, val);
    if (val < 1.50) {
    gpio_put(GREEN_PIN, 1);
    gpio_put(RED_PIN, 0);
    gpio_put(YELLOW_PIN, 0);
    }else if (val < 2.0) {
    gpio_put(GREEN_PIN, 0);
    gpio_put(RED_PIN, 0);
    gpio_put(YELLOW_PIN, 1);
    }else{
    gpio_put(GREEN_PIN, 0);
    gpio_put(RED_PIN, 1);
    gpio_put(YELLOW_PIN, 0);
    }
    sleep_ms(deley);
    }
}