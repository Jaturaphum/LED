#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

int main() {
  int deley = 500;
  const uint RED_PIN = 15;
  const uint YELLOW_PIN = 13;
  const uint GREEN_PIN = 12;
  const uint SW_PIN = 14;
  uint cuonting_switch[]= {RED_PIN, YELLOW_PIN,GREEN_PIN};
  gpio_init(SW_PIN);
  gpio_set_dir(SW_PIN, GPIO_IN);
  gpio_pull_up(SW_PIN);
  for(int i=0; i<3; i++){
    gpio_init(cuonting_switch[i]);
    gpio_set_dir(cuonting_switch[i], GPIO_OUT);
  }

  uint number = 0;
  while (true) {
    if (number == 0) {
    gpio_put(RED_PIN, 0);
    gpio_put(YELLOW_PIN, 0);
    gpio_put(GREEN_PIN, 0);
  } else if (number == 1) {
    gpio_put(RED_PIN, 1);
    gpio_put(YELLOW_PIN, 0);
    gpio_put(GREEN_PIN, 0);
  } else if (number == 2) {
    gpio_put(RED_PIN, 0);
    gpio_put(YELLOW_PIN, 1);
    gpio_put(GREEN_PIN, 0);
  } else if (number == 3) {
    gpio_put(RED_PIN, 1);
    gpio_put(YELLOW_PIN, 1);
    gpio_put(GREEN_PIN, 0);
  } else if (number == 4) {
    gpio_put(RED_PIN, 0);
    gpio_put(YELLOW_PIN, 0);
    gpio_put(GREEN_PIN, 1);
  } else if (number == 5) {
    gpio_put(RED_PIN, 1);
    gpio_put(YELLOW_PIN, 0);
    gpio_put(GREEN_PIN, 1);
  } else if (number == 6) {
    gpio_put(RED_PIN, 0);
    gpio_put(YELLOW_PIN, 1);
    gpio_put(GREEN_PIN, 1);
  } else if (number == 7) {
    gpio_put(RED_PIN, 1);
    gpio_put(YELLOW_PIN, 1);
    gpio_put(GREEN_PIN, 1);
  }
    if (!gpio_get(SW_PIN)) {
        number++;
        sleep_ms(deley);
    }
    if(number > 7) {
        number = 0;
    }
  }
}

  
