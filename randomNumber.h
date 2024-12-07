#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H

#include <stdlib.h>

int GenerateRandomNumber(int max)
{
    srand(time(NULL));
    return rand() % max + 1;
}

#endif // RANDOMNUMBER_H
