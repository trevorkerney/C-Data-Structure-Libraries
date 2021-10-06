#pragma once

#define explspec template<>

#include <string>
using std::string;
using std::to_string;

#include <stdexcept>

#include <cmath>
using std::pow;

enum searchingMethod
{
    linear, binary
};

enum sortingMethod
{
    quick, insertion, merge, shell
};

template<typename type>
class TVector
{
private:

    type* i_vector;

    unsigned int i_capacity;
    unsigned int i_size;

    float i_growth_multiplier;

    bool sorted_guarantee = true;

    static const unsigned int MAX_CAPACITY = 65535;

    void copy(const TVector& p_other)
    {
        if (p_other.i_capacity > 0)
        {
            if (i_capacity > 0)
            {
                delete[] i_vector;
            }
            i_vector = new type[p_other.i_capacity];

            for (unsigned int _i = 0; _i < p_other.i_size; _i++)
            {
                i_vector[_i] = p_other[_i];;
            }
        }
        i_capacity = p_other.i_capacity;
        i_size = p_other.i_size;
        i_growth_multiplier = p_other.i_growth_multiplier;
        sorted_guarantee = p_other.sorted_guarantee;
    }

    inline short compare(const type& p_obj1, const type& p_obj2) const
    {
        throw std::runtime_error("There is no comparison function provided for this type.");
    }
    inline unsigned int min(const unsigned int& p_index1, const unsigned int& p_index2) const
    {
        if (compare(i_vector[p_index2], i_vector[p_index1]) < 0)
            return p_index2;
        else
            return p_index1;
    }
    inline unsigned int max(const unsigned int& p_index1, const unsigned int& p_index2) const
    {
        if (compare(i_vector[p_index1], i_vector[p_index2]) < 0)
            return p_index2;
        else
            return p_index1;
    }

    inline void swap(const unsigned int& p_index1, const unsigned int& p_index2)
    {
        type obj = i_vector[p_index1];
        i_vector[p_index1] = i_vector[p_index2];
        i_vector[p_index2] = obj;
    }

    long linear_search(const type& p_searched) const
    {
        long num_of_lesser = -1;
        for (unsigned int _i = 0; _i < i_size; _i++)
        {
            int comparison = compare(p_searched, i_vector[_i]);
            if ((comparison) == 0)
                return _i;
            if (comparison > 0)
                num_of_lesser--;
        }
        return num_of_lesser;
    }
    long binary_search(const type& p_searched, const int& p_low, const int& p_high, const long& internal_mid = 0) const
    {
        if (p_high >= p_low)
        {
            long mid = (p_high - p_low) / 2 + p_low;

            short comparison = compare(i_vector[mid], p_searched);
            if (comparison != 0)
                if (comparison < 0)
                    return binary_search(p_searched, mid + 1, p_high, mid);
                else
                    return binary_search(p_searched, p_low, mid - 1, mid);
            else
                return mid;
        }
        return (internal_mid + 1) * -1;
    }

    void quick_sort(const int& p_low, const int& p_high)
    {
        auto median3 = [&](const int& p_i1, const int& p_i2, const int& p_i3)
        {
            // algorithm provided by Gyorgy Szekely - https://stackoverflow.com/a/19027761
            return max(min(p_i1, p_i2), min(max(p_i1, p_i2), p_i3));
        };
        auto partition = [&](const int& p_low, const int& p_high)
        { 
            int pivot_index = median3(p_low, p_high / 2, p_high - 1);
            type pivot = i_vector[pivot_index];
            int _i = p_low - 1;
            int _j = p_high;
            while (_i < _j)
            {
                do
                {
                    _i++;
                } while (compare(i_vector[_i], pivot) <= 0 && _i < p_high);
                do
                {
                    _j--;
                } while (compare(i_vector[_j], pivot) > 0);
                if (_i < _j)
                {
                    if (_j == pivot_index)
                    {
                        pivot_index = _i;
                    }
                    swap(_i, _j);
                }
            }
            swap(pivot_index, _j);
            return _j;
        };

        if (p_low < p_high - 1)
        {
            int pivot = partition(p_low, p_high);
            quick_sort(p_low, pivot);
            quick_sort(pivot + 1, p_high);
        }
    }

public:

    TVector(const unsigned int& p_initial_capacity = 0, const unsigned int& p_growth_multiplier = 2)
    {
        if (p_initial_capacity >= 0 && p_initial_capacity < MAX_CAPACITY)
        {
            i_size = 0;
            i_capacity = 0;
            i_growth_multiplier = p_growth_multiplier;
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
    TVector(const TVector& p_other)
    {
        i_capacity = 0;
        i_size = 0;
        i_growth_multiplier = 2;
        copy(p_other);
    }
    ~TVector()
    {
        if (i_capacity > 0)
        {
            delete[] i_vector;
            i_vector = nullptr;
        }
        i_capacity = 0;
    }

    TVector& operator=(const TVector& p_other)
    {
        if (this != &p_other)
        {
            copy(p_other);
        }    
        return *this;    
    }

    type& at(const long& p_index) const
    {
        if (p_index < 0 || p_index > i_size)
        {
            throw std::runtime_error("Out of range");
        }
        return i_vector[p_index];
    }
    type& operator[](const long& p_index) const
    {
        return at(p_index);
    }

    unsigned int size() const
    {
        return i_size;
    }

    void set_growth_multiplier(const float& p_multiplier)
    {
        i_growth_multiplier = p_multiplier;
    }

    float growth_multiplier() const
    {
        return i_growth_multiplier;
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
                for (unsigned int _i = 0; _i < i_size; _i++)
                {
                    new_array[_i] = i_vector[_i];
                }
                delete[] i_vector;
            }
            i_vector = new_array;
            i_capacity = p_amount;
            return p_amount - old_memory_size;
        }
        else
        {
            return reserve(MAX_CAPACITY);
        }
    }

    unsigned int shrink()
    {
        int old_memory_size = i_capacity;
        if (i_capacity > i_size)
        {
            type* new_array;
            if (i_size > 0)
            {
                new_array = new type[i_size];
                
                for (unsigned int _i = 0; _i < i_size; _i++)
                {
                    new_array[_i] = i_vector[_i];
                }
                delete[] i_vector;
                i_vector = new_array;
            }
            else
            {
                delete[] i_vector;
                i_vector = nullptr;
            }
            i_capacity = i_size;
            return old_memory_size - i_size;
        }
        else
        {
            return 0;
        }
    }

    long find(const type& p_searched, bool p_sorted = false, const searchingMethod& p_searching_method = searchingMethod::binary) const
    {
        if (sorted_guarantee == true)
            p_sorted = true;
        if (p_sorted == true)
        {
            switch(p_searching_method)
            {
            case searchingMethod::linear:
                return linear_search(p_searched);
            case searchingMethod::binary:
                return binary_search(p_searched, 0, i_size);
            default:
                throw std::runtime_error("Invalid searching method.");
            }
        }
        else
        {
            return linear_search(p_searched);
        }
    }
    long find(const type& p_searched, const sortingMethod& p_sorting_method, const searchingMethod& p_searching_method) const
    {
        sort(p_sorting_method);
        return find(p_searched, true, p_searching_method);
    }

    bool contains(const type& p_searched, bool p_sorted = false, const searchingMethod& p_searching_method = searchingMethod::binary) const
    {
        if (find(p_searched, p_sorted, p_searching_method) >= 0)
            return true;
        else
            return false;
    }
    bool contains(const type& p_searched, const sortingMethod& p_sorting_method, const searchingMethod& p_searching_method) const
    {
        if (find(p_searched, p_sorting_method, p_searching_method) >= 0)
            return true;
        else
            return false;
    }

    void push(const type& p_obj)
    {
        if (i_size < i_capacity)
        {
            i_vector[i_size] = p_obj;
            i_size++;
            sorted_guarantee = false;
        }
        else
        {
            if (i_capacity == 0)
            {
                reserve(1);
            }
            else if (reserve(i_capacity * i_growth_multiplier) == 0)
            {
                throw std::runtime_error("Exceeded maximum capacity");
            }
            push(p_obj);
        }
    }
    void push(const type* p_objs, const long& p_size)
    {
        for (int _i = 0; _i < p_size; _i++)
        {
            push(p_objs[_i]);
        }
    }

    type pull()
    {
        if (i_size != 0)
        {
            type& obj = i_vector[--i_size];
            return obj;
        }
        else
        {
            throw std::runtime_error("TVector is empty");
        }
    }

    void insert(const type& p_obj, const long& p_index)
    {
        type obj_swap1;
        type obj_swap2;
        if (i_capacity < MAX_CAPACITY)
        {
            if (i_size == i_capacity)
            {
                reserve(i_size * i_growth_multiplier);
            }
            obj_swap1 = at(p_index);
            at(p_index) = p_obj;
            i_size++;
            sorted_guarantee = false;
        }
        else
        {
            throw std::runtime_error("Exceeded maximum capacity");
        }
        for (int _i = p_index + 1; _i < i_size; _i++)
        {
            obj_swap2 = i_vector[_i];
            i_vector[_i] = obj_swap1;
            obj_swap1 = obj_swap2;
        }
    }

    void emplace(const type& p_obj, bool p_sorted = false, const searchingMethod& p_searching_method = searchingMethod::binary)
    {
        long sorted_index = find(p_obj, p_sorted, p_searching_method);
        if (sorted_index < 0)
            sorted_index = (sorted_index + 1) * -1;
        insert(p_obj, sorted_index);
    }
    void emplace(const type& p_obj, const sortingMethod& p_sorting_method, const searchingMethod& p_searching_method)
    {
        long sorted_index = find(p_obj, p_sorting_method, p_searching_method);
        if (sorted_index < 0)
            sorted_index = (sorted_index + 1) * -1;
        insert(p_obj, sorted_index);
    }

    type erase(const long& p_index)
    {
        type obj;
        if (i_size > 0)
        {
            obj = at(p_index);
        }
        else
        {
            throw std::runtime_error("TVector is empty");
        }
        for (int _i = p_index; _i < i_size - 1; _i++)
        {
            i_vector[_i] = i_vector[_i + 1];
        }
        i_size--;
        return obj;
    }

    type extract(const type& p_searched, bool p_sorted = false, const searchingMethod& p_searching_method = searchingMethod::binary)
    {
        short index = find(p_searched, p_sorted, p_searching_method);
        if (index < 0)
            throw std::runtime_error("Object not present in TVector.");
        else
            return erase(index);
    }
    type extract(const type& p_searched, const sortingMethod& p_sorting_method, const searchingMethod& p_searching_method)
    {
        short index = find(p_searched, p_sorting_method, p_searching_method);
        if (index < 0)
            throw std::runtime_error("Object not present in TVector.");
        else
            return erase(index);
    }

    void sort(const sortingMethod& p_method = sortingMethod::quick)
    {
        switch(p_method)
        {
        case sortingMethod::quick:
            quick_sort(0, i_size);
            break;
        
        case sortingMethod::insertion:
            //insertion_sort();
            break;
        
        case sortingMethod::merge:
            // merge_sort();
            break;
        
        case sortingMethod::shell:
            // shell_sort();
            break;

        default:
            throw std::runtime_error("Invalid sorting method.");
        }
        sorted_guarantee = true;
    }
};

explspec short TVector<bool>::                  compare(const bool& p_obj1,                 const bool& p_obj2)                 const
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
explspec short TVector<char>::                  compare(const char& p_obj1,                 const char& p_obj2)                 const
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
explspec short TVector<char16_t>::              compare(const char16_t& p_obj1,             const char16_t& p_obj2)             const
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
explspec short TVector<char32_t>::              compare(const char32_t& p_obj1,             const char32_t& p_obj2)             const
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
explspec short TVector<wchar_t>::               compare(const wchar_t& p_obj1,              const wchar_t& p_obj2)              const
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
explspec short TVector<signed char>::           compare(const signed char& p_obj1,          const signed char& p_obj2)          const
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
explspec short TVector<short>::                 compare(const short& p_obj1,                const short& p_obj2)                const
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
explspec short TVector<int>::                   compare(const int& p_obj1,                  const int& p_obj2)                  const
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
explspec short TVector<long>::                  compare(const long& p_obj1,                 const long& p_obj2)                 const
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
explspec short TVector<long long>::             compare(const long long& p_obj1,            const long long& p_obj2)            const
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
explspec short TVector<unsigned char>::         compare(const unsigned char& p_obj1,        const unsigned char& p_obj2)        const
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
explspec short TVector<unsigned short>::        compare(const unsigned short& p_obj1,       const unsigned short& p_obj2)       const
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
explspec short TVector<unsigned>::              compare(const unsigned& p_obj1,             const unsigned& p_obj2)             const
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
explspec short TVector<unsigned long>::         compare(const unsigned long& p_obj1,        const unsigned long& p_obj2)        const
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
explspec short TVector<unsigned long long>::    compare(const unsigned long long& p_obj1,   const unsigned long long& p_obj2)   const
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
explspec short TVector<float>::                 compare(const float& p_obj1,                const float& p_obj2)                const
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
explspec short TVector<double>::                compare(const double& p_obj1,               const double& p_obj2)               const
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
explspec short TVector<long double>::           compare(const long double& p_obj1,          const long double& p_obj2)          const
{
    return 0;
}
explspec short TVector<string>::                compare(const string& p_obj1,               const string& p_obj2)               const
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
