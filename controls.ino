// Sets the pin numbers for each light
#define LED_PIN1 13
#define LED_PIN2 12
#define LED_PIN3 11
#define LED_PIN4 10

// BAUD 9600 listens for keyboard input
#define BAUD 9600

// Allows the ability to make pointers to void, no parameter functions
typedef void (*FunctionPointer)();

// Defines a dict-like struct. Has a key, the character, and the function it will execute
typedef struct {
  const char key;
  FunctionPointer func;
} DictionaryEntry;

// Initializes pins and starts listening for serial inputs
void setup() {
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
  pinMode(LED_PIN4, OUTPUT);

  Serial.begin(BAUD);
}

// Just turns an LED on or off in one line. Made into a function for reusability
void toggleLED(int pin) {
  digitalWrite(pin, digitalRead(pin) == HIGH  ? LOW : HIGH);
}

// Functions called by keyboard inputs
void moveForward() {
  toggleLED(LED_PIN1);
}

void moveLeft() {
  toggleLED(LED_PIN2);
}

void moveBackward() {
  toggleLED(LED_PIN3);
}

void moveRight() {
  toggleLED(LED_PIN4);
}

// Maps controls to their functions
DictionaryEntry controls[] = {
  {'w', moveForward},
  {'a', moveLeft},
  {'s', moveBackward},
  {'d', moveRight}
};

// Dynamically determines how many controls there are
const int numControls = sizeof(controls) / sizeof(controls[0]);


void loop() {
  // This statement ensures it doesn't read an empty character
  if (Serial.available() > 0) {
    char receivedChar = Serial.read();

    // Looks through the list of controls, and if a match is found, executes its function
    for (int i = 0; i < numControls; i++) {
      if (receivedChar == controls[i].key) {
        controls[i].func();
      }
    }
  }
}
