#include "Terminal.h"

#include <conio.h>

char readKey()
{
    int ch = _getch();
    return static_cast<char>(ch);
}