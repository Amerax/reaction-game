# reaction-game
Arduino reaction game, 2 player

Hello this is my project of reaction time. It's a 2 player game. 

Basically it features two buttons, and a light with a buzzer. When the light turns on the players must try to hit the button before the other player asap. 

This is to see who is faster and records their reaction time with a millisecond value which is displayed on the OLED screen. 

The game is very fun and has multiple pitched buzzer noises so it's not just a plain buzzer. The OLED screen also includes any instructions you might need. 

There is also a false start mechanic, that catches if someone presses the button before the light actually turns on. It automatically makes the other the winner, so no cheating. 

Anyone can build it with these components:

Arduino Uno 1 Breadboard 1 Push Buttons 2 220Ω Resistor 1 LED 1 Passive Buzzer 1 SSD1306 OLED Display (I2C) 1 Jumper Wires (A handful)

Pin Map: 
Player 1 Button	D2
Player 2 Button	D3
LED	D8
Passive Buzzer	D9
OLED SDA	A4
OLED SCL	A5
OLED VCC	5V
OLED GND	GND

Libaries Used:

<Wire.h>
<Adafruit_GFX.h>
<Adafruit_SSD1306.h>

Demo Link: https://youtu.be/O9YidcGFL84

Complete Build Image:

<img width="1206" height="1035" alt="image" src="https://github.com/user-attachments/assets/49921334-1115-462e-9055-f52d21de15c2" />


<img width="210" height="196" alt="image" src="https://github.com/user-attachments/assets/d6f77ead-e900-45f5-b3df-f6468fcf56ac" />
