#include "BinaryNode.h"
#include "AvlNode.h"

// Constructors
template <typename ItemType>
AvlNode<ItemType>::AvlNode() : BinaryNode<ItemType>() {}

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