/*
 Name:		LcdSteering.ino
 Created:	29.12.2021 21:49:50
 Author:	Stefan
*/

// the setup function runs once when you press reset or power the board
// ReSharper disable CppClangTidyClangDiagnosticSignCompare
#include <LiquidCrystal.h>
constexpr int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
constexpr int  switch_pin = 6;

int switchState = 0;
int prevSwitchState = 0;
int reply;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String empty_row = "                ";
int string_length;
char character_sel;
void setup() {
	lcd.begin(16, 2);
	pinMode(switch_pin, INPUT);
	lcd.print("Frage die");
	lcd.setCursor(0, 1);
	lcd.print("Kritsallkugel");
}
void printMarquee(const int line, const String& i_line, LiquidCrystal internal_lcd)
{

	for (int i = 0; i < i_line.length() + 16; i++) {
		for (int j = 0; j < 15; j++) {
			character_sel = empty_row.charAt(j + 1);
			empty_row.setCharAt(j, character_sel);
		}
		character_sel = ' ';
		if (i < i_line.length()) {
			character_sel = i_line.charAt(i);
		}
		empty_row.setCharAt(15, character_sel);
		internal_lcd.setCursor(0, line);
		internal_lcd.print(empty_row);
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
			lcd.print("Wer sagt:");
			switch (reply)
			{
			case 0:

				printMarquee(1, "Ja", lcd);
				break;
			case 1:
				printMarquee(1, "Gaaanz bestimmt", lcd);
				break;
			case 2:
				printMarquee(1, "Klar doch", lcd);
				break;
			case 3:
				printMarquee(1, "Ohh nooo", lcd);
				break;
			case 4:
				printMarquee(1, "Unklar", lcd);
				break;
			case 5:
				printMarquee(1, "Verstehe ich nich...", lcd);
				break;
			case 6:
				printMarquee(1, "Wer will das wissen", lcd);
				break;
			case 7:
				printMarquee(1, "Niemals, no never ever", lcd);
				break;
			}
		}
	}
	prevSwitchState = switchState;

}
