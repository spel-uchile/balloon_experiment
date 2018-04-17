#include <RHReliableDatagram.h>
#include <SPI.h>
#include <RH_RF22.h>

#define CLIENT_ADDRESS 1
#define SERVER_ADDRESS 2

static const int SDN = 4;
double Tb, P, a, Th, H, yaw, pitch, roll;
uint8_t packet[12];
uint8_t from;
uint8_t len;
int tmp;

// Singleton instance of the radio driver.
RH_RF22 driver(2,3);

// Class to manage message delivery and receipt, using the driver declared above.
RHReliableDatagram rf22(driver, SERVER_ADDRESS);

void setup() {
    Serial.begin(115200);
    pinMode(SDN, OUTPUT);
    digitalWrite(SDN, LOW);
    delay(1500);
    if (!rf22.init()) {
        Serial.println(F("Initialization failed"));
    }
    Serial.println(F("Unidirectional test (RX)"));
    driver.setCRCPolynomial(driver.CRC_CCITT);
    driver.setHeaderFlags(0x7E); 
    driver.setFrequency(437.225, 0.05); 
    driver.setTxPower(RH_RF22_TXPOW_20DBM);
    if (!driver.setModemConfig(driver.FSK_Rb2Fd5)) {
        Serial.println(F("Configuration error"));    
    }
    rf22.setRetries(3);
    Serial.println(F("Set Tx Power = RH_RF22_TXPOW_20DB"));
    Serial.println(F("Set configuration = FSK_Rb2Fd5")); 
}

void loop() {
    receivePacket();
}
/**
 * The packet is received and displayed on screen.
 */
void receivePacket() {
    if (rf22.available()) {
        len = sizeof(packet);
        if (rf22.recvfromAck(packet, &len, &from)) {
            decodePacket();
            displayInfo();
        }
    }
}

void decodePacket() {
    tmp = packet[0];
    tmp = (tmp << 8) + packet[1];
    Tb = tmp/100.0;
    
    tmp = packet[2];
    tmp = (tmp << 8) + packet[3];
    tmp = (tmp << 8) + packet[4];
    P = tmp/100.0;

    tmp = packet[5];
    tmp = (tmp << 8) + packet[6];
    tmp = (tmp << 8) + packet[7];
    a = tmp/100.0;
    
    tmp = packet[8];
    tmp = (tmp << 8) + packet[9];
    Th = tmp/100.0;

    tmp = packet[10];
    tmp = (tmp << 8) + packet[11];
    H = tmp/100.0;

    tmp = packet[12];
    tmp = (tmp << 8) + packet[13];
    yaw = tmp/100.0;

    tmp = packet[14];
    tmp = (tmp << 8) + packet[15];
    pitch = tmp/100.0;

    tmp = packet[16];
    tmp = (tmp << 8) + packet[17];
    roll = tmp/100.0;
}

void displayInfo() {
    //Serial.print(F("Got request from : 0x"));
    //Serial.print(from, HEX);
    Serial.print("BMP180 temperature (C): ");
    Serial.print(Tb);
    Serial.print("    BMP180 pressure (hPa): ");
    Serial.print(P);
    Serial.print("    BMP180 altitude (m): ");
    Serial.print(a);
    Serial.print("      HTU21D temperature (C): ");
    Serial.print(Th);
    Serial.print("      HTU21D humidity (%): ");
    Serial.print(H);
    Serial.print("      yaw (deg): ");
    Serial.print(yaw);
    Serial.print("      pitch (deg): ");
    Serial.print(pitch);
    Serial.print("      roll (deg): ");
    Serial.println(roll);
}
