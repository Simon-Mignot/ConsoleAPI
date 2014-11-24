#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "Console.h"

int main()
{
	//console_initConsole();
    console_testColor(BY_FOREGROUND, DEFAULT_TEST_PHRASE);
    system("pause");
    console_testColor(BY_BACKGROUND, DEFAULT_TEST_PHRASE);
    return 0;
}
