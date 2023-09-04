#include "driver/gpio.h"

// Definir pinos
#define LED_PIN_RED 4
#define LED_PIN_YELLOW 2
#define sensor_Aberto 23
#define sensor_Fechado 22
#define botao 18

void iniciar_leds();
//void iniciar_sensor();
int botao_estado();