#ifndef H_TCOMBINATION
#define H_TCOMBINATION

#include "../../TArray/inc/TArray.h"

#include <string>
using std::string;
using std::to_string;
#include <iostream>
using std::cout;
using std::endl;
#include <stdexcept>
using std::invalid_argument;

template <typename type>
class TCombinationIndex
{
public:

    const unsigned& COMBINATION_SIZE;

    TArray<TCombinationIndex<type>*> indexes;

    type* value = nullptr;

    TCombinationIndex(const unsigned& p_COMBO_SIZE) : COMBINATION_SIZE(p_COMBO_SIZE)
    {
        indexes.reserve(COMBINATION_SIZE); // 27 for every lowercase character, plus space

        for (int _i = 0; _i < COMBINATION_SIZE; _i++)
        {
            indexes[_i] = nullptr;
        }
    }
};

template <typename type>
class TCombination
{
private:

    static const unsigned COMBINATION_SIZE = 27;

    TCombinationIndex<type>* root = nullptr;
    
    void check_input(string& p_input) const
    {
        unsigned length = p_input.length();
        if (length == 0)
            throw invalid_argument("Key cannot be empty");
        for (int _i = 0; _i < length; _i++)
        {
            char character = p_input.at(_i);
            if (!(character == 32 || (character > 96 && character < 123)))
                throw invalid_argument("Invalid character at position " + to_string(_i) + ".");
        }
    }

    TCombinationIndex<type>* aux_copy(TCombinationIndex<type>* p_other, TCombinationIndex<type>*& p_TCIndex)
    {
        if (p_other)
        {
            p_TCIndex = new TCombinationIndex<type>(COMBINATION_SIZE);
            for (int _i = 0; _i < COMBINATION_SIZE; _i++)
            {
                TCombinationIndex<type>*& other_char_index = p_other->indexes.at(_i);
                TCombinationIndex<type>*& char_index = p_TCIndex->indexes.at(_i);
                if (other_char_index)
                {
                    char_index = aux_copy(other_char_index, char_index);
                }
            }
        }
        else
            p_TCIndex = nullptr;
        return p_TCIndex;
    }

    TCombinationIndex<type>* aux_insert(TCombinationIndex<type>*& p_TCIndex, string p_key, type p_value, unsigned p_length, unsigned p_index)
    {
        if (!p_TCIndex)
            p_TCIndex = new TCombinationIndex<type>(COMBINATION_SIZE);
        if (p_index == p_length)
            p_TCIndex->value = new type(p_value);
        else
        {
            TCombinationIndex<type>*& char_index = p_TCIndex->indexes.at((unsigned)p_key.at(p_index) - 96);
            char_index = aux_insert(char_index, p_key, p_value, p_length, p_index + 1);
        }
        return p_TCIndex;
    }

    TCombinationIndex<type>* aux_erase(TCombinationIndex<type>*& p_TCIndex, string p_key, unsigned p_length, unsigned p_index, bool& p_preserve)
    {
        if (!p_TCIndex) return nullptr;
        if (p_index == p_length)
        {
            if (p_TCIndex->value)
            {
                delete p_TCIndex->value;
                p_TCIndex->value = nullptr;
            }
            else
                p_preserve = true;
        }
        else
        {
            TCombinationIndex<type>*& char_index = p_TCIndex->indexes.at((unsigned)p_key.at(p_index) - 96);
            char_index = aux_erase(char_index, p_key, p_length, p_index + 1, p_preserve);
        }

        if (!p_preserve)
        {
            if (p_TCIndex->value)
                p_preserve = true;
            unsigned character = (unsigned)p_key.at(p_index) - 96;
            for (unsigned _i = 0; _i < COMBINATION_SIZE; _i++)
            {
                if (p_TCIndex->indexes.at(_i) && _i != character)
                {
                    p_preserve = true;
                    break;
                }
            }
        }

        if (!p_preserve)
        {
            delete p_TCIndex;
            p_TCIndex = nullptr;
        }

        return p_TCIndex;
    }

    type* aux_get(TCombinationIndex<type>*& p_TCIndex, string p_key, unsigned p_length, unsigned p_index = 0)
    {
        if (!p_TCIndex)
            return nullptr;
        if (p_index == p_length - 1)
            return p_TCIndex->value;
        else
        {
            TCombinationIndex<type>*& char_index = p_TCIndex->indexes.at((unsigned)p_key.at(p_index) - 96);;
            return aux_get(char_index, p_key, p_length, p_index + 1);
        }
    }

    void aux_print_keys_inorder(TCombinationIndex<type>*& p_TCIndex, string i_key = "")
    {
        if (!p_TCIndex) return;

        if (p_TCIndex->indexes.at(0))
            aux_print_keys_inorder(p_TCIndex->indexes.at(0), i_key + ' ');
        for (int _i = 1; _i < COMBINATION_SIZE; _i++)
        {
            if (p_TCIndex->indexes.at(_i))
                aux_print_keys_inorder(p_TCIndex->indexes.at(_i), i_key + (char)(_i + 96));
        }

        if (p_TCIndex->value)
            cout << i_key << endl;
    }

    TCombinationIndex<type>* aux_destroy(TCombinationIndex<type>*& p_TCIndex)
    {
        if (!p_TCIndex)
            return nullptr;
        if (p_TCIndex->value)
            delete p_TCIndex->value;
        for (int _i = 0; _i < COMBINATION_SIZE; _i++)
        {
            p_TCIndex->indexes.at(_i) = aux_destroy(p_TCIndex->indexes.at(_i));
        }
        delete p_TCIndex;
        return nullptr;
    }

public:

    TCombination() {}
    TCombination(const TCombination<type>& p_other)
    {
        root = aux_copy(p_other.root, root);
    }
    ~TCombination()
    {
        root = aux_destroy(root);
    }

    TCombination<type>& operator=(const TCombination<type> p_other)
    {
        root = aux_destroy(root);
        root = aux_copy(p_other.root, root);
    }

    void insert(string p_key, type p_value)
    {
        check_input(p_key);
        root = aux_insert(root, p_key, p_value, p_key.length(), 0);
    }

    void erase(string p_key)
    {
        check_input(p_key);
        bool preserve = false;
        root = aux_erase(root, p_key, p_key.length(), 0, preserve);
    }

    type* get(string& p_key)
    {
        check_input(p_key);
        return aux_get(root, p_key, p_key.length(), 0);
    }

    bool contains_key(string& p_key) const
    {
        if (get(p_key))
            return true;
        return false;
    }

    bool is_empty() const
    {
        if (root)
            return false;
        return true;
    }

    void print_keys_inorder()
    {
        aux_print_keys_inorder(root);
    }
};

template<typename type>
const unsigned TCombination<type>::COMBINATION_SIZE;

#endif
