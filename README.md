# Temp-controled-LED-and-Fan
Project for ECE 455

Material:
-	9-volt battery *2
-	16x2 Lcd Display
-	5V 2004 16x2 Lcd Display IIC I2C Adapter 
-	9v battery clip connector
-	Mosfet *3
-	DHT11 Temperature Sensor
-	2N2222 Transistor
-	IR Receiver VS1838B
-	220 Olms Resistor
-	Jumper Wires
-	2 small Bread Boards


Software: Arduino 1.9.0 beta
https://www.arduino.cc/en/software 



List of Libraries
-	IRremote .h
-	LiquidCrystal_I2C.h
-	dht.h
-	Wire.h

Steps:
1. Occur all materials 
2. Start by taking 1 small breadboard, LED string, Mofettes, Resistors, jumper wires, 9v battery, IR sensor, Arduino, Battery clip. 
3. add the Mofettes(With the metal side as the front) and IR sensor to the breadboard. 
4. Then, Connect the resistors to the right pin of each MOSFET using the breadboard. Then connect a jumper wire to the same row as the end of the resistor on the breadboard (Make sure the two ends are not on the same row or utils the two sections in the breadboard). Then connect the other end of the jumper wire to the Arduino. You can use any pin for this except for pin 8, which will be used for the IR sensor. These pins will be used for the LED's color. In this case, I used pins 9(red), 11(green), and 6(blue). Write down which pins you use. You will need to change the code for those pins.
5. Connect the middle pins of the Mofettes to a jumper wire then to the coordination pins on the LED. Then Connect the left pin to a jumper wire, then connect to the ground(Utilize the + and - rows for ground). Connect whichever row you plan to use as the ground to the ground pin on the battery and the Arduino. 
6. For the power to the LED, uses the second set of +- columns and use one to connect the positive side of the battery. You can do this by using jumper wires and a battery clip connector, and the breadboard. Then connect a jumper wire to the power pin to the LED strip. 
7. For the IR Sensor the connect it to the breadboard. The sensor I am using is a 3 pin sensor. The correct pin is the signal pin; you will need to connect the same row as that pin to a jumper wire then connect the other end to the Arduino in pin 8. The reason for this is that the Library used for the IR sensor defaults to pin 8. So if you try to use other pins, you will need to go into the Library and change the pin location of the sensor. Next, you will need to connect the middle pin of the sensor to the column on the board that is being used for the ground. Then you will want to take a jumper cable and connect one end to the 5v power supply of the Arduino. Then you will want to connect the other end of the jumper wire to the other column( not the one used for ground, you can fry your board if you connect the two). For later, you will want to connect that same column to another column on the other breadboard. 
8. For the temperature sensor. We will need the following: DHT11 Temperature Sensor, jumper wire, and the Arduino. The Temperature sensor I am using a 3 pin sensor that uses + , out and -. You will need to connect the sensor to the 5v power supply connection from the same breadboard from steps 7. Then you will need to connect a jumper cable to the same row used for pinout, connect the other end of the wire to a pin numbered pin on the Arduino. I used pin 7; make sure to write down the PIN you will need to change the DHT11_pin in the code. Next, you will need to take a jumper cable, connect the 2nd ground on the Arduino and connect it to the other column on the arduino. Finally, connect a jumper cable from the column to the same row that the - pin is connected to. 
9. To connect the LED display, you may need to solder the 5V 2004 16x2 Lcd Display IIC I2C Adapter to the 16x2 Lcd Display. Make sure the pins line up correctly. Then you will take 3 females to the male jumper wire, connect the female side to the IIC I2C Adapter, then take the wire connected to SCL and connect it to the pin on the Arduino labels SCL. They do the same for the SDA pins. Then for the fine pin connect, use the females to male jumper wire and connect the male end to the same column used for the 5v Arduino power on the 2nd breadboard. 
10. Finally, connecting the Fan, you will need the following: 2pin Fan, 9v battery, 2nd breadboard, Transistor, and jumper wires. Connect the battery to the battery connector clip, then use the second set of +- columns of the second breadboard and connect the + end of the battery to one column. Then you will connect the ground to the same column on the breadboard that the Arduino's ground is connected to.  Next, connect the Transistor to the breadboard. If the round side is the front of the Transistor, connect the middle pin to the numbered pin on the Arduino. In this case, I use pin 5. Write down which pin you use; you will need to change the code later. Connect the left pin to the ground on the breadboard(ground that the Arduino is connected to). Then connect the correct pin to the ground pin on the Fan using jumper wires, and finally connect the power pin on the Fan to the same column at the 9v power from the 2nd battery.
11. After connect everything is connected correctly and that the device is working 



Tips when building
1.	Build and test the LED and IR sensor 1st this can take a while to make sure it is working. 
2.	Build and test the LCD display, temperature sensor and fan. This does will not take long as long as you have IIC I2c adapter because this will simplify the circuit down and you will not need as may resistors and the LCD Display will connect much quicker
3.	Note that the two batteries are used for only the fan and LED strip. 
4.	Depending the on the Fan is used depends on which wires are the ground, power, and possibly single. In this case the speed is depended on the

References Links used to help connect everything:
RGB Strip
-	https://www.instructables.com/DIY-Arduino-RGB-LED-Strip-IR-Controller/ 
-	https://www.youtube.com/watch?v=upuhM59AFPk 

LCD Screen 
-	 https://www.youtube.com/watch?v=9Zb9Ywj-4Xg
-	https://www.youtube.com/watch?v=B8DNokj9LnY
-	https://www.instructables.com/I2C-LCD-Controller-the-easy-way/ 
Temperature Sensor
-	 https://www.circuitbasics.com/how-to-set-up-the-dht11-humidity-sensor-on-an-arduino/
-	https://forum.arduino.cc/t/dht-celsius-to-fahrenheit-conversion/167330/4 

Connecting DC Fan
-	https://circuitdigest.com/microcontroller-projects/automatic-temperature-controlled-fan-project
-	https://landing.coolermaster.com/faq/3-pin-and-4-pin-fan-wire-diagrams/
About the Arduino Board
-	https://forum.arduino.cc/index.php?topic=22676.0 
About Library
-	IRremote .h
https://github.com/Arduino-IRremote/Arduino-IRremote/releases
-	LiquidCrystal_I2C.h
LiquidCrystal is the library used for the LCD display. The _I2C version is for the LCD Display with a I2C adaptor attached to a 2*16 LCD Display.
-	dht.h
DHT is the general Library for 
-	Wire.h

 
 Libraries
-	IRremote.h 
https://github.com/Arduino-IRremote/Arduino-IRremote/releases
-	LiquidCrystal_I2C.h
-	Wire.h
-	dht.h

Work Citations (Resources)
Arduino mega I2C LCD TUTORIAL. (2019, October 02). Retrieved April 18, 2021, from https://www.youtube.com/watch?v=9Zb9Ywj-4Xg
BorisD23, & Instructables. (2018, June 06). DIY Arduino RGB led STRIP IR Controller. Retrieved April 18, 2021, from https://www.instructables.com/DIY-Arduino-RGB-LED-Strip-IR-Controller/
Cooler master FAQ. (n.d.). Retrieved April 18, 2021, from https://landing.coolermaster.com/faq/3-pin-and-4-pin-fan-wire-diagrams/
Dusnoki. (2018, February 25). DIY Arduino Rgb 12v led STRIP IR Controller PCB design, build, Soldering, programming guide. Retrieved April 18, 2021, from https://www.youtube.com/watch?v=upuhM59AFPk
How to connect an I2C lcd display to an arduino MEGA 2560. (2018, January 13). Retrieved April 18, 2021, from https://www.youtube.com/watch?v=B8DNokj9LnY
How to set up THE dht11 humidity sensor on an Arduino. (2020, July 15). Retrieved April 18, 2021, from https://www.circuitbasics.com/how-to-set-up-the-dht11-humidity-sensor-on-an-arduino/
System. (2011, January 19). Can I use THE powerpins to power my Arduino? Retrieved April 18, 2021, from https://forum.arduino.cc/index.php?topic=22676.0
Verdelj, & Instructables. (2017, October 23). I2C LCD controller (the easy way). Retrieved April 18, 2021, from https://www.instructables.com/I2C-LCD-Controller-the-easy-way/
VirusTotal. (n.d.). Retrieved April 18, 2021, from https://www.virustotal.com/gui/file/62e625ff93a5f5c6954439c504ceeed7a4e107e27085bbb931238c167cb8e137/detection


