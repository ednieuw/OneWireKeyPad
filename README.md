# 1x3 and 4x3 membrane keypad controlled with one wire to the analog pin

Quick and dirty copied from my web site:
https://ednieuw.home.xs4all.nl/Woordklok/OneWireKeyPad/OneWireKeyPad.html



<table style="width: 900px">
	<tr>
		<td>This page describes how to wire the output pins of a:<br />
		<br />
		- seven 
pins, 3 columns * 4 rows key pad <br />
		<br />
		<br />
		and a <br />
		</span></span></td>
		<td><img alt="keypad" height="200" src="pics/3x4keypaddwars.jpg" /></td>
	</tr>
	<tr>
		<td>
- four pins three button 3 x 1 keypad, <br />
		<br />
		to a 
one wire analogue output. </span></o:p>
		</td>
		<td><img alt="keypad 3b" height="100" src="pics/3Button.jpg" /></td>
	</tr>
</table>
<br />
The addition of a few resistors converts the key pads to one wire and saves 
many digital pins at the cost one analogue pin.<br />
Libraries are not needed anymore and will save many memory bytes but lacking 
interrupt driven detection of operation of the key pad. <br />
But processors are very fast and in many programs it is possible to check the 
buttons more than 1000 times a second.<br />
The three button key pad is a nice, flat, replacement of a rotary encoder saving 
three digital pins, a library and 1500 bytes.</p>
<br />
Three different resistor resistances are used.<br />
This page:
<a href="http://www.circuitbasics.com/how-to-set-up-a-keypad-on-an-arduino/">
http://www.circuitbasics.com/how-to-set-up-a-keypad-on-an-arduino/</a>
explains how the key pad works.<br />
<br />
There are many tutorials how to make a one-key wire keypad but or they use many 
resistors, make use of libraries or are hard to follow.</p>
<p class="MsoNormal">
<table style="width: 1000px">
	<tr>
		<td class="auto-style2">In the picture on the right one can see that by 
		pressing a button a connection is made between a row and a column. <br />
		By choosing the right resistor combination the output will be different 
		for every button. <br />
		5V is connected to C1 and ground after a 1.1 kilo-ohm resistor.<br />
		When 3 is pressed the current flows from R1 tot C3 and flows to a 1.1 
		kilo-ohm resistor resulting in a reading of 989 bits. <br />
		Pressing * R4 and C1 and connected resulting in a flow through all the 
		resistors and a reading of 125 bits.<br />
		To discriminate between the buttons the difference between the 
		difference button must be as large as possible.<br />
		Because resistors of identical resistance value will not have exact the 
		same resistance measured, readings between modules will vary a little. 
		In the Arduino source code the range per button is large enough to 
		overcome these differences. </td>
		<td class="auto-style2">
		<img alt="Analogue readings" height="342" src="Exceldata.png" width="280" /></td>
		<td><img alt="Keys" height="342" src="3x4keypadbuttonsk.jpg" />&nbsp;</td>
	</tr>
	<tr>
		<td class="auto-style2" colspan="3">&nbsp;</td>
	</tr>
</table>
<span lang="EN-GB" style="mso-ansi-language: EN-GB">
<o:p><span class="auto-style2"><br />
</span></o:p>
</span></p>
<table width="1000">
	<tr>
		<td>
		<img alt="3x4 Keypad" class="auto-style2" height="429" src="Arduino-Keypad-3X4-Pin-Diagram.jpg" width="222" /></td>
		<td style="width: 887px">
		<img alt="Module" height="429" src="Module.jpg" /></td>
	</tr>
	<tr>
		<td class="auto-style2"><br />
		Source code<br />
		<a href="OneWireKeyPad/OneWireKeyPad.ino">OneWireKeyPad.ino</a></td>
		<td class="auto-style2" style="width: 887px">
		<a href="OneWireKeyPad.fzz">OneWireKeyPad.fzz</a> Fritzing file<br />
		<br />
		Below the source code to read the key values</td>
	</tr>
</table>
<ul>
	<li>
	<pre>int sensorPin = A0;   // select the input pin for the potentiometer
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
 if(keyvalue&lt;13) { Serial.println(keyvalue); delay(300); }
 digitalWrite(ledPin, LOW);   // turn the ledPin off:
}</pre>
	</li>
</ul>
<p class="MsoNormal" style="width: 908px"><span lang="EN-GB" style="mso-ansi-language: EN-GB">
<o:p><span class="auto-style2"><br />
<o:p><strong>3 X 1 key pad<br />
<br />
</strong>I use this key pad instead of a rotary encoder.
<table style="width: 900px">
	<tr>
		<td colspan="2"><span lang="EN-GB" style="mso-ansi-language: EN-GB">
		<span class="auto-style2"><a href="3-button-OneWire.jpg">
		<img alt="PCB" class="auto-style3" height="120" src="3-button-OneWire.jpg" /></a></span></span><a href="3-Button.jpg"><img alt="3-button" class="auto-style3" height="120" src="3-Button.jpg" /></a></td>
	</tr>
	<tr>
		<td>
		<img alt="Read bits" height="139" src="Readbits3x1keypad.jpg" width="328" /></td>
		<td><a href="3-button-OneWire.jpg">
		<img alt="PCB" height="211" src="3-button-OneWire.jpg" width="514" /></a></td>
	</tr>
	<tr>
		<td>&nbsp;</td>
		<td>&nbsp;</td>
	</tr>
	<tr>
		<td>Source code: <a href="OneWireKeyPad3x1/OneWireKeyPad3x1.ino">
		OneWireKeyPad3x1.ino</a></td>
		<td>&nbsp;</td>
	</tr>
</table>
<br />
</o:p>
</span>
</o:p>
</span></p>
<pre>                           
//--------------------------------------------
// KEYPAD check for Onewire Keypad input with 5V and 1.1, 4.7, 4.7, 4.7 kOhm resistors
//--------------------------------------------
int sensorPin = A0;   // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
char keyvalue;
char Key;
 </pre>
<pre>void setup() 
{
 pinMode(ledPin, OUTPUT);   // declare the ledPin as an OUTPUT:
 Serial.begin(9600); 
 Serial.println("Started. Press a key");
}</pre>
<pre>void loop() 
{
 sensorValue = analogRead(sensorPin); // read the value from the sensor:
 switch(sensorValue)
  {
    case   0 ... 385:  keyvalue = 99;            break;            // noise
    case 386 ... 635:  keyvalue = -1; Key = 'G'; break;            // G 
    case 636 ... 910:  keyvalue =  0; Key = 'Y'; break;            // Y 
    case 911 ... 1023: keyvalue =  1; Key = 'R'; break;            // R 
  }
 if(keyvalue&lt;2) 
   { 
    Serial.print(Key); Serial.print("  Read bits:"); Serial.println(sensorValue);
    digitalWrite(ledPin, HIGH);          // turn the ledPin on
    delay(300); 
    digitalWrite(ledPin, LOW);           // turn the ledPin off:
   }
}</pre>
<pre>
                          </pre>
<p class="MsoNormal"><span lang="EN-GB" style="mso-ansi-language: EN-GB">
<o:p>
<o:p></o:p>
<br class="auto-style2" />
<span class="auto-style2"><a href="FibonacciClockV039.zip">FibonacciClock 
software V039 + libraries for one wire 4x3 keypad</a></span></o:p></span></p>
<p class="MsoNormal">
<o:p>
</o:p>
</p>
<p class="MsoNormal">
<o:p><font face="Verdana, Arial, Helvetica, sans-serif">Ed Nieuwenhuys, 
	July 2022, March 2021<br />
<span class="auto-style4">November</span><o:p><span class="auto-style4"> 
        2019</span></font></o:p></o:p></p>

<p class="MsoNormal"><font face="Verdana, Arial, Helvetica, sans-serif">
	<a href="../index.html">&lt; --
        Back to start </a></font></p>

