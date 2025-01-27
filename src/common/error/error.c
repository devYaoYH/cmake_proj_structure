#include "error.h"

/**
 * This function should be called if we encounter an unrecoverable error. In
 * non-flight builds, enter a panic state.
 *
 * @todo In flight, decide on appropriate reboot behavior
 *
 * Note: We do not use the pico's built-in panic function to allow for
 * customized behavior.
 */
void fatal_error()
{
#ifdef FLIGHT
    return;
#else
    for (uint32_t i = 0; i < 3; i++)
    {
        // TODO(yaoyiheng): need to add mocked pico lib 
        // gpio_put(PICO_DEFAULT_LED_PIN, 1);
        // sleep_ms(100);
        printf("FATAL_ERROR: %u", i);
    }
    exit(1);
#endif
}
