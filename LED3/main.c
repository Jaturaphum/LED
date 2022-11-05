#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

int deley1 = 5000;
int deley2 = 2000;
void normal(GREEN_PIN, YELLOW_PIN, RED_PIN) {
    gpio_put(GREEN_PIN, 1);
    sleep_ms(deley1);
    gpio_put(GREEN_PIN, 0);
    gpio_put(YELLOW_PIN, 1);
    sleep_ms(deley2);
    gpio_put(YELLOW_PIN, 0);
    gpio_put(RED_PIN, 1);
    sleep_ms(deley1);
    gpio_put(RED_PIN, 0);
    }

void show_signal(GREEN_PIN, YELLOW_PIN, RED_PIN) {
    gpio_put(RED_PIN, 1);
    gpio_put(YELLOW_PIN, 1);
    sleep_ms(500);
    gpio_put(RED_PIN, 0);
    gpio_put(YELLOW_PIN, 0);
    }

int main() {
    const uint RED_PIN = 7;
    const uint YELLOW_PIN = 8;
    const uint GREEN_PIN = 9;
    const uint SW_PIN = 6;
    uint pedestrian_crossing[] = {RED_PIN, YELLOW_PIN, GREEN_PIN};
    gpio_init(SW_PIN);
    gpio_set_dir(SW_PIN, GPIO_IN);
    gpio_pull_up(SW_PIN);
    adc_init();
    adc_gpio_init(26);
    adc_select_input(0);
    for (int i = 0; i < 3; i++) {
    gpio_init(pedestrian_crossing[i]);
    gpio_set_dir(pedestrian_crossing[i], GPIO_OUT);
    }

uint count = 0;
while (true) {
    if (!gpio_get(SW_PIN)) {
        count++;
        sleep_ms(500);
        }
    if (count == 1) {
    show_signal(GREEN_PIN, YELLOW_PIN, RED_PIN);
    }else{
    normal(GREEN_PIN, YELLOW_PIN, RED_PIN);
    }
    count = 0;
 }
}