#include <user_config.h>
#include "user_display.h"
#include "../user-libraries/Adafruit_GFX/Adafruit_GFX.h"
#include "../user-libraries/Adafruit_SSD1306/Adafruit_SSD1306.h"



//#define //Serialprintln os_printf

/*
 * Hardware SPI mode:
 * GND      (GND)         GND
 * VCC      (VCC)         3.3v
 * D0       (CLK)         GPIO14
 * D1       (MOSI)        GPIO13
 * RES      (RESET)       GPIO16
 * DC       (DC)          GPIO0
 * CS       (CS)          GPIO2
 */
// For spi oled module
Adafruit_SSD1306 display(0, 16, 2);

//* For I2C mode:
// Default I2C pins 0 and 2. Pin 4 - optional reset
// Adafruit_SSD1306 display(4);


void display_demo2(void)
{
	//Serialprintln("Display: some text");
	display.clearDisplay();
	// text display tests
	display.setTextSize(1);
	display.setTextColor(WHITE);
	display.setCursor(0,0);
//	display.println("Sming Framework");
	display.setTextColor(BLACK, WHITE); // 'inverted' text
	display.setCursor(104, 7);
//	display.println("v1.0");
	//----
	display.setTextColor(WHITE);
//	display.println("Let's do smart things");
	display.setTextSize(3);
//	display.print("IoT");
	display.display();
//	DemoTimer.stop();      // Finish demo
}

void display_demo1(void)
{
        //Serialprintln("Display: circle");
	// Clear the buffer.
	display.clearDisplay();
	// draw a circle, 10 pixel radius
	display.fillCircle(display.width()/2, display.height()/2, 10, WHITE);
	display.display();
}

void display_init(void)
{

	//Serialprintln("Display: start");
	display.begin(SSD1306_SWITCHCAPVCC);
	display.display();
}	
