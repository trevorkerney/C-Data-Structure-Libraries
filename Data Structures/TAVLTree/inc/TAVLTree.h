#pragma once

#include "../../TBinaryTree/inc/TBinaryTree.h"

template <typename type>
class TAVLTree : public TBinaryTree<type>
{
private:

    int balance(TBinaryTreeNode<type>* p_node) const
    {
        if (p_node)
            return this->aux_height(p_node->lesser) - this->aux_height(p_node->greater);
        return 0;
    }

    TBinaryTreeNode<type>* left_rotate(TBinaryTreeNode<type>* p_node)
    {
        TBinaryTreeNode<type>
        *child = p_node->greater,
        *child_lesser = child->lesser;

        child->lesser = p_node;
        p_node->greater = child_lesser;
        return child;
    }
    TBinaryTreeNode<type>* right_rotate(TBinaryTreeNode<type>* p_node)
    {
        TBinaryTreeNode<type>
        *child = p_node->lesser,
        *child_greater = child->greater;

        child->greater = p_node;
        p_node->lesser = child_greater;
        return child;
    }

    TBinaryTreeNode<type>* aux_insert(const type& p_obj, TBinaryTreeNode<type>*& p_node) override
    {
        if (!p_node)
            p_node = new TBinaryTreeNode<type>(p_obj);
        else
        {
            short comparison = this->compare(p_obj, p_node->value);
            if (comparison < 0)
                p_node->lesser = aux_insert(p_obj, p_node->lesser);
            else if (comparison > 0)
                p_node->greater = aux_insert(p_obj, p_node->greater);
        }

        int balance_factor = balance(p_node);
        if (balance_factor > 1)
        {
            short comparison = this->compare(p_obj, p_node->lesser->value);
            if (comparison < 0)
                return right_rotate(p_node);
            else
            {
                p_node->lesser = left_rotate(p_node->lesser);
                return right_rotate(p_node);
            }
        }
        else if (balance_factor < -1)
        {
            short comparison = this->compare(p_obj, p_node->greater->value);
            if (comparison > 0)
                return left_rotate(p_node);
            else
            {
                p_node->greater = right_rotate(p_node->greater);
                return left_rotate(p_node);
            }
        }

        return p_node;
    }

    TBinaryTreeNode<type>* aux_erase(const type& p_obj, TBinaryTreeNode<type>*& p_node) override
    {
        if (!p_node)
            return p_node;
        else
        {
            short comparison = this->compare(p_obj, p_node->value);
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
                    TBinaryTreeNode<type>* temp_node = this->aux_min(p_node->greater);
                    p_node->value = temp_node->value;
                    p_node->greater = aux_erase(temp_node->value, p_node->greater);
                }
            }

            int balance_factor = balance(p_node);
            if (balance_factor > 1)
            {
                int lesser_balance_factor = balance(p_node->lesser);
                if (lesser_balance_factor < 0)
                {
                    p_node->lesser = left_rotate(p_node->lesser);
                    return right_rotate(p_node);
                }
                else
                {
                    return right_rotate(p_node);
                }
            }
            else if (balance_factor < -1)
            {
                int greater_balance_factor = balance(p_node->greater);
                if (greater_balance_factor > 0)
                {
                    p_node->greater = right_rotate(p_node->greater);
                    return left_rotate(p_node);
                }
                else
                {
                    return left_rotate(p_node);
                }
            }

            return p_node;
        }
        
    }

public:

    TAVLTree() {}
    ~TAVLTree() {}

};
