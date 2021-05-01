#include <dht.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <IRremote.h>


int recvPin = 8; // IR Receiver - Arduino Pin Number 8
int redPin = 9; // RED Output Pin
int greenPin = 11; // GREEN Output Pin
int bluePin = 6; // BLUE Output Pin
int intensity = 10; // Intensity variable
int speedValue = 5; // Speed Variable
int currentColors[] = {0, 0, 0}; // Current Color outputed variable (black by default)
bool customLoop = false; // Variable telling us we are in a custom animation loop

unsigned long previousMillis = 0; // variable for the delay function

LiquidCrystal_I2C lcd(0x27, 16, 2);
IRrecv irrecv(recvPin);
decode_results results;
dht DHT;

#define DHT11_PIN 7
#define fan 5

// Defining hex codes for the remote
#define ON_CODE           0xF7C03F
#define OFF_CODE          0xF740BF
#define INTENSITY_UP_CODE 0xF700FF
#define INTENSITY_DN_CODE 0xF7807F
#define RED_CODE          0xF7A05F
#define GREEN_CODE        0xF720DF
#define BLUE_CODE         0xF7609F
#define WHITE_CODE        0xF7E01F
#define ORANGE_CODE       0xF7B04F
#define TURQUOISE_CODE    0xF710EF 
#define NAVY_CODE         0xF7708F
#define BROWN_CODE        0xF7A857 //light orange
#define TEAL_CODE         0xF730CF
#define PURPLE_DARK_CODE  0xF750AF 
#define ORANGE_LIGHT_CODE 0xF708F7
#define BLUE_LIGHT_CODE   0xF76897
#define PINK_DARK_CODE    0xF7906F
#define YELLOW_CODE       0xF728D7
#define BLUE_BABY_CODE    0xF748B7
#define PINK_CODE         0xF78877


// defining the avaialble colors one by one
int BLACK_COLOR[3] = {0, 0, 0};
int RED_COLOR[3] = {255, 0, 0};
int GREEN_COLOR[3] = {0, 255, 0};
int BLUE_COLOR[3] =  {0, 0, 255};
int WHITE_COLOR[3] = {255, 255, 255};
int ORANGE_COLOR[3] = {255, 99, 0};
int TURQUOISE_COLOR[3] = {0, 255, 21};
int NAVY_COLOR[3] = {0, 76, 153};
int BROWN_COLOR[3] = {153, 140, 0};
int TEAL_COLOR[3] = {0, 202, 225};
int PURPLE_DARK_COLOR[3] = {48, 0, 130};
int ORANGE_LIGHT_COLOR[3] = {255, 100, 0};
int BLUE_LIGHT_COLOR[3] = {0, 123, 159};
int PINK_DARK_COLOR[3] = {255, 0, 128};
int YELLOW_COLOR[3] = {255, 255, 0};
int BLUE_BABY_COLOR[3] = {0, 104, 145};
int PINK_COLOR[3] = {255, 102, 178};

// defining all the available remote codes in an array
int AVAILABLE_CODES[24] = {ON_CODE, OFF_CODE, INTENSITY_UP_CODE, INTENSITY_DN_CODE, RED_CODE, GREEN_CODE, BLUE_CODE, WHITE_CODE, ORANGE_CODE, TURQUOISE_CODE, NAVY_CODE, BROWN_CODE, TEAL_CODE, PURPLE_DARK_CODE, ORANGE_LIGHT_CODE, BLUE_LIGHT_CODE, PINK_DARK_CODE, YELLOW_CODE, BLUE_BABY_CODE, PINK_CODE};

// defining all the available colors in an array
int AVAILABLE_COLORS[16][3] = {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, {255, 99, 0}, {0, 255, 21}, {0, 76, 153}, {153, 140, 0}, {0, 202, 225}, {48, 0, 130}, {255, 100, 0}, {0, 123, 159}, {255, 0, 128}, {255, 255, 0}, {0, 104, 145}, {255, 102, 178}} ;

int redVal = 0;
int grnVal = 0;
int bluVal = 0;

int prevR = redVal;
int prevG = grnVal;
int prevB = bluVal;

byte degree[8] =
{
  0b00011,
  0b00011,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};


void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  lcd.createChar(1, degree);
  lcd.clear();
  lcd.print("   Fan Speed  ");
  lcd.setCursor(0, 1);
  lcd.print("  Controlling ");
  delay(2000);
  analogWrite(fan, 255);
  lcd.clear();
}

// function for interpreting the incoming code and eighter setting a fixed color or starting a custom loop function
void interpretRemoteCode(int code) {
  int randomColor[3] = {random(256), random(256), random(256)};
  switch (code) {
    case ON_CODE: setColor(randomColor); break;
    case OFF_CODE: setColor(BLACK_COLOR); break;
    case RED_CODE: setColor(RED_COLOR); break;
    case GREEN_CODE: setColor(GREEN_COLOR); break;
    case BLUE_CODE: setColor(BLUE_COLOR); break;
    case WHITE_CODE: setColor(WHITE_COLOR); break;
    case ORANGE_CODE: setColor(ORANGE_COLOR); break;
    case TURQUOISE_CODE: setColor(TURQUOISE_COLOR); break;
    case NAVY_CODE: setColor(NAVY_COLOR); break;
    case BROWN_CODE: setColor(BROWN_COLOR); break;
    case TEAL_CODE: setColor(TEAL_COLOR); break;
    case PURPLE_DARK_CODE: setColor(PURPLE_DARK_COLOR); break;
    case ORANGE_LIGHT_CODE: setColor(ORANGE_LIGHT_COLOR); break;
    case BLUE_LIGHT_CODE: setColor(BLUE_LIGHT_COLOR); break;
    case PINK_DARK_CODE: setColor(PINK_DARK_COLOR); break;
    case YELLOW_CODE: setColor(YELLOW_COLOR); break;
    case BLUE_BABY_CODE: setColor(BLUE_BABY_COLOR); break;
    case PINK_CODE: setColor(PINK_COLOR); break;
  }
}

// raise the intensity of light or the speed of animation
void raiseIntensity() {
  if (!customLoop) {
    if (intensity <= 9) {
      intensity++;
    }
  } else if (speedValue <= 9) {
    speedValue++;
  }
}

// lower the intensity of light or the speed of animation
void lowerIntensity() {
  if (!customLoop) {
    if (intensity >= 2) {
      intensity--;
    }
  } else if (speedValue >= 2) {
    speedValue--;
  }
}

// set the currentColors variable
void setColor(int colors[]) {
  currentColors[0] = colors[0];
  currentColors[1] = colors[1];
  currentColors[2] = colors[2];
}

// calculate the intensity and send the current color out via the output pins
void sendColor()
{
  if (customLoop == false) {
    int red = currentColors[0];
    int green = currentColors[1];
    int blue = currentColors[2];

    int mappedIntensity = map(intensity, 0, 10, 0, 255);
    int redComputed = map(red, 0, 255, 0, mappedIntensity);
    int blueComputed = map(blue, 0, 255, 0, mappedIntensity);
    int greenComputed = map(green, 0, 255, 0, mappedIntensity);

    analogWrite(redPin, redComputed); // Sends PWM signal to the Red pin
    analogWrite(greenPin, greenComputed);
    analogWrite(bluePin, blueComputed);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.backlight();
  unsigned long currentMillis = millis(); // check for a code from the remote every 100 milliseconds
  lcd.setCursor(0, 0);
fanControl();
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
   if (currentMillis - previousMillis >= 100) {
      previousMillis = currentMillis;
     findCode();
    } 
    
    
  delay(2000);
  
  

}
// helper function to check if a value is present in an array
int existsInArray(int compareValue, int arrayName[], int arraySize) {
  for (int x = 0; x < arraySize; x = x + 1) {
    if (arrayName[x] == compareValue) {
      return true;
    }
  }
  return false;
}

// decode remote controll code and if found in the array of available codes interpret it
void findCode() {
  if (irrecv.decode(&results)) {
    if (existsInArray(results.value, AVAILABLE_CODES, 24)) {
      Serial.println("Code Found");
      interpretRemoteCode(results.value);
        customLoop = false;
        sendColor();
     
    } else {
      Serial.println("Invalid Code");
    }
    irrecv.resume();
  }
}


// Controls the fan
void fanControl() {
  int randomColor[3] = {random(256), random(256), random(256)};
  DHT.read11(DHT11_PIN);
  int temp = DHT.temperature;
  int Temp = DHT.temperature *1.8+32 ;
  
  lcd.print("Temp:");
  lcd.print(Temp );   // Printing temperature on LCD
  lcd.write(1);
  lcd.print("F");
  lcd.setCursor(0, 1);  
  
 
  if (temp < 25 )
  {
    analogWrite(5, 0);
    lcd.print("Fan OFF            ");
   setColor(randomColor);
   sendColor();
    delay(100);
  }

  else if (temp == 25)
  {
    analogWrite(fan, 51);
    lcd.print("Fan Speed: 20%   ");
    setColor(BLUE_LIGHT_COLOR);
    sendColor();
    delay(100);
  }

  else if (temp == 26)
  {
    analogWrite(fan, 102);
    lcd.print("Fan Speed: 40%   ");
    setColor(TEAL_COLOR);
    sendColor();
    delay(100);
  }

  else if (temp == 27)
  {
    analogWrite(fan, 153);
    lcd.print("Fan Speed: 60%   ");
    setColor(GREEN_COLOR);
    sendColor();
    delay(100);
  }

  else if (temp == 28)
  {
    analogWrite(fan, 204);
    lcd.print("Fan Speed: 80%    ");
    setColor(PINK_COLOR);
    sendColor();
    delay(100);
  }
  else if (temp > 28)
  {
    analogWrite(fan, 255);
    lcd.print("Fan Speed: 100%   ");
    setColor(RED_COLOR);
    sendColor();
    delay(100);
  }
  delay(3000);
}
