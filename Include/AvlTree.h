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

        // Overriding to include rebalance
        BinaryNode<ItemType>* insertInorder(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNode);
        BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& success);

    public:
        AvlTree() : BinarySearchTree<ItemType>() {}
        AvlTree(const ItemType& rootItem) : BinarySearchTree<ItemType>(rootItem) {}
        AvlTree(const AvlTree<ItemType>& tree) : BinarySearchTree<ItemType>(tree) {}

        bool add(const ItemType& newEntry);
};

#endif