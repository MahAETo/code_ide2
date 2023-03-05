/* This code works with Sim800L and a push button
 * Press the button to send a simple SMS/Text to a specified phone number
 * Refer to www.SurtrTech.com for more details 
 */

#include <SoftwareSerial.h>

SoftwareSerial sim800l(2, 3); // RX,TX for Arduino and for the module it's TXD RXD, they should be inverted

int IRSensor = 4;
int led =5;



void setup()
{
 
  pinMode (IRSensor, INPUT); //The button is always on HIGH level, when pressed it goes LOW
  sim800l.begin(9600);   //Module baude rate, this is on max, it depends on the version
  Serial.begin(9600);   
  delay(1000);
  pinMode(led,OUTPUT);
}
 
void loop()
{
  

  int statusSensor = digitalRead (IRSensor);
 
  if (statusSensor == 0) {                                 
    SendSMS();
    delay(1000); 

    

 }
 
  if (sim800l.available()){            //Displays on the serial monitor if there's a communication from the module
    Serial.write(sim800l.read()); 
  }
}
 
void SendSMS()
{
  Serial.println("Sending SMS...");               //Show this message on serial monitor
  sim800l.print("AT+CMGF=1\r");                   //Set the module to SMS mode
  delay(100);
  sim800l.print("AT+CMGS=\"+201113852218\"\r");  //Your phone number don't forget to include your country code, example +212123456789"
  delay(500);
  sim800l.print("dokdok");       //This is the text to send to the phone number, don't make it too long or you have to modify the SoftwareSerial buffer
  delay(500);
  sim800l.print((char)26);// (required according to the datasheet)
  delay(500);
  sim800l.println();
  Serial.println("Text Sent.");
  delay(500);

}
 
