#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#include "util.h"

void cursor_visible(bool type)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들가져오기 
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = type; // 0: 커서 보이기, 1: 커서 숨기기 
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}


void init() {
	system("mode con cols=70 lines=100 | title desert island");
	cursor_visible(TRUE);
}

// 커서 위치 이동함수  
void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들가져오기 
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

// 첫번째: 텍스트, 두번째: 배경  
void setColor(int forground, int background) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들가져오기 
	int code = forground + background * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}

int pressedKey()
{
    int pressedKey;
    while (1)
    {
        if (_kbhit())
        {
            pressedKey = _getch();
            return pressedKey;
        }
    }

}

bool keyCheckerIgnoreCase(char key)
{
    while (1)
    {
        if (_kbhit())
        {
            int pressedKey = _getch();
            if ((key > 'A' && key < 'Z'))
            {
                if (pressedKey == key || pressedKey == key + 32)
                    return true;
                else
                    return false;
            }
            else if ((key > 'a' && key < 'z'))
            {
                if (pressedKey == key || pressedKey == key - 32)
                    return true;
                else
                    return false;
            }
            else
            {
                if (pressedKey == key)
                    return true;
                else
                    return false;
            }
        }
    }
}