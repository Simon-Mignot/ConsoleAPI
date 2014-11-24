#ifndef CONSOLE_H
#define CONSOLE_H

#include <windows.h>
#include <iostream>
#include <string>

#define BY_FOREGROUND	0
#define BY_BACKGROUND	1

enum Color
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
};
#define MAX_COLOR	16


struct ConsoleColor
{
	Color foreground;
	Color background;
};


class Console
{
	public:
		virtual ~Console();

		void setForegroundColor(Color foreground);
		void setBackgroundColor(Color background);
		void setColor(Color foreground, Color background);
		void setColor(ConsoleColor color);

		void resetForegroundColor();
		void resetBackgroundColor();
		void resetColor();

		void setCursorPosition(int x, int y);


		void clear();

		void testColor(int mode = BY_BACKGROUND, std::string stringTest = "Hello Coloured World!");

		static Console* getSingleInstance();

	protected:
	private:
		Console();

		HANDLE m_consoleHandle;
		ConsoleColor m_currentColor;
		ConsoleColor m_defaultColor;

		static Console* m_singleInstance;
};

#endif // CONSOLE_H
