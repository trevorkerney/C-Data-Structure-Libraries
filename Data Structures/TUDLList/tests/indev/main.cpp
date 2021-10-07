#include "../../inc/TUDLList.h"

#include <iostream>

int main()
{
    TUDLList<int> tq;

    tq.push_back(1);
    tq.push_back(2);
    tq.push_back(3);
    tq.push_back(4);
    
    std::cout << tq.next() << std::endl;
    std::cout << tq.next() << std::endl;

    tq.push_back(5);
    tq.push_back(6);

    std::cout << tq.next() << std::endl;
    std::cout << tq.next() << std::endl;
    std::cout << tq.next() << std::endl;
    std::cout << tq.next() << std::endl;

    tq.push_back(7);
    tq.push_back(8);

    std::cout << tq.next() << std::endl;
    std::cout << tq.next() << std::endl;

    std::cout << "made it." << std::endl;
}
