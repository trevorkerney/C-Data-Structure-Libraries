#include "../../inc/TVector.h"

#include <iostream>

int main()
{
    TVector<int> tv;

    tv.reserve(5);

    tv.push(4);
    tv.push(7);
    tv.push(52);

    for (int _i = 0; _i < tv.size(); _i++)
    {
        std::cout << tv[_i] << std::endl;
    }
    std::cout << "-----------" << std::endl;

    int num = tv.erase(0);

    for (int _i = 0; _i < tv.size(); _i++)
    {
        std::cout << tv[_i] << std::endl;
    }
    std::cout << "-----------" << std::endl;

    tv.insert(11, 1);
    tv.insert(32, 0);

    for (int _i = 0; _i < tv.size(); _i++)
    {
        std::cout << tv[_i] << std::endl;
    }
    std::cout << "-----------" << std::endl;

    int num2 = tv.pull();

    for (int _i = 0; _i < tv.size(); _i++)
    {
        std::cout << tv[_i] << std::endl;
    }
    std::cout << "-----------" << std::endl;

    std::cout << "size: " << tv.size() << std::endl;
}
