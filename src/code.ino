#include <Wire.h>
#include <LiquidCrystal_I2C.h> #include <string.h>

// LCD Setup
LiquidCrystal_I2C lcd(0x27, 20, 4); // 20x4 LCD at I2C address 0x27

// Pin Definitions
#define RED_BUTTON 4 // Menu selection/letter swapping #define GREEN_BUTTON 5 // Hints
#define SKIP_BUTTON 9 // Question skipping #define POT_PIN A0  // Potentiometer #define BUZZER 6 // Buzzer
#define RED_LED 7 // Wrong answer #define GREEN_LED 8  // Correct answer

// Game Constants
const int TOTAL_ROUNDS = 3;

// Word Banks
char animals[][6] = {"TIGER", "ZEBRA", "SHARK", "HORSE", "EAGLE", "SNAKE", "WHALE", "OTTER", "ROBIN", "PANDA"};
char countries[][6] = {"INDIA", "CHILE", "EGYPT", "QATAR", "ITALY", "JAPAN", "YEMEN", "SUDAN", "SPAIN", "GHANA"};

// Global Variables int category = -1;
char correctWord[6]; char scrambledWord[6]; int cursorPos = 0;
int selectedPos = -1; bool hintUsed = false; int score = 0;
int roundNum = 0;
bool usedWords[10] = {false}; // Track used words (10 is the max number of words in each category)

// Function Prototypes void showWelcomeScreen();
void showMenu(); void chooseCategory(); void playGame();
void updateDisplay(); void handleUserInput();
void moveLetter(int from, int to);
void scrambleWord(const char* input, char* output); void correctAnswer();
void skipQuestion(); void showFinalScore();
void resetUsedWords(); // Function to reset used words

// Setup
void setup() { lcd.init(); lcd.backlight();

pinMode(RED_BUTTON, INPUT_PULLUP); pinMode(GREEN_BUTTON, INPUT_PULLUP); pinMode(SKIP_BUTTON, INPUT_PULLUP); pinMode(BUZZER, OUTPUT); pinMode(RED_LED, OUTPUT); pinMode(GREEN_LED, OUTPUT);

randomSeed(analogRead(A1)); showWelcomeScreen();
}

void loop() { showMenu();
}

// Welcome Screen void showWelcomeScreen() { lcd.clear();
lcd.setCursor(0, 0); lcd.print("WELCOME TO"); lcd.setCursor(0, 2); lcd.print("SCRAMBLEBOX"); delay(2000);
}

// Simplified Main Menu void showMenu() {
lcd.clear();
lcd.print("PRESS RED BUTTON");
lcd.setCursor(0, 2); lcd.print("TO START GAME");

while (true) {
if (digitalRead(RED_BUTTON) == LOW) { delay(300);
chooseCategory(); break;
}
}
}

// Category Selection void chooseCategory() {
lcd.clear(); lcd.print("CATEGORIES:"); lcd.setCursor(0, 2); lcd.print("ANIMALS (Red)"); lcd.setCursor(0, 3); lcd.print("COUNTRIES (Green)");

while (true) {
if (digitalRead(RED_BUTTON) == LOW) { category = 0;
lcd.clear();
lcd.print("ANIMALS SELECTED");
delay(2000); playGame(); break;
}
if (digitalRead(GREEN_BUTTON) == LOW) { category = 1;
lcd.clear();
lcd.print("COUNTRIES SELECTED");
delay(2000); playGame(); break;
}
}
}

// Reset Used Words void resetUsedWords() {
for (int i = 0; i < 10; i++) {
usedWords[i] = false; // Reset all used words
}
}

// Gameplay
void playGame() { score = 0;
resetUsedWords(); // Reset used words at the start of the game

for (roundNum = 0; roundNum < TOTAL_ROUNDS; roundNum++) { int idx;
bool wordSelected = false;

// Select a random word that hasn't been used while (!wordSelected) {
idx = random(0, category == 0 ? sizeof(animals) / sizeof(animals[0]) : sizeof(countries) / sizeof(countries[0]));
if (!usedWords[idx]) {
usedWords[idx] = true; // Mark this word as used wordSelected = true; // A valid word has been selected
}
}

// Copy the selected word and scramble it
strcpy(correctWord, category == 0 ? animals[idx] : countries[idx]); scrambleWord(correctWord, scrambledWord);

cursorPos = 0;
selectedPos = -1; hintUsed = false;

while (true) { updateDisplay(); handleUserInput();

if (digitalRead(SKIP_BUTTON) == LOW) { skipQuestion();
break;
}

if (strcmp(scrambledWord, correctWord) == 0) { correctAnswer();
delay(1000); break;
}
}
}
showFinalScore();
}

// Improved Cursor Handling void updateDisplay() {
lcd.clear(); lcd.print(scrambledWord);
// Ensure cursor stays within word bounds
cursorPos = constrain(cursorPos, 0, strlen(scrambledWord)); // Adjusted to allow cursor to reach the last position
lcd.setCursor(cursorPos, 1); lcd.print("^");
}

void handleUserInput() {
static int lastPotValue = -1; // Store the last potentiometer value int potVal = analogRead(POT_PIN);

// Map the potentiometer value to the range of the scrambled word length
cursorPos = map(potVal, 0, 1023, 0, strlen(scrambledWord)); // Ensure it maps to the full length

// Only update cursor position if the potentiometer value has changed significantly if (abs(potVal - lastPotValue) > 10) { // Adjust the threshold as needed
cursorPos = constrain(cursorPos, 0, strlen(scrambledWord)); // Adjusted to allow cursor to reach the last position
lastPotValue = potVal; // Update the last potentiometer value
}


if (digitalRead(RED_BUTTON) == LOW) { delay(300);
if (selectedPos == -1) { selectedPos = cursorPos;
} else if (cursorPos != selectedPos) { moveLetter(selectedPos, cursorPos); selectedPos = -1;

}
}

if (digitalRead(GREEN_BUTTON) == LOW && !hintUsed) { hintUsed = true;
lcd.setCursor(0, 2); lcd.print("FIRST LETTER: "); lcd.print(correctWord[0]); delay(2000);
}
}

// Letter Movement void moveLetter(int from, int to) { char temp = scrambledWord[from]; if (from < to) {
for (int i = from; i < to; i++) { scrambledWord[i] = scrambledWord[i + 1];
}
} else {
for (int i = from; i > to; i--) { scrambledWord[i] = scrambledWord[i - 1];
}
}
scrambledWord[to] = temp;
}

// Word Scrambling
void scrambleWord(const char* input, char* output) { strcpy(output, input);
for (int i = 0; i < strlen(output); i++) { int j = random(strlen(output));
char temp = output[i]; output[i] = output[j]; output[j] = temp;
}
}

// Skip Functionality void skipQuestion() { digitalWrite(RED_LED, HIGH); tone(BUZZER, 500, 300);
delay(300); noTone(BUZZER);
