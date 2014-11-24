#include <iostream>
#include <windows.h>
#include "Console.h"

int main()
{
    Console* console = Console::getSingleInstance();
    console->testColor(BY_FOREGROUND);
    system("pause");
    console->testColor(BY_BACKGROUND);
    return 0;
}
