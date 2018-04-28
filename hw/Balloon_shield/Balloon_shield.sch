EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:Radiosonda-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L ARDUINO_DUE_SHIELD SHIELD1
U 1 1 5AE0AB8B
P 3800 4300
F 0 "SHIELD1" H 3400 6950 60  0000 C CNN
F 1 "ARDUINO_DUE_SHIELD" H 3800 4300 60  0000 C CNN
F 2 "FT:ARDUINO_DUE_SHIELD" H 3800 4100 50  0001 C CNN
F 3 "" H 3800 4300 60  0000 C CNN
	1    3800 4300
	1    0    0    -1  
$EndComp
$Comp
L RFM22B TRX1
U 1 1 5AE0B8A9
P 7350 2850
F 0 "TRX1" H 7350 3350 60  0000 C CNN
F 1 "RFM22B" H 7350 2350 60  0000 C CNN
F 2 "Transceptores:RFM22B" H 7350 3350 60  0001 C CNN
F 3 "" H 7350 3350 60  0001 C CNN
	1    7350 2850
	1    0    0    -1  
$EndComp
$Comp
L SMA J1
U 1 1 5AE0B90E
P 6150 2500
F 0 "J1" H 6160 2620 50  0000 C CNN
F 1 "SMA" V 6265 2500 50  0000 C CNN
F 2 "Antenna:SMA" H 6150 2500 50  0001 C CNN
F 3 "" H 6150 2500 50  0001 C CNN
	1    6150 2500
	-1   0    0    -1  
$EndComp
Text Label 7850 2500 0    60   ~ 0
GND
Text Label 6850 2600 2    60   ~ 0
GND
Text Label 7850 3200 0    60   ~ 0
GND
$Comp
L GND #PWR01
U 1 1 5AE0F2C8
P 7850 3250
F 0 "#PWR01" H 7850 3000 50  0001 C CNN
F 1 "GND" H 7850 3100 50  0000 C CNN
F 2 "" H 7850 3250 50  0001 C CNN
F 3 "" H 7850 3250 50  0001 C CNN
	1    7850 3250
	1    0    0    -1  
$EndComp
Text Label 6450 4200 2    60   ~ 0
GND
Text Label 9400 2600 0    60   ~ 0
MISO
Text Label 9400 2700 0    60   ~ 0
GND
Text Label 9400 2800 0    60   ~ 0
SCK
Text Label 9400 2900 0    60   ~ 0
VCC
Text Label 9400 3000 0    60   ~ 0
MOSI
Text Label 9400 3100 0    60   ~ 0
SD_CS
Text Label 6850 2900 2    60   ~ 0
VCC
Text Label 6850 2700 2    60   ~ 0
RX_ANT
Text Label 6850 2800 2    60   ~ 0
TX_ANT
Text Label 6850 3000 2    60   ~ 0
TX_ANT
Text Label 6850 3100 2    60   ~ 0
RX_ANT
Text Label 7850 2600 0    60   ~ 0
SDN
Text Label 7850 2700 0    60   ~ 0
TRX_INT
Text Label 7850 2800 0    60   ~ 0
TRX_CS
Text Label 7850 2900 0    60   ~ 0
SCK
Text Label 7850 3000 0    60   ~ 0
MOSI
Text Label 7850 3100 0    60   ~ 0
MISO
NoConn ~ 6900 3200
Text Label 6850 2500 2    60   ~ 0
ANT
$Comp
L GND #PWR02
U 1 1 5AE0FE78
P 6150 2750
F 0 "#PWR02" H 6150 2500 50  0001 C CNN
F 1 "GND" H 6150 2600 50  0000 C CNN
F 2 "" H 6150 2750 50  0001 C CNN
F 3 "" H 6150 2750 50  0001 C CNN
	1    6150 2750
	1    0    0    -1  
$EndComp
Text Label 4750 1450 0    60   ~ 0
MOSI
Text Label 4750 1550 0    60   ~ 0
GND
Text Label 4750 1350 0    60   ~ 0
VCC
Text Label 3550 1450 2    60   ~ 0
SCK
Text Label 3550 1350 2    60   ~ 0
MISO
$Comp
L +3V3 #PWR03
U 1 1 5AE10119
P 4750 1300
F 0 "#PWR03" H 4750 1150 50  0001 C CNN
F 1 "+3V3" H 4750 1440 50  0000 C CNN
F 2 "" H 4750 1300 50  0001 C CNN
F 3 "" H 4750 1300 50  0001 C CNN
	1    4750 1300
	1    0    0    -1  
$EndComp
Text Label 6450 4300 2    60   ~ 0
VCC
Text Label 6450 4400 2    60   ~ 0
SDA
Text Label 6450 4500 2    60   ~ 0
SCL
Text Label 4750 4350 0    60   ~ 0
SDA
Text Label 4750 4450 0    60   ~ 0
SCL
NoConn ~ 9350 2500
Text Label 2750 3250 2    60   ~ 0
SD_CS
Text Label 4750 3250 0    60   ~ 0
TRX_INT
Text Label 4750 3350 0    60   ~ 0
TRX_CS
Text Label 4750 3150 0    60   ~ 0
SDN
Text Label 7400 4550 2    60   ~ 0
VCC
Text Label 7400 4450 2    60   ~ 0
SDA
Text Label 7400 4350 2    60   ~ 0
SCL
Text Label 7400 4250 2    60   ~ 0
GND
NoConn ~ 7450 4150
$Comp
L Si7021 U1
U 1 1 5AE1DF37
P 6800 4400
F 0 "U1" H 6850 4750 60  0000 C CNN
F 1 "Si7021" H 6850 4150 60  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x04_Pitch2.54mm" H 6750 4400 60  0001 C CNN
F 3 "" H 6750 4400 60  0001 C CNN
	1    6800 4400
	1    0    0    -1  
$EndComp
$Comp
L MPU6050 U5
U 1 1 5AE1E7D6
P 9700 4100
F 0 "U5" H 9700 4400 60  0000 C CNN
F 1 "MPU6050" H 9700 3400 60  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x08_Pitch2.54mm" H 9550 4100 60  0001 C CNN
F 3 "" H 9550 4100 60  0001 C CNN
	1    9700 4100
	1    0    0    -1  
$EndComp
Text Label 9250 3950 2    60   ~ 0
VCC
Text Label 9250 4050 2    60   ~ 0
GND
Text Label 9250 4150 2    60   ~ 0
SCL
Text Label 9250 4250 2    60   ~ 0
SDA
Text Label 9250 4350 2    60   ~ 0
XDA
Text Label 9250 4450 2    60   ~ 0
XCL
Text Label 9250 4550 2    60   ~ 0
AD0
Text Label 9250 4650 2    60   ~ 0
IMU_INT
Text Label 6100 5450 2    60   ~ 0
GND
Text Label 6100 5250 2    60   ~ 0
VCC
Text Label 6150 5650 2    60   ~ 0
TX2
Text Label 6150 5750 2    60   ~ 0
RX2
Text Label 4750 3950 0    60   ~ 0
TX2
Text Label 4750 4050 0    60   ~ 0
RX2
$Comp
L SD U4
U 1 1 5AE1FA2E
P 8900 2800
F 0 "U4" H 8850 3250 60  0000 C CNN
F 1 "SD" H 8850 2350 60  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x07_Pitch2.54mm" H 9000 2850 60  0001 C CNN
F 3 "" H 9000 2850 60  0001 C CNN
	1    8900 2800
	1    0    0    -1  
$EndComp
Text Label 4750 3750 0    60   ~ 0
IMU_INT
$Comp
L BMP180 U3
U 1 1 5AE2018D
P 7850 4350
F 0 "U3" H 7850 4700 60  0000 C CNN
F 1 "BMP180" H 7850 4000 60  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x05_Pitch2.54mm" H 7700 4300 60  0001 C CNN
F 3 "" H 7700 4300 60  0001 C CNN
	1    7850 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 2500 7850 2500
Wire Wire Line
	7800 3200 7850 3200
Wire Wire Line
	7850 3200 7850 3250
Wire Wire Line
	6900 2600 6850 2600
Wire Wire Line
	6500 4200 6450 4200
Wire Wire Line
	6900 2900 6850 2900
Wire Wire Line
	6900 2700 6850 2700
Wire Wire Line
	6850 2800 6900 2800
Wire Wire Line
	6900 3000 6850 3000
Wire Wire Line
	6850 3100 6900 3100
Wire Wire Line
	7800 2600 7850 2600
Wire Wire Line
	7800 2700 7850 2700
Wire Wire Line
	7850 2800 7800 2800
Wire Wire Line
	7800 2900 7850 2900
Wire Wire Line
	7850 3000 7800 3000
Wire Wire Line
	7800 3100 7850 3100
Wire Wire Line
	6900 2500 6300 2500
Wire Wire Line
	6150 2700 6150 2750
Wire Wire Line
	4700 1450 4750 1450
Wire Wire Line
	3600 1350 3550 1350
Wire Wire Line
	3600 1450 3550 1450
Wire Wire Line
	4700 1350 4750 1350
Wire Wire Line
	4750 1550 4700 1550
Wire Wire Line
	4750 1350 4750 1300
Wire Wire Line
	6500 4300 6450 4300
Wire Wire Line
	6500 4400 6450 4400
Wire Wire Line
	6450 4500 6500 4500
Wire Wire Line
	4700 4350 4750 4350
Wire Wire Line
	4750 4450 4700 4450
Wire Wire Line
	4700 3150 4750 3150
Wire Wire Line
	4700 3350 4750 3350
Wire Wire Line
	7450 4550 7400 4550
Wire Wire Line
	7400 4250 7450 4250
Wire Wire Line
	7450 4350 7400 4350
Wire Wire Line
	7400 4450 7450 4450
Wire Wire Line
	9300 3950 9250 3950
Wire Wire Line
	9250 4050 9300 4050
Wire Wire Line
	9300 4150 9250 4150
Wire Wire Line
	9250 4250 9300 4250
Wire Wire Line
	9300 4350 9250 4350
Wire Wire Line
	9250 4450 9300 4450
Wire Wire Line
	9300 4550 9250 4550
Wire Wire Line
	9250 4650 9300 4650
Wire Wire Line
	4700 3950 4750 3950
Wire Wire Line
	4750 4050 4700 4050
Wire Wire Line
	9350 2600 9400 2600
Wire Wire Line
	9400 2700 9350 2700
Wire Wire Line
	9350 2800 9400 2800
Wire Wire Line
	9400 2900 9350 2900
Wire Wire Line
	9350 3000 9400 3000
Wire Wire Line
	9400 3100 9350 3100
Wire Wire Line
	4700 4250 4750 4250
Wire Wire Line
	4750 4150 4700 4150
Text Label 4750 4250 0    60   ~ 0
XDA
Text Label 4750 4150 0    60   ~ 0
XCL
Text Label 4750 3850 0    60   ~ 0
AD0
NoConn ~ 6150 5850
NoConn ~ 6150 5550
$Comp
L Conn_01x08_Female J2
U 1 1 5AE264A9
P 6350 5550
F 0 "J2" H 6350 5950 50  0000 C CNN
F 1 "L80" H 6350 5050 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x08_Pitch2.54mm" H 6350 5550 50  0001 C CNN
F 3 "" H 6350 5550 50  0001 C CNN
	1    6350 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 5250 6150 5250
Wire Wire Line
	6150 5450 6100 5450
NoConn ~ 6150 5350
Wire Wire Line
	4750 3250 4700 3250
Wire Wire Line
	4750 3750 4700 3750
Wire Wire Line
	4750 3850 4700 3850
NoConn ~ 6150 5950
Wire Wire Line
	2750 3250 2800 3250
Wire Wire Line
	2700 2650 2800 2650
$Comp
L GND #PWR?
U 1 1 5AE27AD9
P 2700 2800
F 0 "#PWR?" H 2700 2550 50  0001 C CNN
F 1 "GND" H 2700 2650 50  0000 C CNN
F 2 "" H 2700 2800 50  0001 C CNN
F 3 "" H 2700 2800 50  0001 C CNN
	1    2700 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 2750 2700 2750
Wire Wire Line
	2700 2650 2700 2800
Connection ~ 2700 2750
Wire Wire Line
	2800 2450 2700 2450
Wire Wire Line
	2700 2450 2700 2400
$Comp
L +3V3 #PWR?
U 1 1 5AE27C8C
P 2700 2400
F 0 "#PWR?" H 2700 2250 50  0001 C CNN
F 1 "+3V3" H 2700 2540 50  0000 C CNN
F 2 "" H 2700 2400 50  0001 C CNN
F 3 "" H 2700 2400 50  0001 C CNN
	1    2700 2400
	1    0    0    -1  
$EndComp
$EndSCHEMATC
