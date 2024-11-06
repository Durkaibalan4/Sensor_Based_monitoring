# Sensor-Based Monitoring System for the Oil and Gas Industry

 ![niral photo](https://github.com/user-attachments/assets/21308042-9ffc-46e0-8c59-94a775ba6dc7)

## Problem Statement

The oil and gas industry faces significant risks due to potential explosions. Developing a reliable explosion risk detection system that can effectively identify potential threat zones and issue early warnings to nearby workers is essential for safety.

## Project Overview

This project focuses on building a monitoring system that integrates various sensors and communication modules to detect explosion risks and monitor critical parameters in oil and gas pipelines. The system aims to identify threats such as gas leaks, flame detection, and abnormal pressure changes, issuing early warnings for preventive action.

## Components Used

- **Microcontroller**: Arduino Mega 2560
- **Communication Module**: ESP8266
- **Sensors**:
  - MQ2 Sensor (Gas detection)
  - MQ135 Sensor (Air quality)
  - Flame Sensor (Fire detection)
  - Pressure Sensor (Pressure monitoring)
  - Water Flow Sensor (Flow rate monitoring)
- **Communication Link**: LoRa Transmitter and Receiver
- **Additional Equipment**:
  - Pipes for oil and gas flow simulation
   

## Requirement Gathering and Setup

1. **Research and Problem Identification**:
   - Analyzed industry challenges and identified explosion risk as a significant issue.
   - Gathered information on components suitable for detecting potential risks.

2. **Components Integration**:
   - Interfaced sensors with the Arduino Mega 2560.
   - Connected pressure and water flow sensors to analog pins for threshold settings.
   - Connected MQ2, MQ135, and flame sensors to digital pins to detect active conditions.

3. **Communication Integration**:
   - Linked the LoRa transmitter to the Arduino Mega 2560 for transmitting sensor data.
   - Connected the LoRa receiver to the ESP8266 module to enable data monitoring over a mobile device or server via SSID and password.

## Prototype Setup

1. **Sensor Placement**:
   - Mounted sensors on a board and connected them to the Arduino Mega 2560.
   - Installed pressure sensors in holes made on the pipe to monitor pressure changes.
   - Integrated a water flow sensor in the flow path for excess flow detection.

2. **Testing and Monitoring**:
   - Flowed water through the pipe to simulate oil and gas flow.
   - Monitored sensor outputs through the ESP8266, validating functionality.

## System Functionality

- **Gas Detection**: MQ2 and MQ135 sensors detect gas leaks and monitor air quality.
- **Fire Detection**: Flame sensor identifies potential fire incidents.
- **Pressure Monitoring**: Pressure sensor tracks changes to ensure they remain within safe limits.
- **Flow Monitoring**: Water flow sensor detects anomalies in flow rate.

## Future Enhancements

- Incorporate additional safety mechanisms like automated shut-off valves.
- Enhance data logging and alert systems with cloud integration.
- Extend monitoring to handle different environmental conditions for broader applicability.

## Conclusion

This prototype demonstrates a comprehensive approach to detecting explosion risks in the oil and gas industry using cost-effective sensors and communication modules. It provides a framework for early warnings and safer work environments.

---

**Developed with Arduino IDE and tested in a simulated environment.**
<img width="960" alt="Screenshot 2024-06-28 145600" src="https://github.com/user-attachments/assets/5f9967b6-75ed-48b9-adb5-b33ac83728d4">

![Schematic Design](https://github.com/user-attachments/assets/43403eb3-fc0d-4c70-bd18-1a6aaa893ff0)

![Layout](https://github.com/user-attachments/assets/fd9fe7d8-c709-4ea1-b6fe-ebac44c7e666)

![3D view](https://github.com/user-attachments/assets/4a92a978-e336-455b-81db-ce768e52194e)
