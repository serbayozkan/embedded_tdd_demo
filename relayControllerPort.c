/*
 * relaySchedulerPort.c
 *
 *  Created on: Apr 28, 2020
 *      Author: serbay.ozkan
 */

#include <stdio.h>

#include "relayController.h"

static void relay_gpio_high(uint8_t id);
static void relay_gpio_low(uint8_t id);

void relay_gpio_init(void)
{
	relay_gpio_on = relay_gpio_high;
	relay_gpio_off = relay_gpio_low;
}

static void relay_gpio_high(uint8_t id)
{
	switch (id) {
		case RELAY1:
		// Set GPIO Pin of Relay1 to High
			break;

		case RELAY2:
		// Set GPIO Pin of Relay2 to High
			break;

		case RELAY3:
		// Set GPIO Pin of Relay3 to High
			break;

		case RELAY4:
		// Set GPIO Pin of Relay4 to High
			break;

		default:
			break;
	}
}

static void relay_gpio_low(uint8_t id)
{
	switch (id) {
		case RELAY1:
		// Set GPIO Pin of Relay1 to Low
			break;

		case RELAY2:
		// Set GPIO Pin of Relay2 to Low
			break;

		case RELAY3:
		// Set GPIO Pin of Relay3 to Low
			break;

		case RELAY4:
		// Set GPIO Pin of Relay4 to Low
			break;

		default:
			break;
	}
}

