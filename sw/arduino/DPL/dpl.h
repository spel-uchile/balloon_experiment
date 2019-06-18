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
 * @class DPL
 * @brief Class that manages ballon's deployment
 * @author: Matías Vidal
 */

/*Requiered Libraries*/
#include <Arduino.h>
#include <Wire.h>
#include "pines.h"

class DPL {
    /*Private Members*/

    // DLP Objects

    // Internal Variables
public:
    /*Public Members*/
    char func;
    bool deployed;
    uint8_t port;
    uint8_t rep;
    unsigned long t0, dt;
    const int OBC = 0;
    const uint8_t enable_pins[6] = {8, 4, 1, 2, 11, 10};
    const uint8_t status_pins[6] = {9, 3, 0, 5, 13, 12};

    /*Base contructor (null)*/
    DPL() {}

    // methods
    void init(void);
    void deploy(uint8_t port);
    void cmdHandler(int numBytes);
    bool status(uint8_t port);
    uint8_t report(void);

// private:
    // methods
};
