#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
	typedef struct	a
	{
	int second;
	int minute;
	int hour;
	int light;
	int alarm;
	} 				b;
  
void	setup() 
{
	pinMode(7, OUTPUT);
	lcd.begin(16, 2);
	lcd.print("Time: ");
}

void	loop() 
{
	b bs;

	bs.second = 0;
	bs.minute = 0;
	bs.hour = 0;
	bs.light = 255;
	bs.alarm = 1;
	while (bs.hour != 24)
	{
		bs.second++;
		delay(990);
		if (bs.second == 60)
		{
			bs.minute++;
			bs.second = 0;
			lcd.setCursor(10, 1);
			lcd.print(" ");
		}
		if (bs.minute == 60)
		{
			bs.hour++;
			bs.minute = 0;
		}
		lcd.setCursor(4, 1);
		if (bs.hour < 10)
			lcd.print(0);
		lcd.print(bs.hour);
		lcd.print(":");
		if (bs.minute < 10)
			lcd.print(0);
		lcd.print(bs.minute);
		lcd.print(":");
		if (bs.second < 10)
			lcd.print(0);
		lcd.print(bs.second);
		if (bs.minute >= bs.alarm)
			if (bs.light < 255)
				analogWrite(7, bs.light++);
		lcd.print(" ");
		lcd.print(bs.light);
  	}
}
