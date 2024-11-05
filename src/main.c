#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/devicetree.h>

// #define LED_NODE DT_ALIAS(leddeneme)

// #if !DT_NODE_HAS_STATUS(LED_NODE, okay)
// #error "Unsupported board: led0 alias is not defined"
// #endif


static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(DT_ALIAS(leddeneme), gpios);

int main(void){
    if (!device_is_ready(led.port)) {
        return 0;
    }

    gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);

    while (1) {
        gpio_pin_toggle_dt(&led);
        k_msleep(2000);
    }
}