#pragma once

#include <iostream>
#include <exception>

template <typename type>
class TQueueNode
{
private:

    TQueueNode<type>* i_prev = nullptr;
    type i_value;
    TQueueNode<type>* i_next = nullptr;

public:

    TQueueNode(type p_value) 
    {
        i_value = p_value;
    }
    ~TQueueNode()
    {

    }

    type value() const 
    {
        return i_value;
    }
    TQueueNode<type>* prev() const
    {
        return i_prev;
    }
    TQueueNode<type>* next() const 
    {
        return i_next;
    }
    void set_prev(TQueueNode* p_prev)
    {
        i_prev = p_prev;
    }
    void set_next(TQueueNode* p_next)
    {
        i_next = p_next;
    }
};



template <typename type>
class TQueue
{
private:

    TQueueNode<type>* i_head = nullptr;
    TQueueNode<type>* i_foot = nullptr;

    int i_size = 0;

public:

    TQueue()
    {

    }
    ~TQueue()
    {
        TQueueNode<type>* prev_node = nullptr;
        while(i_head)
        {
            prev_node = i_head;
            i_head = i_head -> next();
            delete prev_node;
        }
    }

    int size() const
    {
        return i_size;
    }

    void push(type p_obj)
    {
        TQueueNode<type>* node = new TQueueNode<type>(p_obj);

        if (i_head)
        {
            i_foot -> set_next(node);
            node -> set_prev(i_foot);
            i_foot = node;
        }
        else
        {
            set_head(node);
            set_foot(node);
        }
        i_size++;
    }

    type next()
    {
        type value;
        if (i_head)
        {
            TQueueNode<type>* old_head = i_head;
            value = old_head -> value();
            if (i_head == i_foot)
            {
                set_head(nullptr);
                set_foot(nullptr);
            }
            else
            {
                i_head = i_head -> next();
                i_head -> set_prev(nullptr);
            }
            delete old_head;
            dec_size();
        }
        else
        {
            throw std::runtime_error("Queue is empty");
        }
        return value;
    }

};
