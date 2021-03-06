EESchema Schematic File Version 5
LIBS:OBC-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 2
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
L Payload:Payload U0
U 1 1 5D24FBCD
P 8050 3100
F 0 "U0" H 8050 4648 50  0000 C CNN
F 1 "Payload" H 8050 4557 50  0000 C CNN
F 2 "Payload:PC104-Standard" H 6950 3900 50  0001 C CNN
F 3 "" H 6950 3900 50  0001 C CNN
	1    8050 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 4300 3750 4350
Wire Wire Line
	3750 4350 3850 4350
Wire Wire Line
	4450 4350 4450 4300
Wire Wire Line
	3850 4300 3850 4350
Connection ~ 3850 4350
Wire Wire Line
	3850 4350 3950 4350
Wire Wire Line
	3950 4300 3950 4350
Connection ~ 3950 4350
Wire Wire Line
	3950 4350 4050 4350
Wire Wire Line
	4050 4300 4050 4350
Connection ~ 4050 4350
Wire Wire Line
	4050 4350 4100 4350
Wire Wire Line
	4150 4300 4150 4350
Connection ~ 4150 4350
Wire Wire Line
	4150 4350 4250 4350
Wire Wire Line
	4250 4300 4250 4350
Connection ~ 4250 4350
Wire Wire Line
	4250 4350 4350 4350
Wire Wire Line
	4350 4300 4350 4350
Connection ~ 4350 4350
Wire Wire Line
	4350 4350 4450 4350
Wire Wire Line
	4100 4350 4100 4400
Connection ~ 4100 4350
Wire Wire Line
	4100 4350 4150 4350
$Comp
L power:GND #PWR0101
U 1 1 5D25914E
P 4100 4400
F 0 "#PWR0101" H 4100 4150 50  0001 C CNN
F 1 "GND" H 4105 4227 50  0000 C CNN
F 2 "" H 4100 4400 50  0001 C CNN
F 3 "" H 4100 4400 50  0001 C CNN
	1    4100 4400
	1    0    0    -1  
$EndComp
Text Label 8200 3300 0    50   ~ 0
GND
Text Label 10350 3300 2    50   ~ 0
GND
Text Label 10350 3400 2    50   ~ 0
GND
Text Label 5300 2100 2    50   ~ 0
SDA
Text Label 5300 2200 2    50   ~ 0
SCL
Text Label 5650 2300 0    50   ~ 0
SDA
Text Label 5650 2400 0    50   ~ 0
SCL
Text Label 5650 3900 0    50   ~ 0
CSP_SDA
Text Label 5650 4000 0    50   ~ 0
CSP_SCL
Wire Wire Line
	6050 3900 5650 3900
Wire Wire Line
	5650 4000 6050 4000
Wire Wire Line
	6050 3800 5650 3800
Text Label 5650 3800 0    50   ~ 0
TXD
Text Label 7950 3800 2    50   ~ 0
RXD
Text Label 3000 2100 0    50   ~ 0
TXD
Text Label 3000 2200 0    50   ~ 0
RXD
Wire Wire Line
	3000 2100 3350 2100
Wire Wire Line
	3350 2200 3000 2200
Text Label 5300 3500 2    50   ~ 0
SCLK0
Text Label 5300 3400 2    50   ~ 0
MOSI0
Text Label 5300 3300 2    50   ~ 0
MISO0
Text Label 8200 2000 0    50   ~ 0
SCLK1
Text Label 8200 1900 0    50   ~ 0
MISO1
Text Label 10350 1900 2    50   ~ 0
MOSI1
Wire Wire Line
	8200 1900 8500 1900
Wire Wire Line
	8500 2000 8200 2000
Wire Wire Line
	10050 1900 10350 1900
Wire Wire Line
	10050 3300 10350 3300
Wire Wire Line
	10050 3400 10350 3400
Wire Wire Line
	8500 3300 8200 3300
Text Label 5300 3200 2    50   ~ 0
CS0
Text Label 10350 2000 2    50   ~ 0
CS1
Wire Wire Line
	10350 2000 10050 2000
Text Label 5300 3100 2    50   ~ 0
CS1
Text Label 3000 3000 0    50   ~ 0
SCLK1
Text Label 3000 2900 0    50   ~ 0
MOSI1
Text Label 3000 2800 0    50   ~ 0
MISO1
Wire Wire Line
	3350 2800 3000 2800
Wire Wire Line
	3000 2900 3350 2900
Wire Wire Line
	3350 3000 3000 3000
Text Label 5650 3000 0    50   ~ 0
MOSI0
Text Label 5650 2900 0    50   ~ 0
SCLK0
Wire Wire Line
	7600 2900 7950 2900
Text Label 7950 2900 2    50   ~ 0
MISO0
Text Label 7950 3000 2    50   ~ 0
CS0
Wire Wire Line
	7950 3000 7600 3000
Text Label 5300 2500 2    50   ~ 0
CSP_SCL
Text Label 5300 2400 2    50   ~ 0
CSP_SDA
Wire Wire Line
	5300 2100 4950 2100
Wire Wire Line
	4950 2200 5300 2200
$Comp
L Connector:Raspberry_Pi_2_3 J0
U 1 1 5D2525F1
P 4150 3000
F 0 "J0" H 4150 4481 50  0000 C CNN
F 1 "Raspberry_Pi_2_3" H 4150 4390 50  0000 C CNN
F 2 "Module:Raspberry_Pi_Zero_Socketed_THT_FaceDown_MountingHoles" H 4150 3000 50  0001 C CNN
F 3 "https://www.raspberrypi.org/documentation/hardware/raspberrypi/schematics/rpi_SCH_3bplus_1p0_reduced.pdf" H 4150 3000 50  0001 C CNN
	1    4150 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 2400 5300 2400
Wire Wire Line
	4950 2500 5300 2500
Wire Wire Line
	4950 3100 5300 3100
Wire Wire Line
	4950 3200 5300 3200
Wire Wire Line
	4950 3300 5300 3300
Wire Wire Line
	4950 3400 5300 3400
Wire Wire Line
	4950 3500 5300 3500
Text Label 3000 2400 0    50   ~ 0
GPIO16
Wire Wire Line
	3350 2400 3000 2400
Text Label 7950 2200 2    50   ~ 0
GPIO16
Wire Wire Line
	5650 2100 6050 2100
Wire Wire Line
	5650 2300 6050 2300
Wire Wire Line
	5650 2400 6050 2400
Wire Wire Line
	5650 2900 6050 2900
Wire Wire Line
	5650 3000 6050 3000
Text Label 3000 2500 0    50   ~ 0
GPIO17
Wire Wire Line
	3000 2500 3350 2500
Text Label 7950 3700 2    50   ~ 0
GPIO17
Wire Wire Line
	3350 2600 3000 2600
Text Label 3000 2600 0    50   ~ 0
GPIO18
Text Label 5650 3700 0    50   ~ 0
GPIO18
Wire Wire Line
	3350 3200 3000 3200
Wire Wire Line
	3000 3300 3350 3300
Text Label 3000 3200 0    50   ~ 0
GPIO22
Text Label 3000 3300 0    50   ~ 0
GPIO23
Text Label 5650 3500 0    50   ~ 0
GPIO23
Wire Wire Line
	7600 3800 7950 3800
Wire Wire Line
	3350 3400 3000 3400
Wire Wire Line
	3000 3500 3350 3500
Wire Wire Line
	3350 3700 3000 3700
Text Label 3000 3700 0    50   ~ 0
GPIO27
Text Label 5650 3600 0    50   ~ 0
GPIO27
Wire Wire Line
	3350 3600 3000 3600
Text Label 3000 3600 0    50   ~ 0
GPIO26
Text Label 5650 2100 0    50   ~ 0
GPIO26
Text Label 3000 3400 0    50   ~ 0
GPIO24
Text Label 5650 3400 0    50   ~ 0
GPIO24
Text Label 3000 3500 0    50   ~ 0
GPIO25
Text Label 5650 3200 0    50   ~ 0
GPIO25
Wire Wire Line
	5300 2700 4950 2700
Text Label 5300 2700 2    50   ~ 0
GPIO4
Text Label 5650 4100 0    50   ~ 0
GPIO4
Wire Wire Line
	6050 4100 5650 4100
Text Label 5300 2800 2    50   ~ 0
GPIO5
Wire Wire Line
	5300 2800 4950 2800
Text Label 5650 2700 0    50   ~ 0
GPIO5
Text Label 5300 2900 2    50   ~ 0
GPIO6
Wire Wire Line
	4950 2900 5300 2900
Text Label 5650 2600 0    50   ~ 0
GPIO6
Wire Wire Line
	4950 3700 5300 3700
Wire Wire Line
	5300 3800 4950 3800
Text Label 5300 3700 2    50   ~ 0
GPIO12
Text Label 5650 2200 0    50   ~ 0
GPIO12
Wire Wire Line
	5650 2200 6050 2200
Text Label 5300 3800 2    50   ~ 0
GPIO13
Text Label 5650 2500 0    50   ~ 0
GPIO13
Wire Wire Line
	8500 3100 8200 3100
Wire Wire Line
	10050 3100 10350 3100
Text Label 8200 3100 0    50   ~ 0
5V0
Text Label 10350 3100 2    50   ~ 0
5V0
$Comp
L Connector:Conn_01x02_Male J1
U 1 1 5D263D13
P 3250 1300
F 0 "J1" H 3358 1481 50  0000 C CNN
F 1 "Power" H 3358 1390 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 3250 1300 50  0001 C CNN
F 3 "~" H 3250 1300 50  0001 C CNN
	1    3250 1300
	1    0    0    -1  
$EndComp
Text Label 3850 1300 2    50   ~ 0
5V0
Text Label 3850 1400 2    50   ~ 0
5V_PI
Wire Wire Line
	4050 1700 4050 1650
Wire Wire Line
	4050 1650 3950 1650
Wire Wire Line
	3950 1650 3950 1700
Wire Wire Line
	3950 1650 3950 1400
Wire Wire Line
	3450 1400 3950 1400
Connection ~ 3950 1650
Wire Wire Line
	5650 2600 6050 2600
Wire Wire Line
	5650 3500 6050 3500
Wire Wire Line
	5650 3400 6050 3400
Text Label 7950 3600 2    50   ~ 0
GPIO22
Wire Wire Line
	5650 3200 6050 3200
Wire Wire Line
	6050 3600 5650 3600
Wire Wire Line
	5650 3700 6050 3700
Wire Wire Line
	7950 3700 7600 3700
Wire Wire Line
	7950 3600 7600 3600
Wire Wire Line
	5650 2700 6050 2700
Wire Wire Line
	6050 2500 5650 2500
Wire Wire Line
	7950 2200 7600 2200
Wire Wire Line
	8200 3200 8500 3200
Wire Wire Line
	10350 3200 10050 3200
Text Label 8200 3200 0    50   ~ 0
3V3
Text Label 10350 3200 2    50   ~ 0
3V3
Wire Wire Line
	4250 1700 4250 1650
Wire Wire Line
	4250 1650 4350 1650
Wire Wire Line
	4350 1650 4350 1700
Wire Wire Line
	4350 1650 4750 1650
Connection ~ 4350 1650
Text Label 4750 1650 2    50   ~ 0
3V3
$Comp
L Connector:Screw_Terminal_01x02 J2
U 1 1 5D261C4A
P 3600 5100
F 0 "J2" H 3680 5092 50  0000 L CNN
F 1 "Terminal_5V0" H 3680 5001 50  0000 L CNN
F 2 "TerminalBlock:TerminalBlock_Altech_AK300-2_P5.00mm" H 3600 5100 50  0001 C CNN
F 3 "~" H 3600 5100 50  0001 C CNN
	1    3600 5100
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x04_Male J6
U 1 1 5D2667C7
P 6250 5100
F 0 "J6" H 6358 5381 50  0000 C CNN
F 1 "I2C" H 6358 5290 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 6250 5100 50  0001 C CNN
F 3 "~" H 6250 5100 50  0001 C CNN
	1    6250 5100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J7
U 1 1 5D266E04
P 6250 5850
F 0 "J7" H 6358 6131 50  0000 C CNN
F 1 "CSP_I2C" H 6358 6040 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 6250 5850 50  0001 C CNN
F 3 "~" H 6250 5850 50  0001 C CNN
	1    6250 5850
	1    0    0    -1  
$EndComp
Text Label 4050 5000 2    50   ~ 0
5V_PI
Text Label 4850 5400 2    50   ~ 0
5V_PI
Text Label 4850 5500 2    50   ~ 0
5V_PI
Text Label 4850 5800 2    50   ~ 0
3V3
Text Label 4850 5900 2    50   ~ 0
3V3
Wire Wire Line
	4050 5000 3800 5000
Wire Wire Line
	3800 5100 3950 5100
Wire Wire Line
	3950 5100 3950 5150
$Comp
L power:GND #PWR0102
U 1 1 5D2690FB
P 3950 5150
F 0 "#PWR0102" H 3950 4900 50  0001 C CNN
F 1 "GND" H 3955 4977 50  0000 C CNN
F 2 "" H 3950 5150 50  0001 C CNN
F 3 "" H 3950 5150 50  0001 C CNN
	1    3950 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 5000 4550 5000
Wire Wire Line
	4550 5100 4850 5100
Wire Wire Line
	4850 5800 4550 5800
Wire Wire Line
	4550 5900 4850 5900
Text Label 6850 6050 2    50   ~ 0
CSP_SDA
Text Label 6850 5950 2    50   ~ 0
CSP_SCL
Text Label 6850 5300 2    50   ~ 0
SDA
Text Label 6850 5200 2    50   ~ 0
SCL
Text Label 6850 5000 2    50   ~ 0
3V3
Text Label 6850 5750 2    50   ~ 0
3V3
Wire Wire Line
	6850 5000 6450 5000
Wire Wire Line
	6450 5100 6850 5100
Wire Wire Line
	6850 5200 6450 5200
Wire Wire Line
	6850 5750 6450 5750
Wire Wire Line
	6450 5850 6850 5850
Wire Wire Line
	6850 5950 6450 5950
Wire Wire Line
	6450 6050 6850 6050
Wire Wire Line
	6450 5300 6850 5300
Text Label 6850 5100 2    50   ~ 0
GND
Text Label 6850 5850 2    50   ~ 0
GND
Text Label 5950 5000 2    50   ~ 0
GND
Wire Wire Line
	5550 5300 5950 5300
Text Label 5950 5100 2    50   ~ 0
3V3
$Comp
L Connector:Conn_01x04_Male J5
U 1 1 5D2773BC
P 5350 5100
F 0 "J5" H 5458 5381 50  0000 C CNN
F 1 "I2C" H 5458 5290 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 5350 5100 50  0001 C CNN
F 3 "~" H 5350 5100 50  0001 C CNN
	1    5350 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 5200 5550 5200
Text Label 5950 5300 2    50   ~ 0
CSP_SDA
Text Label 5950 5200 2    50   ~ 0
CSP_SCL
Wire Wire Line
	5550 5100 5950 5100
Wire Wire Line
	5950 5000 5550 5000
$Sheet
S 8050 5100 600  600 
U 5D2760D4
F0 "Sensors" 50
F1 "sensors.sch" 50
F2 "3V3" I L 8050 5200 50 
F3 "GND" I L 8050 5600 50 
F4 "SCL" I L 8050 5300 50 
F5 "SDA" I L 8050 5400 50 
F6 "RX" I L 8050 5500 50 
F7 "TX" I R 8650 5200 50 
$EndSheet
Text Label 7700 5200 0    50   ~ 0
3V3
Text Label 7700 5300 0    50   ~ 0
CSP_SCL
Text Label 7700 5400 0    50   ~ 0
CSP_SDA
Text Label 7700 5500 0    50   ~ 0
TXD
Text Label 8850 5200 2    50   ~ 0
RXD
Wire Wire Line
	8850 5200 8650 5200
Wire Wire Line
	7800 5600 7800 5750
$Comp
L power:GND #PWR0103
U 1 1 5D278E16
P 7800 5750
F 0 "#PWR0103" H 7800 5500 50  0001 C CNN
F 1 "GND" H 7805 5577 50  0000 C CNN
F 2 "" H 7800 5750 50  0001 C CNN
F 3 "" H 7800 5750 50  0001 C CNN
	1    7800 5750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 5200 8050 5200
Wire Wire Line
	7700 5300 8050 5300
Wire Wire Line
	7700 5500 8050 5500
Wire Wire Line
	7700 5400 8050 5400
Wire Wire Line
	7800 5600 8050 5600
$Comp
L Connector:Conn_01x06_Male J3
U 1 1 5D27C9CC
P 4350 5200
F 0 "J3" H 4458 5581 50  0000 C CNN
F 1 "PICOBLADE1" H 4458 5490 50  0000 C CNN
F 2 "Connector_Molex:Molex_PicoBlade_53048-0610_1x06_P1.25mm_Horizontal" H 4350 5200 50  0001 C CNN
F 3 "~" H 4350 5200 50  0001 C CNN
	1    4350 5200
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x06_Male J4
U 1 1 5D27D485
P 4350 6000
F 0 "J4" H 4458 6381 50  0000 C CNN
F 1 "PICOBLADE2" H 4458 6290 50  0000 C CNN
F 2 "Connector_Molex:Molex_PicoBlade_53048-0610_1x06_P1.25mm_Horizontal" H 4350 6000 50  0001 C CNN
F 3 "~" H 4350 6000 50  0001 C CNN
	1    4350 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 5200 4850 5200
Wire Wire Line
	4550 5300 4850 5300
Wire Wire Line
	4850 5500 4550 5500
Wire Wire Line
	4550 5400 4850 5400
Text Label 4850 5200 2    50   ~ 0
GND
Text Label 4850 5300 2    50   ~ 0
GND
Text Label 4850 5000 2    50   ~ 0
3V3
Text Label 4850 5100 2    50   ~ 0
3V3
Wire Wire Line
	4550 6200 4850 6200
Wire Wire Line
	4850 6300 4550 6300
Wire Wire Line
	4550 6100 4850 6100
Wire Wire Line
	4550 6000 4850 6000
Text Label 4850 6300 2    50   ~ 0
5V_PI
Text Label 4850 6200 2    50   ~ 0
5V_PI
Text Label 4850 6000 2    50   ~ 0
GND
Text Label 4850 6100 2    50   ~ 0
GND
$Comp
L Connector:Conn_01x01_Male J13
U 1 1 5D29151A
P 2200 2950
F 0 "J13" H 2308 3131 50  0000 C CNN
F 1 "RPI_MOUNT3" H 2308 3040 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 2200 2950 50  0001 C CNN
F 3 "~" H 2200 2950 50  0001 C CNN
	1    2200 2950
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Male J14
U 1 1 5D29180F
P 2200 3200
F 0 "J14" H 2308 3381 50  0000 C CNN
F 1 "RPI_MOUNT4" H 2308 3290 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 2200 3200 50  0001 C CNN
F 3 "~" H 2200 3200 50  0001 C CNN
	1    2200 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 3200 2400 3200
Wire Wire Line
	2400 2950 2450 2950
Wire Wire Line
	2450 2950 2450 3200
Wire Wire Line
	2450 3200 2450 3250
Connection ~ 2450 3200
$Comp
L power:GND #PWR0104
U 1 1 5D29519F
P 2450 3250
F 0 "#PWR0104" H 2450 3000 50  0001 C CNN
F 1 "GND" H 2455 3077 50  0000 C CNN
F 2 "" H 2450 3250 50  0001 C CNN
F 3 "" H 2450 3250 50  0001 C CNN
	1    2450 3250
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Male J8
U 1 1 5D2A5713
P 3250 900
F 0 "J8" H 3358 1081 50  0000 C CNN
F 1 "Power2" H 3358 990 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 3250 900 50  0001 C CNN
F 3 "~" H 3250 900 50  0001 C CNN
	1    3250 900 
	1    0    0    -1  
$EndComp
Text Label 3850 1000 2    50   ~ 0
5V_PI
Wire Wire Line
	7950 4300 7600 4300
Text Label 7950 4300 2    50   ~ 0
OUT5_5V0
Text Label 3850 900  2    50   ~ 0
OUT5_5V0
Wire Wire Line
	3450 900  3850 900 
Wire Wire Line
	3450 1000 3850 1000
Wire Wire Line
	3450 1300 3850 1300
$EndSCHEMATC
