/* 
  This easy sketch pulses each color of the LED, smoothly brightening and darkening each color in sequence. It’s like the normal Blink sketch but has a lot more pizzazz!
  
  Retrieved from: https://web.archive.org/web/20151206212142/http://legacy.punchthrough.com/bean/examples/rgb-led-pulse
    
  This example code is in the public domain.
*/

void setup() {
    // initialize serial communication at 57600 bits per second:
    Serial.begin(57600);
}
 
// the loop routine runs over and over again forever:
void loop() {
    for (int i = 0; i < 128; i += 2) {
        Bean.setLed(0,0,i);
        delay(1);
    }
    for (int i = 128; i > 0; i -= 2) {
        Bean.setLed(0,0,i);
        delay(1);
    }
    Bean.setLed(0,0,0);
    Bean.sleep(1000);
    for (int i = 0; i < 128; i += 2) {
        Bean.setLed(0,i,0);
        delay(1);
    }
    for (int i = 128; i > 0; i -= 2) {
        Bean.setLed(0,i,0);
        delay(1);
    }
    Bean.setLed(0,0,0);
    Bean.sleep(1000);
    for (int i = 0; i < 128; i += 2) {
        Bean.setLed(i,0,0);
        delay(1);
    }
    for (int i = 128; i > 0; i -= 2) {
        Bean.setLed(i,0,0);
        delay(1);
    }
    Bean.setLed(0,0,0);
    Bean.sleep(3000);
}