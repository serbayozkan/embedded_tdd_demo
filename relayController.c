/*
 * relayController.c
 *
 *  Created on: Apr 26, 2020
 *      Author: serbay.ozkan
 */

#include "relayController.h"

#include <stddef.h>

static bool relay_status[MAX_RELAY_NUMBER];

static bool relay_is_id_correct(uint8_t id);

vptr_to_func relay_gpio_on;
vptr_to_func relay_gpio_off;

bool relay_get_status(uint8_t id)
{
	if (relay_is_id_correct(id)) return relay_status[id];
	else return false;
}

void relay_set_status(uint8_t id)
{
	relay_status[id] = true;
}

void relay_clear_status(uint8_t id)
{
	relay_status[id] = false;
}

static bool relay_is_id_correct(uint8_t id)
{
	bool is_id_correct = false;

	if (id < RELAY1 || id > RELAY4) is_id_correct =  false;
	else is_id_correct = true;

	return is_id_correct;
}

void relay_turn_on(uint8_t id)
{
	if (relay_gpio_on != NULL) relay_gpio_on(id);
	relay_set_status(id);
}

void relay_turn_off(uint8_t id)
{
	if (relay_gpio_off != NULL) relay_gpio_off(id);
	relay_clear_status(id);
}

void relay_turn_on_all(void)
{
	for (int id = RELAY1; id <= RELAY4; id++)
	{
		relay_turn_on(id);
	}
}

void relay_turn_off_all(void)
{
	for (int id = RELAY1; id <= RELAY4; id++)
	{
		relay_turn_off(id);
	}
}
