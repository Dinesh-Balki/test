n#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET    -1  // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int insideTemp = 24;  // Example temperature inside
int outsideTemp = 29; // Example temperature outside
int humidity = 64;    // Example humidity percentage

void setup() {
  // Initialize OLED display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();
}

void loop() {
  display.clearDisplay();

  // Display temperature inside
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print(F("Temp."));
  display.setCursor(0, 10);
  display.print(F("inside: "));
  display.print(insideTemp);
  display.print(F(" C"));

  // Display temperature outside
  display.setCursor(0, 20);
  display.print(F("outside: "));
  display.print(outsideTemp);
  display.print(F(" C"));

  // Display humidity
  display.setCursor(0, 35);
  display.print(F("Humidity: "));
  display.print(humidity);
  display.print(F(" %"));

  // Draw weather icon
  display.drawCircle(105, 15, 10, SSD1306_WHITE); // sun icon
  display.drawLine(105, 5, 105, 25, SSD1306_WHITE);
  display.drawLine(95, 15, 115, 15, SSD1306_WHITE);

  // Refresh display
  display.display();
  delay(2000);
}
