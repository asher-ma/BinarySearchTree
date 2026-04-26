#include "BinaryTree.h"

// Constructors
BinaryTree<ItemType>::BinaryTree(){}

BinaryTree<ItemType>::BinaryTree(const ItemType& rootItem), rootItem(rootItem) {
    rootPtr = new BinaryNode(rootItem);
}

// BinaryTree(const ItemType& rootItem,
//         const BinaryTree<ItemType>* leftTreePtr,
//         const BinaryTree<ItemType>* rightTreePtr);

// BinaryTree(const BinaryNodeTree<ItemType>& tree);


// Members
bool isEmpty(){
    if (rootItem == nullptr){
        return true;
    }
    return false;
}

int getHeight(){
    return getHeightHelper(rootPtr);
}

int getHeightHelper(BinaryNode<ItemType>* subTreePtr) {
    if (!subTreePtr.isEmpty()){
        return 0;
    } else {
        return max(1+getHeightHelper(subTreePtr->rightChildPtr),
            1+getHeightHelper(subTreePtr->leftChildPtr));
    }
}