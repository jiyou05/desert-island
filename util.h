#pragma once

enum {
	black,
	blue,
	green,
	cyan,
	red,
	purple,
	brown,
	lightgray,
	darkgray,
	lightblue,
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	yellow,
	white
};

void cursor_visible(bool);
void init();
void gotoxy(int, int);
void setColor(int, int);
int pressedKey();
bool keyCheckerIgnoreCase(char);




