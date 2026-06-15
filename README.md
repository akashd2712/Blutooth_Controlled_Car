# Bluetooth Controlled Car 🚗

## Overview
This project demonstrates a **Bluetooth-controlled car** with autonomous obstacle avoidance using an ultrasonic sensor and vibration motor feedback. The car uses an ESP32 microcontroller to manage motor control and wireless Bluetooth communication.

## Features
- 🎮 **Bluetooth Control**: Wirelessly control car movement via smartphone
- 🔊 **Obstacle Detection**: Ultrasonic sensor detects obstacles within 30cm
- 📳 **Haptic Feedback**: Vibration motors provide feedback for different actions
- ⚡ **4-Motor Drive**: Independent motor control for precise movement
- 🛑 **Autonomous Stopping**: Auto-stops when obstacle detected

## Components Used
- **Microcontroller**: ESP32
- **Motor Driver**: L298N (controls 4 motors)
- **Sensors**: HC-SR04 Ultrasonic Sensor
- **Actuators**: 4 DC Motors, 3 Vibration Motors
- **Communication**: Bluetooth Module (HC-05 or built-in ESP32 BLE)

## Pin Configuration
```
Ultrasonic Sensor:
- Trigger Pin: GPIO 4
- Echo Pin: GPIO 5

Vibration Motors:
- Left Motor: GPIO 27 (turns RIGHT)
- Right Motor: GPIO 14 (turns LEFT)
- Center Motor: GPIO 26 (stops)

Motor Driver (L298N):
- Motor A: GPIO 18, 19
- Motor B: GPIO 21, 22
```

## How It Works

### Motor Control
- **Move Forward**: All 4 motors rotate forward
- **Move Backward**: All 4 motors rotate backward
- **Turn Left/Right**: Differential motor speeds enable turning
- **Stop**: All motors halt

### Obstacle Avoidance
- Ultrasonic sensor continuously measures distance
- If distance > 30cm: Car moves forward
- If distance ≤ 30cm: Car stops and reverses
- Vibration motors indicate movement direction

### Bluetooth Commands
Control via serial Bluetooth commands from a smartphone app

## Code Structure
```cpp
setup()           // Initialize pins and sensors
loop()            // Main control logic
getDistance()     // Read ultrasonic sensor
moveForward()     // Forward movement
moveBackward()    // Backward movement
turnLeft()        // Left turn
turnRight()       // Right turn
stopAllMotors()   // Stop all motors
```

## Installation & Setup
1. Upload `BT_CAR.ino` to ESP32
2. Pair your smartphone via Bluetooth
3. Use a Bluetooth terminal app to send movement commands
4. Connect components according to pin configuration

## Usage
- Send serial commands via Bluetooth terminal
- Monitor distance readings on Serial Monitor
- Test autonomous obstacle avoidance

## Future Enhancements
- Add line-following sensor
- Implement app-based GUI control
- Add GPS navigation
- Temperature/humidity monitoring

## License
DIY Internship Project - Free to use for educational purposes
