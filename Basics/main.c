//-----------------------------------------------------------------------------------------------
/*
 * Program to toggle the inbuilt LED of STM32F407 Discovery board.
 *
 * GPIOD -> PIN 12 -> Green LED
 * GPIOD -> PIN 13 -> Orange LED
 * GPIOD -> PIN 14 -> Red LED
 * GPIOD -> PIN 15 -> Blue LED
 *
 * Steps:
 * 
 * 1. Enable clock access to the GPIOD by accessing 
 *    'RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)' and setting bit 3 as high.
 *
 * 2. Set pins 12,13,14,15 of GPIOD as output type by accessing 'GPIO port mode register (GPIOx_MODER)'.
 *    01: General purpose output mode.
 *
 * 3. To turn on and off the LEDs, set the corresponding bits in the 
 *    'GPIO port bit set/reset register (GPIOx_BSRR)'.
 *
 * 4. Call the delay function.
 *
 * Author            : Vysakh C S
 * Date              : 10-02-2024
 * Development board : STM32F407VGT6 Discovery Board
 * IDE               : Keil uVision V5.39.0.0
 */
//-----------------------------------------------------------------------------------------------

#include "stm32f407xx.h"

// Function prototypes
void clock_config(void);
void gpio_config(void);
void delay(void);
void SysTick_Handler(void);
uint32_t getTick(void);
void Systick(void);
void Delays(uint32_t seconds);
void Blue_ON(void);
void Blue_OFF(void);
void Orange_ON(void);
void Orange_OFF(void);
int blue_main(void);
int orange_main(void);

// Global variables for tick counts
static volatile uint32_t tick;
static volatile uint32_t _tick;
volatile uint32_t orange_stack[40];
volatile uint32_t blue_stack[40];

uint32_t *sp_orange = &orange_stack;
uint32_t *sp_blue = &blue_stack;

//-----------------------------------------------------------------------------------------------
// Function to turn on the Blue LED (PIN 15)
void Blue_ON(void) {
    GPIOD->ODR |= GPIO_ODR_OD15;
}

// Function to turn off all LEDs
void Blue_OFF(void) {
    GPIOD->ODR = 0U;
}

// Function to turn on the Orange LED (PIN 13)
void Orange_ON(void) {
    GPIOD->ODR |= GPIO_ODR_OD13;
}

// Function to turn off all LEDs
void Orange_OFF(void) {
    GPIOD->ODR = 0U;
}

// Blue LED main function
int blue_main(void) {
    while (1) {
        Blue_ON();
        Delays(1);
        Blue_OFF();
        Delays(1);
    }
}

// Orange LED main function
int orange_main(void) {
    while (1) {
        Orange_ON();
        Delays(1);
        Orange_OFF();
        Delays(1);
    }
}

//-----------------------------------------------------------------------------------------------
// Main function
int main(void) {
    uint32_t volatile start = 0U; // Can be changed to toggle between blue_main and orange_main
    clock_config();
    gpio_config();
    Systick();

    if (start) {
        blue_main();
    } else {
        orange_main();
    }

    while (1) {
        // Infinite loop
    }
}
//-----------------------------------------------------------------------------------------------

// Enabling clock access to the GPIOD
void clock_config(void) {
    // Setting 3rd bit in the RCC_AHB1ENR register to enable GPIOD clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
}

// Setting MODE register to output type
void gpio_config(void) {
    // GPIOD pins - 12,13,14,15 set to output
    GPIOD->MODER |= GPIO_MODER_MODER12_0 | GPIO_MODER_MODER13_0 | GPIO_MODER_MODER14_0 | GPIO_MODER_MODER15_0;
}

// SysTick configuration for time-based delays
void Systick(void) {
    SystemCoreClockUpdate();
    SysTick_Config(SystemCoreClock / 100U);  // 10ms interval
    __enable_irq();
}

// SysTick Handler (interrupt-based time tracking)
void SysTick_Handler(void) {
    ++tick;
}

// Function to retrieve the current tick count
uint32_t getTick(void) {
    __disable_irq();
    _tick = tick;
    __enable_irq();
    return _tick;
}

// Delays function in seconds (based on SysTick)
void Delays(uint32_t seconds) {
    uint32_t temp;
    seconds *= 100;  // Convert seconds to 10ms ticks
    temp = getTick();
    while ((getTick() - temp) < seconds) {
        // Wait until the required number of ticks pass
    }
}
//-----------------------------------------------------------------------------------------------
