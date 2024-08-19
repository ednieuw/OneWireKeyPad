int sensorPin = A0;   // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
char keyvalue;
char Key;
 
void setup() 
{
 pinMode(ledPin, OUTPUT);   // declare the ledPin as an OUTPUT:
 Serial.begin(9600); 
 Serial.println("Started. Press a key");
}

void loop() 
{
 sensorValue = analogRead(sensorPin); // read the value from the sensor:
 switch(sensorValue)
  {
    case   0 ... 385:  keyvalue = 99;            break;            // noise
    case 386 ... 635:  keyvalue = -1; Key = 'G'; break;            // G 
    case 636 ... 910:  keyvalue =  0; Key = 'Y'; break;            // Y 
    case 911 ... 1023: keyvalue =  1; Key = 'R'; break;            // R 
  }
 if(keyvalue<2) 
   { 
    Serial.print(Key); Serial.print("  Read bits:"); Serial.println(sensorValue);
    digitalWrite(ledPin, HIGH);          // turn the ledPin on
    delay(300); 
    digitalWrite(ledPin, LOW);   // turn the ledPin off:
   }
}
