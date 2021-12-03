#ifndef H_TARRAY
#define H_TARRAY

#define explspec template<>

#include <string>
using std::string;
using std::to_string;
#include <stdexcept>
#include <cmath>
using std::pow;

template <typename type>
class TArray
{
private:

    type* i_array;

    size_t i_capacity;

    static const size_t MAX_CAPACITY = 65535;

    void copy(const TArray& p_other)
    {
        if (p_other.i_capacity > 0)
        {
            if (i_capacity > 0)
            {
                delete[] i_array;
            }
            i_array = new type[p_other.i_capacity];

            for (size_t _i = 0; _i < p_other.i_capacity; _i++)
            {
                i_array[_i] = p_other[_i];;
            }
        }
        i_capacity = p_other.i_capacity;
    }

    inline short compare(const type& p_obj1, const type& p_obj2) const
    {
        throw std::runtime_error("There is no comparison function provided for this type.");
    }

    long long linear_search(const type& p_searched) const
    {
        for (size_t _i = 0; _i < i_capacity; _i++)
        {
            int comparison = compare(p_searched, i_array[_i]);
            if ((comparison) == 0)
                return _i;
        }
        return -1;
    }

public:

    TArray(const unsigned& p_initial_capacity = 0)
    {
        if (p_initial_capacity < MAX_CAPACITY)
        {
            i_capacity = 0;
            if (p_initial_capacity > 0)
            {
                reserve(p_initial_capacity);
            }
        }
        else
            throw std::runtime_error("Out of allowed TArray range: 0 - " + to_string(MAX_CAPACITY));
    }
    TArray(const TArray& p_other)
    {
        i_capacity = 0;
        copy(p_other);
    }
    ~TArray()
    {
        if (i_capacity > 0)
        {
            delete[] i_array;
            i_array = nullptr;
        }
    }

    TArray& operator=(const TArray& p_other)
    {
        if (this != &p_other)
        {
            copy(p_other);
        }    
        return *this;
    }

    type& at(const unsigned& p_index) const
    {
        if (!(p_index < i_capacity))
            throw std::runtime_error("Out of range");
        return i_array[p_index];
    }
    type& operator[](const unsigned& p_index) const
    {
        return at(p_index);
    }

    size_t capacity() const
    {
        return i_capacity;
    }

    size_t reserve(const unsigned& p_amount)
    {
        const size_t old_memory_size = i_capacity;
        if ((p_amount == MAX_CAPACITY && i_capacity == MAX_CAPACITY) || p_amount <= i_capacity)
            return 0;
        else if (p_amount <= MAX_CAPACITY)
        {
            type* new_array = new type[p_amount];
            if (i_capacity > 0)
            {
                for (unsigned int _i = 0; _i < i_capacity; _i++)
                {
                    new_array[_i] = i_array[_i];
                }
                delete[] i_array;
            }
            i_array = new_array;
            i_capacity = p_amount;
            return p_amount - old_memory_size;
        }
        else
            return reserve(MAX_CAPACITY);
    }

    long find(const type& p_searched) const
    {
        return linear_search(p_searched);
    }
};

template<typename type>
const size_t TArray<type>::MAX_CAPACITY;

explspec short TArray<bool>::                  compare(const bool& p_obj1,                 const bool& p_obj2)                 const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<char>::                  compare(const char& p_obj1,                 const char& p_obj2)                 const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<signed char>::           compare(const signed char& p_obj1,          const signed char& p_obj2)          const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<short>::                 compare(const short& p_obj1,                const short& p_obj2)                const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<int>::                   compare(const int& p_obj1,                  const int& p_obj2)                  const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<long>::                  compare(const long& p_obj1,                 const long& p_obj2)                 const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<long long>::             compare(const long long& p_obj1,            const long long& p_obj2)            const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<unsigned char>::         compare(const unsigned char& p_obj1,        const unsigned char& p_obj2)        const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<unsigned short>::        compare(const unsigned short& p_obj1,       const unsigned short& p_obj2)       const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<unsigned>::              compare(const unsigned& p_obj1,             const unsigned& p_obj2)             const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<unsigned long>::         compare(const unsigned long& p_obj1,        const unsigned long& p_obj2)        const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0; 
}
explspec short TArray<unsigned long long>::    compare(const unsigned long long& p_obj1,   const unsigned long long& p_obj2)   const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<float>::                 compare(const float& p_obj1,                const float& p_obj2)                const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<double>::                compare(const double& p_obj1,               const double& p_obj2)               const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<long double>::           compare(const long double& p_obj1,          const long double& p_obj2)          const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<string>::                compare(const string& p_obj1,               const string& p_obj2)               const
{
    int comparison = p_obj1.compare(p_obj2);
    if (comparison != 0)
        if (comparison > 0)
            return 1;
        else
            return -1;
    else
        return 0;
}

#endif

#ifndef H_TSTRIE
#define H_TSTRIE

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
