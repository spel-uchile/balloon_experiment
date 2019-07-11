EESchema Schematic File Version 5
LIBS:OBC-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
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
L Sensor:BMP180-V2 U1
U 1 1 5D276284
P 5250 2300
F 0 "U1" H 5428 2346 50  0000 L CNN
F 1 "BMP180-V2" H 5428 2255 50  0000 L CNN
F 2 "Sensor:BMP180-V2" H 5200 2300 50  0001 C CNN
F 3 "" H 5200 2300 50  0001 C CNN
	1    5250 2300
	1    0    0    -1  
$EndComp
$Comp
L Sensor:MPU-9250-BREAKOUT-R U2
U 1 1 5D276755
P 5250 3000
F 0 "U2" H 5428 3046 50  0000 L CNN
F 1 "MPU-9250-BREAKOUT-R" H 5428 2955 50  0000 L CNN
F 2 "Sensor:MPU-9250-BREAKOUT-R" H 5100 2900 50  0001 C CNN
F 3 "" H 5100 2900 50  0001 C CNN
	1    5250 3000
	1    0    0    -1  
$EndComp
$Comp
L GPS:XA1110 U3
U 1 1 5D276C04
P 5400 3850
F 0 "U3" H 5400 4337 60  0000 C CNN
F 1 "XA1110" H 5400 4231 60  0000 C CNN
F 2 "GPS:XA1110" H 5100 3800 60  0001 C CNN
F 3 "" H 5100 3800 60  0001 C CNN
	1    5400 3850
	1    0    0    -1  
$EndComp
Text HLabel 4700 2150 0    50   Input ~ 0
3V3
Text HLabel 4700 2250 0    50   Input ~ 0
GND
Text HLabel 4700 2350 0    50   Input ~ 0
SCL
Text HLabel 4700 2450 0    50   Input ~ 0
SDA
Text HLabel 6100 3950 2    50   Input ~ 0
RX
Text HLabel 6100 4050 2    50   Input ~ 0
TX
Text Label 4700 2150 0    50   ~ 0
3V3
Text Label 4700 2250 0    50   ~ 0
GND
Text Label 4700 2350 0    50   ~ 0
SCL
Text Label 4700 2450 0    50   ~ 0
SDA
Text Label 4700 2850 0    50   ~ 0
SCL
Text Label 4700 2950 0    50   ~ 0
SDA
Text Label 4700 3050 0    50   ~ 0
3V3
Text Label 4700 3150 0    50   ~ 0
GND
Text Label 4700 3850 0    50   ~ 0
3V3
Text Label 4700 3750 0    50   ~ 0
GND
Text Label 6100 3950 2    50   ~ 0
RX
Text Label 6100 4050 2    50   ~ 0
TX
Wire Wire Line
	4700 2150 4900 2150
Wire Wire Line
	4900 2250 4700 2250
Wire Wire Line
	4700 2350 4900 2350
Wire Wire Line
	4900 2450 4700 2450
Wire Wire Line
	4900 2950 4700 2950
Wire Wire Line
	4700 2850 4900 2850
Wire Wire Line
	4900 3050 4700 3050
Wire Wire Line
	4700 3150 4900 3150
Wire Wire Line
	4700 3750 4900 3750
Wire Wire Line
	4700 3850 4900 3850
Wire Wire Line
	6100 3950 5900 3950
Wire Wire Line
	5900 4050 6100 4050
$EndSCHEMATC
