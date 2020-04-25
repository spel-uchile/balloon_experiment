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
 * @class DPL
 * @brief Class that manages ballon's deployment
 * @author: Matías Vidal
 */

/*Requiered Libraries*/
#include <Arduino.h>
#include "pines.h"

class DPL {
    /*Private Members*/

    // DLP Objects

    // Internal Variables
public:
    /*Public Members*/
    bool deployed;
    uint8_t rep;
    unsigned long t0, dt;
    const uint8_t enable_pins[6] = {EN_DPL1, EN_DPL2, EN_DPL3,
                                    EN_DPL4, EN_DPL5, EN_DPL6};
    const uint8_t status_pins[6] = {DPL_STATUS1, DPL_STATUS2, DPL_STATUS3,
                                    DPL_STATUS4, DPL_STATUS5, DPL_STATUS6};

    /*Base contructor (null)*/
    DPL() {}

    // methods
    void init(void);
    void deploy(uint8_t port);
    bool status(uint8_t port);
    uint8_t report(void);

// private:
    // methods
};
