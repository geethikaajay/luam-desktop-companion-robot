#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// ===== OLED SPI PINS (YOUR WIRING) =====
#define OLED_CLK   18
#define OLED_MOSI  23
#define OLED_CS    5
#define OLED_DC    4
#define OLED_RST   2

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  OLED_MOSI,
  OLED_CLK,
  OLED_DC,
  OLED_RST,
  OLED_CS
);

// ---------- FACE HELPERS ----------

void drawMouth(int cx, int y) {
  display.drawPixel(cx - 4, y, SSD1306_WHITE);
  display.drawPixel(cx - 3, y + 1, SSD1306_WHITE);
  display.drawPixel(cx - 2, y + 2, SSD1306_WHITE);
  display.drawPixel(cx - 1, y + 3, SSD1306_WHITE);
  display.drawPixel(cx,     y + 3, SSD1306_WHITE);
  display.drawPixel(cx + 1, y + 2, SSD1306_WHITE);
  display.drawPixel(cx + 2, y + 1, SSD1306_WHITE);
  display.drawPixel(cx + 3, y, SSD1306_WHITE);
}

void drawOpenEyes() {
  display.clearDisplay();

  int centerX = 64;
  int eyeY = 26;

  // LEFT EYE
  display.fillCircle(centerX - 20, eyeY, 7, SSD1306_WHITE);
  display.drawLine(centerX - 25, eyeY - 10, centerX - 29, eyeY - 14, SSD1306_WHITE);
  display.drawLine(centerX - 20, eyeY - 11, centerX - 20, eyeY - 16, SSD1306_WHITE);
  display.drawLine(centerX - 15, eyeY - 10, centerX - 11, eyeY - 14, SSD1306_WHITE);

  // RIGHT EYE
  display.fillCircle(centerX + 20, eyeY, 7, SSD1306_WHITE);
  display.drawLine(centerX + 15, eyeY - 10, centerX + 11, eyeY - 14, SSD1306_WHITE);
  display.drawLine(centerX + 20, eyeY - 11, centerX + 20, eyeY - 16, SSD1306_WHITE);
  display.drawLine(centerX + 25, eyeY - 10, centerX + 29, eyeY - 14, SSD1306_WHITE);

  drawMouth(centerX, 44);
  display.display();
}

void drawClosedEyes() {
  display.clearDisplay();

  int centerX = 64;
  int eyeY = 26;

  display.fillRoundRect(centerX - 27, eyeY, 14, 4, 2, SSD1306_WHITE);
  display.fillRoundRect(centerX + 13, eyeY, 14, 4, 2, SSD1306_WHITE);

  drawMouth(centerX, 44);
  display.display();
}

// ---------- SETUP ----------

void setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC)) {
    while (true);
  }

  display.setRotation(0);   // upright
  drawOpenEyes();
}

// ---------- LOOP ----------

void loop() {
  delay(3000);      // eyes open 3 sec
  drawClosedEyes(); // blink
  delay(150);       // blink duration
  drawOpenEyes();
}
