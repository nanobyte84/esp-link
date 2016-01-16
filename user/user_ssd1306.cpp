

#include "user_ssd1306.h"
#include "../user-libraries/SSD1306/SSD1306.h"
#include "../user-libraries/SSD1306/SSD1306Ui.h"
#include "images.h"



// Initialize the oled display for address 0x3c
// sda-pin=14 and sdc-pin=12
SSD1306   display(0x3c, 14, 2);
SSD1306Ui ui     ( &display );



bool msOverlay(SSD1306 *display, SSD1306UiState* state) {
  display->setTextAlignment(TEXT_ALIGN_RIGHT);
  display->setFont(ArialMT_Plain_10);
//  display->drawString(128, 0, String(millis()));
  return true;
}

bool drawFrame1(SSD1306 *display, SSD1306UiState* state, int x, int y) {
  // draw an xbm image.
  // Please note that everything that should be transitioned
  // needs to be drawn relative to x and y

  // if this frame need to be refreshed at the targetFPS you need to
  // return true
  display->drawXbm(x + 34, y + 14, WiFi_Logo_width, WiFi_Logo_height, WiFi_Logo_bits);
  return false;
}

bool drawFrame2(SSD1306 *display, SSD1306UiState* state, int x, int y) {
  // Demonstrates the 3 included default sizes. The fonts come from SSD1306Fonts.h file
  // Besides the default fonts there will be a program to convert TrueType fonts into this format
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
//  display->drawString(0 + x, 10 + y, "Arial 10");

  display->setFont(ArialMT_Plain_16);
//  display->drawString(0 + x, 20 + y, "Arial 16");

  display->setFont(ArialMT_Plain_24);
//  display->drawString(0 + x, 34 + y, "Arial 24");

  return false;
}

bool drawFrame3(SSD1306 *display, SSD1306UiState* state, int x, int y) {
  // Text alignment demo
  display->setFont(ArialMT_Plain_10);

  // The coordinates define the left starting point of the text
  display->setTextAlignment(TEXT_ALIGN_LEFT);
//  display->drawString(0 + x, 11 + y, "Left aligned (0,10)");

  // The coordinates define the center of the text
  display->setTextAlignment(TEXT_ALIGN_CENTER);
//  display->drawString(64 + x, 22, "Center aligned (64,22)");

  // The coordinates define the right end of the text
  display->setTextAlignment(TEXT_ALIGN_RIGHT);
//  display->drawString(128 + x, 33, "Right aligned (128,33)");
  return false;
}

bool drawFrame4(SSD1306 *display, SSD1306UiState* state, int x, int y) {
  // Demo for drawStringMaxWidth:
  // with the third parameter you can define the width after which words will be wrapped.
  // Currently only spaces and "-" are allowed for wrapping
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
//  display->drawStringMaxWidth(0 + x, 10 + y, 128, "Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore.");
  return false;
}


// this array keeps function pointers to all frames
// frames are the single views that slide from right to left
bool (*frames[])(SSD1306 *display, SSD1306UiState* state, int x, int y) = { drawFrame1, drawFrame2, drawFrame3, drawFrame4 };


// how many frames are there?
int frameCount = 4;

bool (*overlays[])(SSD1306 *display, SSD1306UiState* state)             = { msOverlay };
int overlaysCount = 1;





void ssd1306_init(void)
{
    ui.setTargetFPS(30);

    ui.setActiveSymbole(activeSymbole);
    ui.setInactiveSymbole(inactiveSymbole);

    // You can change this to
    // TOP, LEFT, BOTTOM, RIGHT
    ui.setIndicatorPosition(BOTTOM);

    // Defines where the first frame is located in the bar.
    ui.setIndicatorDirection(LEFT_RIGHT);

    // You can change the transition that is used
    // SLIDE_LEFT, SLIDE_RIGHT, SLIDE_TOP, SLIDE_DOWN
    ui.setFrameAnimation(SLIDE_LEFT);

    // Add frames
    ui.setFrames(frames, frameCount);

    // Add overlays
    ui.setOverlays(overlays, overlaysCount);

    // Inital UI takes care of initalising the display too.
    ui.init();

    display.flipScreenVertically();
}	


void ssd1306_demo1(void)
{
	  int remainingTimeBudget = ui.update();
}


void ssd1306_demo2(void)
{
}
