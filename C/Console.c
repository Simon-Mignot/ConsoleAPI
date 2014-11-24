#include "Console.h"

HANDLE console_consoleHandle;
ConsoleColor console_currentColor;
ConsoleColor console_defaultColor;
int console_singleton = 0;


void console_initConsole()
{
	console_consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	console_defaultColor.foreground = DARK_WHITE;
	console_defaultColor.background = BLACK;
	console_currentColor.foreground = console_defaultColor.foreground;
	console_currentColor.background = console_defaultColor.background;
	console_resetColor();
	console_singleton = 1;
}


void console_setForegroundColor(Color foreground)
{
	console_setColor(foreground, console_currentColor.background);
}
void console_setBackgroundColor(Color background)
{
	console_setColor(console_currentColor.foreground, background);
}
void console_setColor(Color foreground, Color background)
{
	console_currentColor.foreground = foreground;
	console_currentColor.background = background;
	console_setConsoleColor(console_currentColor);
}
void console_setConsoleColor(ConsoleColor color)
{
	console_currentColor = color;
	SetConsoleTextAttribute(console_consoleHandle, console_currentColor.foreground + console_currentColor.background*16);
}

void console_resetForegroundColor()
{
	console_setForegroundColor(console_defaultColor.foreground);
}
void console_resetBackgroundColor()
{
	console_setBackgroundColor(console_defaultColor.background);
}
void console_resetColor()
{
	console_setColor(console_defaultColor.foreground, console_defaultColor.background);
}

void console_clear()
{
	system("cls");
}

void console_testColor(int mode, char* stringTest)
{
	if(!console_singleton)
	{
		printf("Console Handle unitialized.\n");
		system("pause");
	}
	char* colorsName[16] = {"BLACK", "DARK_BLUE", "DARK_GREEN", "DARK_CYAN", "DARK_RED", "DARK_PINK", "DARK_YELLOW", "DARK_WHITE",
						"LIGHT_BLACK", "LIGHT_BLUE", "LIGHT_GREEN", "LIGHT_CYAN", "LIGHT_RED", "LIGHT_PINK", "LIGHT_YELLOW", "WHITE"};
	for(unsigned int i = 0; i < MAX_COLOR; ++i)
		for(unsigned int j = 0; j < MAX_COLOR; ++j)
		{
			int _i, _j;
			if(mode == BY_FOREGROUND)
				_i = j, _j = i;
			else
				_i = i, _j = j;
			console_setColor((Color)_j, (Color)_i);
			printf(" %s ", stringTest);
			console_resetColor();
			printf("\t%s - %s\n", colorsName[_j], colorsName[_i]);
		}
	console_resetColor();
}


void console_setCursorPosition(int x, int y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(console_consoleHandle, pos);
}
