#include "../../inc/TVector.h"

#include <iostream>

int main()
{
    TVector<std::string> tvs;

    tvs.reserve(5);

    tvs.push("Indiana Jones");
    tvs.push("Inception");
    tvs.push("Star Wars");
    tvs.push("Scarface");
    tvs.push("Heat");
    tvs.push("Hardball");
    tvs.push("Harry Potter");

    tvs.sort();

    for (int _i = 0; _i < tvs.size(); _i++)
    {
        std::cout << tvs[_i] << std::endl;
    }

    std::cout << "size: " << tvs.size() << std::endl;
}
