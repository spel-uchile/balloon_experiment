EESchema Schematic File Version 5
EELAYER 32 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
Comment5 ""
Comment6 ""
Comment7 ""
Comment8 ""
Comment9 ""
$EndDescr
Connection ~ 7150 2550
Connection ~ 6650 2550
NoConn ~ 5250 2500
Wire Wire Line
	4850 2600 5250 2600
Wire Wire Line
	4850 2700 5250 2700
Wire Wire Line
	4850 2800 5250 2800
Wire Wire Line
	4850 2900 5250 2900
Wire Wire Line
	4850 3000 5250 3000
Wire Wire Line
	6200 2150 6650 2150
Wire Wire Line
	6200 2200 6200 2150
Wire Wire Line
	6200 2500 6200 2550
Wire Wire Line
	6200 2550 5900 2550
Wire Wire Line
	6650 2150 6650 2200
Wire Wire Line
	6650 2500 6650 2550
Wire Wire Line
	6650 2550 6650 2750
Wire Wire Line
	6650 2550 7150 2550
Wire Wire Line
	6650 2750 6700 2750
Wire Wire Line
	6650 2950 6650 3050
Wire Wire Line
	6700 2950 6650 2950
Wire Wire Line
	7100 2750 7150 2750
Wire Wire Line
	7150 2550 7600 2550
Wire Wire Line
	7150 2750 7150 2550
Wire Wire Line
	7150 2950 7100 2950
Wire Wire Line
	7150 2950 7150 3050
Wire Wire Line
	7600 2550 7600 2700
Wire Wire Line
	7600 3000 7600 3050
Text Label 4900 2600 0    50   ~ 0
SWDIO
Text Label 4900 2700 0    50   ~ 0
SWCLK
Text Label 4900 2800 0    50   ~ 0
GND
Text Label 4900 2900 0    50   ~ 0
3V3
Text Label 4900 3000 0    50   ~ 0
RESET
Text Label 5900 2550 0    50   ~ 0
SWCLK
Text Label 6200 2150 0    50   ~ 0
3V3
Text Label 6650 2550 0    50   ~ 0
RESET
Text HLabel 4850 2600 0    50   Input ~ 0
SWDIO
Text HLabel 4850 2700 0    50   Input ~ 0
SWCLK
Text HLabel 4850 2800 0    50   Input ~ 0
GND
Text HLabel 4850 2900 0    50   Input ~ 0
3V3
Text HLabel 4850 3000 0    50   Input ~ 0
RESET
$Comp
L power:GND #PWR0120
U 1 1 5D1DAC80
P 6650 3050
F 0 "#PWR0120" H 6650 2800 50  0001 C CNN
F 1 "GND" H 6655 2877 50  0000 C CNN
F 2 "" H 6650 3050 50  0001 C CNN
F 3 "" H 6650 3050 50  0001 C CNN
	1    6650 3050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 5D801DC5
P 7150 3050
F 0 "#PWR0105" H 7150 2800 50  0001 C CNN
F 1 "GND" H 7155 2877 50  0000 C CNN
F 2 "" H 7150 3050 50  0001 C CNN
F 3 "" H 7150 3050 50  0001 C CNN
	1    7150 3050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0121
U 1 1 5D1DFA15
P 7600 3050
F 0 "#PWR0121" H 7600 2800 50  0001 C CNN
F 1 "GND" H 7605 2877 50  0000 C CNN
F 2 "" H 7600 3050 50  0001 C CNN
F 3 "" H 7600 3050 50  0001 C CNN
	1    7600 3050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5BFFC4E5
P 6200 2350
F 0 "R1" V 6300 2350 50  0000 C CNN
F 1 "1k" V 6200 2350 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6130 2350 50  0001 C CNN
F 3 "~" H 6200 2350 50  0001 C CNN
	1    6200 2350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5D1DB464
P 6650 2350
F 0 "R2" V 6750 2300 50  0000 L CNN
F 1 "10k" V 6650 2300 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6580 2350 50  0001 C CNN
F 3 "~" H 6650 2350 50  0001 C CNN
	1    6650 2350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C6
U 1 1 5D1DAA3D
P 7600 2850
F 0 "C6" H 7715 2896 50  0000 L CNN
F 1 "100nF" H 7715 2805 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 7638 2700 50  0001 C CNN
F 3 "~" H 7600 2850 50  0001 C CNN
	1    7600 2850
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x06_Male J2
U 1 1 5E278DB4
P 5450 2800
F 0 "J2" H 5422 2683 50  0000 R CNN
F 1 "Programmer" H 5422 2773 50  0000 R CNN
F 2 "Connector_Molex:Molex_PicoBlade_53048-0610_1x06_P1.25mm_Horizontal" H 5450 2800 50  0001 C CNN
F 3 "~" H 5450 2800 50  0001 C CNN
	1    5450 2800
	-1   0    0    1   
$EndComp
$Comp
L Switch:SW_Push_Dual SW1
U 1 1 5D1E1E72
P 6900 2750
F 0 "SW1" H 6950 2450 50  0000 R CNN
F 1 "Reset_push" H 6800 2700 50  0000 R CNN
F 2 "Button_Switch_THT:SW_TH_Tactile_Omron_B3F-10xx" H 6900 2950 50  0001 C CNN
F 3 "~" H 6900 2950 50  0001 C CNN
	1    6900 2750
	1    0    0    -1  
$EndComp
$EndSCHEMATC
