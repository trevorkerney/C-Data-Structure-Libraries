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
    combo.insert("catwalk", 101);
    combo.insert("zebra", 11);

    cout << "------------ PRINTING ------------" << endl;

    cout << "--- inorder ---" << endl;
    combo.print_keys_inorder();
    cout << "---------------" << endl;

    cout << "--- preorder ---" << endl;
    combo.print_keys_preorder();
    cout << "----------------" << endl;

    combo.erase("cat");
    combo.erase("zebra");

    cout << "--- erased inorder ---" << endl;
    combo.print_keys_inorder();
    cout << "--------------" << endl;

    cout << "--- erased preorder ---" << endl;
    combo.print_keys_preorder();
    cout << "---------------" << endl;

    cout << "----------------------------------\n" << endl;

    cout << "------------ RETRIEVAL ------------" << endl;

    int num = combo.get("cab");
    cout << num << endl;

    cout << combo.get("dog") << endl;
    combo.get("dog") = 87;
    cout << combo.get("dog") << endl;

    cout << "-----------------------------------\n" << endl;

    cout << "-------------\nDone" << endl;
}
