#include <iostream>
using std::cout;
using std::endl;
#include <thread>
using std::thread;

#include "../../inc/TAVLTree.h"

void insert(int num, TAVLTree<int>* tavltree)
{
    tavltree->insert(num);
}

void erase(int num, TAVLTree<int>* tavltree)
{
    tavltree->erase(num);
}

int main()
{
    TAVLTree<int> tavlt;
    
    thread insert1(insert, 7, &tavlt);
    thread insert2(insert, 54, &tavlt);
    thread insert3(insert, 234, &tavlt);

    thread erase1(erase, 52, &tavlt);
    thread erase2(erase, 7, &tavlt);

    thread insert4(insert, 84, &tavlt);
    thread insert5(insert, 334, &tavlt);
    thread insert6(insert, 185, &tavlt);
    thread insert7(insert, 94, &tavlt);

    thread erase3(erase, 334, &tavlt);

    insert1.join();
    insert2.join();
    insert3.join();

    erase1.join();
    erase2.join();

    insert4.join();
    insert5.join();
    insert6.join();
    insert7.join();

    erase3.join();

    tavlt.print_tree();

    return 0;
}
