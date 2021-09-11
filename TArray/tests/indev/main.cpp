#include "../../inc/TArray.h"

#include <iostream>

int main()
{
    TArray<int> ta;

    ta.reserve(20);

    ta[18] = 7;

    for (int _i = 0; _i < 20; _i++)
    {
        std::cout << _i << ": " << ta.at(_i) << std::endl;
    }

    ta[4] = 6;

    int j = ta[4];

    std::cout << std::endl << j << std::endl;
}
