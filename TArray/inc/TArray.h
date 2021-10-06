#pragma once

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

    unsigned int i_capacity;

    static const unsigned int MAX_CAPACITY = 65535;

    void copy(const TArray& p_other)
    {
        if (p_other.i_capacity > 0)
        {
            if (i_capacity > 0)
            {
                delete[] i_array;
            }
            i_array = new type[p_other.i_capacity];

            for (unsigned int _i = 0; _i < p_other.i_capacity; _i++)
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

    unsigned int linear_search(const type& p_searched) const
    {
        for (unsigned int _i = 0; _i < i_capacity; _i++)
        {
            int comparison = compare(p_searched, i_array[_i]);
            if ((comparison) == 0)
                return _i;
        }
        return -1;
    }

public:

    TArray(int p_initial_capacity = 0)
    {
        if (p_initial_capacity >= 0 && p_initial_capacity < MAX_CAPACITY)
        {
            i_capacity = 0;
            if (p_initial_capacity > 0)
            {
                reserve(p_initial_capacity);
            }
        }
        else
        {
            throw std::runtime_error("Out of allowed TArray range: 0 - " + to_string(MAX_CAPACITY));
        }
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

    type& at(int p_index) const
    {
        if (!(p_index >= 0 && p_index < i_capacity))
        {
            throw std::runtime_error("Out of range");
        }
        return i_array[p_index];
    }
    type& operator[](const int p_index) const
    {
        return at(p_index);
    }

    int capacity() const
    {
        return i_capacity;
    }

    unsigned int reserve(const long& p_amount)
    {
        unsigned int old_memory_size = i_capacity;

        if ((p_amount == MAX_CAPACITY && i_capacity == MAX_CAPACITY) || p_amount <= i_capacity)
        {
            return 0;
        }
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
        {
            return reserve(MAX_CAPACITY);
        }
    }

    long find(const type& p_searched) const
    {
        return linear_search(p_searched);
    }
};

explspec short TArray<bool>::                  compare(const bool& p_obj1,                 const bool& p_obj2)                 const
{
    int comparison = p_obj1 - p_obj2;
    if (comparison != 0)
        if (comparison > 0)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<char>::                  compare(const char& p_obj1,                 const char& p_obj2)                 const
{
    short comparison = p_obj1 - p_obj2;
    if (comparison != 0)
        if (comparison > 0)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<char16_t>::              compare(const char16_t& p_obj1,             const char16_t& p_obj2)             const
{
    short comparison = p_obj1 - p_obj2;
    if (comparison != 0)
        if (comparison > 0)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<char32_t>::              compare(const char32_t& p_obj1,             const char32_t& p_obj2)             const
{
    short comparison = p_obj1 - p_obj2;
    if (comparison != 0)
        if (comparison > 0)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<wchar_t>::               compare(const wchar_t& p_obj1,              const wchar_t& p_obj2)              const
{
    short comparison = p_obj1 - p_obj2;
    if (comparison != 0)
        if (comparison > 0)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<signed char>::           compare(const signed char& p_obj1,          const signed char& p_obj2)          const
{
    int comparison = p_obj1 - p_obj2;
    if (comparison != 0)
        if (comparison > 0)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<short>::                 compare(const short& p_obj1,                const short& p_obj2)                const
{
    short comparison = p_obj1 - p_obj2;
    if (comparison != 0)
        if (comparison > 0)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<int>::                   compare(const int& p_obj1,                  const int& p_obj2)                  const
{
    int comparison = p_obj1 - p_obj2;
    if (comparison != 0)
        if (comparison > 0)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<long>::                  compare(const long& p_obj1,                 const long& p_obj2)                 const
{
    long comparison = p_obj1 - p_obj2;
    if (comparison != 0)
        if (comparison > 0)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<long long>::             compare(const long long& p_obj1,            const long long& p_obj2)            const
{
    long long comparison = p_obj1 - p_obj2;
    if (comparison != 0)
        if (comparison > 0)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<unsigned char>::         compare(const unsigned char& p_obj1,        const unsigned char& p_obj2)        const
{
    int comparison = p_obj1 - p_obj2;
    if (comparison != 0)
        if (comparison > 0)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<unsigned short>::        compare(const unsigned short& p_obj1,       const unsigned short& p_obj2)       const
{
    int comparison = p_obj1 - p_obj2;
    if (comparison != 0)
        if (comparison > 0)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<unsigned>::              compare(const unsigned& p_obj1,             const unsigned& p_obj2)             const
{
    int comparison = p_obj1 - p_obj2;
    if (comparison != 0)
        if (comparison > 0)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<unsigned long>::         compare(const unsigned long& p_obj1,        const unsigned long& p_obj2)        const
{
    long comparison = p_obj1 - p_obj2;
    if (comparison != 0)
        if (comparison > 0)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<unsigned long long>::    compare(const unsigned long long& p_obj1,   const unsigned long long& p_obj2)   const
{
    unsigned long long num1 = p_obj1;
    int num1_digits = 1;
    while (num1 /= 10)
        num1_digits++;

    unsigned long long num2 = p_obj2;
    int num2_digits = 1;
    while (num2 /= 10)
        num2_digits++;

    if (num1_digits > num2_digits)
    {
        return 1;
    }
    else if (num1_digits < num2_digits)
    {
        return -1;
    }
    else
    {
        unsigned short highest_digit = 0;
        for (int _i = 0; _i < num1_digits; _i++)
        {
            unsigned long long current_power = pow(10, num1_digits) - _i;
            unsigned short num1_digit = (p_obj1 - p_obj1 % current_power) / current_power;
            unsigned short num2_digit = (p_obj2 - p_obj2 % current_power) / current_power;
            if (num1_digit > num2_digit)
            {
                return 1;
            }
            else if (num1_digit < num2_digit)
            {
                return -1;
            }
        }
        return 0;
    }

    unsigned short comparison = p_obj1 - p_obj2;
    if (comparison != 0)
        if (comparison > 0)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<float>::                 compare(const float& p_obj1,                const float& p_obj2)                const
{
    float comparison = p_obj1 - p_obj2;
    if (comparison != 0)
        if (comparison > (float)0)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<double>::                compare(const double& p_obj1,               const double& p_obj2)               const
{
    double comparison = p_obj1 - p_obj2;
    if (comparison != 0)
        if (comparison > (double)0)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TArray<long double>::           compare(const long double& p_obj1,          const long double& p_obj2)          const
{
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
