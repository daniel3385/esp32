#include <stdio.h>
#include "stdbool.h"
#include "esp_log.h"

#define TAG "MY_CUSTOM"

void app_main(void)
{
    ESP_LOGI(TAG, "My custom int is %d", CONFIG_MY_INT);
    ESP_LOGI(TAG, "My custom string is %s", CONFIG_MY_STRING);

    bool my_bool;

    #ifdef CONFIG_MY_BOOL
        my_bool = true;
    #else
        my_bool = false;
    #endif

    ESP_LOGI(TAG, "My custom bool is %s", (my_bool ? "yes" : "no"));

    int my_option;

    #ifdef CONFIG_OPTION_1
        my_option = 1;
    #elif CONFIG_OPTION_2
        my_option = 2;
    #else
        my_option = 3;
    #endif

    ESP_LOGI(TAG, "My custom option is %d", my_option);
}
