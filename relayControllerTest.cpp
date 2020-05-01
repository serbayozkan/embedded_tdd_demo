/*
 * relayControllerTest.cpp
 *
 *  Created on: Apr 25, 2020
 *      Author: serbay.ozkan
 */

#include "CppUTest/TestHarness.h"
#include <stdbool.h>
#include <stdint.h>

extern "C"
{
#include "relayController.h"
}

TEST_GROUP(relay_controller)
{
	void setup()
	{
		relay_turn_off_all();
	}

	void teardown()
	{

	}
};

TEST(relay_controller, getRelayStatus)
{
	CHECK_FALSE(relay_get_status(RELAY1));
}

TEST(relay_controller, setRelayStatus)
{
	relay_set_status(RELAY1);

	CHECK_TRUE(relay_get_status(RELAY1));
}

TEST(relay_controller, clearRelayStatus)
{
	relay_set_status(RELAY1);
	relay_clear_status(RELAY1);

	CHECK_FALSE(relay_get_status(RELAY1));
}

TEST(relay_controller, relayStatusBoundaryConditions)
{
	CHECK_FALSE(relay_get_status(-1));
	CHECK_FALSE(relay_get_status(8));
}

TEST(relay_controller, turnOnSpecificRelay)
{
	relay_turn_on(RELAY1);

	CHECK_TRUE(relay_get_status(RELAY1));
}

TEST(relay_controller, turnOffSpecificRelay)
{
	relay_turn_on(RELAY1);
	relay_turn_off(RELAY1);

	CHECK_FALSE(relay_get_status(RELAY1));
}

TEST(relay_controller, turnOnAllRelays)
{
	relay_turn_on_all();

	for (int id = RELAY1; id <= RELAY4; id++)
	{
		CHECK_TRUE(relay_get_status(id));
	}
}

TEST(relay_controller, turnOffAllRelays)
{
	relay_turn_on_all();
	relay_turn_off_all();

	for (int id = RELAY1; id <= RELAY4; id++)
	{
		CHECK_FALSE(relay_get_status(id));
	}
}
