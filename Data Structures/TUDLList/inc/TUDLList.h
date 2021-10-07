#pragma once

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

public:

    TUDLList()
    {

    }
    ~TUDLList()
    {
        TUDLListNode<type>* prev_node = nullptr;
        while(i_front)
        {
            prev_node = i_front;
            i_front = i_front -> next;
            delete prev_node;
        }
    }

    void push_back(const type& p_obj)
    {
        TUDLListNode<type>* node = new TUDLListNode<type>(p_obj);
        if (i_back)
        {
            i_back -> next = node;
            node -> prev = i_back;
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
            i_front -> prev = node;
            node -> next = i_front;
            i_front = node;

            i_back -> next = node;
            node -> prev = i_back;
            i_back = node;
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

    type next()
    {
        type value;
        if (i_front)
        {
            value = i_front -> value;
            if (i_front == i_back)
            {
                delete i_front;
                i_front = nullptr;
                i_back = nullptr;
            }
            else
            {
                i_front = i_front -> next;
                delete i_front -> prev;
                i_front -> prev = nullptr;
            }
        }
        else
        {
            throw std::runtime_error("Queue is empty");
        }
        return value;
    }
    
};

template <typename type>
class TUDLListIterator
{
private:

    TUDLListNode<type>* prev = nullptr;
    TUDLListNode<type>* node = nullptr;
    TUDLListNode<type>* next;

public:

    TUDLListIterator(const TUDLList<type>& p_tudllist)
    {
        next = p_tudllist->i_front;
    }

    bool has_next() const
    {
        if (next)
        {
            return true;
        }
        return false;
    }
    type next()
    {
        prev = node;
        node = next;
        next = node->next;
        return node->value;
    }

    bool has_prev() const
    {
        if (prev)
        {
            return true;
        }
        return false;
    }
    type prev()
    {
        next = node;
        node = prev;
        prev = node->prev;
        return node->value;
    }

    type value()
    {
        return node->value;
    }

};
