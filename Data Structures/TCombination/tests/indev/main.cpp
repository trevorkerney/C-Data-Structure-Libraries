#include "../../inc/TCombination.h"

#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    TCombination<int> combo;

    combo.insert("cat", 42);
    combo.insert("cab", 69);
    combo.insert("dog", 29);
    combo.insert("catacombs", 101);
    combo.insert("", 111);

    combo.print_keys_inorder();

    cout << "------------\nDone" << endl;
}
