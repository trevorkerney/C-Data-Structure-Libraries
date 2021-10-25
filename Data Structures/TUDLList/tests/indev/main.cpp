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

    // 62 58 73 64 12 35 54 17

    TUDLListIterator<int>* tqi1 = tq.iterator();
    TUDLListIterator<int>* tqi2 = tq.iterator(-1);

    tqi1->next();
    tqi2->prev();
    
    cout << tq.pull_back() << endl;
    cout << tq.pull_back() << endl;
    cout << tq.pull_front() << endl;
    cout << tq.pull_front() << endl;

    cout << tqi1->next() << endl;
    cout << tqi2->prev() << endl;

    TUDLListIterator<int>* tqi3 = tq.iterator();
    TUDLListIterator<int>* tqi4 = tq.iterator(-1);

    std::cout << "made it." << std::endl;
}
