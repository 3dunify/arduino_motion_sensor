/**
 * Arduino Motion Sensor 
 *(https://github.com/3dunify/arduino_motion_sensor) 
 * Developed By 3DUnify (https://www.3dunify.in/)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <ESP8266WiFi.h>
#define BLYNK_PRINT Serial       
#include <BlynkSimpleEsp8266.h>
char auth[] = "Your-35-Character-Code";

/* WiFi credentials */
char ssid[] = "Your-WiFi-Name";
char pass[] = "Your-Password";

/* HC-SR501 Motion Detector */
#define pirPin 5                // D1 Pin on the NodeMCU.
int pirValue;                   
int pinValue;                  

BLYNK_WRITE(V0)
{
 pinValue = param.asInt();    
} 

void setup()
  {
    Serial.begin(115200);
    delay(10);
    Blynk.begin(auth, ssid, pass);
    pinMode(pirPin, INPUT);
  }

void loop()
  {
     if (pinValue == HIGH)    
      {
        getPirValue();
      }
    Blynk.run();
  }

void getPirValue(void)        //Get PIR Data
  {
   pirValue = digitalRead(pirPin);
    if (pirValue) 
     { 
       Serial.println("Motion detected");
       Blynk.notify("Motion detected");  
     }
  }
