#pragma once

#include <stdexcept>

template <typename type>
class TArray
{
private:

    type* i_array;

    unsigned int i_size;
    void inc_size(int p_amount = 1)
    {
        i_size += p_amount;
    }

    const unsigned int MAX_SIZE = 65535;

public:

    TArray(int p_initial_size = 2)
    {
        if (p_initial_size >= 0 && p_initial_size < this -> MAX_SIZE)
        {
            this -> i_array = new type[p_initial_size];
            this -> i_size = p_initial_size;
        }
        else
        {
            throw std::runtime_error("Out of allowed TArray range: 0 - " + this -> MAX_SIZE);
        }
    }
    ~TArray()
    {
        delete i_array;
    }

    type& operator[](int p_index)
    {
        return this -> at(p_index);
    }

    int size() const
    {
        return this -> i_size;
    }

    type& at(int p_index) const noexcept(false)
    {
        if (!(p_index >= 0 && p_index < this -> size()))
        {
            throw std::runtime_error("Out of range");
        }
        return this -> i_array[p_index];
    }
    type& operator[](const int p_index) const
    {
        return at(p_index);
    }

    void reserve(int p_amount) noexcept(false)
    {
        if (p_amount > this -> size() && p_amount <= this -> MAX_SIZE)
        {
            type* new_array = new type[p_amount];
            for (unsigned int _i = 0; _i < this -> size(); _i++)
            {
                new_array[_i] = i_array[p_amount];
                this -> i_array = new_array;
            }
            this -> inc_size(p_amount - this -> size());
        }
        else
        {
            throw std::runtime_error("Out of range");
        }
    }

};
