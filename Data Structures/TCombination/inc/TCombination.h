#ifndef H_TCOMBINATION
#define H_TCOMBINATION

#include "../../TArray/inc/TArray.h"

#include <string>
using std::string;
using std::to_string;
#include <stdexcept>
using std::invalid_argument;

template <typename type>
struct TCombinationIndex
{
    const unsigned COMBO_SIZE;

    TArray<TCombinationIndex<type>*> indexes;

    type value;

    TCombinationIndex()
    {
        indexes.reserve(27); // 27 for every lowercase character, plus space

        for (int _i = 0; _i < 27; _i++)
        {
            indexes[_i] = nullptr;
        }
    }

    TCombinationIndex<type>* at(const unsigned p_index) const
    {
        return indexes[p_index];
    }
};

template <typename type>
class TCombination
{
private:

    TCombinationIndex<type>* root = nullptr;

    TCombinationIndex<type>* aux_insert(TCombinationIndex<type>*& p_TCIndex, const string& p_key, type& p_value, const unsigned& p_length, unsigned p_index = 0)
    {
        if (p_index == p_length) value = p_value;
        else
        {
            if (!p_TCIndex)
                p_TCIndex = new TCombinationIndex<type>;
            unsigned character = (int)p_key.at(p_index);
            p_TCIndex->indexes.at(character - 96) = aux_insert(p_TCIndex->indexes.at(character - 96), p_key, p_length, p_index + 1);
        }
        return p_TCIndex;
    }

    void aux_print_keys_inorder(TCombinationIndex<type>*& p_TCIndex, string i_key) const
    {
        if (!p_TCIndex) return;

        //for ()
    }

public:

    TCombination() {}
    TCombination(const TCombination<type>& p_other) {}
    ~TCombination() {}

    TCombination<type>& operator=(const TCombination<type>& p_other) {}

    void insert(string& p_key, type& p_value)
    {
        unsigned length = p_key.length();
        for (int _i = 0; _i < length; _i++)
        {
            char character = p_key.at(_i);
            if (!(character == 32 || (character > 96 && character < 123)))
                throw invalid_argument("Invalid character at position " + to_string(_i) + ".");
        }
        root = aux_insert(root, p_key, length, 0);
    }

    void erase(string& p_key)
    {

    }

    void print_keys_inorder() const
    {
        aux_print_keys_inorder(root);
    }
};

#endif
