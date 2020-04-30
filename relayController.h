/*
 * relayScheduler.h
 *
 *  Created on: Apr 26, 2020
 *      Author: serbay.ozkan
 */

#ifndef RELAYCONTROLLER_H_
#define RELAYCONTROLLER_H_

#include <stdbool.h>
#include <stdint.h>

#define MAX_RELAY_NUMBER    ( 4 )

enum
{
	RELAY1 = 0, RELAY2, RELAY3, RELAY4
};

bool relay_get_status(uint8_t id);
void relay_set_status(uint8_t id);
void relay_clear_status(uint8_t id);

void relay_turn_on_all(void);
void relay_turn_off_all(void);
void relay_turn_on(uint8_t id);
void relay_turn_off(uint8_t id);

typedef void (*vptr_to_func)(uint8_t);

extern vptr_to_func relay_gpio_on;
extern vptr_to_func relay_gpio_off;

#endif /* RELAYCONTROLLER_H_ */
