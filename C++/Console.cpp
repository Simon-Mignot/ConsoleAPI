#include "Console.h"

Console* Console::m_singleInstance = NULL;

Console::Console()
{
	m_consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	m_defaultColor.foreground = DARK_WHITE;
	m_defaultColor.background = BLACK;
	m_currentColor.foreground = m_defaultColor.foreground;
	m_currentColor.background = m_defaultColor.background;
	this->resetColor();
}

Console::~Console()
{
		//dtor
}

Console* Console::getSingleInstance()
{
	if(m_singleInstance == NULL)
	{
		m_singleInstance = new Console();
	}
	return m_singleInstance;
}

void Console::setForegroundColor(Color foreground)
{
	this->setColor(foreground, m_currentColor.background);
}
void Console::setBackgroundColor(Color background)
{
	this->setColor(m_currentColor.foreground, background);
}
void Console::setColor(Color foreground, Color background)
{
	m_currentColor.foreground = foreground;
	m_currentColor.background = background;
	this->setColor(m_currentColor);
}
void Console::setColor(ConsoleColor color)
{
	m_currentColor = color;
	SetConsoleTextAttribute(m_consoleHandle, m_currentColor.foreground + m_currentColor.background*16);
}

void Console::resetForegroundColor()
{
	this->setForegroundColor(m_defaultColor.foreground);
}
void Console::resetBackgroundColor()
{
	this->setBackgroundColor(m_defaultColor.background);
}
void Console::resetColor()
{
	this->setColor(m_defaultColor.foreground, m_defaultColor.background);
}

void Console::clear()
{
	system("cls");
}

void Console::testColor(int mode, std::string stringTest)
{
	std::string colorsName[16] = {"BLACK", "DARK_BLUE", "DARK_GREEN", "DARK_CYAN", "DARK_RED", "DARK_PINK", "DARK_YELLOW", "DARK_WHITE",
						"LIGHT_BLACK", "LIGHT_BLUE", "LIGHT_GREEN", "LIGHT_CYAN", "LIGHT_RED", "LIGHT_PINK", "LIGHT_YELLOW", "WHITE"};
	for(unsigned int i = 0; i < MAX_COLOR; ++i)
			for(unsigned int j = 0; j < MAX_COLOR; ++j)
			{
				int _i, _j;
				if(mode == BY_FOREGROUND)
					_i = j, _j = i;
				else
					_i = i, _j = j;
				this->setColor(static_cast<Color>(_j), static_cast<Color>(_i));
				std::cout << " " << stringTest << " ";
				this->resetColor();
				std::cout << '\t' << colorsName[_j] << " - " << colorsName[_i] << '\n';
			}
	this->resetColor();
}


void Console::setCursorPosition(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(m_consoleHandle, pos);
}
