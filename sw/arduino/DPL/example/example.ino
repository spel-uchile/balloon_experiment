/**
 *                                  DPL
 *   Balloon deployment system. It can deploy the balloons of a radiosonde.
 *   It works by cutting the balloon's wire with nichrome. The PCB follows
 *   the PC104 standard.
 *   
 *   Copyright (C) 2019-2019, Matías Vidal Valladares, matvidal.
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
 * @brief Simple Deployment example
 * @author: Matías Vidal
 */

#include "dpl.h"
#include "pines.h"

DPL dpl;

// ================================================================
// ===                      INITIAL SETUP                       ===
// ================================================================


void setup() {
        SerialUSB.begin(115200);
        dpl.init();
        functions();
}

// ================================================================
// ===                    MAIN PROGRAM LOOP                     ===
// ================================================================

void loop() {
    if (Serial.available() > 0) {
        // Read the incoming byte:
        char input = SerialUSB.read();
        // say what you got:
        SerialUSB.print("Received command number: ");
        SerialUSB.println(input);
        if (input == '0') {
            functions();
        }
        else if (input == '1' || input == '2' || input == '3' ||
		 input == '4' || input == '5' || input == '6') {
            dpl.deploy(input);
	    SerialUSB.print("Deployment status: ");
	    SerialUSB.println(dpl.status(input));
        }
	else if (input == '7') {
	    SerialUSB.print("Report: ");
	    SerialUSB.println(dpl.report(), BIN);
	}
	else {
	    SerialUSB.print(input);
	    SerialUSB.println(" is not a valid command");
	}
    }
}

void functions() {
    SerialUSB.println(F("Deployment system's functions definition:"));
    SerialUSB.println(F("0) List of commands"));
    SerialUSB.println(F("1) Deploy the balloon from port number 1"));
    SerialUSB.println(F("2) Deploy the balloon from port number 2"));
    SerialUSB.println(F("3) Deploy the balloon from port number 3"));
    SerialUSB.println(F("4) Deploy the balloon from port number 4"));
    SerialUSB.println(F("5) Deploy the balloon from port number 5"));
    SerialUSB.println(F("6) Deploy the balloon from port number 6"));
    SerialUSB.println(F("7) Report the status of the deployment system"));
}

