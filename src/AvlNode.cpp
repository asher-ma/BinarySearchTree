#include "BinaryNode.h"
#include "AvlNode.h"

// Constructors
template <typename ItemType>
AvlNode<ItemType>::AvlNode() : BinaryNode<ItemType>(), height(1) {}

template <typename ItemType>
AvlNode<ItemType>::AvlNode(const ItemType& anItem) : BinaryNode<ItemType>(anItem), height(1) {}


// Public methods

template <typename ItemType>
void AvlNode<ItemType>::setHeight(int height) {
    this->height = height;
}

template <typename ItemType>
int AvlNode<ItemType>::getHeight() const {
    return height;
}

template <typename ItemType>
AvlNode<ItemType>* AvlNode<ItemType>::getLeftChildPtr() const {
    return static_cast<AvlNode<ItemType>*>(BinaryNode<ItemType>::getLeftChildPtr());
}

template <typename ItemType>
AvlNode<ItemType>* AvlNode<ItemType>::getRightChildPtr() const {
    return static_cast<AvlNode<ItemType>*>(BinaryNode<ItemType>::getRightChildPtr());
}