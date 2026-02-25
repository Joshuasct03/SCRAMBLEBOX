# 🎮 ScrambleBox – Arduino-Based Word Jumble Game Console

## Overview

**ScrambleBox** is an interactive Arduino-based word jumble game designed to improve vocabulary and cognitive skills through hands-on gameplay.

The system combines **embedded electronics and game logic** to create a standalone educational gaming console where players unscramble words using physical controls instead of a mobile or computer interface.

The project demonstrates practical applications of **Arduino programming, hardware interfacing, and user interaction design**.

---

## Project Demo

🎥 *Working demonstration video:*
![Demo](demo_video.mp4)

---

## Features

* Interactive word unscrambling gameplay
* Category selection (Animals / Countries)
* Randomized word scrambling algorithm
* Scoring system based on performance
* Hint mechanism for assisted gameplay
* LCD-based real-time display
* LED and buzzer feedback for user actions
* Potentiometer-controlled cursor movement
* Standalone hardware gaming console

---

## Hardware Architecture

![Circuit Diagram](circuit_diagram.png)

The system is centered around an **Arduino Uno**, which manages:

* Game logic execution
* Button inputs
* LCD display updates
* Audio and visual feedback

(Architecture and working principle described in project report .)

---

## Hardware Components

* Arduino Uno
* 20×4 LCD Display with I2C module
* Push buttons (Input controls)
* Potentiometer (Cursor control)
* LEDs (Status indication)
* Buzzer (Audio feedback)
* Resistors & Breadboard
* 12V Power Adapter

---

## How the Game Works

1. Power on the device.
2. Select a category using buttons.
3. A scrambled word appears on the LCD.
4. Move cursor using potentiometer.
5. Swap letters using button controls.
6. Use hint option if needed.
7. Score is calculated after multiple rounds.

The gameplay flowchart and system working are illustrated in the report diagrams (Chapter 3) .

---

## Repository Structure

```
SCRAMBLEBOX/
│
├── SCRAMBLEBOX.ino      # Arduino source code
├── CIRCUIT_DIAGRAM.png  # Hardware wiring diagram
├── README.md
└── LICENSE
```

---

## My Contributions

* Implemented Arduino game logic and interaction flow
* Integrated LCD display and input controls
* Developed word scrambling and scoring logic
* Hardware assembly and testing
* System debugging and validation

---

## Learning Outcomes

* Embedded system design using Arduino
* Hardware–software integration
* User interface design with physical controls
* Real-time input handling
* Educational game development concepts

---

## Academic Context

Developed as a **B.Tech Mini Project** in Electronics and Communication Engineering
Sree Chitra Thirunal College of Engineering, Thiruvananthapuram.

---

## Team

* Hashim S N
* Joshua Felix
* Muneera S

---

## License

MIT License — for academic and learning purposes.
