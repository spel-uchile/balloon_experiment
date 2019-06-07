EESchema Schematic File Version 5
LIBS:DPL-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 3
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
L Payload:Payload U1
U 1 1 5C059BEE
P 9000 3250
F 0 "U1" H 9000 4798 50  0000 C CNN
F 1 "Payload" H 9000 4707 50  0000 C CNN
F 2 "" H 7900 4050 50  0001 C CNN
F 3 "" H 7900 4050 50  0001 C CNN
	1    9000 3250
	1    0    0    -1  
$EndComp
Text Label 9250 3450 0    50   ~ 0
GND
Text Label 11200 3450 2    50   ~ 0
GND
Text Label 11200 3550 2    50   ~ 0
GND
Wire Wire Line
	11200 3450 11000 3450
Wire Wire Line
	11000 3550 11200 3550
Wire Wire Line
	9450 3450 9250 3450
Text Label 6800 4050 0    50   ~ 0
SDA
Text Label 6800 4150 0    50   ~ 0
SCL
Wire Wire Line
	7000 4050 6800 4050
Wire Wire Line
	6800 4150 7000 4150
$Comp
L Connector:Screw_Terminal_01x02 J1
U 1 1 5C0ECC20
P 1400 4450
F 0 "J1" H 1480 4442 50  0000 L CNN
F 1 "DPL1" H 1480 4351 50  0000 L CNN
F 2 "" H 1400 4450 50  0001 C CNN
F 3 "~" H 1400 4450 50  0001 C CNN
	1    1400 4450
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J2
U 1 1 5C0ED411
P 2550 4450
F 0 "J2" H 2630 4442 50  0000 L CNN
F 1 "DPL2" H 2630 4351 50  0000 L CNN
F 2 "" H 2550 4450 50  0001 C CNN
F 3 "~" H 2550 4450 50  0001 C CNN
	1    2550 4450
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J3
U 1 1 5C0ED755
P 3700 4450
F 0 "J3" H 3780 4442 50  0000 L CNN
F 1 "DPL3" H 3780 4351 50  0000 L CNN
F 2 "" H 3700 4450 50  0001 C CNN
F 3 "~" H 3700 4450 50  0001 C CNN
	1    3700 4450
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J4
U 1 1 5C0ED94F
P 1400 5350
F 0 "J4" H 1480 5342 50  0000 L CNN
F 1 "DPL4" H 1480 5251 50  0000 L CNN
F 2 "" H 1400 5350 50  0001 C CNN
F 3 "~" H 1400 5350 50  0001 C CNN
	1    1400 5350
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J5
U 1 1 5C0EDB6A
P 2550 5350
F 0 "J5" H 2630 5342 50  0000 L CNN
F 1 "DPL5" H 2630 5251 50  0000 L CNN
F 2 "" H 2550 5350 50  0001 C CNN
F 3 "~" H 2550 5350 50  0001 C CNN
	1    2550 5350
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J6
U 1 1 5C0EDE0E
P 3700 5350
F 0 "J6" H 3780 5342 50  0000 L CNN
F 1 "DPL6" H 3780 5251 50  0000 L CNN
F 2 "" H 3700 5350 50  0001 C CNN
F 3 "~" H 3700 5350 50  0001 C CNN
	1    3700 5350
	1    0    0    -1  
$EndComp
$Sheet
S 1000 1800 800  800 
U 5CF85FE2
F0 "usb" 50
F1 "USB.sch" 50
F2 "VBUS" I R 1800 1900 50 
F3 "USB_DP" I R 1800 2050 50 
F4 "USB_DM" I R 1800 2200 50 
F5 "USB_ID" I R 1800 2350 50 
F6 "GND" I R 1800 2500 50 
$EndSheet
$Sheet
S 1050 3400 750  600 
U 5CF86024
F0 "power" 50
F1 "Power.sch" 50
F2 "3V3" I R 1800 3500 50 
F3 "VDDANA" I R 1800 3650 50 
F4 "VDDCORE" I R 1800 3800 50 
F5 "GND" I L 1050 3800 50 
F6 "VIN" I L 1050 3500 50 
$EndSheet
Text Label 3900 3350 0    50   ~ 0
GND
Text Label 6600 2850 2    50   ~ 0
GND
Text Label 2200 3800 2    50   ~ 0
VDDCORE
Wire Wire Line
	2200 3800 1800 3800
Wire Wire Line
	2200 3650 1800 3650
Wire Wire Line
	2200 3500 1800 3500
Text Label 2200 3500 2    50   ~ 0
3V3
Text Label 2200 3650 2    50   ~ 0
VDDANA
Text Label 850  3800 0    50   ~ 0
GND
Text Label 850  3500 0    50   ~ 0
VIN
Wire Wire Line
	850  3800 1050 3800
Wire Wire Line
	850  3500 1050 3500
Text Label 2150 2050 2    50   ~ 0
USB_DP
Text Label 2150 2200 2    50   ~ 0
USB_DM
Text Label 2150 2350 2    50   ~ 0
USB_ID
Text Label 2150 2500 2    50   ~ 0
GND
Text Label 2150 1900 2    50   ~ 0
VBUS
Wire Wire Line
	2150 1900 1800 1900
Wire Wire Line
	1800 2050 2150 2050
Wire Wire Line
	2150 2200 1800 2200
Wire Wire Line
	1800 2350 2150 2350
Wire Wire Line
	2150 2500 1800 2500
Text Label 6600 2750 2    50   ~ 0
VDDCORE
Text Label 3900 3250 0    50   ~ 0
VDDANA
Text Label 6600 3250 2    50   ~ 0
USB_DP
Text Label 6600 3350 2    50   ~ 0
USB_DM
Text Label 6600 2950 2    50   ~ 0
USB_ID
Text Label 6600 3450 2    50   ~ 0
SCL
Text Label 6600 3550 2    50   ~ 0
SDA
Text Label 6600 2650 2    50   ~ 0
3V3
$Comp
L Arduino:SAMD21E U0
U 1 1 5CF97A4C
P 5250 3200
F 0 "U0" H 5250 4215 50  0000 C CNN
F 1 "SAMD21E" H 5250 4124 50  0000 C CNN
F 2 "" H 5250 3100 50  0001 C CNN
F 3 "" H 5250 3100 50  0001 C CNN
	1    5250 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	9250 3250 9450 3250
Wire Wire Line
	11200 3250 11000 3250
Text Label 11200 3250 2    50   ~ 0
5V0
Text Label 9250 3250 0    50   ~ 0
5V0
$Comp
L Connector:Conn_01x05_Male J0
U 1 1 5CF9AA17
P 3950 1300
F 0 "J0" H 4058 1681 50  0000 C CNN
F 1 "Programer" H 4058 1590 50  0000 C CNN
F 2 "" H 3950 1300 50  0001 C CNN
F 3 "~" H 3950 1300 50  0001 C CNN
	1    3950 1300
	1    0    0    -1  
$EndComp
Text Label 4450 1100 2    50   ~ 0
SWDIO
Text Label 4450 1200 2    50   ~ 0
SWCLK
Text Label 4450 1300 2    50   ~ 0
GND
Text Label 4450 1400 2    50   ~ 0
3V3
Text Label 4450 1500 2    50   ~ 0
RESET
Wire Wire Line
	4450 1100 4150 1100
Wire Wire Line
	4150 1200 4450 1200
Wire Wire Line
	4450 1300 4150 1300
Wire Wire Line
	4150 1400 4450 1400
Wire Wire Line
	4450 1500 4150 1500
Text Label 6600 3050 2    50   ~ 0
RESET
Text Label 6600 2450 2    50   ~ 0
SWDIO
Text Label 6600 2550 2    50   ~ 0
SWCLK
$Comp
L Transistor_FET:IRF540N Q1
U 1 1 5CF98A4C
P 1150 4800
F 0 "Q1" H 1356 4846 50  0000 L CNN
F 1 "IRF540N" H 1356 4755 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 1400 4725 50  0001 L CIN
F 3 "http://www.irf.com/product-info/datasheets/data/irf540n.pdf" H 1150 4800 50  0001 L CNN
	1    1150 4800
	-1   0    0    -1  
$EndComp
$Comp
L Transistor_FET:IRF540N Q2
U 1 1 5CF99BAE
P 2300 4800
F 0 "Q2" H 2506 4846 50  0000 L CNN
F 1 "IRF540N" H 2506 4755 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 2550 4725 50  0001 L CIN
F 3 "http://www.irf.com/product-info/datasheets/data/irf540n.pdf" H 2300 4800 50  0001 L CNN
	1    2300 4800
	-1   0    0    -1  
$EndComp
$Comp
L Transistor_FET:IRF540N Q3
U 1 1 5CF9A83E
P 3450 4800
F 0 "Q3" H 3656 4846 50  0000 L CNN
F 1 "IRF540N" H 3656 4755 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 3700 4725 50  0001 L CIN
F 3 "http://www.irf.com/product-info/datasheets/data/irf540n.pdf" H 3450 4800 50  0001 L CNN
	1    3450 4800
	-1   0    0    -1  
$EndComp
$Comp
L Transistor_FET:IRF540N Q4
U 1 1 5CF9B683
P 1150 5700
F 0 "Q4" H 1356 5746 50  0000 L CNN
F 1 "IRF540N" H 1356 5655 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 1400 5625 50  0001 L CIN
F 3 "http://www.irf.com/product-info/datasheets/data/irf540n.pdf" H 1150 5700 50  0001 L CNN
	1    1150 5700
	-1   0    0    -1  
$EndComp
$Comp
L Transistor_FET:IRF540N Q5
U 1 1 5CF9BF48
P 2300 5700
F 0 "Q5" H 2506 5746 50  0000 L CNN
F 1 "IRF540N" H 2506 5655 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 2550 5625 50  0001 L CIN
F 3 "http://www.irf.com/product-info/datasheets/data/irf540n.pdf" H 2300 5700 50  0001 L CNN
	1    2300 5700
	-1   0    0    -1  
$EndComp
$Comp
L Transistor_FET:IRF540N Q6
U 1 1 5CF9C64D
P 3450 5700
F 0 "Q6" H 3656 5746 50  0000 L CNN
F 1 "IRF540N" H 3656 5655 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 3700 5625 50  0001 L CIN
F 3 "http://www.irf.com/product-info/datasheets/data/irf540n.pdf" H 3450 5700 50  0001 L CNN
	1    3450 5700
	-1   0    0    -1  
$EndComp
$Comp
L Device:Crystal Y1
U 1 1 5CF9F2BB
P 3950 2500
F 0 "Y1" H 3950 2768 50  0000 C CNN
F 1 "32.768kHz" H 3950 2677 50  0000 C CNN
F 2 "" H 3950 2500 50  0001 C CNN
F 3 "~" H 3950 2500 50  0001 C CNN
	1    3950 2500
	0    1    1    0   
$EndComp
$Comp
L Device:C C1b1
U 1 1 5CF9F785
P 3600 2750
F 0 "C1b1" H 3715 2796 50  0000 L CNN
F 1 "9pF" H 3715 2705 50  0000 L CNN
F 2 "" H 3638 2600 50  0001 C CNN
F 3 "~" H 3600 2750 50  0001 C CNN
	1    3600 2750
	0    1    1    0   
$EndComp
$Comp
L Device:C C1a1
U 1 1 5CF9FB5E
P 3600 2250
F 0 "C1a1" H 3715 2296 50  0000 L CNN
F 1 "9pF" H 3715 2205 50  0000 L CNN
F 2 "" H 3638 2100 50  0001 C CNN
F 3 "~" H 3600 2250 50  0001 C CNN
	1    3600 2250
	0    1    1    0   
$EndComp
Wire Wire Line
	1050 4600 1050 4550
Wire Wire Line
	1050 4550 1200 4550
Text Label 1050 4450 0    50   ~ 0
5V0
Wire Wire Line
	2200 4600 2200 4550
Wire Wire Line
	2200 4550 2350 4550
Text Label 2200 4450 0    50   ~ 0
5V0
Wire Wire Line
	3350 4600 3350 4550
Wire Wire Line
	3350 4550 3500 4550
Text Label 3350 4450 0    50   ~ 0
5V0
Wire Wire Line
	1050 5450 1200 5450
Wire Wire Line
	1050 5450 1050 5500
Text Label 1050 5350 0    50   ~ 0
5V0
Wire Wire Line
	2200 5500 2200 5450
Wire Wire Line
	2200 5450 2350 5450
Text Label 2200 5350 0    50   ~ 0
5V0
Wire Wire Line
	3350 5500 3350 5450
Wire Wire Line
	3350 5450 3500 5450
Text Label 3350 5350 0    50   ~ 0
5V0
Wire Wire Line
	1200 4450 1050 4450
Wire Wire Line
	1050 5000 1050 5050
$Comp
L power:GND #PWR?
U 1 1 5CF99838
P 1050 5050
F 0 "#PWR?" H 1050 4800 50  0001 C CNN
F 1 "GND" H 1055 4877 50  0000 C CNN
F 2 "" H 1050 5050 50  0001 C CNN
F 3 "" H 1050 5050 50  0001 C CNN
	1    1050 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 4450 2200 4450
Wire Wire Line
	2200 5000 2200 5050
$Comp
L power:GND #PWR?
U 1 1 5CF9AF8D
P 2200 5050
F 0 "#PWR?" H 2200 4800 50  0001 C CNN
F 1 "GND" H 2205 4877 50  0000 C CNN
F 2 "" H 2200 5050 50  0001 C CNN
F 3 "" H 2200 5050 50  0001 C CNN
	1    2200 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 5000 3350 5050
$Comp
L power:GND #PWR?
U 1 1 5CF9BBE1
P 3350 5050
F 0 "#PWR?" H 3350 4800 50  0001 C CNN
F 1 "GND" H 3355 4877 50  0000 C CNN
F 2 "" H 3350 5050 50  0001 C CNN
F 3 "" H 3350 5050 50  0001 C CNN
	1    3350 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 4450 3350 4450
Wire Wire Line
	1200 5350 1050 5350
Wire Wire Line
	1050 5900 1050 5950
$Comp
L power:GND #PWR?
U 1 1 5CF9C528
P 1050 5950
F 0 "#PWR?" H 1050 5700 50  0001 C CNN
F 1 "GND" H 1055 5777 50  0000 C CNN
F 2 "" H 1050 5950 50  0001 C CNN
F 3 "" H 1050 5950 50  0001 C CNN
	1    1050 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 5900 2200 5950
Wire Wire Line
	2350 5350 2200 5350
$Comp
L power:GND #PWR?
U 1 1 5CF9CBDF
P 2200 5950
F 0 "#PWR?" H 2200 5700 50  0001 C CNN
F 1 "GND" H 2205 5777 50  0000 C CNN
F 2 "" H 2200 5950 50  0001 C CNN
F 3 "" H 2200 5950 50  0001 C CNN
	1    2200 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 5900 3350 5950
Wire Wire Line
	3350 5350 3500 5350
$Comp
L power:GND #PWR?
U 1 1 5CF9D59C
P 3350 5950
F 0 "#PWR?" H 3350 5700 50  0001 C CNN
F 1 "GND" H 3355 5777 50  0000 C CNN
F 2 "" H 3350 5950 50  0001 C CNN
F 3 "" H 3350 5950 50  0001 C CNN
	1    3350 5950
	1    0    0    -1  
$EndComp
Text Label 1700 4800 2    50   ~ 0
EN_DPL1
Wire Wire Line
	1350 4800 1700 4800
Text Label 2850 4800 2    50   ~ 0
EN_DPL2
Text Label 4000 4800 2    50   ~ 0
EN_DPL3
Text Label 1700 5700 2    50   ~ 0
EN_DPL4
Text Label 2850 5700 2    50   ~ 0
EN_DPL5
Text Label 4000 5700 2    50   ~ 0
EN_DPL6
Wire Wire Line
	2500 4800 2850 4800
Wire Wire Line
	4000 4800 3650 4800
Wire Wire Line
	4000 5700 3650 5700
Wire Wire Line
	2850 5700 2500 5700
Wire Wire Line
	1700 5700 1350 5700
Wire Wire Line
	4450 2450 4400 2450
Wire Wire Line
	4400 2450 4400 2250
Wire Wire Line
	4400 2250 3950 2250
Wire Wire Line
	4400 2750 4400 2550
Wire Wire Line
	4400 2550 4450 2550
Wire Wire Line
	3750 2750 3950 2750
Wire Wire Line
	3950 2650 3950 2750
Connection ~ 3950 2750
Wire Wire Line
	3950 2750 4400 2750
Connection ~ 3950 2250
Wire Wire Line
	3950 2250 3750 2250
Wire Wire Line
	3450 2250 3400 2250
Wire Wire Line
	3400 2250 3400 2750
Wire Wire Line
	3400 2750 3450 2750
Wire Wire Line
	3400 2750 3400 2800
Connection ~ 3400 2750
$Comp
L power:GND #PWR?
U 1 1 5CF9C5E9
P 3400 2800
F 0 "#PWR?" H 3400 2550 50  0001 C CNN
F 1 "GND" H 3405 2627 50  0000 C CNN
F 2 "" H 3400 2800 50  0001 C CNN
F 3 "" H 3400 2800 50  0001 C CNN
	1    3400 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 2250 3950 2350
$Comp
L Switch:SW_Reed SW1
U 1 1 5CFAADC7
P 4850 5450
F 0 "SW1" H 4850 5672 50  0000 C CNN
F 1 "SW_Reed" H 4850 5581 50  0000 C CNN
F 2 "" H 4850 5450 50  0001 C CNN
F 3 "~" H 4850 5450 50  0001 C CNN
	1    4850 5450
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Reed SW2
U 1 1 5CFAB4B3
P 4850 5800
F 0 "SW2" H 4850 6022 50  0000 C CNN
F 1 "SW_Reed" H 4850 5931 50  0000 C CNN
F 2 "" H 4850 5800 50  0001 C CNN
F 3 "~" H 4850 5800 50  0001 C CNN
	1    4850 5800
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Reed SW3
U 1 1 5CFAB742
P 4850 6150
F 0 "SW3" H 4850 6372 50  0000 C CNN
F 1 "SW_Reed" H 4850 6281 50  0000 C CNN
F 2 "" H 4850 6150 50  0001 C CNN
F 3 "~" H 4850 6150 50  0001 C CNN
	1    4850 6150
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Reed SW4
U 1 1 5CFAB865
P 4850 6500
F 0 "SW4" H 4850 6722 50  0000 C CNN
F 1 "SW_Reed" H 4850 6631 50  0000 C CNN
F 2 "" H 4850 6500 50  0001 C CNN
F 3 "~" H 4850 6500 50  0001 C CNN
	1    4850 6500
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Reed SW5
U 1 1 5CFABAC0
P 4850 6850
F 0 "SW5" H 4850 7072 50  0000 C CNN
F 1 "SW_Reed" H 4850 6981 50  0000 C CNN
F 2 "" H 4850 6850 50  0001 C CNN
F 3 "~" H 4850 6850 50  0001 C CNN
	1    4850 6850
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Reed SW6
U 1 1 5CFABE05
P 4850 7200
F 0 "SW6" H 4850 7422 50  0000 C CNN
F 1 "SW_Reed" H 4850 7331 50  0000 C CNN
F 2 "" H 4850 7200 50  0001 C CNN
F 3 "~" H 4850 7200 50  0001 C CNN
	1    4850 7200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5CFAC755
P 5800 5800
F 0 "R2" H 5870 5846 50  0000 L CNN
F 1 "1k" H 5870 5755 50  0000 L CNN
F 2 "" V 5730 5800 50  0001 C CNN
F 3 "~" H 5800 5800 50  0001 C CNN
	1    5800 5800
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R3
U 1 1 5CFAC7EA
P 5800 6150
F 0 "R3" H 5870 6196 50  0000 L CNN
F 1 "1k" H 5870 6105 50  0000 L CNN
F 2 "" V 5730 6150 50  0001 C CNN
F 3 "~" H 5800 6150 50  0001 C CNN
	1    5800 6150
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R4
U 1 1 5CFAC8CF
P 5800 6500
F 0 "R4" H 5870 6546 50  0000 L CNN
F 1 "1k" H 5870 6455 50  0000 L CNN
F 2 "" V 5730 6500 50  0001 C CNN
F 3 "~" H 5800 6500 50  0001 C CNN
	1    5800 6500
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R5
U 1 1 5CFACA54
P 5800 6850
F 0 "R5" H 5870 6896 50  0000 L CNN
F 1 "1k" H 5870 6805 50  0000 L CNN
F 2 "" V 5730 6850 50  0001 C CNN
F 3 "~" H 5800 6850 50  0001 C CNN
	1    5800 6850
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R6
U 1 1 5CFAD116
P 5800 7200
F 0 "R6" H 5870 7246 50  0000 L CNN
F 1 "1k" H 5870 7155 50  0000 L CNN
F 2 "" V 5730 7200 50  0001 C CNN
F 3 "~" H 5800 7200 50  0001 C CNN
	1    5800 7200
	0    -1   -1   0   
$EndComp
Text Label 5600 5450 2    50   ~ 0
DPL_STATUS1
Wire Wire Line
	5050 5450 5650 5450
Text Label 5600 5800 2    50   ~ 0
DPL_STATUS2
Text Label 5600 6150 2    50   ~ 0
DPL_STATUS3
Text Label 5600 6500 2    50   ~ 0
DPL_STATUS4
Text Label 5600 6850 2    50   ~ 0
DPL_STATUS5
Text Label 5600 7200 2    50   ~ 0
DPL_STATUS6
Wire Wire Line
	5650 5800 5050 5800
Wire Wire Line
	5100 6150 5650 6150
Wire Wire Line
	5650 6500 5050 6500
Wire Wire Line
	5050 6850 5650 6850
Wire Wire Line
	5950 5450 6000 5450
Wire Wire Line
	6000 5450 6000 5800
Wire Wire Line
	6000 7200 5950 7200
Wire Wire Line
	5950 6850 6000 6850
Connection ~ 6000 6850
Wire Wire Line
	6000 6850 6000 7200
Wire Wire Line
	5950 6500 6000 6500
Connection ~ 6000 6500
Wire Wire Line
	6000 6500 6000 6850
Wire Wire Line
	5950 6150 6000 6150
Connection ~ 6000 6150
Wire Wire Line
	6000 6150 6000 6500
Wire Wire Line
	5950 5800 6000 5800
Connection ~ 6000 5800
Wire Wire Line
	6000 5800 6000 6150
Wire Wire Line
	6000 7200 6000 7250
Connection ~ 6000 7200
$Comp
L power:GND #PWR?
U 1 1 5CFB9A35
P 6000 7250
F 0 "#PWR?" H 6000 7000 50  0001 C CNN
F 1 "GND" H 6005 7077 50  0000 C CNN
F 2 "" H 6000 7250 50  0001 C CNN
F 3 "" H 6000 7250 50  0001 C CNN
	1    6000 7250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5CFB9EE2
P 5800 5450
F 0 "R1" H 5870 5496 50  0000 L CNN
F 1 "1k" H 5870 5405 50  0000 L CNN
F 2 "" V 5730 5450 50  0001 C CNN
F 3 "~" H 5800 5450 50  0001 C CNN
	1    5800 5450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5050 7200 5650 7200
Text Label 4500 5450 0    50   ~ 0
3V3
Wire Wire Line
	4650 5450 4500 5450
Wire Wire Line
	4500 5450 4500 5800
Wire Wire Line
	4500 7200 4650 7200
Wire Wire Line
	4650 5800 4500 5800
Connection ~ 4500 5800
Wire Wire Line
	4500 5800 4500 6150
Connection ~ 4500 6150
Wire Wire Line
	4500 6150 4500 6500
Wire Wire Line
	4500 6150 4650 6150
Wire Wire Line
	4650 6500 4500 6500
Connection ~ 4500 6500
Wire Wire Line
	4500 6500 4500 6850
Connection ~ 4500 6850
Wire Wire Line
	4500 6850 4500 7200
Wire Wire Line
	4500 6850 4650 6850
Text Label 3900 3050 0    50   ~ 0
EN_DPL1
Text Label 3900 3150 0    50   ~ 0
DPL_STATUS1
Wire Wire Line
	4450 3050 3900 3050
Wire Wire Line
	3900 3150 4450 3150
Wire Wire Line
	3900 3250 4450 3250
Wire Wire Line
	3900 3350 4450 3350
Text Label 3900 3450 0    50   ~ 0
EN_DPL2
Text Label 3900 3650 0    50   ~ 0
EN_DPL3
Text Label 3900 3550 0    50   ~ 0
DPL_STATUS2
Text Label 3900 3750 0    50   ~ 0
DPL_STATUS3
Text Label 3900 3850 0    50   ~ 0
EN_DPL4
Text Label 3900 3950 0    50   ~ 0
DPL_STATUS4
Wire Wire Line
	4450 3450 3900 3450
Wire Wire Line
	3900 3550 4450 3550
Wire Wire Line
	3900 3650 4450 3650
Wire Wire Line
	4450 3750 3900 3750
Wire Wire Line
	3900 3850 4450 3850
Wire Wire Line
	4450 3950 3900 3950
Text Label 6600 3950 2    50   ~ 0
EN_DPL5
Text Label 6600 3850 2    50   ~ 0
DPL_STATUS5
Wire Wire Line
	6600 3950 6050 3950
Wire Wire Line
	6050 3850 6600 3850
Wire Wire Line
	6050 2450 6600 2450
Wire Wire Line
	6050 2550 6600 2550
Wire Wire Line
	6050 2650 6600 2650
Wire Wire Line
	6050 2750 6600 2750
Wire Wire Line
	6050 2850 6600 2850
Wire Wire Line
	6050 2950 6600 2950
Wire Wire Line
	6050 3050 6600 3050
Wire Wire Line
	6050 3350 6600 3350
Wire Wire Line
	6050 3450 6600 3450
Wire Wire Line
	6050 3550 6600 3550
Wire Wire Line
	6050 3250 6600 3250
Text Label 6600 3750 2    50   ~ 0
EN_DPL6
Text Label 6600 3650 2    50   ~ 0
DPL_STATUS6
Wire Wire Line
	6600 3650 6050 3650
Wire Wire Line
	6050 3750 6600 3750
$EndSCHEMATC
