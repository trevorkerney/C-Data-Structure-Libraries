#pragma once

#include "../../TVector/inc/TVector.h"

#include <iostream>
#include <exception>

template <typename type>
struct TUDLListNode
{
    TUDLListNode<type>* prev = nullptr;
    type value;
    TUDLListNode<type>* next = nullptr;

    TUDLListNode(type p_value) 
    {
        value = p_value;
    }

};

template <typename type>
class TUDLListIterator;

template <typename type>
class TUDLList
{
friend class TUDLListIterator<type>;
private:

    TUDLListNode<type>* i_front = nullptr;
    TUDLListNode<type>* i_back = nullptr;

    TVector<TUDLListIterator<type>*> i_iterators;

public:

    TUDLList() {}
    ~TUDLList()
    {
        TUDLListNode<type>* prev = nullptr;
        while(i_front)
        {
            prev = i_front;
            i_front = i_front->next;
            delete prev;
        }

        for (unsigned int _i = 0; _i < i_iterators.size(); _i++)
        {
            delete i_iterators[_i];
        }
    }

    void push_back(const type& p_obj)
    {
        TUDLListNode<type>* node = new TUDLListNode<type>(p_obj);
        if (i_back)
        {
            i_back->next = node;
            node->prev = i_back;
            i_back = node;
        }
        else
        {
            i_front = node;
            i_back = node;
        }
    }
    void push_back(const type* p_objs, const long& p_size)
    {
        for (unsigned int _i = 0; _i < p_size; _i++)
            push_back(p_objs[_i]);
    }

    void push_front(const type& p_obj)
    {
        TUDLListNode<type>* node = new TUDLListNode<type>(p_obj);
        if (i_front)
        {
            i_front->prev = node;
            node->next = i_front;
            i_front = node;
        }
        else
        {
            i_front = node;
            i_back = node;
        }
    }
    void push_front(const type* p_objs, const long& p_size)
    {
        for (unsigned int _i = 0; _i < p_size; _i++)
            push_front(p_objs[_i]);
    }
    
    type pop_back()
    {
        type value;
        if (i_back)
        {
            value = i_back->value;
            if (i_front == i_back)
            {
                delete i_back;
                i_front = nullptr;
                i_back = nullptr;
                for (unsigned int _i = 0; _i < i_iterators.size(); _i++)
                {
                    delete i_iterators[_i];
                }
            }
            else
            {
                i_back = i_back->prev;
                delete i_back->next;
                i_back->next = nullptr;
            }
        }
        else
        {
            throw std::runtime_error("TUDLList is empty");
        }
        return value;
    }

    type pop_front()
    {
        type value;
        if (i_front)
        {
            value = i_front->value;
            if (i_front == i_back)
            {
                delete i_front;
                i_front = nullptr;
                i_back = nullptr;
                for (unsigned int _i = 0; _i < i_iterators.size(); _i++)
                {
                    delete i_iterators[_i];
                }
            }
            else
            {
                i_front = i_front->next;
                delete i_front->prev;
                i_front->prev = nullptr;
            }
        }
        else
        {
            throw std::runtime_error("TUDLList is empty");
        }
        return value;
    }

    TUDLListIterator<type>* iterator(const short& p_start = 0)
    {
        TUDLListIterator<type>* iter = new TUDLListIterator<type>(this, p_start);
        i_iterators.push(iter);
        return iter;
    }

};

template <typename type>
class TUDLListIterator
{
friend class TUDLList<type>;
private:

    TUDLList<type>* i_master;

    TUDLListNode<type>* i_prev;
    TUDLListNode<type>* node = nullptr;
    TUDLListNode<type>* i_next;

    TUDLListIterator(TUDLList<type>* p_tudllist, const short& p_start = 0)
    {
        i_master = p_tudllist;
        if (p_start >= 0)
        {
            i_prev = nullptr;
            i_next = i_master->i_front;
        }
        else
        {
            i_next = nullptr;
            i_prev = i_master->i_back;
        }
    }
    ~TUDLListIterator() {}

public:

    bool has_next() const
    {
        if (i_next)
        {
            return true;
        }
        return false;
    }
    type next()
    {
        i_prev = node;
        node = i_next;
        i_next = node->next;
        return node->value;
    }

    bool has_prev() const
    {
        if (i_prev)
        {
            return true;
        }
        return false;
    }
    type prev()
    {
        i_next = node;
        node = i_prev;
        i_prev = node->prev;
        return node->value;
    }

    type value()
    {
        return node->value;
    }

    void clear()
    {
        i_master->i_iterators.extract(this);
        delete this;
    }

};
