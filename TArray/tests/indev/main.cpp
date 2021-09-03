#include "../../inc/TArray.h"

#include <iostream>

int main()
{
    TArray<int> ta;

    ta.reserve(20);

    ta.at(18) = 7;

    std::cout << ta.at(18) << std::endl;
}