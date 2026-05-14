#include "BinarySearchTree.h"
#include "AvlTree.h"


// Constructors

template <typename ItemType>
AvlTree<ItemType>::AvlTree() : BinarySearchTree<ItemType>() {}

template <typename ItemType>
AvlTree<ItemType>::AvlTree(const ItemType& rootItem) : BinarySearchTree<ItemType>(rootItem) {}

template <typename ItemType>
AvlTree<ItemType>::AvlTree(const AvlTree<ItemType>& tree) : BinarySearchTree<ItemType>(tree) {
    // TODO: Balance given tree
}


// Private methods

template <typename ItemType>
int AvlTree<ItemType>::getHeight(AvlNode<ItemType>* nodePtr) const {
    return nodePtr->getHeight();
}

// Should be called after recursion while traversing back up tree
template <typename ItemType>
void AvlTree<ItemType>::updateHeight(AvlNode<ItemType>* nodePtr) {
    if (nodePtr->isLeaf()){
        nodePtr->setHeight(1);
    } else {
        nodePtr->setHeight(1+max(nodePtr->getLeftChildPtr()->getHeight(),
            nodePtr->getRightChildPtr()->getHeight()));
    }
}

template <typename ItemType>
int AvlTree<ItemType>::getBalanceFactor(AvlNode<ItemType>* nodePtr) const {
    return nodePtr->getRightChildPtr()->getHeight() - nodePtr->getLeftChildPtr()->getHeight();
}

template <typename ItemType>
AvlNode<ItemType>* AvlTree<ItemType>::balance(AvlNode<ItemType>* nodePtr) {
    int BF = nodePtr->getBalanceFactor();
    if (BF < -1) { // Left heavy
        if (nodePtr->getLeftChildPtr()->getBalanceFactor() > 0) { // Left Right
            return rotateLeftRight(nodePtr);
        } else { // Left Right
            return rotateRight(nodePtr);
        }
    } else if (BF > 1) { // Right heavy
        if (nodePtr->getRightChildPtr()->getBalanceFactor() <0) { // Right Left
            return rotateRightLeft(nodePtr);
        } else { // Right Right
            return rotateLeft(nodePtr);
        }
    } else {
        return nodePtr;
    }
}


// Rotations

template <typename ItemType>
AvlNode<ItemType>* AvlTree<ItemType>::rotateLeft(AvlNode<ItemType>* nodePtr) {
    AvlNode<ItemType>* rightChild = nodePtr->getRightChildPtr();

    nodePtr->setRightChildPtr(rightChild->getLeftChildPtr());
    rightChild->setLeftChildPtr(nodePtr);
    
    nodePtr->updateHeight();
    rightChild->updateHeight();

    return rightChild;
}

template <typename ItemType>
AvlNode<ItemType>* AvlTree<ItemType>::rotateRight(AvlNode<ItemType>* nodePtr) {
    AvlNode<ItemType>* leftChild = nodePtr->getLeftChildPtr();

    nodePtr->setLeftChildPtr(leftChild->getRightChildPtr());
    leftChild->setRightChildPtr(nodePtr);
    
    nodePtr->updateHeight();
    leftChild->updateHeight();

    return leftChild;
}

template <typename ItemType>
AvlNode<ItemType>* AvlTree<ItemType>::rotateLeftRight(AvlNode<ItemType>* nodePtr) {}

template <typename ItemType>
AvlNode<ItemType>* AvlTree<ItemType>::rotateRightLeft(AvlNode<ItemType>* nodePtr) {}


// Overridden methods

template <typename ItemType>
BinaryNode<ItemType>* AvlTree<ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& success) {
    if (subTreePtr == nullptr) { // reached leaf
        success = false;
        return nullptr;
    } else if (subTreePtr->getItem() == target) { // reached target
        subTreePtr = removeNode(subTreePtr); // Remove the node
        if (subTreePtr != nullptr) {
            subTreePtr = balance(subTreePtr); // Balance node if not a leaf
        }
        success = true;
        return subTreePtr;
    }

    AvlNode<ItemType>* tempPtr;
    if (subTreePtr->getItem() > target) {
        // Search the left subtree
        tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, success);
        subTreePtr->setLeftChildPtr(tempPtr);
        subTreePtr = balance(subTreePtr); // Balance node after recursion
        return subTreePtr;
    } else {
        // Search the right subtree
        tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, success);
        subTreePtr->setRightChildPtr(tempPtr);
        subTreePtr = balance(subTreePtr); // Balance node after recursion
        return subTreePtr;
    }
}

template <typename ItemType>
BinaryNode<ItemType>* AvlTree<ItemType>::insertInorder(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNode) {
    if (subTreePtr == nullptr) {
        return newNode;
    }

    AvlNode<ItemType>* tempPtr;
    if (subTreePtr->getItem() > newNode->getItem()) {
        tempPtr = insertInorder(subTreePtr->getLeftChildPtr(), newNode);
        subTreePtr->setLeftChildPtr(tempPtr);
        subTreePtr = balance(subTreePtr); // Balance node after recursion
    } else {
        tempPtr = insertInorder(subTreePtr->getRightChildPtr(), newNode);
        subTreePtr->setRightChildPtr(tempPtr);
        subTreePtr = balance(subTreePtr); // Balance node after recursion
    }
    return subTreePtr;
}

template <typename ItemType>
bool AvlTree<ItemType>::add(const ItemType& newEntry) {
    AvlNode<ItemType>* newNodePtr = new AvlNode<ItemType>(newEntry);
    this->rootPtr = insertInorder(this->rootPtr, newNodePtr);
    return true;
}