#ifndef H_TUDLLIST
#define H_TUDLLIST

#include <iostream>
#include <exception>

#include <mutex>
using std::mutex;
using std::lock_guard;

#include "../../TVector/inc/TVector.h"

mutex TUDLList_thread_guard;

template <typename type>
struct TUDLListNode
{
    type value;
    TUDLListNode<type>* prev = nullptr;
    TUDLListNode<type>* next = nullptr;

    TUDLListNode(type p_value) : value(p_value) {}

};

template <typename type>
class TUDLListIterator;

template <typename type>
class TUDLList
{
friend class TUDLListIterator<type>;
private:

    TUDLListNode<type>* front = nullptr;
    TUDLListNode<type>* back = nullptr;

    TVector<TUDLListIterator<type>*> i_iterators;

    void copy(const TUDLList& p_other)
    {
        if (p_other.front)
        {
            TUDLListNode<type>* other_node = p_other.front;
            this->front = new TUDLListNode<type>(p_other.front->value);
            TUDLListNode<type>* this_node = this->front;
            while (other_node->next)
            {
                other_node = other_node->next;
                this_node->next = new TUDLListNode<type>(other_node->value);
                this_node->next->prev = this_node;
                this_node = this_node->next;
            }
            this->back = this_node;
        }
    }

public:

    TUDLList() {}
    TUDLList(const TUDLList& p_other)
    {
        copy(p_other);
    }
    ~TUDLList()
    {
        TUDLListNode<type>* prev = nullptr;
        while(front)
        {
            prev = front;
            front = front->next;
            delete prev;
        }

        for (unsigned int _i = 0; _i < i_iterators.size(); _i++)
            delete i_iterators[_i];
    }

    TUDLList& operator=(const TUDLList& p_other)
    {
        lock_guard<mutex> lock(TUDLList_thread_guard);
        TUDLListNode<type>* prev = nullptr;
        TUDLListNode<type>* node = this->front;
        while (node)
        {
            prev = node;
            node = node->next;
            delete prev;
        }
        copy(p_other);
    }

    bool is_empty() const
    {
        lock_guard<mutex> lock(TUDLList_thread_guard);
        if (!front)
            return true;
        return false;
    }

    void push_back(const type& p_obj)
    {
        lock_guard<mutex> lock(TUDLList_thread_guard);
        TUDLListNode<type>* node = new TUDLListNode<type>(p_obj);
        if (back)
        {
            back->next = node;
            node->prev = back;
            back = node;
        }
        else
        {
            front = node;
            back = node;
        }
    }
    void push_back(const type* p_objs, const long& p_size)
    {
        lock_guard<mutex> lock(TUDLList_thread_guard);
        for (unsigned int _i = 0; _i < p_size; _i++)
            push_back(p_objs[_i]);
    }

    void push_front(const type& p_obj)
    {
        lock_guard<mutex> lock(TUDLList_thread_guard);
        TUDLListNode<type>* node = new TUDLListNode<type>(p_obj);
        if (front)
        {
            front->prev = node;
            node->next = front;
            front = node;
        }
        else
        {
            front = node;
            back = node;
        }
    }
    void push_front(const type* p_objs, const long& p_size)
    {
        lock_guard<mutex> lock(TUDLList_thread_guard);
        for (unsigned int _i = 0; _i < p_size; _i++)
            push_front(p_objs[_i]);
    }

    type pull_back()
    {
        lock_guard<mutex> lock(TUDLList_thread_guard);
        type value = back->value;
        if (back)
        {
            back = back->prev;
            back->next = nullptr;
        }
        else
        {
            throw std::runtime_error("List is empty.");
        }
        return value;
    }

    type pull_front()
    {
        lock_guard<mutex> lock(TUDLList_thread_guard);
        type value = front->value;
        if (front)
        {
            front = front->next;
            front->prev = nullptr;
        }
        else
        {
            throw std::runtime_error("List is empty.");
        }
        return value;
    }

    TUDLListIterator<type>* iterator(const short& p_start = 0)
    {
        lock_guard<mutex> lock(TUDLList_thread_guard);
        if (front)
        {
            TUDLListIterator<type>* iter = new TUDLListIterator<type>(this, p_start);
            i_iterators.push(iter);
            return iter;
        }
        else
            return nullptr;
    }

};

template <typename type>
class TUDLListIterator
{
friend class TUDLList<type>;
private:

    TUDLList<type>* master;

    TUDLListNode<type>* node = nullptr;

    TUDLListIterator(TUDLList<type>* p_tudllist, const short& p_start = 0) : master(p_tudllist)
    {
        if (p_start >= 0)
        {
            node = master->front;
        }
        else
        {
            node = master->back;
        }
    }
    ~TUDLListIterator() {}

public:

    bool has_next() const
    {
        if (node->next)
        {
            return true;
        }
        return false;
    }
    type& next()
    {
        node = node->next;
        return node->value;
    }

    bool has_prev() const
    {
        if (node->prev)
        {
            return true;
        }
        return false;
    }
    type& prev()
    {
        node = node->prev;
        return node->value;
    }

    type value() const
    {
        return node->value;
    }

    void clear()
    {
        master->i_iterators.extract(this);
        delete this;
    }

};

#endif
