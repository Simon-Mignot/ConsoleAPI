#ifndef CONSOLE_H
#define CONSOLE_H

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

#define BY_FOREGROUND	0
#define BY_BACKGROUND	1
#define DEFAULT_TEST_PHRASE 	"Hello Coloured World!"

typedef enum
{
	BLACK = 0,
	DARK_BLUE,
	DARK_GREEN,
	DARK_CYAN,
	DARK_RED,
	DARK_PINK,
	DARK_YELLOW,
	DARK_WHITE,
	LIGHT_BLACK,
	LIGHT_BLUE,
	LIGHT_GREEN,
	LIGHT_CYAN,
	LIGHT_RED,
	LIGHT_PINK,
	LIGHT_YELLOW,
	WHITE
} Color;
#define MAX_COLOR	16

typedef struct
{
	Color foreground;
	Color background;
} ConsoleColor;

void console_setForegroundColor(Color foreground);
void console_setBackgroundColor(Color background);

void console_setColor(Color foreground, Color background);
void console_setConsoleColor(ConsoleColor color);
void console_resetForegroundColor();

void console_resetBackgroundColor();
void console_resetColor();

void console_setCursorPosition(int x, int y);

void console_clear();

void console_testColor(int mode, char* stringTest);



#endif // CONSOLE_H
