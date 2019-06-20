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
 * @brief Deployment system's pin definition
 * @author: Matías Vidal
 */
 
#define  EN_DPL1 8 	// Deploy ballon from port number 1
#define  EN_DPL2 4 	// Deploy ballon from port number 2
#define  EN_DPL3 1 	// Deploy ballon from port number 3
#define  EN_DPL4 2 	// Deploy ballon from port number 4
#define  EN_DPL5 11 	// Deploy ballon from port number 5
#define  EN_DPL6 10     // Deploy ballon from port number 6
#define  DPL_STATUS1 9  // Deployment status of port number 1
#define  DPL_STATUS2 3  // Deployment status of port number 2
#define  DPL_STATUS3 0  // Deployment status of port number 3
#define  DPL_STATUS4 5  // Deployment status of port number 4
#define  DPL_STATUS5 13 // Deployment status of port number 5
#define  DPL_STATUS6 12 // Deployment status of port number 6
