/*
 Name:		LcdSteering.ino
 Created:	29.12.2021 21:49:50
 Author:	Stefan
*/

// the setup function runs once when you press reset or power the board
#include <LiquidCrystal.h>
constexpr int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
constexpr int  switch_pin = 6;

int switchState = 0;
int prevSwitchState = 0;
int reply;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String reihe = "                ";
int satz_laenge;
char zeichen;
void setup() {
	lcd.begin(16, 2);
	pinMode(switch_pin, INPUT);
	lcd.print("Frage die");
	lcd.setCursor(0, 1);
	lcd.print("Kritsallkugel");
}
void printMarquee(int line, String iLine, LiquidCrystal lcd)
{

	for (int i = 0; i < iLine.length() + 16; i++) {
		for (int j = 0; j < 15; j++) {
			zeichen = reihe.charAt(j + 1);
			reihe.setCharAt(j, zeichen);
		}
		zeichen = ' ';
		if (i < iLine.length()) {
			zeichen = iLine.charAt(i);
		}
		reihe.setCharAt(15, zeichen);
		lcd.setCursor(0, line);
		lcd.print(reihe);
		delay(250);
	}
}
// the loop function runs over and over again until power down or reset
void loop() {
	switchState = digitalRead(switch_pin);
	if (switchState != prevSwitchState)
	{
		if (switchState == LOW)
		{
			reply = random(8);
			lcd.clear();
			lcd.noAutoscroll();
			lcd.setCursor(0, 0);
			lcd.print("Die Kugel sagt:");
			switch (reply)
			{
			case 0:

				printMarquee(1, "ja", lcd);
				break;
			case 1:
				printMarquee(1, "gaaanz bestimmt", lcd);
				break;
			case 2:
				printMarquee(1, "Klar", lcd);
				break;
			case 3:
				printMarquee(1, "Ohh nooo", lcd);
				break;
			case 4:
				printMarquee(1, "Unklar", lcd);
				break;
			case 5:
				printMarquee(1, "verstehe ich nich", lcd);
				break;
			case 6:
				printMarquee(1, "wer will das wissen", lcd);
				break;
			case 7:
				printMarquee(1, "Niemals", lcd);
				break;
			}
		}
	}
	prevSwitchState = switchState;

}
