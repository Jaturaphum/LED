#include "pico/stdlib.h"

int main() {
    int deley = 500;
    const uint RED_PIN = 13;
    const uint YELLOW_PIN = 14;
    const uint GREEN_PIN = 15;
    uint countiong_light[]= {RED_PIN, YELLOW_PIN, GREEN_PIN };
    for(int i=0; i<3; i++){
        gpio_init(countiong_light[i]);
        gpio_set_dir(countiong_light[i], GPIO_OUT);
    }

while (true) {
    gpio_put(RED_PIN, 0);
    gpio_put(YELLOW_PIN, 0);
    gpio_put(GREEN_PIN, 0);
    sleep_ms(deley);
    gpio_put(RED_PIN, 1);
    gpio_put(YELLOW_PIN, 0);
    gpio_put(GREEN_PIN, 0);
    sleep_ms(deley);
    gpio_put(RED_PIN, 0);
    gpio_put(YELLOW_PIN, 1);
    gpio_put(GREEN_PIN, 0);
    sleep_ms(deley);
    gpio_put(RED_PIN, 1);
    gpio_put(YELLOW_PIN, 1);
    gpio_put(GREEN_PIN, 0);
    sleep_ms(deley);
    gpio_put(RED_PIN, 0);
    gpio_put(YELLOW_PIN, 0);
    gpio_put(GREEN_PIN, 1);
    sleep_ms(deley);
    gpio_put(RED_PIN, 1);
    gpio_put(YELLOW_PIN, 0);
    gpio_put(GREEN_PIN, 1);
    sleep_ms(deley);
    gpio_put(RED_PIN, 0);
    gpio_put(YELLOW_PIN, 1);
    gpio_put(GREEN_PIN, 1);
    sleep_ms(deley);
    gpio_put(RED_PIN, 1);
    gpio_put(YELLOW_PIN, 1);
    gpio_put(GREEN_PIN, 1);
    sleep_ms(deley);
    }
}