#include <FreeRTOS.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>
#include <stdint.h>

#include "system/system.h"

void gpio_setup(void);
void delay_ms(uint32_t ms);

void delay_ms(uint32_t ms)
{
    const uint32_t loop_count =
        21000; // This value can be adjusted based on the actual clock frequency.

    for (uint32_t i = 0; i < ms; i++)
    {
        for (uint32_t j = 0; j < loop_count; j++)
        {
            __asm__("nop");
        }
    }
}

void gpio_setup(void)
{
    rcc_periph_clock_enable(RCC_GPIOA);
    gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO5);
}

int main(void)
{
    clock_setup();
    gpio_setup();

    while (1)
    {
        // Your application code here
        gpio_toggle(GPIOA, GPIO5);
        delay_ms(500);
    }

    return 0;
}
