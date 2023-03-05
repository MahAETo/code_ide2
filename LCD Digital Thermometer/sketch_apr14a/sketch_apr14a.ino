
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int degree;
double realDegree;
String lcdBuffer;
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  degree = 0;
  realDegree = 0;
  lcd.print("Today's temp:");
  // Print a message to the LCD.
  
}

void loop(){
  lcd.print("                ");
  degree = analogRead(0);
  realDegree = (double)degree/1024;
  realDegree *= 5;
  realDegree -= 0.5;
  realDegree *= 100;
  lcd.setCursor(0,1);
  realDegree = (9.0/5)*(realDegree) + 32;
  String output = String(realDegree) + String((char)178) + "F";
  lcd.print(output);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
}
