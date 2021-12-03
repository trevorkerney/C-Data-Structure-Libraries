#include "../../inc/TSTrie.h"

#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    TSTrie<int> strie;

    strie.insert("cat", 42);
    strie.insert("cab", 69);
    strie.insert("dog", 29);
    strie.insert("catwalk", 101);
    strie.insert("zebra", 11);

    cout << "------------ PRINTING ------------" << endl;

    cout << "--- inorder ---" << endl;
    strie.print_keys_inorder();
    cout << "---------------" << endl;

    cout << "--- preorder ---" << endl;
    strie.print_keys_preorder();
    cout << "----------------" << endl;

    strie.erase("cat");
    strie.erase("zebra");
    cout << "\nAFTER ERASING 'cat' AND 'zebra'\n" << endl;

    cout << "--- inorder ---" << endl;
    strie.print_keys_inorder();
    cout << "--------------" << endl;

    cout << "--- preorder ---" << endl;
    strie.print_keys_preorder();
    cout << "---------------" << endl;

    cout << "----------------------------------\n" << endl;

    cout << "------------ RETRIEVAL ------------" << endl;

    int num = strie.get("cab");
    cout << num << " (should be 69)" << endl;

    cout << strie.get("dog") << " (should be 29)" << endl;
    strie.get("dog") = 87;
    cout << strie.get("dog") << " (should be 87)" << endl;

    cout << "-----------------------------------\n" << endl;

    cout << "-------------\nDone" << endl;
}
