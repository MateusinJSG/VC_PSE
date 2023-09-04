#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "spi_flash_mmap.h"
#include "esp_heap_caps.h"
#include "driver/gpio.h"
#include "rom/gpio.h"
#include "iniciar.h"

// Definir pinos
#define LED_PIN_RED 4
#define LED_PIN_YELLOW 2
#define sensor_Aberto 23
#define sensor_Fechado 22
#define botao 18

int estado = 1; // fechado
int flag = 0;

void app_main(){ //Função principal
    iniciar_leds();
    gpio_set_level(LED_PIN_RED, 0);
    gpio_set_level(LED_PIN_YELLOW, 0);
    voltar:
    bool bt = botao_estado();
    bool Aberto = gpio_get_level(sensor_Aberto);
    bool Fechado = gpio_get_level(sensor_Fechado);
    if (bt && estado==1){
        estado = 2; // abrindo
        gpio_set_level(LED_PIN_RED, 0);
        gpio_set_level(LED_PIN_YELLOW,1);
    }
    else if (Aberto && estado == 2)
    {
        estado =3; // aberto
        gpio_set_level(LED_PIN_RED, 1);
        gpio_set_level(LED_PIN_YELLOW,0);
    }
    else if (bt && estado == 3){
        estado =4; // fechando
        flag = !flag;
        gpio_set_level(LED_PIN_RED, 1);
        gpio_set_level(LED_PIN_YELLOW,1);
    }
    else if (Fechado && estado ==4){
        estado = 1; // fechado
        gpio_set_level(LED_PIN_RED, 0);
        gpio_set_level(LED_PIN_YELLOW,0);
    }
    printf("estado = %d", estado);
    printf("  botao = %d", bt);
    printf(" s_Aberto =%d", Aberto);
    printf(" s_Fechado =%d\n", Fechado);
    goto voltar;
}