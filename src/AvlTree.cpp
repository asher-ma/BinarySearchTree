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
void AvlTree<ItemType>::updateHeight(AvlNode<ItemType>* nodePtr) {
    if (nodePtr->isLeaf()){
        nodePtr->setHeight(1);
    } else if (nodePtr->getLeftChildPtr() == nullptr) {
        nodePtr->setHeight(1+nodePtr->getRightChildPtr()->getHeight());
    } else if (nodePtr->getRightChildPtr() == nullptr) {
        nodePtr->setHeight(1+nodePtr->getLeftChildPtr()->getHeight());
    } else {
        nodePtr->setHeight(1+max(nodePtr->getLeftChildPtr()->getHeight(),
            nodePtr->getRightChildPtr()->getHeight()));
    }
}

template <typename ItemType>
int AvlTree<ItemType>::getBalanceFactor(AvlNode<ItemType>* nodePtr) const {
    if (nodePtr == nullptr) {
        return 0;
    }
    int rightHeight = 0;
    int leftHeight = 0;
    if (nodePtr->getRightChildPtr() != nullptr) {
        rightHeight = nodePtr->getRightChildPtr()->getHeight();
    }
    if (nodePtr->getLeftChildPtr() != nullptr) {
        leftHeight = nodePtr->getLeftChildPtr()->getHeight();
    }

    return rightHeight - leftHeight;
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
        if (nodePtr->getRightChildPtr()->getBalanceFactor() < 0) { // Right Left
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
    
    updateHeight(nodePtr);
    updateHeight(rightChild);

    return rightChild;
}

template <typename ItemType>
AvlNode<ItemType>* AvlTree<ItemType>::rotateRight(AvlNode<ItemType>* nodePtr) {
    AvlNode<ItemType>* leftChild = nodePtr->getLeftChildPtr();

    nodePtr->setLeftChildPtr(leftChild->getRightChildPtr());
    leftChild->setRightChildPtr(nodePtr);
    
    updateHeight(nodePtr);
    updateHeight(leftChild);

    return leftChild;
}

template <typename ItemType>
AvlNode<ItemType>* AvlTree<ItemType>::rotateLeftRight(AvlNode<ItemType>* nodePtr) {
    nodePtr->setLeftChildPtr(rotateLeft(nodePtr->getLeftChildPtr()));
    return rotateRight(nodePtr);
}

template <typename ItemType>
AvlNode<ItemType>* AvlTree<ItemType>::rotateRightLeft(AvlNode<ItemType>* nodePtr) {
    nodePtr->setRightChildPtr(rotateRight(nodePtr->getRightChildPtr()));
    return rotateLeft(nodePtr);
}


// Overridden methods

template <typename ItemType>
AvlNode<ItemType>* AvlTree<ItemType>::insertInorder(AvlNode<ItemType>* subTreePtr, AvlNode<ItemType>* newNode) {
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
AvlNode<ItemType>* AvlTree<ItemType>::removeValue(AvlNode<ItemType>* subTreePtr, const ItemType target, bool& success) {
    if (subTreePtr == nullptr) { // reached leaf
        success = false;
        return nullptr;
    } else if (subTreePtr->getItem() == target) { // reached target
        subTreePtr = static_cast<AvlNode<ItemType>*>(removeNode(subTreePtr)); // Remove the node
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
bool AvlTree<ItemType>::add(const ItemType& newEntry) {
    AvlNode<ItemType>* newNodePtr = new AvlNode<ItemType>(newEntry);
    this->rootPtr = insertInorder(this->rootPtr, newNodePtr);
    return true;
}

template <typename ItemType>
bool AvlTree<ItemType>::remove( const ItemType& anEntry) {
    bool success = false;
    this->rootPtr = removeValue(this->rootPtr, anEntry, success);
    return success;
}