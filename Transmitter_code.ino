#include <SPI.h>
#include <LoRa.h>

#define ss 10  // Chip Select Pin for LoRa Module
#define rst 9  // Reset Pin for LoRa Module
#define dio0 2  // Interrupt Pin for LoRa Module

byte localAddress = 0xBB;      // address of this device
byte destination = 0xFF;      // destination to send to

int flameSensorPin = 6; // Digital pin for flame sensor
int waterFlowSensorPin = A1; // Analog pin for water flow sensor
int mq2SensorPin = 7; // Analog pin for MQ-2 sensor

void setup() {
  Serial.begin(115200);

  // Initialize LoRa
  LoRa.setPins(ss, rst, dio0);
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}
void loop() {
  // Read sensor data
  int flameValue = digitalRead(flameSensorPin);
  int waterFlowValue = analogRead(waterFlowSensorPin);
  int mq2Value = digitalRead(mq2SensorPin);

  // Convert sensor readings to boolean values
  bool flameDetected = (flameValue == 1);
  bool waterFlowDetected = (waterFlowValue > 300); // Adjust threshold as needed
  bool gasDetected = (mq2Value == 0);
  Serial.println(flameDetected);
  Serial.println(waterFlowDetected);
  Serial.println(gasDetected);
  // Send boolean data via LoRa
  sendData(flameDetected, waterFlowDetected, gasDetected);

  delay(5000); // Adjust delay as needed
}

void sendData(bool flameDetected, bool waterFlowDetected, bool gasDetected) {
  // Prepare the data to send via LoRa
  String dataToSend;
  String dataToSendd;
  String dataToSenddd;
  if (flameDetected) {
    dataToSend = "Flame Detected "; // Set bit 0 if flame detected
  }
  if (waterFlowDetected) {
    dataToSendd = "Oil Detected "; // Set bit 1 if water flow detected
  }
  if (gasDetected) {
    dataToSenddd = "Gas Detected "; // Set bit 2 if gas detected
  }

  // Send data via LoRa
  LoRa.beginPacket();
  LoRa.write(destination); // add destination address
  LoRa.write(localAddress); // add sender address
  LoRa.print(dataToSend);
  LoRa.print(dataToSendd);
  LoRa.print(dataToSenddd);// add payload
  LoRa.endPacket();

  Serial.print("Data sent via LoRa: ");
  Serial.println(dataToSend);
  Serial.println(dataToSendd);
  Serial.println(dataToSenddd);// Print data sent for debugging
}
