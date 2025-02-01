#include <stdio.h>
#include "esp_log.h" 
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_random.h"
#include "math.h"

#define TAG1 "DICE"

int dice_role()
{
    int random = esp_random();
    random = abs(random); // make it positive
    random = (random % 6) + 1; // make it from 1 to 6
    return random;
}

void app_main(void)
{
    esp_log_level_set("LOG", ESP_LOG_INFO);
    ESP_LOGE("LOG", "This is an error.");
    ESP_LOGW("LOG", "This is a warning.");
    ESP_LOGI("LOG", "This is an info.");
    ESP_LOGD("LOG", "This is a debug.");
    ESP_LOGV("LOG", "This is verbose.");

    while(true)
    {
        // Delay of 1 second
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        ESP_LOGI(TAG1, "Random number %ld", (long int)dice_role());
    }
}
