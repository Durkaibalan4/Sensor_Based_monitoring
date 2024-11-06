#include <ESP8266WiFi.h>
#include <SPI.h>
#include <LoRa.h>

#define ss 15  // D8 (GPIO 15)
#define rst 16  // D0 (GPIO 16)
#define dio0 4  // D2 (GPIO 4)

byte localAddress = 0xFF;      // address of this device
byte destination = 0xBB;      // destination to send to

void setup() {
  Serial.begin(115200);

  while (!Serial);

  Serial.println("LoRa Receiver Setup");

  LoRa.setPins(ss, rst, dio0);
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  // parse for a packet, and call onReceive with the result:
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    onReceive(packetSize);
  }
}

void onReceive(int packetSize) {
  if (packetSize == 0) return;          // if there's no packet, return

  // read packet header bytes:
  int recipient = LoRa.read();          // recipient address
  byte sender = LoRa.read();            // sender address
  byte incomingMsgId = LoRa.read();     // incoming msg ID
  byte incomingLength = LoRa.read();    // incoming msg length

  //--------------- Start receiving Sensor Data --------------------

  // received a packet
  Serial.print("Received packet:  ");
  String LoRaData = LoRa.readString();
  Serial.println(LoRaData);

  // Split the received data
  int pos1 = LoRaData.indexOf('/');
  int pos2 = LoRaData.lastIndexOf('/');

  String flameValueStr = LoRaData.substring(0, pos1);
  String waterFlowStr = LoRaData.substring(pos1 + 1, pos2);
  String gasValueStr = LoRaData.substring(pos2 + 1);

  // Convert string values to integers
  int flameValue = flameValueStr.toInt();
  int waterFlow = waterFlowStr.toInt();
  int gasValue = gasValueStr.toInt();

  // Process received data
  Serial.print("Flame Value: ");
  Serial.println(flameValue);
  Serial.print("Water Flow Value: ");
  Serial.println(waterFlow);
  Serial.print("Gas Value: ");
  Serial.println(gasValue);
}
