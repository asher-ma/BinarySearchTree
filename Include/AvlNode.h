#ifndef _AVL_NODE_H_
#define _AVL_NODE_H_

#include "BinaryNode.h"

template <typename ItemType>
class AvlNode : public BinaryNode<ItemType>{
    private:
        int height; // To calculate balance factor of parent with O(1)
    public:
        AvlNode();
        AvlNode(const ItemType& anItem);
        AvlNode(const ItemType& anItem, AvlNode<ItemType>* leftPtr,
        AvlNode<ItemType>* rightPtr);
        void setHeight(int height);
        int getHeight() const ;
};

#include "../src/AvlNode.cpp"

#endif