#include "../../inc/TUDLList.h"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    TUDLList<int> tq;

    tq.push_back(12);
    tq.push_back(35);
    tq.push_back(54);
    tq.push_front(64);
    tq.push_front(73);
    tq.push_back(17);
    tq.push_front(58);
    tq.push_front(62);

    TUDLListIterator<int>* tqi1 = tq.iterator();
    TUDLListIterator<int>* tqi2 = tq.iterator(-1);
    
    int num1 = tq.pop_back();
    int num2 = tq.pop_back();
    int num3 = tq.pop_front();
    int num4 = tq.pop_front();

    int inum1 = tqi1->next();
    int inum2 = tqi2->prev();

    TUDLListIterator<int>* tqi3 = tq.iterator();
    TUDLListIterator<int>* tqi4 = tq.iterator(-1);

    

    std::cout << "made it." << std::endl;
}
