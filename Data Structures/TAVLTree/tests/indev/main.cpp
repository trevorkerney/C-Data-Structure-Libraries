#include <iostream>
using std::cout;
using std::endl;

#include "../../inc/TAVLTree.h"

int main()
{
    cout << "-------- TBinaryTree --------" << endl << endl;
    TBinaryTree<int> tbt;
    tbt.insert(-265);
    tbt.insert(-42);
    tbt.insert(-31);
    tbt.insert(-23);
    tbt.insert(0);
    tbt.insert(2);
    tbt.insert(5);
    tbt.insert(8);
    tbt.insert(12);
    tbt.insert(24);
    tbt.insert(33);
    tbt.insert(35);
    tbt.insert(46);
    tbt.insert(83);
    tbt.insert(855);
    tbt.insert(-365);
    tbt.print_tree();
    cout << "------ end TBinaryTree ------" << endl << endl;

    cout << "--------- TAVLTree ---------" << endl << endl;
    TAVLTree<int> tavlt;
    tavlt.insert(-265);
    tavlt.insert(-42);
    tavlt.insert(-31);
    tavlt.insert(-23);
    tavlt.insert(0);
    tavlt.insert(2);
    tavlt.insert(5);
    tavlt.insert(8);
    tavlt.insert(12);
    tavlt.insert(24);
    tavlt.insert(33);
    tavlt.insert(35);
    tavlt.insert(46);
    tavlt.insert(83);
    tavlt.insert(855);
    tavlt.insert(-365);
    tavlt.print_tree();
    cout << "------- end TAVLTree -------" << endl;
}
