#include <DS3231.h>
#include <Wire.h>
#include <LedControl.h>

//MATRIX DISPLAY
LedControl lc = LedControl(8, 6, 7, 4);	//DIN, CLK, CS, count of displays

//RTC DS3231
byte second, minute, hour; //global variables
RTClib rtc;

// Object with the functions to set the time
//DS3231 setTime;

byte bright;

const uint64_t IMAGES[] = {
    0x0018242424241800,   // 0
    0x0010101014181000,   // 1
    0x003c041820241800,   // 2
    0x001c201038201c00,   // 3
    0x0010103c14181000,   // 4
    0x001c20201c043c00,   // 5
    0x0018243c04241800,   // 6
    0x0008080810203c00,   // 7
    0x0018242418241800,   // 8
    0x001824203c241800    // 9
};


void setup() {
	Wire.begin();

	bright = 7;
	delay(10);

	//SET ALL DISPLAYS
	for (byte address = 0; address<4; address++) {
		lc.shutdown(address, false);	//powersaving
		lc.setIntensity(address, bright);	//set light intensity 0 - min, 15 - max
		lc.clearDisplay(address);		//clear display
	}
	
	// Functions used just to set the time of the clock
  // Object at the top of the program must be uncommented for it to work
	//setTime.setMinute(18);
	//setTime.setHour(10);

}

void loop() {

  	GetRtc(); // Update time variables
	  WriteTime();	//write actual time to matrix display

  	delay(1000);
}

void WriteTime() {
	drawSymbols(3, (byte) floor(hour/10));
	drawSymbols(2, hour % 10);

  	drawSymbols(1, (byte) floor(minute/10));
  	drawSymbols(0, minute % 10);

	// Blinking dots
	lc.setLed(2, 1, 7, true);  //addr, row, column
	lc.setLed(2, 2, 7, true);
	lc.setLed(2, 5, 7, true);
	lc.setLed(2, 6, 7, true);
}

//read RTC
void GetRtc() {
  	DateTime now = rtc.now();

	second = now.second();
	minute = now.minute();
	hour = now.hour();
}

void drawSymbols(byte position, byte digit) {
	for (int i = 0; i < 8; i++) {
		byte row = (IMAGES[digit] >> i * 8) & 0xFF;
		for (int j = 0; j < 8; j++) {
		lc.setLed(position, i, j, bitRead(row, j));
		}
	}

	delay(1000);
}
