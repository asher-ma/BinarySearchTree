#include "BinaryTreeAbstract.h"
#include "BinaryTree.h"

// Constructors
template <typename ItemType>
BinaryTree<ItemType>::BinaryTree(){}

template <typename ItemType>
BinaryTree<ItemType>::BinaryTree(const ItemType& rootItem) {
    rootPtr = new BinaryNode<ItemType>(rootItem);
}

// BinaryTree(const ItemType& rootItem,
//         const BinaryTree<ItemType>* leftTreePtr,
//         const BinaryTree<ItemType>* rightTreePtr);

// BinaryTree(const BinaryNodeTree<ItemType>& tree);


// Members
template <typename ItemType>
bool BinaryTree<ItemType>::isEmpty() const {
    if (rootPtr == nullptr){
        return true;
    }
    return false;
}

template <typename ItemType>
int BinaryTree<ItemType>::getHeight() const {
    return getHeightHelper(rootPtr);
}

template <typename ItemType>
int BinaryTree<ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr) const {
    if (!subTreePtr.isEmpty()){
        return 0;
    } else {
        return max(1+getHeightHelper(subTreePtr->rightChildPtr),
            1+getHeightHelper(subTreePtr->leftChildPtr));
    }
}