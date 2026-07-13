#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Pins
const int PLAYER1 = 2;
const int PLAYER2 = 3;
const int LED = 8;
const int BUZZER = 9;

void setup() {
  pinMode(PLAYER1, INPUT_PULLUP);
  pinMode(PLAYER2, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(LED, LOW);

  randomSeed(analogRead(A0));

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.display();

  startScreen();
}

void loop() {
  // this waits, it starts the game when button is pressed
  while (digitalRead(PLAYER1) == HIGH && digitalRead(PLAYER2) == HIGH)
    ;

  delay(300);

  // this is just the default waiting screen 
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Reaction Game");
  display.println();
  display.println("Wait...");
  display.display();

  unsigned long waitTime = random(2000, 6001);
  unsigned long startTime = millis();

  // Random waiting period
  while (millis() - startTime < waitTime) {
    if (digitalRead(PLAYER1) == LOW) {
      falseStart(1);
      return;
    }

    if (digitalRead(PLAYER2) == LOW) {
      falseStart(2);
      return;
    }
  }

// the go press screen 
  digitalWrite(LED, HIGH);
  tone(BUZZER, 1500, 100);

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("GO!");
  display.display();

  unsigned long reactionStart = millis();

  while (true) {
    if (digitalRead(PLAYER1) == LOW) {
      playerWon(1, millis() - reactionStart);
      return;
    }

    if (digitalRead(PLAYER2) == LOW) {
      playerWon(2, millis() - reactionStart);
      return;
    }
  }
}

void startScreen() {
    digitalWrite(LED, LOW);
    noTone(BUZZER);

    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Reaction Game");
    display.println();
    display.println("Press a button");
    display.println("to start");
    display.display();
  }

  void playerWon(int player, unsigned long reaction) {
    digitalWrite(LED, LOW);
    tone(BUZZER, 2000, 250);

    display.clearDisplay();
    display.setCursor(0, 0);

    if (player == 1)
      display.println("Player 1 Wins!");
    else
      display.println("Player 2 Wins!");

    display.print("Time: ");
    display.print(reaction);
    display.println(" ms");

    display.display();

    delay(3000);

    startScreen();
  }

// this is for when the player presses button before light lights up
 void falseStart(int player) {
    digitalWrite(LED, LOW);

    for (int i = 0; i < 3; i++) {
      tone(BUZZER, 300, 150);
      delay(200);
    }

    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("False Start!");
    display.println();

    if (player == 1)
      display.println("Player 2 Wins!");
    else
      display.println("Player 1 Wins!");

    display.display();

    delay(3000);

    startScreen();
  }

