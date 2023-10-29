// include the library code:
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};
byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);  // initialize LCD and set up the number of columns and rows.
  lcd.createChar(0, armsDown);
  lcd.createChar(1, armsUp);
}

void loop() {
  // put your main code here, to run repeatedly:
  //when people armsDown:
  for (int i = 7; i > -1; i--) {
    if (i % 2 == 0) {
      lcd.setCursor(i, 0);
      lcd.Write(byte(1));
      lcd.setCursor(15 - i, 0);
      lcd.Write(byte(1));
      delay(500);
      lcd.clear();
    } else {
      lcd.setCursor(i, 0);
      lcd.Write(byte(0));
      lcd.setCursor(15 - i, 0);
      lcd.Write(byte(0));
      delay(500);
      lcd.clear();
    }
  }
  //when people armsUp:
  for (int i = 0; i < 8; i++) {
    if (i % 2 == 0) {
      lcd.setCursor(i, 1);
      lcd.Write(byte(1));
      lcd.setCursor(15 - i, 1);
      lcd.Write(byte(1));
      delay(500);
      lcd.clear();
    } else {
      lcd.setCursor(i, 1);
      lcd.Write(byte(0));
      lcd.setCursor(15 - i, 1);
      lcd.Write(byte(0));
      delay(500);  //wait for a second
      lcd.clear();
    }
  }
}
