int sensorPin = A0;   // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
byte keyvalue;

void setup() 
{
 pinMode(ledPin, OUTPUT);   // declare the ledPin as an OUTPUT:
 Serial.begin(9600); 
 Serial.println("Started. Press a key");
}

void loop() 
{
 sensorValue = analogRead(sensorPin); // read the value from the sensor:
 digitalWrite(ledPin, HIGH);          // turn the ledPin on
 switch(sensorValue)
  {
    case   0 ... 100:  keyvalue = 13; break;   // noise
    case 101 ... 132:  keyvalue = 12; break;   // * 
    case 133 ... 154:  keyvalue =  0; break;   // 0 
    case 155 ... 216:  keyvalue = 11; break;   // # 
    case 217 ... 281:  keyvalue =  7; break;   // 7 
    case 282 ... 318:  keyvalue =  4; break;   // 4 
    case 319 ... 349:  keyvalue =  1; break;   // 1 
    case 350 ... 390:  keyvalue =  8; break;   // 8 
    case 391 ... 463:  keyvalue =  5; break;   // 5 
    case 464 ... 519:  keyvalue =  2; break;   // 2 
    case 520 ... 619:  keyvalue =  9; break;   // 9 
    case 620 ... 848:  keyvalue =  6; break;   // 6 
    case 849 ... 1023: keyvalue =  3; break;   // 3
  }
 if(keyvalue<13) { Serial.println(keyvalue); delay(300); }
 digitalWrite(ledPin, LOW);   // turn the ledPin off:
}
