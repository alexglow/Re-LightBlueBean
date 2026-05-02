/* 
  This sketch cycles the RGB LED through the colors blue, green, red, and off forever.
    
  Retrieved from: https://web.archive.org/web/20151206204737/http://legacy.punchthrough.com/bean/examples/blink/
    
  This example code is in the public domain.
*/

void setup() {
    // initialize serial communication at 57600 bits per second:
    Serial.begin(57600);
}
 
// the loop routine runs over and over again forever:
void loop() {
    Bean.setLed(0,0,255);  // blue
    Bean.sleep(250);
    Bean.setLed(0,255,0);  // green
    Bean.sleep(250);
    Bean.setLed(255,0,0);  // red
    Bean.sleep(250);
    Bean.setLed(0,0,0);    // off
    Bean.sleep(3000);
}