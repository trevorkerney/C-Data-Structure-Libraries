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


    // return value held by node
    type value() const 
    {
        return i_value;
    }
    // returns pointer to node before this one
    TQueueNode<type>* prev() const
    {
        return i_prev;
    }
    // returns pointer to node after this one
    TQueueNode<type>* next() const 
    {
        return i_next;
    }


    // sets prev pointer to parameter
    void set_prev(TQueueNode* p_prev)
    {
        i_prev = p_prev;
    }
    // sets next pointer to parameter
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
    // sets head pointer to parameter
    void set_head(TQueueNode<type>* p_head)
    {
        i_head = p_head;
    }
    
    TQueueNode<type>* i_foot = nullptr;
    // sets foot pointer to parameter
    void set_foot(TQueueNode<type>* p_foot) 
    {
        i_foot = p_foot;
    }

    int i_size = 0;
    // increments i_size
    void inc_size() 
    {
        i_size++;
    }
    // decrements i_size
    void dec_size() 
    {
        i_size--;
    }

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


    // returns size of queue
    int size() const
    {
        return i_size;
    }


    // inserts object at end of queue
    void push_back(type p_obj)
    {
        TQueueNode<type>* node = new TQueueNode<type>(p_obj);

        if (i_head)
        {
            i_foot -> set_next(node);
            node -> set_prev(i_foot);
            set_foot(node);
        }
        else
        {
            set_head(node);
            set_foot(node);
        }
        inc_size();
    }
    // removes the head of the queue and returns its value
    type next(int p_quiet = 0) noexcept(false)
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
