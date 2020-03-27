EESchema Schematic File Version 4
LIBS:ATmega_SAT-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Microchip_SAMD:ATSAMD21G18A-AUT U2
U 1 1 5E330085
P 3050 4150
F 0 "U2" H 3050 1950 50  0000 C CNN
F 1 "ATSAMD21G18A-AUT" H 3050 1850 50  0000 C CNN
F 2 "Housings_QFP:TQFP-48_7x7mm_Pitch0.5mm" H 2100 2400 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/SAMD21-Family-DataSheet-DS40001882D.pdf" H 3050 5150 50  0001 C CNN
	1    3050 4150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5E332CD5
P 4150 6200
F 0 "#PWR0101" H 4150 5950 50  0001 C CNN
F 1 "GND" H 4155 6027 50  0000 C CNN
F 2 "" H 4150 6200 50  0001 C CNN
F 3 "" H 4150 6200 50  0001 C CNN
	1    4150 6200
	1    0    0    -1  
$EndComp
Text GLabel 4150 6200 1    50   Input ~ 0
GND
Text GLabel 2950 6050 3    50   Input ~ 0
GND
Text GLabel 3150 6050 3    50   Input ~ 0
GND
Text GLabel 2050 5650 0    50   Input ~ 0
RESET
$Comp
L Switch:SW_Push SW1
U 1 1 5E3357ED
P 1250 5650
F 0 "SW1" H 1250 5935 50  0000 C CNN
F 1 "SW_Push" H 1250 5844 50  0000 C CNN
F 2 "Buttons_Switches_SMD:SW_SPST_B3SL-1022P" H 1250 5850 50  0001 C CNN
F 3 "~" H 1250 5850 50  0001 C CNN
	1    1250 5650
	1    0    0    -1  
$EndComp
Text GLabel 1050 5650 0    50   Input ~ 0
RESET
Text GLabel 1450 5650 2    50   Input ~ 0
GND
$Comp
L Device:R R1
U 1 1 5E3373E3
P 2050 5900
F 0 "R1" H 2120 5946 50  0000 L CNN
F 1 "10k" H 2120 5855 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 1980 5900 50  0001 C CNN
F 3 "~" H 2050 5900 50  0001 C CNN
	1    2050 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 5650 2050 5750
Text GLabel 2050 6050 3    50   Input ~ 0
3V3
$Comp
L Device:C C4
U 1 1 5E33991C
P 2700 1750
F 0 "C4" H 2815 1796 50  0000 L CNN
F 1 "0.1uF" H 2815 1705 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 2738 1600 50  0001 C CNN
F 3 "~" H 2700 1750 50  0001 C CNN
	1    2700 1750
	1    0    0    -1  
$EndComp
Text GLabel 2700 1600 1    50   Input ~ 0
GND
Text GLabel 2700 1900 2    50   Input ~ 0
3V3
Wire Wire Line
	2700 1900 2700 2150
$Comp
L Device:C C3
U 1 1 5E340FA2
P 2300 1750
F 0 "C3" H 2415 1796 50  0000 L CNN
F 1 "0.1uF" H 2415 1705 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 2338 1600 50  0001 C CNN
F 3 "~" H 2300 1750 50  0001 C CNN
	1    2300 1750
	1    0    0    -1  
$EndComp
Text GLabel 2300 1600 1    50   Input ~ 0
GND
Text GLabel 2300 1900 2    50   Input ~ 0
3V3
$Comp
L Device:L L1
U 1 1 5E3458BF
P 3400 1900
F 0 "L1" H 3453 1946 50  0000 L CNN
F 1 "FB - 30 Ohm" H 3453 1855 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" H 3400 1900 50  0001 C CNN
F 3 "~" H 3400 1900 50  0001 C CNN
	1    3400 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 2150 2950 2150
Wire Wire Line
	2950 2150 2950 2250
Wire Wire Line
	2300 1900 2300 2250
Wire Wire Line
	2300 2250 2850 2250
Text GLabel 3400 2050 2    50   Input ~ 0
3V3
$Comp
L Device:C C5
U 1 1 5E34BF77
P 3400 1600
F 0 "C5" H 3515 1646 50  0000 L CNN
F 1 "0.1uF" H 3515 1555 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 3438 1450 50  0001 C CNN
F 3 "~" H 3400 1600 50  0001 C CNN
	1    3400 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 1750 3150 1750
Wire Wire Line
	3150 1750 3150 2250
Text GLabel 3400 1450 1    50   Input ~ 0
GND
Connection ~ 3400 1750
$Comp
L Device:C C6
U 1 1 5E358AF9
P 4050 1600
F 0 "C6" H 4165 1646 50  0000 L CNN
F 1 "0.1uF" H 4165 1555 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 4088 1450 50  0001 C CNN
F 3 "~" H 4050 1600 50  0001 C CNN
	1    4050 1600
	1    0    0    -1  
$EndComp
Text GLabel 4050 1450 1    50   Input ~ 0
GND
Wire Wire Line
	3250 2250 3250 2150
Wire Wire Line
	3250 2150 4050 2150
Wire Wire Line
	4050 2150 4050 1750
$Comp
L Device:Crystal_Small Y1
U 1 1 5E35B455
P 1850 2600
F 0 "Y1" V 1850 2700 50  0000 L CNN
F 1 "32.768 kHz" V 1700 2500 50  0000 L CNN
F 2 "Crystals:Crystal_SMD_3215-2pin_3.2x1.5mm" H 1850 2600 50  0001 C CNN
F 3 "~" H 1850 2600 50  0001 C CNN
	1    1850 2600
	0    1    1    0   
$EndComp
Wire Wire Line
	1750 2500 1850 2500
Wire Wire Line
	2050 2500 2050 2550
Wire Wire Line
	1750 2700 1850 2700
Wire Wire Line
	2050 2700 2050 2650
Connection ~ 1850 2500
Wire Wire Line
	1850 2500 2050 2500
Connection ~ 1850 2700
Wire Wire Line
	1850 2700 2050 2700
$Comp
L Device:C_Small C2
U 1 1 5E360B1C
P 1650 2700
F 0 "C2" V 1500 2700 50  0000 C CNN
F 1 "15pF" V 1400 2700 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 1650 2700 50  0001 C CNN
F 3 "~" H 1650 2700 50  0001 C CNN
	1    1650 2700
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C1
U 1 1 5E3612E6
P 1650 2500
F 0 "C1" V 1879 2500 50  0000 C CNN
F 1 "15pF" V 1788 2500 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 1650 2500 50  0001 C CNN
F 3 "~" H 1650 2500 50  0001 C CNN
	1    1650 2500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1550 2500 1550 2600
Wire Wire Line
	1550 2600 1500 2600
Connection ~ 1550 2600
Wire Wire Line
	1550 2600 1550 2700
Text GLabel 1500 2600 0    50   Input ~ 0
GND
$Comp
L Connector:Conn_01x02_Male J13
U 1 1 5E368AFB
P 8900 1100
F 0 "J13" H 9008 1281 50  0000 C CNN
F 1 "Jumper LEDs 3V3" H 9008 1190 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 8900 1100 50  0001 C CNN
F 3 "~" H 8900 1100 50  0001 C CNN
	1    8900 1100
	1    0    0    -1  
$EndComp
Text GLabel 9100 1100 2    50   Input ~ 0
3V3
$Comp
L power:+3.3V #PWR0102
U 1 1 5E36D014
P 4150 5700
F 0 "#PWR0102" H 4150 5550 50  0001 C CNN
F 1 "+3.3V" H 4165 5873 50  0000 C CNN
F 2 "" H 4150 5700 50  0001 C CNN
F 3 "" H 4150 5700 50  0001 C CNN
	1    4150 5700
	1    0    0    -1  
$EndComp
Text GLabel 4150 5700 3    50   Input ~ 0
3V3
Text GLabel 8900 2700 1    50   Input ~ 0
3V3L
$Comp
L Device:LED D2
U 1 1 5E3325D6
P 8900 3150
F 0 "D2" V 8939 3032 50  0000 R CNN
F 1 "RED" V 8848 3032 50  0000 R CNN
F 2 "LEDs:LED_0603_HandSoldering" H 8900 3150 50  0001 C CNN
F 3 "~" H 8900 3150 50  0001 C CNN
	1    8900 3150
	0    -1   -1   0   
$EndComp
Text GLabel 8900 3300 3    50   Input ~ 0
GND
$Comp
L Device:R R5
U 1 1 5E331674
P 8900 2850
F 0 "R5" H 8970 2896 50  0000 L CNN
F 1 "330" H 8970 2805 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 8830 2850 50  0001 C CNN
F 3 "~" H 8900 2850 50  0001 C CNN
	1    8900 2850
	1    0    0    -1  
$EndComp
Text GLabel 9250 2700 1    50   Input ~ 0
3V3L
$Comp
L Device:R R6
U 1 1 5E3399A7
P 9250 2850
F 0 "R6" H 9320 2896 50  0000 L CNN
F 1 "330" H 9320 2805 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 9180 2850 50  0001 C CNN
F 3 "~" H 9250 2850 50  0001 C CNN
	1    9250 2850
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D3
U 1 1 5E339C5F
P 9250 3150
F 0 "D3" V 9289 3032 50  0000 R CNN
F 1 "GREEN" V 9198 3032 50  0000 R CNN
F 2 "LEDs:LED_0603_HandSoldering" H 9250 3150 50  0001 C CNN
F 3 "~" H 9250 3150 50  0001 C CNN
	1    9250 3150
	0    -1   -1   0   
$EndComp
Text GLabel 9250 3300 3    50   Input ~ 0
TX_LED
Text GLabel 9750 2700 1    50   Input ~ 0
3V3L
$Comp
L Device:R R8
U 1 1 5E33A29C
P 9750 2850
F 0 "R8" H 9820 2896 50  0000 L CNN
F 1 "330" H 9820 2805 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 9680 2850 50  0001 C CNN
F 3 "~" H 9750 2850 50  0001 C CNN
	1    9750 2850
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D4
U 1 1 5E33A529
P 9750 3150
F 0 "D4" V 9789 3032 50  0000 R CNN
F 1 "YELLOW" V 9698 3032 50  0000 R CNN
F 2 "LEDs:LED_0603_HandSoldering" H 9750 3150 50  0001 C CNN
F 3 "~" H 9750 3150 50  0001 C CNN
	1    9750 3150
	0    -1   -1   0   
$EndComp
Text GLabel 9750 3300 3    50   Input ~ 0
RX_LED
$Comp
L Transistor_FET:2N7002 Q1
U 1 1 5E33BBB1
P 8300 3500
F 0 "Q1" H 8506 3546 50  0000 L CNN
F 1 "2N7002" H 8506 3455 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 8500 3425 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7002.pdf" H 8300 3500 50  0001 L CNN
	1    8300 3500
	1    0    0    -1  
$EndComp
Text GLabel 8100 3500 0    50   Input ~ 0
D13-SCK
$Comp
L Device:LED D1
U 1 1 5E33DCEE
P 8400 3150
F 0 "D1" V 8439 3033 50  0000 R CNN
F 1 "BLUE" V 8348 3033 50  0000 R CNN
F 2 "LEDs:LED_0603_HandSoldering" H 8400 3150 50  0001 C CNN
F 3 "~" H 8400 3150 50  0001 C CNN
	1    8400 3150
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R4
U 1 1 5E33E827
P 8400 2850
F 0 "R4" H 8470 2896 50  0000 L CNN
F 1 "330" H 8470 2805 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 8330 2850 50  0001 C CNN
F 3 "~" H 8400 2850 50  0001 C CNN
	1    8400 2850
	1    0    0    -1  
$EndComp
Text GLabel 8400 2700 1    50   Input ~ 0
3V3L
Text GLabel 2050 2750 0    50   Input ~ 0
A0
Text GLabel 2050 2850 0    50   Input ~ 0
AREF
Text GLabel 2050 2950 0    50   Input ~ 0
A3
Text GLabel 2050 3050 0    50   Input ~ 0
A4
Text GLabel 2050 3150 0    50   Input ~ 0
D8
Text GLabel 2050 3250 0    50   Input ~ 0
D9
Text GLabel 4050 2550 2    50   Input ~ 0
A5
Text GLabel 4050 2650 2    50   Input ~ 0
RX_LED
Text GLabel 4050 2750 2    50   Input ~ 0
A1
Text GLabel 4050 2850 2    50   Input ~ 0
A2
Text GLabel 4050 3150 2    50   Input ~ 0
TXD
Text GLabel 4050 3250 2    50   Input ~ 0
RXD
Text GLabel 2050 3350 0    50   Input ~ 0
D4-SDA
Text GLabel 2050 3450 0    50   Input ~ 0
D3-SCL
Text GLabel 2050 3550 0    50   Input ~ 0
D1-TX0
Text GLabel 2050 3650 0    50   Input ~ 0
D0-RX1
Text GLabel 2050 3850 0    50   Input ~ 0
DGPIO0
Text GLabel 2050 3950 0    50   Input ~ 0
D2
Text GLabel 2050 4050 0    50   Input ~ 0
D5
Text GLabel 2050 4150 0    50   Input ~ 0
DI
Text GLabel 2050 4250 0    50   Input ~ 0
SCK
Text GLabel 2050 4350 0    50   Input ~ 0
CS
Text GLabel 2050 4450 0    50   Input ~ 0
DO
Text GLabel 2050 4550 0    50   Input ~ 0
D6
Text GLabel 2050 4650 0    50   Input ~ 0
D7
Text GLabel 2050 4750 0    50   Input ~ 0
SDA
Text GLabel 2050 4850 0    50   Input ~ 0
SCL
Text GLabel 2050 4950 0    50   Input ~ 0
USB_D-
Text GLabel 2050 5050 0    50   Input ~ 0
USB_D+
Text GLabel 2050 5150 0    50   Input ~ 0
TX_LED
Text GLabel 2050 5250 0    50   Input ~ 0
USB_HOST_EN
Text GLabel 2050 5350 0    50   Input ~ 0
SWCLK
Text GLabel 2050 5450 0    50   Input ~ 0
SWDIO
Text GLabel 9100 1200 2    50   Input ~ 0
3V3L
$Comp
L Connector:Conn_01x02_Male J15
U 1 1 5E42295B
P 9650 1100
F 0 "J15" H 9758 1281 50  0000 C CNN
F 1 "Jumper USB 3V3" H 9758 1190 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 9650 1100 50  0001 C CNN
F 3 "~" H 9650 1100 50  0001 C CNN
	1    9650 1100
	1    0    0    -1  
$EndComp
Text GLabel 9850 1200 2    50   Input ~ 0
3V3
Text GLabel 9850 1100 2    50   Input ~ 0
3V3USB
$Comp
L Connector:Conn_01x02_Male J16
U 1 1 5E4234D3
P 9650 1550
F 0 "J16" H 9758 1731 50  0000 C CNN
F 1 "Vin 3v3" H 9758 1640 50  0000 C CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53261-0271_02x1.25mm_Angled" H 9650 1550 50  0001 C CNN
F 3 "~" H 9650 1550 50  0001 C CNN
	1    9650 1550
	1    0    0    -1  
$EndComp
Text GLabel 9850 1550 2    50   Input ~ 0
3V3
Text GLabel 9850 1650 2    50   Input ~ 0
GND
$Comp
L Connector:Conn_01x02_Male J14
U 1 1 5E4273F1
P 8900 1550
F 0 "J14" H 9008 1731 50  0000 C CNN
F 1 "Vin" H 9008 1640 50  0000 C CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53261-0271_02x1.25mm_Angled" H 8900 1550 50  0001 C CNN
F 3 "~" H 8900 1550 50  0001 C CNN
	1    8900 1550
	1    0    0    -1  
$EndComp
Text GLabel 9100 1550 2    50   Input ~ 0
VIN
Text GLabel 9100 1650 2    50   Input ~ 0
GND
$Comp
L Connector:Conn_01x02_Male J9
U 1 1 5E42900B
P 7950 1100
F 0 "J9" H 8058 1281 50  0000 C CNN
F 1 "Jumper OBC 3V3" H 8058 1190 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 7950 1100 50  0001 C CNN
F 3 "~" H 7950 1100 50  0001 C CNN
	1    7950 1100
	1    0    0    -1  
$EndComp
Text GLabel 8150 1200 2    50   Input ~ 0
3V3
Text GLabel 8150 1100 2    50   Input ~ 0
3V3OBC
$Comp
L Connector:Conn_01x02_Male J10
U 1 1 5E434FEA
P 7950 1550
F 0 "J10" H 8058 1731 50  0000 C CNN
F 1 "Jumper OBC Vin" H 8058 1640 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 7950 1550 50  0001 C CNN
F 3 "~" H 7950 1550 50  0001 C CNN
	1    7950 1550
	1    0    0    -1  
$EndComp
Text GLabel 9100 1550 2    50   Input ~ 0
VIN
Text GLabel 8150 1650 2    50   Input ~ 0
VIN
Text GLabel 8150 1550 2    50   Input ~ 0
VINOBC
Text GLabel 10800 4850 1    50   Input ~ 0
3V3USB
Text GLabel 10800 5250 3    50   Input ~ 0
GND
$Comp
L Device:C C8
U 1 1 5E394685
P 10800 5100
F 0 "C8" H 10915 5146 50  0000 L CNN
F 1 "2.2uF" H 10915 5055 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 10838 4950 50  0001 C CNN
F 3 "~" H 10800 5100 50  0001 C CNN
	1    10800 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	10800 4850 10800 4950
Wire Wire Line
	10650 4850 10800 4850
Text GLabel 10050 5350 3    50   Input ~ 0
GND
Wire Wire Line
	10050 5250 9750 5250
Connection ~ 10050 5250
Wire Wire Line
	10050 5250 10050 5350
Wire Wire Line
	10350 5250 10050 5250
Connection ~ 9750 4850
Connection ~ 10050 4850
Wire Wire Line
	10050 4850 9750 4850
Wire Wire Line
	10050 4950 10050 4850
$Comp
L Regulator_Linear:AP2112K-3.3 U4
U 1 1 5E3909EC
P 10350 4950
F 0 "U4" H 10350 5292 50  0000 C CNN
F 1 "AP2112K-3.3" H 10350 5201 50  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23-5_HandSoldering" H 10350 5275 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/AP2112.pdf" H 10350 5050 50  0001 C CNN
	1    10350 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	9750 4850 9350 4850
Wire Wire Line
	9750 4950 9750 4850
$Comp
L Device:C C7
U 1 1 5E38FA07
P 9750 5100
F 0 "C7" H 9865 5146 50  0000 L CNN
F 1 "1.0uF" H 9865 5055 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 9788 4950 50  0001 C CNN
F 3 "~" H 9750 5100 50  0001 C CNN
	1    9750 5100
	1    0    0    -1  
$EndComp
Text GLabel 7750 5900 0    50   Input ~ 0
USB_HOST_EN
Text GLabel 8250 5550 1    50   Input ~ 0
VIN
Wire Wire Line
	8250 5900 8050 5900
Connection ~ 8250 5900
Wire Wire Line
	8250 5900 8250 5850
Connection ~ 8450 5900
Wire Wire Line
	8450 5900 8250 5900
$Comp
L Device:R R2
U 1 1 5E38A957
P 7900 5900
F 0 "R2" V 7693 5900 50  0000 C CNN
F 1 "330" V 7784 5900 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7830 5900 50  0001 C CNN
F 3 "~" H 7900 5900 50  0001 C CNN
	1    7900 5900
	0    1    1    0   
$EndComp
$Comp
L Device:R R3
U 1 1 5E389C7B
P 8250 5700
F 0 "R3" H 8320 5746 50  0000 L CNN
F 1 "100k" H 8320 5655 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 8180 5700 50  0001 C CNN
F 3 "~" H 8250 5700 50  0001 C CNN
	1    8250 5700
	1    0    0    -1  
$EndComp
Text GLabel 8800 5950 3    50   Input ~ 0
GND
Text GLabel 8800 5850 1    50   Input ~ 0
VIN
Wire Wire Line
	8750 5650 8750 5700
Connection ~ 8750 5650
Wire Wire Line
	8450 5650 8750 5650
Wire Wire Line
	8450 5900 8450 5650
Wire Wire Line
	8050 5250 8750 5250
Wire Wire Line
	8750 5250 8750 5650
Connection ~ 9000 5350
Wire Wire Line
	9000 5350 9000 5900
$Comp
L 74xGxx:74AHC1G125 U3
U 1 1 5E37FDC0
P 8750 5900
F 0 "U3" H 8750 5600 50  0000 C CNN
F 1 "74AHC1G125" H 8750 5500 50  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23-5_HandSoldering" H 8750 5900 50  0001 C CNN
F 3 "http://www.ti.com/lit/sg/scyt129e/scyt129e.pdf" H 8750 5900 50  0001 C CNN
	1    8750 5900
	1    0    0    -1  
$EndComp
Text GLabel 9350 4700 1    50   Input ~ 0
VIN
Connection ~ 9350 4850
Wire Wire Line
	9350 4850 9350 4700
Wire Wire Line
	9350 5350 9350 5250
Wire Wire Line
	9000 5350 9350 5350
Wire Wire Line
	9000 5150 9000 5350
Wire Wire Line
	9350 4850 9350 4950
Wire Wire Line
	9200 4850 9350 4850
$Comp
L Device:R R7
U 1 1 5E37DA57
P 9350 5100
F 0 "R7" H 9420 5146 50  0000 L CNN
F 1 "47k" H 9420 5055 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 9280 5100 50  0001 C CNN
F 3 "~" H 9350 5100 50  0001 C CNN
	1    9350 5100
	1    0    0    -1  
$EndComp
Text GLabel 7700 5500 3    50   Input ~ 0
GND
Wire Wire Line
	7700 5450 7750 5450
Connection ~ 7700 5450
Wire Wire Line
	7700 5450 7700 5500
Wire Wire Line
	7650 5450 7700 5450
Text GLabel 8050 5150 2    50   Input ~ 0
USB_D-
Text GLabel 8050 5050 2    50   Input ~ 0
USB_D+
Wire Wire Line
	8550 4850 8800 4850
Wire Wire Line
	8050 4850 8350 4850
$Comp
L Device:Polyfuse_Small F1
U 1 1 5E377C40
P 8450 4850
F 0 "F1" V 8245 4850 50  0000 C CNN
F 1 "Polyfuse_Small" V 8336 4850 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" H 8500 4650 50  0001 L CNN
F 3 "~" H 8450 4850 50  0001 C CNN
	1    8450 4850
	0    1    1    0   
$EndComp
$Comp
L Connector:USB_B_Micro J8
U 1 1 5E37427A
P 7750 5050
F 0 "J8" H 7807 5517 50  0000 C CNN
F 1 "USB_B_Micro" H 7807 5426 50  0000 C CNN
F 2 "Connectors_USB:USB_Micro-B_Molex_47346-0001" H 7900 5000 50  0001 C CNN
F 3 "~" H 7900 5000 50  0001 C CNN
	1    7750 5050
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_PMOS_DSG e1
U 1 1 5E36A51E
P 9000 4950
F 0 "e1" V 9343 4950 50  0000 C CNN
F 1 "2.5A / 30V" V 9252 4950 50  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 9200 5050 50  0001 C CNN
F 3 "~" H 9000 4950 50  0001 C CNN
	1    9000 4950
	0    -1   -1   0   
$EndComp
Text GLabel 8400 3700 3    50   Input ~ 0
GND
Wire Notes Line
	7000 6550 7000 450 
Wire Notes Line
	7000 2200 11250 2200
Wire Notes Line
	7000 4150 11250 4150
Text Label 8850 700  0    50   ~ 0
JUMPERS
Text Label 8900 2350 0    50   ~ 0
LEDs
Text Label 8900 4300 0    50   ~ 0
USB
$Comp
L Connector:Conn_01x02_Male J11
U 1 1 5E36553A
P 7950 1950
F 0 "J11" H 8058 2131 50  0000 C CNN
F 1 "Jumper EPS VBAT" H 8058 2040 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 7950 1950 50  0001 C CNN
F 3 "~" H 7950 1950 50  0001 C CNN
	1    7950 1950
	1    0    0    -1  
$EndComp
Text GLabel 8150 1950 2    50   Input ~ 0
VEPS
Text GLabel 8150 2050 2    50   Input ~ 0
VBAT
$Comp
L Connector:Conn_01x02_Male J12
U 1 1 5E366105
P 8800 1950
F 0 "J12" H 8908 2131 50  0000 C CNN
F 1 "Jumper VSTK VBAT" H 8908 2040 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 8800 1950 50  0001 C CNN
F 3 "~" H 8800 1950 50  0001 C CNN
	1    8800 1950
	1    0    0    -1  
$EndComp
Text GLabel 9000 1950 2    50   Input ~ 0
VSTK
Text GLabel 9000 2050 2    50   Input ~ 0
VBAT
Text GLabel 4050 3050 2    50   Input ~ 0
SPI_SCK
Text GLabel 4050 2950 2    50   Input ~ 0
SPI_MOSI
Text GLabel 2050 3750 0    50   Input ~ 0
SPI-MISO
Wire Notes Line
	4900 3750 7000 3750
Wire Notes Line
	4900 450  4900 3750
$Comp
L Connector:Conn_01x02_Male J1
U 1 1 5E7E36D7
P 9650 1950
F 0 "J1" H 9758 2131 50  0000 C CNN
F 1 "BAT_JUMPER" H 9758 2040 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 9650 1950 50  0001 C CNN
F 3 "~" H 9650 1950 50  0001 C CNN
	1    9650 1950
	1    0    0    -1  
$EndComp
Text GLabel 9850 1950 2    50   Input ~ 0
VBAT
Text GLabel 9850 2050 2    50   Input ~ 0
VBAT2
$EndSCHEMATC
