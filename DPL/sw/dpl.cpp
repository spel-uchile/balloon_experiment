/**
 *                                  DPL
 *   Balloon deployment system. It can deploy the balloons of a radiosonde.
 *   It works by cutting the balloon's wire with nichrome. The PCB follows
 *   the PC104 standard.
 *   
 *   Copyright (C) 2019-2020, Matías Vidal Valladares, matvidal.
 *   Authors: Matías Vidal Valladares <matias.vidal.v@gmail.com>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

/**
 * @brief Simple balloon deployment Library
 * @author Matías Vidal
 */

#include "dpl.h"

bool deployed;
uint8_t rep;
unsigned long t0, dt;
const uint8_t enable_pins[6] = {EN_DPL1, EN_DPL2, EN_DPL3,
    				EN_DPL4, EN_DPL5, EN_DPL6};
const uint8_t status_pins[6] = {DPL_STATUS1, DPL_STATUS2, DPL_STATUS3,
                                DPL_STATUS4, DPL_STATUS5, DPL_STATUS6};

//-------------------------- Public Methods --------------------------
/**
 * Initialize all the pins of the deployment
 * system.
 */
void DPL::init(void) {
    for (int i=0; i<6; i++) {
        pinMode(enable_pins[i], OUTPUT);
	digitalWrite(enable_pins[i], LOW);
        pinMode(status_pins[i], INPUT);
    }
}

/**
 * Deploy a balloon attached to one port of the
 * deployment system.
 * @param port: The port at which the balloon
 * 		to be deployed is attached.
 */
void DPL::deploy(uint8_t port) {
    t0 = millis();
    dt = 0;
    digitalWrite(enable_pins[port], HIGH);
    deployed = status(port);
    while (!deployed && dt < 3000) {
	delay(100);
	deployed = status(port);
	dt = millis() - t0;
    }	    
    digitalWrite(enable_pins[port], LOW);
}

/**
 * Returns the status of the deployment of a
 * balloon from port.
 * @param port: The pin associated to the
 * 		deployment port that will read
 * 		the deployment status.
 * @return True if the balloon was successfully
 * 	   deployed.
 */
bool DPL::status(uint8_t port) {
    return !digitalRead(status_pins[port]);
}

/**
 * Returns the status of all six deployment ports.
 * @return A byte with the status on its six most
 * significant bits.
 */
uint8_t DPL::report(void) {
    rep = 0;
    if (status(0))
	rep = rep | 128;
    if (status(1))
	rep = rep | 64;
    if (status(2))
	rep = rep | 32;
    if (status(3))
	rep = rep | 16;
    if (status(4))
	rep = rep | 8;
    if (status(5))
	rep = rep | 4;
    return rep;
}
