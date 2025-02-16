#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "nvs.h"
#include "nvs_flash.h"
#include "esp_log.h"

#define TAG "LOG"
#define STORAGE_NAMESPACE "my_storage"
#define STORAGE_KEY "num_reboots"

void app_main(void)
{
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    ESP_ERROR_CHECK(nvs_flash_init());

    nvs_handle handler;

    ESP_ERROR_CHECK(nvs_open(STORAGE_NAMESPACE, NVS_READWRITE, &handler));

    int32_t num_reboots = 0;

    esp_err_t result = nvs_get_i32(handler, STORAGE_KEY, &num_reboots);

    switch (result)
    {
    case ESP_OK:
        ESP_LOGI(TAG, "Number of reboots is %ld", num_reboots);
        break;
    
    default:
        ESP_LOGE(TAG, "Error %s while reading %s", esp_err_to_name(result) , STORAGE_NAMESPACE);
        break;
    }

    num_reboots++;
    nvs_set_i32(handler, STORAGE_KEY, num_reboots);
    nvs_commit(handler);
    nvs_close(handler);
}
