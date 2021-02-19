#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define SCREEN_ID 0x3C  // OLED display adress

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ID)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  // Clear the buffer
  display.clearDisplay();
  printText();
  delay(1500);
}

void loop() {
}

void printText() {
  display.clearDisplay();
  display.setTextSize(1);             // The fontsize
  display.setTextColor(WHITE);        // Draw white text
  
  display.setCursor(0, 0);           // Start at top-left corner
  display.print("Hello World");       //the text

  display.setCursor(0 , 10);
  display.print("My second line");

  display.setCursor(0 , 20);
  display.print("aaaaaaaaaaaaaaaaaaaab"); //21 max letters by line (6 px/char)
  
  display.display();                  //call to display
}
