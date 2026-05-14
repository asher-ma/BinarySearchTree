#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

#include "AvlNode.h"
#include "BinarySearchTree.h"

template <typename ItemType>
class AvlTree : public BinarySearchTree<ItemType> {
    private:
        int getHeight(AvlNode<ItemType>* nodePtr) const ;
        void updateHeight(AvlNode<ItemType>* nodePtr);
        int getBalanceFactor(AvlNode<ItemType>* nodePtr) const ;
        
        AvlNode<ItemType>* balance(AvlNode<ItemType>* nodePtr);
        AvlNode<ItemType>* rotateLeft(AvlNode<ItemType>* nodePtr);
        AvlNode<ItemType>* rotateRight(AvlNode<ItemType>* nodePtr);
        AvlNode<ItemType>* rotateLeftRight(AvlNode<ItemType>* nodePtr);
        AvlNode<ItemType>* rotateRightLeft(AvlNode<ItemType>* nodePtr);

    public:
        AvlTree() : BinarySearchTree<ItemType>() {}
        AvlTree(const ItemType& rootItem) : BinarySearchTree<ItemType>(rootItem) {}
        AvlTree(const AvlTree<ItemType>& tree) : BinarySearchTree<ItemType>(tree) {}

        bool add(const ItemType& newEntry); // Need to override to rebalance
        bool remove(const ItemType& anEntry); 
};

#endif