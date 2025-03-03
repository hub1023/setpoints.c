/*
 * setpoints.c
 *
 *  Created on: Mar 2, 2025
 *      Author: PlasmaPC
 */

#include "setpoints.h"

SetpointConfig setpoints = {
    .values = {40, 35, 80, 50, 20, 10, 25, 10, 60, 35, 38, 40, 35},
    .labels = {
        "CH_Temp_HI", "CH_Temp_LO", "CH_%RH_HI", "CH_%RH_LO",
        "EGG_TURN_INTVL", "EGG_TURN_TIME", "VENT_INTERVAL", "VENT_TIME",
        "CH_%RH SP", "CH_TEMP_SP", "HTR_TEMP-SP", "HTR_TEMP_HI", "HTR_TEMP_LO"
    }
};


void display_spSettings(void) {
	for (int i = 0; i < NUM_SETPOINTS; i++) {
		snprintf(buffer, sizeof(buffer), "%d - %s: %.1f \r\n", i + 1,
				setpoints.labels[i], setpoints.values[i]);
		Serial2_Write(buffer);

	}
	Serial2_Write("\r\n");
}

// Display the currently selected setpoint
void display_selectedSP(void) {
	if (setstate < NUM_SETPOINTS) {
		snprintf(buffer, sizeof(buffer), "%d - %s: %.2f \r\n", setstate + 1,
				setpoints.labels[setstate], setpoints.values[setstate]);
	} else {
		snprintf(buffer, sizeof(buffer), "- End of Setpoints\r\n");
	}
}



