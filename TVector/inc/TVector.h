#pragma once

#include <stdexcept>

template <typename type>
class TVector
{
private:

    type* i_vector;

    unsigned int i_memory_size;
    unsigned int i_size;

    float i_growth_multiplier;

    const unsigned int MAX_SIZE = 65535;

public:

    TVector(const unsigned int& p_initial_size = 2, const unsigned int& p_growth_multiplier = 2)
    {
        if (p_initial_size >= 0 && p_initial_size < MAX_SIZE)
        {
            i_vector = new type[p_initial_size];
            i_memory_size = p_initial_size;
            i_size = 0;
            i_growth_multiplier = p_growth_multiplier;
        }
        else
        {
            throw std::runtime_error("Out of allowed TArray range: 0 - " + MAX_SIZE);
        }
    }
    ~TVector()
    {
        delete i_vector;
    }

    type& at(const int& p_index) const noexcept(false)
    {
        if (p_index < 0 || p_index > i_size)
        {
            throw std::runtime_error("Out of range");
        }
        return i_vector[p_index];
    }
    type& operator[](const int& p_index) const
    {
        return at(p_index);
    }

    unsigned int size() const
    {
        return i_size;
    }

    void set_growth_multiplier(float p_multiplier)
    {
        i_growth_multiplier = p_multiplier;
    }

    float growth_multiplier(float p_multiplier) const
    {
        return i_growth_multiplier;
    }

    unsigned int reserve(const int& p_amount)
    {
        unsigned int old_memory_size = i_memory_size;

        if ((p_amount == MAX_SIZE && i_memory_size == MAX_SIZE) || p_amount <= i_memory_size)
        {
            return 0;
        }
        else if (p_amount <= MAX_SIZE)
        {
            type* new_array = new type[p_amount];
            for (unsigned int _i = 0; _i < i_size; _i++)
            {
                new_array[_i] = i_vector[_i];
            }
            i_vector = new_array;
            i_memory_size = p_amount;
            return p_amount - old_memory_size;
        }
        else
        {
            return reserve(MAX_SIZE);
        }
    }

    unsigned int shrink()
    {
        int old_memory_size = i_memory_size;
        if (i_memory_size > i_size)
        {
            type* new_array;
            if (i_size > 2)
            {
                new_array = new type[i_size];
                i_memory_size = i_size;
            }
            else
            {
                new_array = new type[2];
                i_memory_size = 2;
            }
            for (unsigned int _i = 0; _i < i_size; _i++)
            {
                new_array[_i] = i_vector[_i];
            }
            i_vector = new_array;
            return old_memory_size - i_size;
        }
        else
        {
            return 0;
        }
    }

    void push(const type p_obj) noexcept(false)
    {
        if (i_size < i_memory_size)
        {
            i_vector[i_size] = p_obj;
        }
        else
        {
            if (i_memory_size != MAX_SIZE)
            {
                reserve(i_size * i_growth_multiplier);
                push(p_obj);
            }
            else
            {
                throw std::runtime_error("Exceeded maximum capacity");
            }
        }
        i_size++;
    }

    void push(const type* p_objs, const int& p_size)
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

    void insert(const type p_obj, const int& p_index) noexcept(false)
    {
        type obj_swap1;
        type obj_swap2;
        if (i_size < i_memory_size)
        {
            obj_swap1 = at(p_index);
            at(p_index) = p_obj;
            i_size++;
        }
        else
        {
            if (i_memory_size != MAX_SIZE)
            {
                reserve(i_size * i_growth_multiplier);
                obj_swap1 = at(p_index);
                at(p_index) = p_obj;
                i_size++;
            }
            else
            {
                throw std::runtime_error("Exceeded maximum capacity");
            }
        }
        for (int _i = p_index + 1; _i < i_size; _i++)
        {
            obj_swap2 = i_vector[_i];
            i_vector[_i] = obj_swap1;
            obj_swap1 = obj_swap2;
        }
    }

    type erase(const int& p_index)
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
};
