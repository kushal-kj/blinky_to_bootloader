#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

static void rcc_setup(void)
{
	rcc_clock_setup_pll(&rcc_hsi_configs[RCC_CLOCK_3V3_84MHZ]);
}

static void gpio_setup(void)
{
	rcc_periph_clock_enable(RCC_GPIOA);
	gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO5);
}

int main(void)
{
	rcc_setup();
	gpio_setup();

	while(1)
	{
		gpio_toggle(GPIOA, GPIO5);
		for(int i=0; i< 1000000; i++) __asm__("nop");

	}
	return 0;
}
