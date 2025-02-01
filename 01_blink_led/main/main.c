#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_PIN 2

void app_main(void)
{
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    // Use uint32_t instead of boll because of gpio_set_level func below.
    uint32_t led_state = 0;

    while (true)
    {
        gpio_set_level(LED_PIN, led_state);
        led_state = !led_state;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }   
}
