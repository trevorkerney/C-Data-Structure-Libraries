#pragma once

#define explspec template<>

#include <string>
using std::string;
using std::to_string;
#include <stdexcept>
#include <cmath>
using std::pow;
#include <mutex>
using std::mutex;
using std::lock_guard;

mutex TArray_thread_guard;

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
        lock_guard<mutex> lock(TArray_thread_guard);
        if (this != &p_other)
        {
            copy(p_other);
        }    
        return *this;
    }

    type& at(const unsigned& p_index) const
    {
        lock_guard<mutex> lock(TArray_thread_guard);
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
        lock_guard<mutex> lock(TArray_thread_guard);
        return i_capacity;
    }

    size_t reserve(const unsigned& p_amount)
    {
        lock_guard<mutex> lock(TArray_thread_guard);
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
        lock_guard<mutex> lock(TArray_thread_guard);
        return linear_search(p_searched);
    }
};

template<typename type>
const size_t TArray<type>::MAX_CAPACITY;

explspec short TArray<bool>::                  compare(const bool& p_obj1,                 const bool& p_obj2)                 const
{
    lock_guard<mutex> lock(TArray_thread_guard);
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
    lock_guard<mutex> lock(TArray_thread_guard);
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
    lock_guard<mutex> lock(TArray_thread_guard);
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
    lock_guard<mutex> lock(TArray_thread_guard);
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
    lock_guard<mutex> lock(TArray_thread_guard);
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
    lock_guard<mutex> lock(TArray_thread_guard);
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
    lock_guard<mutex> lock(TArray_thread_guard);
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
    lock_guard<mutex> lock(TArray_thread_guard);
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
    lock_guard<mutex> lock(TArray_thread_guard);
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
    lock_guard<mutex> lock(TArray_thread_guard);
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
    lock_guard<mutex> lock(TArray_thread_guard);
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
    lock_guard<mutex> lock(TArray_thread_guard);
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
    lock_guard<mutex> lock(TArray_thread_guard);
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
    lock_guard<mutex> lock(TArray_thread_guard);
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
    lock_guard<mutex> lock(TArray_thread_guard);
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
    lock_guard<mutex> lock(TArray_thread_guard);
    int comparison = p_obj1.compare(p_obj2);
    if (comparison != 0)
        if (comparison > 0)
            return 1;
        else
            return -1;
    else
        return 0;
}
