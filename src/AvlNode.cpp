#include "BinaryNode.h"
#include "AvlNode.h"

// Constructors
template <typename ItemType>
AvlNode<ItemType>::AvlNode() : BinaryNode() {}

template <typename ItemType>
AvlNode<ItemType>::AvlNode(const ItemType& anItem) : BinaryNode(anItem),
    height(this.getHeight()) {}

// Public methods
template <typename ItemType>
void AvlNode<ItemType>::setHeight(int height) {
    this.height = height;
}

template <typename ItemType>
int AvlNode<ItemType>::getHeight() const {
    return height;
}