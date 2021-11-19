#pragma once

#define explspec template<>

#include <iostream>
using std::cout;
using std::endl;
#include <iomanip>
using std::setw;
using std::setfill;
#include <string>
using std::string;
using std::to_string;
#include <cmath>
using std::abs;
#include <sstream>
using std::stringstream;
#include <stdexcept>

template <typename type>
class TBinaryTreeNode
{
public:

    type value;

    TBinaryTreeNode<type> *lesser = nullptr, *greater = nullptr;

    TBinaryTreeNode(type p_value) : value(p_value) {}

};

template <typename type>
class TBinaryTree
{
protected:

    TBinaryTreeNode<type>* root = nullptr;

    inline short compare(const type& p_obj1, const type& p_obj2) const
    {
        throw std::runtime_error("There is no comparison function provided for this type.");
    }

    TBinaryTreeNode<type>* aux_copy(const TBinaryTreeNode<type>* p_other, const TBinaryTreeNode<type>*& p_node)
    {
        p_node = nullptr;
        if (p_other)
        {
            p_node = new TBinaryTreeNode<type>(p_other->value);
            p_node->lesser = aux_copy(p_other->lesser, p_node->lesser);
            p_node->greater = aux_copy(p_other->greater, p_node->greater);
        }
        return p_node;
    }

    TBinaryTreeNode<type>* aux_find(const type& p_obj, TBinaryTreeNode<type>* p_node) const
    {
        if (p_node)
        {
            short comparison = compare(p_obj, p_node->value);
            if (comparison == 0)
                return p_node;
            else
            {
                if (comparison > 0)
                    return aux_find(p_obj, p_node->greater);
                else
                    return aux_find(p_obj, p_node->lesser);
            }
        }
        return nullptr;
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
        if (p_node)
            cout << p_node->value << "\n";
        if (p_node->greater)
            aux_print_inorder(p_node->greater);
    }

    void aux_print_tree(TBinaryTreeNode<int>* p_node, string* p_lines, int p_max_length, int p_height, int i_height = 0) const
    {
        throw std::runtime_error("Tree printing is not supported for this type");
    }

    virtual TBinaryTreeNode<type>* aux_insert(const type& p_obj, TBinaryTreeNode<type>*& p_node)
    {
        if (!p_node)
            p_node = new TBinaryTreeNode<type>(p_obj);
        else
        {
            short comparison = compare(p_obj, p_node->value);
            if (comparison < 0)
                p_node->lesser = aux_insert(p_obj, p_node->lesser);
            else if (comparison > 0)
                p_node->greater = aux_insert(p_obj, p_node->greater);
        }
        return p_node;
    }

    virtual TBinaryTreeNode<type>* aux_erase(const type& p_obj, TBinaryTreeNode<type>*& p_node)
    {
        if (!p_node)
            return p_node;
        else
        {
            short comparison = compare(p_obj, p_node->value);
            if (comparison < 0)
                p_node->lesser = aux_erase(p_obj, p_node->lesser);
            else if (comparison > 0)
                p_node->greater = aux_erase(p_obj, p_node->greater);
            else
            {
                if (!(p_node->lesser))
                {
                    TBinaryTreeNode<type>* temp_node = p_node->greater;
                    delete p_node;
                    return temp_node;
                }
                else if (!(p_node->greater))
                {
                    TBinaryTreeNode<type>* temp_node = p_node->lesser;
                    delete p_node;
                    return temp_node;
                }
                else
                {
                    TBinaryTreeNode<type>* temp_node = aux_min(p_node->greater);
                    p_node->value = temp_node->value;
                    p_node->greater = aux_erase(temp_node->value, p_node->greater);
                }
            }
            return p_node;
        }
        
    }

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
        if (p_node)
        {
            if (p_node->lesser)
                aux_destroy(p_node->lesser);
            if (p_node->greater)
                aux_destroy(p_node->greater);
            delete p_node;
            p_node = nullptr;
        }
    }

public:

    TBinaryTree() {}
    TBinaryTree(const TBinaryTree<type>& p_other)
    {
        root = aux_copy(p_other.root);
    } 
    virtual ~TBinaryTree()
    {
        aux_destroy(root);
    }

    TBinaryTree<type>& operator=(const TBinaryTree<type>& p_other)
    {
        aux_destroy(root);
        root = aux_copy(p_other.root);
    }

    void print_inorder() const
    {
        aux_print_inorder(root);
        cout << endl;
    }

    void print_tree() const
    {
        throw std::runtime_error("Tree printing is not supported for this type");
    }

    void insert(const type& p_obj)
    {
        root = aux_insert(p_obj, root);
    }

    void erase(const type& p_obj)
    {
        root = aux_erase(p_obj, root);
    }

    bool contains(const type& p_obj) const
    {
        if (aux_find(p_obj, root))
            return true;
        return false;
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
    TBinaryTreeNode<int>
    *max_node = aux_max(root),
    *min_node = aux_min(root);

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
