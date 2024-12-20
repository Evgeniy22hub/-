#include<stdio.h>

typedef struct {
    char *name;       
    char *core;      
    int  frequency; 
    int  temperature;
} microcontroller;

int main() {
    microcontroller STM32F407VG = {
        .name = "STM32F407VG",
        .core = "Cortex-M4F",
        .frequency = 125, 
        .temperature = 45
    };


    printf("До модернизации:\n");
    printf("Название: %s\n", STM32F407VG.name);
    printf("Ядро: %s\n", STM32F407VG.core);
    printf("Частота: %d МГц\n", STM32F407VG.frequency);
    printf("Температура: %d C\n\n", STM32F407VG.temperature);

    STM32F407VG.frequency = 168;
    STM32F407VG.temperature = 75;

    printf("После модернизации:\n");
    printf("Название: %s\n", STM32F407VG.name);
    printf("Ядро: %s\n", STM32F407VG.core);
    printf("Частота: %d МГц\n", STM32F407VG.frequency);
    printf("Температура: %d C\n", STM32F407VG.temperature);

    return 0;
}