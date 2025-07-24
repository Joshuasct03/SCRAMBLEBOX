# SCRAMBLEBOX
DESCRIPTION: 
The ScrambleBox mini project is an Arduino-based Word Jumble Game. It is an interactive project that challenges players to unscramble words using an Arduino microcontroller. It features a user-friendly interface with buttons for input, a display for showing scrambled words, and scoring based on performance, making it an engaging educational tool for enhancing vocabulary skills. The ScrambleBox Word Jumble Game is an innovative educational project designed to enhance vocabulary and cognitive skills through interactive gameplay. Utilizing an Arduino microcontroller, the game presents players with scrambled words that they must decipher within a limited number of attempts. Key Features include user interaction, A dynamic scoring system, visual and sound feedback and a unique word scrambling logic. This project not only serves as a fun activity but also as a practical application of programming and electronics, making it suitable for educational settings and hobbyist exploration.

HARDWARE: 
Power Adapter, Arduino Uno, 20x4 LCD, Buzzer (CC1206AN), LEDs, Resistors, Potentiometer, Momentary push buttons, I2C Module, Breadboard, Jumper Wires, Hookup wires, Soldering Iron, Solder, Wire Cutters, Strippers, Multimeter, Forex Sheet.

FEATURES:
Core Game Logic: Arduino Uno effectively manages game logic, user inputs, and controls display, LEDs, and buzzer.
Clear Display: 20x4 LCD with I2C provides clear visibility for scrambled words, hints, and score updates.
Intuitive Input: Button interface enables seamless word selection, letter swapping, and hint requests. Potentiometer allows precise cursor control for letter manipulation.
Dynamic Gameplay: Randomization algorithm ensures unique scrambled words per round; scoring system rewards performance. Words are not repeated within a session.
Enhanced User Feedback: LED and buzzer alerts provide real-time confirmation of actions and correct answers.
Reliable Operation: Consistent and stable performance without crashes; hardware components and power supply functioned as expected under various test conditions.
Assistive Hint System: Effectively helps players progress through the game.

HOW TO PLAY:
To play ScrambleBox, power on the device and press the Red Button to start. Choose a category—Animals (Red Button) or Countries (Green Button). A scrambled word will appear on the LCD. Use the rotary potentiometer to move the cursor across the letters. To swap letters, select the first letter with the Red Button, move the cursor, and press the Red Button again to swap. If you're stuck, press the Green Button to reveal a hint—the first letter of the correct word. You can skip the current word anytime using the Skip Button. For each correct answer, you’ll earn 2 points, or 1 point if a hint was used. After 3 rounds, your total score is displayed. Reset and replay to improve your score and vocabulary!

REFERENCES: 
1.	Word Jumble Logic by Hari Wiguna: https://github.com/hwiguna/HariFun_180_Word_Jumble
2.	Arduino Forum on String Manipulation: https://forum.arduino.cc/t/string- manipulation/1262560
3.	Arduino. (n.d.). Arduino Reference. Retrieved from https://www.arduino.cc/reference/en/
4.	Youngkwon Bae, Jinsook Lim and Taewuk Lee, "Work in progress - a study on educational computer games for e-learning based on activity theory," Proceedings Frontiers in Education 35th Annual Conference, Indianopolis, IN, USA, 2005, pp. F1C- 18, doi: 10.1109/FIE.2005.1612004. keywords: {Game theory;Electronic learning;Computer science education;Educational activities;Humans;Internet;Visualization;Educational  institutions;Activity theory;Educational computer games;Game learning}
5.	Instructables and Hackster.io. (n.d.). Various projects and tutorials related to Arduino and game development. Retrieved from https://www.instructables.com/ and https://www.hackster.io/
6.	K. Sitdhisanguan, N. Chotikakamthorn, A. Dechaboon and P. Out, "Evaluation the Efficacy of Computer - Based Training Using Tangible User Interface for Low-Function Children with Autism," 2008 Second IEEE International Conference on Digital Game and Intelligent Toy Enhanced Learning, Banff, AB, Canada, 2008, pp. 70-74, doi: 10.1109/DIGITEL.2008.28. keywords:  {Computer interfaces;User interfaces;Autism;Pediatrics;Medical treatment;Shape;Virtual reality;Information technology;Hospitals;Application  software;Tangible  user interface;Autism;Evaluation;Training;Interaction Technique}
