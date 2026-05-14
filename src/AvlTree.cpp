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
AvlNode<ItemType>* AvlTree<ItemType>::rotateLeft(AvlNode<ItemType>* nodePtr) {}

template <typename ItemType>
AvlNode<ItemType>* AvlTree<ItemType>::rotateRight(AvlNode<ItemType>* nodePtr) {}

template <typename ItemType>
AvlNode<ItemType>* AvlTree<ItemType>::rotateLeftRight(AvlNode<ItemType>* nodePtr) {}

template <typename ItemType>
AvlNode<ItemType>* AvlTree<ItemType>::rotateRightLeft(AvlNode<ItemType>* nodePtr) {}


// Public Methods

template <typename ItemType>
bool AvlTree<ItemType>::add(const ItemType& newEntry) {
    return false;
}

template <typename ItemType>
bool AvlTree<ItemType>::remove(const ItemType& anEntry) {
    return false;
}