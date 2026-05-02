/* 
  This example project uses a light sensor and a piezo speaker to generate a changing tone based on the amount of light sensed. More light causes the Bean to produce a higher-pitch tone and vice versa.
  
  Light sensor circuit:
  Phototransistor from GPIO 0 to A1 (short leg)
  1M ohm resistor from A1 to GND

  Speaker circuit:
  Piezo speaker from pin 2 to pin 5
  1K ohm resistor from pin 5 to GND

  Retrieved from: https://web.archive.org/web/20151220044948/http://legacy.punchthrough.com/bean/examples/theremin/
    
  This example code is in the public domain.
*/

#define BLEVEL 255
#define MINLEVEL 50

void setup()
{
    // initialize serial communication
    Serial.begin(57600);
    pinMode(0, OUTPUT);    //set D0 as output
    pinMode(2, OUTPUT);
    digitalWrite(0, LOW);   //turn it off initially
}

// the loop routine runs over and over again forever:
void loop()
{
    digitalWrite(0, HIGH);
    delay(10);
    int sensorValue = analogRead(A1);
    int r,g,b;
    if (sensorValue > MINLEVEL && sensorValue < BLEVEL + 1) {
        g = (sensorValue - MINLEVEL) / 2;
        b = 0;
    } else if (sensorValue > BLEVEL) {
        g = sensorValue - MINLEVEL;
        if (g > 255) {
            g = 255;
        }
        b = sensorValue - BLEVEL;
        if (b > 255) {
            b = 255;
        }
    } else {
        g = 0;
        b = 0;
    }
    Bean.setLed(0, g, b);
    tone(2, 300 + sensorValue * 10, 20);
}