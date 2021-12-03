#ifndef H_TSTRIE
#define H_TSTRIE

#include "../../TArray/inc/TArray.h"

#include <string>
using std::string;
using std::to_string;
#include <iostream>
using std::cout;
using std::endl;
#include <stdexcept>
using std::invalid_argument;

#define COMBINATION_SIZE 26

template <typename type>
class TSTrie;

template <typename type>
class TSTrieIndex
{
friend class TSTrie<type>;
private:

    TArray<TSTrieIndex<type>*> indexes;

    type* value = nullptr;

    TSTrieIndex()
    {
        indexes.reserve(COMBINATION_SIZE);

        for (unsigned _i = 0; _i < COMBINATION_SIZE; _i++)
        {
            indexes[_i] = nullptr;
        }
    }
};

template <typename type>
class TSTrie
{
private:

    TSTrieIndex<type>* root = nullptr;

    void check_input(const string p_input) const
    {
        unsigned length = p_input.length();
        if (length == 0)
            throw invalid_argument("Key cannot be empty");
        for (unsigned _i = 0; _i < length; _i++)
        {
            char character = p_input.at(_i);
            if (!(character > 96 && character < 123))
                throw invalid_argument("Invalid character at position " + to_string(_i) + ".");
        }
    }

    unsigned ascii_to_index(const unsigned p_dec)
    {
        return p_dec - 97;
    }

    unsigned index_to_ascii(const unsigned p_dec)
    {
        return p_dec + 97;
    }

    TSTrieIndex<type>* aux_copy(const TSTrieIndex<type>*& p_TCIndex, const TSTrieIndex<type>* p_other)
    {
        if (p_other)
        {
            p_TCIndex = new TSTrieIndex<type>(COMBINATION_SIZE);
            if (p_other->value)
                p_TCIndex->value = new type(p_other->value);
            for (int _i = 0; _i < COMBINATION_SIZE; _i++)
            {
                TSTrieIndex<type>*& other_char_index = p_other->indexes.at(_i);
                TSTrieIndex<type>*& char_index = p_TCIndex->indexes.at(_i);
                if (other_char_index)
                    char_index = aux_copy(p_other->indexes.at(_i), p_TCIndex->indexes.at(_i));
            }
            return p_TCIndex;
        }
        else
            return nullptr;
    }

    TSTrieIndex<type>* aux_insert(TSTrieIndex<type>*& p_TCIndex, const string p_key, const type p_value, const unsigned p_length, unsigned p_index)
    {
        if (!p_TCIndex)
            p_TCIndex = new TSTrieIndex<type>;
        if (p_index == p_length)
            p_TCIndex->value = new type(p_value);
        else
        {
            TSTrieIndex<type>*& char_index = p_TCIndex->indexes.at(ascii_to_index((unsigned)p_key.at(p_index)));
            char_index = aux_insert(char_index, p_key, p_value, p_length, p_index + 1);
        }
        return p_TCIndex;
    }

    TSTrieIndex<type>* aux_erase(TSTrieIndex<type>*& p_TCIndex, const string p_key, const unsigned p_length, unsigned p_index, bool& p_preserve)
    {
        if (!p_TCIndex)
            return nullptr;
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
            TSTrieIndex<type>*& char_index = p_TCIndex->indexes.at(ascii_to_index((unsigned)p_key.at(p_index)));
            char_index = aux_erase(char_index, p_key, p_length, p_index + 1, p_preserve);
        
            if (!p_preserve)
            {
                if (p_TCIndex->value)
                    p_preserve = true;
                unsigned character = ascii_to_index((unsigned)p_key.at(p_index));
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
        }
        return p_TCIndex;
    }

    type* aux_get(TSTrieIndex<type>*& p_TCIndex, const string p_key, const unsigned p_length, unsigned p_index = 0)
    {
        if (!p_TCIndex)
            return nullptr;
        if (p_index == p_length)
            return p_TCIndex->value;
        else
            return aux_get(p_TCIndex->indexes.at(ascii_to_index((unsigned)p_key.at(p_index))), p_key, p_length, p_index + 1);
    }

    void aux_print_keys_inorder(TSTrieIndex<type>*& p_TCIndex, string i_key = "")
    {
        if (!p_TCIndex) return;

        for (unsigned _i = 0; _i < COMBINATION_SIZE; _i++)
        {
            if (p_TCIndex->indexes.at(_i))
                aux_print_keys_inorder(p_TCIndex->indexes.at(_i), i_key + (char)index_to_ascii(_i));
        }

        if (p_TCIndex->value)
            cout << i_key << endl;
    }

    void aux_print_keys_preorder(TSTrieIndex<type>*& p_TCIndex, string i_key = "")
    {
        if (!p_TCIndex) return;

        if (p_TCIndex->value)
            cout << i_key << endl;

        for (unsigned _i = 0; _i < COMBINATION_SIZE; _i++)
        {
            if (p_TCIndex->indexes.at(_i))
                aux_print_keys_preorder(p_TCIndex->indexes.at(_i), i_key + (char)index_to_ascii(_i));
        }
    }

    TSTrieIndex<type>* aux_destroy(TSTrieIndex<type>*& p_TCIndex)
    {
        if (!p_TCIndex)
            return nullptr;
        if (p_TCIndex->value)
            delete p_TCIndex->value;
        for (unsigned _i = 0; _i < COMBINATION_SIZE; _i++)
        {
            p_TCIndex->indexes.at(_i) = aux_destroy(p_TCIndex->indexes.at(_i));
        }
        delete p_TCIndex;
        return nullptr;
    }

public:

    TSTrie() {}
    TSTrie(const TSTrie<type>& p_other)
    {
        root = aux_copy(root, p_other.root);
    }
    ~TSTrie()
    {
        root = aux_destroy(root);
    }

    TSTrie<type>& operator=(const TSTrie<type> p_other)
    {
        root = aux_destroy(root);
        root = aux_copy(root, p_other.root);
    }

    void insert(const string p_key, const type p_value)
    {
        check_input(p_key);
        root = aux_insert(root, p_key, p_value, p_key.length(), 0);
    }

    void erase(const string p_key)
    {
        check_input(p_key);
        bool preserve = false;
        root = aux_erase(root, p_key, p_key.length(), 0, preserve);
    }

    type& get(const string p_key)
    {
        check_input(p_key);
        type* value = aux_get(root, p_key, p_key.length(), 0);
        if (value)
            return *value;
        else
            throw invalid_argument("No value held by the key '" + p_key + "'");
    }

    bool contains_key(const string p_key) const
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

    void print_keys_preorder()
    {
        aux_print_keys_preorder(root);
    }
};

#endif
