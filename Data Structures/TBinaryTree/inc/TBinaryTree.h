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

    TBinaryTreeNode<type> *lesser = nullptr, *greater = nullptr;

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
    void aux_min(TBinaryTreeNode<type>* p_begin, TBinaryTreeNode<type>*& p_searched, TBinaryTreeNode<type>*& p_parent) const
    {
        if (p_begin->lesser)
        {
            p_parent = p_begin;
            aux_min(p_begin->lesser, p_searched, p_parent);
        }
        else
            p_searched = p_begin;
    }
    void aux_max(TBinaryTreeNode<type>* p_begin, TBinaryTreeNode<type>*& p_searched, TBinaryTreeNode<type>*& p_parent) const
    {
        if (p_begin->greater)
        {
            p_parent = p_begin;
            aux_max(p_begin->greater, p_searched, p_parent);
        }
        else
            p_searched = p_begin;
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
    void aux_print_tree(TBinaryTreeNode<int>* p_node, string* p_lines, int p_max_length, int p_height, int i_height = 0) const
    {
        throw std::runtime_error("Tree printing is not supported for this type");
    }
    #endif

    int aux_height(const TBinaryTreeNode<type>* p_node) const
    {
        if (p_node == nullptr) return -1;
        else
        {
            int left_height = aux_height(p_node->lesser);
            int right_height = aux_height(p_node->greater);

            if (left_height > right_height)
                return ++left_height;
            else
                return ++right_height;
        }
    }

    void replace_values(TBinaryTreeNode<type>* p_node1, TBinaryTreeNode<type>* p_node2)
    {
        type temp = p_node1->value;
        p_node1->value = p_node2->value;
        p_node2->value = temp;
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

    virtual TBinaryTreeNode<type>* insert(const type& p_obj)
    {
        if (root)
        {
            TBinaryTreeNode<type> *tbi = nullptr, *tbi_parent = nullptr;
            aux_find(p_obj, root, tbi, tbi_parent);
            if (tbi) return tbi;
            short comparison = compare(p_obj, tbi_parent->value);
            TBinaryTreeNode<type>* new_node = new TBinaryTreeNode<type>(p_obj);
            if (comparison > 0)
                tbi_parent->greater = new_node;
            else
                tbi_parent->lesser = new_node;
            return new_node;
        }
        else
        {
            root = new TBinaryTreeNode<type>(p_obj);
            return root;
        }
    }

    virtual bool erase(const type& p_obj)
    {
        TBinaryTreeNode<type> pseudo_root(0), *tbd = nullptr, *tbd_parent = &pseudo_root;
        pseudo_root.greater = root;
        aux_find(p_obj, root, tbd, tbd_parent);
        if (!tbd) return false;

        if (tbd->lesser)
        {
            TBinaryTreeNode<type> *tbd_lmax = nullptr, *tbd_lmax_parent = tbd;
            aux_max(tbd->lesser, tbd_lmax, tbd_lmax_parent);

            if (tbd_lmax_parent == tbd)
            {
                if (tbd_lmax->lesser)
                    tbd_lmax_parent->lesser = tbd_lmax->lesser;
                else
                    tbd_lmax_parent->lesser = nullptr;
            }
            else
            {
                if (tbd_lmax->lesser)
                    tbd_lmax_parent->greater = tbd_lmax->lesser;
                else
                    tbd_lmax_parent->greater = nullptr;
            }
            replace_values(tbd, tbd_lmax);
            tbd = tbd_lmax;
        }
        else if (tbd->greater)
        {
            TBinaryTreeNode<type> *tbd_rmin = nullptr, *tbd_rmin_parent = tbd;
            aux_min(tbd->greater, tbd_rmin, tbd_rmin_parent);
            if (tbd_rmin_parent == tbd)
            {
                if (tbd_rmin->greater)
                    tbd_rmin_parent->greater = tbd_rmin->greater;
            }
            else
            {
                if (tbd_rmin->greater)
                    tbd_rmin_parent->lesser = tbd_rmin->greater;
            }

            replace_values(tbd, tbd_rmin);
            tbd = tbd_rmin;
        }
        else
        {
            if (compare(tbd->value, tbd_parent->value) > 0)
                tbd_parent->greater = nullptr;
            else
                tbd_parent->lesser = nullptr;
        }
        delete tbd;
        root = pseudo_root.greater;
        return true;
    }

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
#include <iomanip>
using std::setw;
using std::setfill;
#include <cmath>
using std::abs;
#include <sstream>
using std::stringstream;

using std::to_string;

explspec void TBinaryTree<int>::aux_print_tree(TBinaryTreeNode<int>* p_node, string* p_lines, int p_max_length, int p_height, int i_height) const
{
    if (p_node->lesser)
        aux_print_tree(p_node->lesser, p_lines, p_max_length, p_height, i_height + 1);
    
    stringstream ss;
    if (p_node->value < 0)
        ss << setw(p_max_length - 1) << setfill('0') << to_string(abs(p_node->value));
    else
    {
        ss << setw(p_max_length) << setfill('0') << to_string(p_node->value);
    }
    for (int _i = 0; _i <= p_height; _i++)
    {
        if (_i == i_height)
            if (p_node->value < 0)
                p_lines[_i].append('-' + ss.str());
            else
                p_lines[_i].append(ss.str());
        else
        {
            for (int _j = 0; _j < p_max_length; _j++)
                p_lines[_i].append(" ");
        }
    }

    if (p_node->greater)
        aux_print_tree(p_node->greater, p_lines, p_max_length, p_height, i_height + 1);
}

explspec void TBinaryTree<int>::print_tree() const
{
    int height = aux_height(root);
    if (height < 0) return;

    short max_int_length = 1, min_int_length = 1;
    TBinaryTreeNode<int> *max_node = nullptr, *max_node_parent = nullptr, *min_node = nullptr, *min_node_parent = nullptr;
    aux_max(root, max_node, max_node_parent);
    aux_min(root, min_node, min_node_parent);
    int max_value = max_node->value, min_value = min_node->value;
    while (max_value >= 10)
    {
        max_int_length++;
        max_value/=10;
    }
    if (min_value < 0) // accounting for negative sign character
        min_int_length++;
    min_value = abs(min_value);
    while (min_value >= 10)
    {
        min_int_length++;
        min_value/=10;
    }
    if (min_int_length > max_int_length)
        max_int_length = min_int_length;

    string lines[height + 1];

    aux_print_tree(root, lines, max_int_length, height);

    for (int _i = 0; _i < height + 1; _i++)
    {
        cout << lines[_i] << '\n' << '\n';
    }
    cout << endl;
}
#endif
