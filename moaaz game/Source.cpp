#include "source.h"

cmpchoice randomchoice()
{
    return cmpchoice((rand() % 3) + 1);
}