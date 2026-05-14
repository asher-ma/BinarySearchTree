#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

#include "AvlNode.h"
#include "BinarySearchTree.h"

template <typename ItemType>
class AvlTree : public BinarySearchTree<ItemType> {
    private:
        void updateHeight(AvlNode<ItemType>* nodePtr);
        int getBalanceFactor(AvlNode<ItemType>* nodePtr) const ;
        
        AvlNode<ItemType>* balance(AvlNode<ItemType>* nodePtr);
        AvlNode<ItemType>* rotateLeft(AvlNode<ItemType>* nodePtr);
        AvlNode<ItemType>* rotateRight(AvlNode<ItemType>* nodePtr);
        AvlNode<ItemType>* rotateLeftRight(AvlNode<ItemType>* nodePtr);
        AvlNode<ItemType>* rotateRightLeft(AvlNode<ItemType>* nodePtr);

        // Overloading to include rebalance
        AvlNode<ItemType>* insertInorder(AvlNode<ItemType>* subTreePtr, AvlNode<ItemType>* newNode);
        AvlNode<ItemType>* removeValue(AvlNode<ItemType>* subTreePtr, const ItemType target, bool& success);

    public:
        AvlTree() : BinarySearchTree<ItemType>() {}
        AvlTree(const ItemType& rootItem) : BinarySearchTree<ItemType>(rootItem) {}
        AvlTree(const AvlTree<ItemType>& tree) : BinarySearchTree<ItemType>(tree) {}

        // Overriding to call new overloaded helpers
        bool add(const ItemType& newEntry);
        bool remove( const ItemType& anEntry);
};

#include "../src/AvlTree.cpp"

#endif