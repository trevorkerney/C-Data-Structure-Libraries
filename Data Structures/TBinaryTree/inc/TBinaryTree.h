#pragma once

#define explspec template<>

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <stdexcept>

#include "../../TVector/inc/TVector.h"

template <typename type>
class TBinaryTree;

template <typename type>
class TBinaryTreeNode
{
friend class TBinaryTree<type>;
private:

    type value;

    TBinaryTreeNode<type> *lesser  = nullptr, *greater = nullptr;

    TBinaryTreeNode(type p_value) : value(p_value) {}

public:

    type& getValue()
    {
        return value;
    }

};

template <typename type>
class TBinaryTreeIterator;

template <typename type>
class TBinaryTree
{
private:

    TBinaryTreeNode<type>* root = nullptr;

    TVector<TBinaryTreeIterator<type>*> i_iterators;

    inline short compare(const type& p_obj1, const type& p_obj2) const
    {
        throw std::runtime_error("There is no comparison function provided for this type.");
    }

    TBinaryTreeNode<type>* aux_copy(const TBinaryTreeNode<type>* p_other)
    {
        TBinaryTreeNode<type>* node = nullptr;
        if (p_other)
        {
            node = new TBinaryTreeNode<type>(p_other->value);
            node->lesser = aux_copy(p_other->lesser);
            node->greater = aux_copy(p_other->greater);
        }
        return node;
    }

    TBinaryTreeNode<type>* aux_min(TBinaryTreeNode<type>* p_node) const
    {
        if (p_node->lesser)
            return aux_min(p_node->lesser);
        else
            return p_node;
    }

    TBinaryTreeNode<type>* aux_max(TBinaryTreeNode<type>* p_node) const
    {
        if (p_node->greater)
            return aux_max(p_node->greater);
        else
            return p_node;
    }

    void aux_print_inorder(TBinaryTreeNode<type>* p_node) const
    {
        if (p_node->lesser)
            aux_print_inorder(p_node->lesser);
        cout << p_node->value << "\n";
        if (p_node->greater)
            aux_print_inorder(p_node->greater);
    }

    #ifdef _DEBUG
    void aux_print_tree(TBinaryTreeNode<int>* p_node, string*& p_lines, int p_rows, int pi_depth = 0) const
    {
        throw std::runtime_error("Tree printing is not supported for this type");
    }
    #endif

    int aux_depth(const TBinaryTreeNode<type>* p_node) const
    {
        if (p_node == nullptr) return -1;
        else
        {
            int left_depth = aux_depth(p_node->lesser);
            int right_depth = aux_depth(p_node->greater);

            if (left_depth > right_depth)
                return ++left_depth;
            else
                return ++right_depth;
        }
    }

    void aux_find(const type& p_obj, TBinaryTreeNode<type>* p_begin, TBinaryTreeNode<type>*& p_searched, TBinaryTreeNode<type>*& p_parent) const
    {
        if (p_begin)
        {
            short comparison = compare(p_obj, p_begin->value);
            if (comparison == 0)
                p_searched = p_begin;
            else
            {
                p_parent = p_begin;
                if (comparison > 0)
                    aux_find(p_obj, p_begin->greater, p_searched, p_parent);
                else
                    aux_find(p_obj, p_begin->lesser, p_searched, p_parent);
            }
        }
    }

    void aux_insert(const type& p_obj, TBinaryTreeNode<type>* p_node)
    {
        short comparison = compare(p_obj, p_node->value);
        if (comparison > 0)
        {
            if (p_node->greater)
                aux_insert(p_obj, p_node->greater);
            else
                p_node->greater = new TBinaryTreeNode<type>(p_obj);
        }
        else if (comparison < 0)
        {
            if (p_node->lesser)
                aux_insert(p_obj, p_node->lesser);
            else
                p_node->lesser = new TBinaryTreeNode<type>(p_obj);
        }
    }

    void aux_destroy(TBinaryTreeNode<type>* p_node)
    {
        if (p_node->lesser)
            aux_destroy(p_node->lesser);
        if (p_node->greater)
            aux_destroy(p_node->greater);
        delete p_node;
        p_node = nullptr;
    }

public:

    TBinaryTree() {}
    TBinaryTree(const TBinaryTree<type>& p_other)
    {
        if (p_other.root)
            this->root = aux_copy(p_other.root);
    } 
    virtual ~TBinaryTree()
    {
        aux_destroy(root);

        for (size_t _i = 0; _i < i_iterators.size(); _i++)
        {
            delete i_iterators[_i];
        }
    }

    TBinaryTree<type>& operator=(const TBinaryTree<type>& p_other)
    {
        aux_destroy(root);
        for (size_t _i = 0; _i < i_iterators.size(); _i++)
        {
            delete i_iterators[_i];
        }

        root = aux_copy(p_other);
    }

    void print_inorder() const
    {
        if (root)
        {
            aux_print_inorder(root);
            cout << endl;
        }
    }

    #ifdef _DEBUG
    void print_tree() const
    {
        throw std::runtime_error("Tree printing is not supported for this type");
    }
    #endif

    virtual void insert(const type& p_obj)
    {
        if (root)
            aux_insert(p_obj, root);
        else
            root = new TBinaryTreeNode<type>(p_obj);
    }

    /* bool delete(const type& p_obj)
    {

        TBinaryTreeNode<type>* parent = aux_find(p_obj, root, -1, nullptr);
        if (!parent) return false;
        TBinaryTreeNode<type>* tbd; // to be deleted
        bool direction;
        if (compare(p_obj, parent->greater->value) == 0)
        {
            direction = true;
            tbd = parent->greater;
        }
        else
        {
            direction = false;
            tbd = parent->lesser;
        }

        TBinaryTreeNode<type>* replacement = nullptr;
        if (tbd->lesser)
        {
            replacement = tbd->lesser;
            TBinaryTreeNode<type>* greatest_child = tbd->lesser;
            while (greatest_child->greater)
                greatest_child = greatest_child->greater;
            greatest_child->greater = tbd->greater;
        }
        else if (tbd->greater)
            replacement = tbd->greater;

        if (direction)
            parent->greater = replacement;
        else
            parent->lesser = replacement;
        delete tbd;
        return true;

    } */

    bool contains(const type& p_obj) const
    {
        TBinaryTreeNode<type> *tbd = nullptr, *parent = nullptr;
        aux_find(p_obj, root, tbd, parent);
        if (tbd)
            return true;
        return false;
    }

    TBinaryTreeIterator<type>* iterator()
    {
        if (root)
        {
            TBinaryTreeIterator<type>* iter = new TBinaryTreeIterator<type>(this);
            i_iterators.push(iter);
            return iter;
        }
        else
            return nullptr;
    }

};

template <typename type>
class TBinaryTreeIterator
{
friend class TBinaryTree<type>;
private:

    TBinaryTree<type>* master;
    TBinaryTreeNode<type>* node;

    TBinaryTreeIterator(TBinaryTree<type>* p_tbinarytree) : master(p_tbinarytree)
    {
        node = master->root;
    }
    ~TBinaryTreeIterator() {}

public:

    bool has_lesser() const
    {
        if (node->lesser)
            return true;
        return false;
    }

    type& lesser()
    {
        node = node->lesser;
        return node->value;
    }

    bool has_greater() const
    {
        if (node->greater)
            return true;
        return false;
    }

    type& greater()
    {
        node = node->greater;
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

explspec short TBinaryTree<bool>::                  compare(const bool& p_obj1,                 const bool& p_obj2)                 const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TBinaryTree<char>::                  compare(const char& p_obj1,                 const char& p_obj2)                 const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TBinaryTree<signed char>::           compare(const signed char& p_obj1,          const signed char& p_obj2)          const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TBinaryTree<short>::                 compare(const short& p_obj1,                const short& p_obj2)                const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TBinaryTree<int>::                   compare(const int& p_obj1,                  const int& p_obj2)                  const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TBinaryTree<long>::                  compare(const long& p_obj1,                 const long& p_obj2)                 const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TBinaryTree<long long>::             compare(const long long& p_obj1,            const long long& p_obj2)            const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TBinaryTree<unsigned char>::         compare(const unsigned char& p_obj1,        const unsigned char& p_obj2)        const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TBinaryTree<unsigned short>::        compare(const unsigned short& p_obj1,       const unsigned short& p_obj2)       const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TBinaryTree<unsigned>::              compare(const unsigned& p_obj1,             const unsigned& p_obj2)             const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TBinaryTree<unsigned long>::         compare(const unsigned long& p_obj1,        const unsigned long& p_obj2)        const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0; 
}
explspec short TBinaryTree<unsigned long long>::    compare(const unsigned long long& p_obj1,   const unsigned long long& p_obj2)   const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TBinaryTree<float>::                 compare(const float& p_obj1,                const float& p_obj2)                const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TBinaryTree<double>::                compare(const double& p_obj1,               const double& p_obj2)               const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TBinaryTree<long double>::           compare(const long double& p_obj1,          const long double& p_obj2)          const
{
    if (p_obj1 != p_obj2)
        if (p_obj1 > p_obj2)
            return 1;
        else
            return -1;
    else
        return 0;
}
explspec short TBinaryTree<string>::                compare(const string& p_obj1,               const string& p_obj2)               const
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

#ifdef _DEBUG
#include <iostream>
using std::cout;
using std::endl;
#include <cmath>
using std::pow;

/* explspec void TBinaryTree<int>::aux_print_tree(TBinaryTreeNode<int>* p_node, string*& p_lines, int p_rows, int pi_depth) const
{
    if (!p_node) return;

    if (p_node->lesser)
        aux_print_tree(p_node->lesser, p_lines, p_rows, pi_depth++);

} */

explspec void TBinaryTree<int>::print_tree() const
{

    int depth = aux_depth(root);
    if (depth < 0) return;

    short max_int_length = 1;
    int max_value = aux_max(root)->value;
    while (max_value >= 10)
    {
        max_int_length++;
        max_value/=10;
    }

    unsigned int
    columns = (int)pow(2.0f, depth) * 2 * max_int_length - max_int_length,
    rows = depth * 2 + 1;

    string lines[rows];
    
}
#endif
