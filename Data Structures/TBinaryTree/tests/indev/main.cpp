#include <iostream>
using std::cout;
using std::endl;

#include "../../inc/TBinaryTree.h"

int main()
{

    TBinaryTree<int> tbt;

    cout << "----- empty erase -----" << endl;
    //cout << tbt.erase(4) << endl;
    //cout << tbt.erase(24) << endl;
    cout << "--- end empty erase ---" << endl;

    tbt.insert(5);
    tbt.insert(8);
    tbt.insert(24);
    tbt.insert(35);
    tbt.insert(12);
    tbt.insert(83);
    tbt.insert(855);
    tbt.insert(46);
    tbt.insert(33);
    tbt.insert(2);
    tbt.insert(-23);
    tbt.insert(-42);
    tbt.insert(0);
    tbt.insert(-265);
    tbt.insert(-31);

    cout << "----- contains -----" << endl;
    cout << tbt.contains(13) << endl;
    cout << tbt.contains(5) << endl;
    cout << tbt.contains(8) << endl;
    cout << tbt.contains(24) << endl;
    cout << tbt.contains(13) << endl;
    cout << tbt.contains(42) << endl;
    cout << tbt.contains(12) << endl;
    cout << tbt.contains(83) << endl;
    cout << tbt.contains(25) << endl;
    cout << tbt.contains(855) << endl;
    cout << tbt.contains(46) << endl;
    cout << tbt.contains(33) << endl;
    cout << "--- end contains ---" << endl;

    //cout << tbt.erase(4) << endl;
    //cout << tbt.erase(24) << endl;
    //cout << tbt.erase(1337) << endl;
    //cout << tbt.erase(83) << endl;
    //cout << tbt.erase(69) << endl;
    //cout << tbt.erase(-42) << endl;
    //cout << tbt.erase(29) << endl;
    
    cout << "hello" << endl;
}