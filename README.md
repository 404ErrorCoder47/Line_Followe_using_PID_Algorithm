# Line_Followe_using_PID_Algorithm
# 🤖 Line Follower Robot using Arduino

This project is an **Arduino-based Line Follower Robot** that uses IR sensors to detect and follow a black line on a white surface. It's a classic robotics project that helps beginners understand sensor input, motor control, and embedded programming using Arduino.

## 🧠 What It Does

- Detects a black line on a light surface using IR sensors.
- Controls two motors (left and right) to follow the path.
- Simple logic based on IR sensor readings to adjust direction.

## 📂 Project Structure

- `LineFollower.ino` – The main Arduino sketch with the logic for line following.

## ⚙️ Hardware Required

- 1x Arduino UNO (or compatible)
- 1x IR Sensors Array (left and right)
- 2x DC Motors with Motor Driver (e.g., L298N)
- Chassis with wheels
- Power source (batteries or USB)
- Jumper wires and breadboard 

## 🛠️ Circuit Diagram
- Left IR Sensor -> Arduino A0
- Right IR Sensor -> Arduino A1
- Left Motor -> Motor Driver Output 1 & 2
- Right Motor -> Motor Driver Output 3 & 4
- Motor Driver IN1/IN2/IN3/IN4 -> Arduino D3/D4/D5/D6

> You can adjust pin numbers in the code to match your setup.

## 🔌 Setup Instructions

1. Clone this repository or download the `.ino` file:
   ```bash
   github.com/404ErrorCoder47/Line_Followe_using_PID_Algorithm
2. Open LineFollower.ino in the Arduino IDE.

3. Connect your Arduino and select the correct board and port.

4. Upload the code to the Arduino.

5. Power your robot and place it on a line path to test.

🧠 Code Logic Summary
if (leftSensor detects black && rightSensor detects white)
    turn right
else if (leftSensor detects white && rightSensor detects black)
    turn left
else if (both sensors detect black)
    go forward
else
    stop

🧑‍💻 Author
+ Soumaditya Sengupta
+ Shaswata Pal
+ Sourodeep Hazra
+ soumadityasengupta@gmail.com
Feel free to connect and contribute!




