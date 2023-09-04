#include "driver/gpio.h"
#include "./iniciar.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void iniciar_leds() //Função para iniciar os pinos do LED
{
    esp_rom_gpio_pad_select_gpio(LED_PIN_RED);
    gpio_set_direction(LED_PIN_RED, GPIO_MODE_OUTPUT);
    esp_rom_gpio_pad_select_gpio(LED_PIN_YELLOW);
    gpio_set_direction(LED_PIN_YELLOW, GPIO_MODE_OUTPUT);
}

//void iniciar_sensor() //Função para iniciar os sensores
//{
//    esp_rom_gpio_pad_select_gpio(sensor_Aberto);
//    gpio_set_direction(sensor_Aberto, GPIO_MODE_INPUT);
//    esp_rom_gpio_pad_select_gpio(sensor_Fechado);
//    gpio_set_direction(sensor_Fechado, GPIO_MODE_INPUT);
//}

int botao_estado(){ //Função para leitura do botão
    bool status = 0;
    bool button = 0;
    bool last_button = 0;
    int tempo = 0;

    while(tempo<10)
    {
        button = gpio_get_level(botao);


        if (button && !last_button)
        {
            status = !status;
            last_button = button;
            break;
        }
        vTaskDelay(10/portTICK_PERIOD_MS);
        tempo ++;
    }
    return status;
}
