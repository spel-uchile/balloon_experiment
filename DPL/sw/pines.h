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
 * @brief Deployment system's pin definition
 * @author: Matías Vidal
 */
 
#define  EN_DPL1 3 	// Deploy ballon from port number 1
#define  EN_DPL2 0 	// Deploy ballon from port number 2
#define  EN_DPL3 5 	// Deploy ballon from port number 3
#define  EN_DPL4 13 	// Deploy ballon from port number 4
#define  EN_DPL5 12 	// Deploy ballon from port number 5
#define  DPL_STATUS1 4  // Deployment status of port number 1
#define  DPL_STATUS2 1  // Deployment status of port number 2
#define  DPL_STATUS3 2  // Deployment status of port number 3
#define  DPL_STATUS4 11 // Deployment status of port number 4
#define  DPL_STATUS5 10 // Deployment status of port number 5
