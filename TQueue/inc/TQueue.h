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
        this -> i_value = p_value;
    }
    ~TQueueNode()
    {

    }


    // return value held by node
    type value() const 
    {
        return this -> i_value;
    }
    // returns pointer to node before this one
    TQueueNode<type>* prev() const
    {
        return this -> i_prev;
    }
    // returns pointer to node after this one
    TQueueNode<type>* next() const 
    {
        return this -> i_next;
    }


    // sets prev pointer to parameter
    void set_prev(TQueueNode* p_prev)
    {
        this -> i_prev = p_prev;
    }
    // sets next pointer to parameter
    void set_next(TQueueNode* p_next)
    {
        this -> i_next = p_next;
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
        this -> i_head = p_head;
    }
    
    TQueueNode<type>* i_foot = nullptr;
    // sets foot pointer to parameter
    void set_foot(TQueueNode<type>* p_foot) 
    {
        this -> i_foot = p_foot;
    }

    int i_size = 0;
    // increments i_size
    void inc_size() 
    {
        this -> i_size++;
    }
    // decrements i_size
    void dec_size() 
    {
        this -> i_size--;
    }

public:

    TQueue()
    {

    }
    ~TQueue()
    {
        TQueueNode<type>* prev_node = nullptr;
        while(this -> i_head)
        {
            prev_node = this -> i_head;
            this -> i_head = this -> i_head -> next();
            delete prev_node;
        }
    }


    // returns size of queue
    int size() const
    {
        return this -> i_size;
    }


    // inserts object at end of queue
    void push_back(type p_obj)
    {
        TQueueNode<type>* node = new TQueueNode<type>(p_obj);

        if (this -> i_head)
        {
            this -> i_foot -> set_next(node);
            node -> set_prev(i_foot);
            this -> set_foot(node);
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
        if (this -> i_head)
        {
            TQueueNode<type>* old_head = this -> i_head;
            value = old_head -> value();
            if (this -> i_head == this -> i_foot)
            {
                set_head(nullptr);
                set_foot(nullptr);
            }
            else
            {
                this -> i_head = this -> i_head -> next();
                this -> i_head -> set_prev(nullptr);
            }
            delete old_head;
            this -> dec_size();
        }
        else
        {
            throw std::runtime_error("Queue is empty");
        }
        return value;
    }

};
