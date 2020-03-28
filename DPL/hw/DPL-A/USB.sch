EESchema Schematic File Version 5
EELAYER 32 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 5
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
Connection ~ 6350 4100
Connection ~ 6750 4100
Connection ~ 6550 4500
Wire Wire Line
	4450 3100 4750 3100
Wire Wire Line
	4450 3300 4750 3300
Wire Wire Line
	4450 3400 4750 3400
Wire Wire Line
	4450 3500 4750 3500
Wire Wire Line
	4750 3200 4450 3200
Wire Wire Line
	5200 3750 5200 4100
Wire Wire Line
	5300 3750 5300 3850
Wire Wire Line
	5600 3150 5900 3150
Wire Wire Line
	5600 3350 5900 3350
Wire Wire Line
	5600 3450 5900 3450
Wire Wire Line
	5600 3550 6000 3550
Wire Wire Line
	6350 4100 5200 4100
Wire Wire Line
	6350 4100 6750 4100
Wire Wire Line
	6350 4150 6350 4100
Wire Wire Line
	6350 4450 6350 4500
Wire Wire Line
	6350 4500 6550 4500
Wire Wire Line
	6550 4500 6550 4550
Wire Wire Line
	6550 4500 6750 4500
Wire Wire Line
	6600 3550 6300 3550
Wire Wire Line
	6750 4100 6750 4150
Wire Wire Line
	6750 4100 7700 4100
Wire Wire Line
	6750 4500 6750 4450
Wire Wire Line
	7200 3550 6850 3550
Wire Wire Line
	7700 3000 7500 3000
Wire Wire Line
	7700 3050 7700 3000
Wire Wire Line
	7700 4100 7700 4050
Wire Wire Line
	8200 3550 8550 3550
Text Label 4750 3100 2    50   ~ 0
VUSB
Text Label 4750 3200 2    50   ~ 0
USB_DP
Text Label 4750 3300 2    50   ~ 0
USB_DM
Text Label 4750 3400 2    50   ~ 0
USB_ID
Text Label 4750 3500 2    50   ~ 0
GND
Text Label 5300 3800 0    50   ~ 0
GND
Text Label 5900 3150 2    50   ~ 0
VUSB
Text Label 5900 3350 2    50   ~ 0
USB_DP
Text Label 5900 3450 2    50   ~ 0
USB_DM
Text Label 5900 3550 2    50   ~ 0
ID
Text Label 6450 4100 0    50   ~ 0
SHIELD
Text Label 6600 3550 2    50   ~ 0
USB_ID
Text Label 6850 3550 0    50   ~ 0
USB_DP
Text Label 7500 3000 0    50   ~ 0
VUSB
Text Label 8550 3550 2    50   ~ 0
USB_DM
Text HLabel 4450 3100 0    50   Input ~ 0
VUSB
Text HLabel 4450 3200 0    50   Input ~ 0
USB_DP
Text HLabel 4450 3300 0    50   Input ~ 0
USB_DM
Text HLabel 4450 3400 0    50   Input ~ 0
USB_ID
Text HLabel 4450 3500 0    50   Input ~ 0
GND
$Comp
L power:GND #PWR0102
U 1 1 5B62BD38
P 5300 3850
F 0 "#PWR0102" H 5300 3600 50  0001 C CNN
F 1 "GND" H 5305 3677 50  0000 C CNN
F 2 "" H 5300 3850 50  0001 C CNN
F 3 "" H 5300 3850 50  0001 C CNN
	1    5300 3850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5BA44753
P 6550 4550
F 0 "#PWR0103" H 6550 4300 50  0001 C CNN
F 1 "GND" H 6555 4377 50  0000 C CNN
F 2 "" H 6550 4550 50  0001 C CNN
F 3 "" H 6550 4550 50  0001 C CNN
	1    6550 4550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5D1D507C
P 6150 3550
F 0 "R4" V 6250 3500 50  0000 L CNN
F 1 "330" V 6150 3500 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6080 3550 50  0001 C CNN
F 3 "~" H 6150 3550 50  0001 C CNN
	1    6150 3550
	0    1    1    0   
$EndComp
$Comp
L Device:R R3
U 1 1 5B62BE0D
P 6750 4300
F 0 "R3" H 6820 4346 50  0000 L CNN
F 1 "1M" H 6820 4255 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6680 4300 50  0001 C CNN
F 3 "~" H 6750 4300 50  0001 C CNN
	1    6750 4300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C5
U 1 1 5B62BE71
P 6350 4300
F 0 "C5" H 6465 4346 50  0000 L CNN
F 1 "4.7nF" H 6465 4255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 6388 4150 50  0001 C CNN
F 3 "~" H 6350 4300 50  0001 C CNN
	1    6350 4300
	1    0    0    -1  
$EndComp
$Comp
L Connector:USB_B_Micro J1
U 1 1 5B62635D
P 5300 3350
F 0 "J1" H 5355 3817 50  0000 C CNN
F 1 "USB_B_Micro" H 5355 3726 50  0000 C CNN
F 2 "Connector_USB:USB_Micro-B_Molex_47346-0001" H 5450 3300 50  0001 C CNN
F 3 "~" H 5450 3300 50  0001 C CNN
	1    5300 3350
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:PRTR5V0U2X D1
U 1 1 5B62BD6A
P 7700 3550
AR Path="/5B62BD6A" Ref="D1"  Part="1" 
AR Path="/5B626331/5B62BD6A" Ref="D1"  Part="1" 
F 0 "D1" H 7850 3900 50  0000 L CNN
F 1 "PRTR5V0U2X" H 7850 3200 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-143" H 7760 3550 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/PRTR5V0U2X.pdf" H 7760 3550 50  0001 C CNN
	1    7700 3550
	1    0    0    -1  
$EndComp
$EndSCHEMATC
