#include "BinaryNode.h"

template <typename ItemType>
BinaryNode<ItemType>::BinaryNode(){}

template <typename ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem): item(anItem),
    leftChildPtr(nullptr), rightChildPtr(nullptr) {}

template <typename ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem, BinaryNode<ItemType>*
leftPtr, BinaryNode<ItemType>* rightPtr) :item(anItem), leftChildPtr(leftPtr),
    rightChildPtr(rightPtr) {};

template <typename ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem){
    this->item = anItem;
}

template <typename ItemType>
ItemType BinaryNode<ItemType>::getItem() const {
    return this->item;
}

template <typename ItemType>
bool BinaryNode<ItemType>::isLeaf() const {
    return (this->leftChildPtr == nullptr && this->rightChildPtr == nullptr);
}

template <typename ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const {
    return this->leftChildPtr;
}

template <typename ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const {
    return this->rightChildPtr;
}

template <typename ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode<ItemType>* leftPtr) {
    this->leftChildPtr = leftPtr;
}

template <typename ItemType>
void BinaryNode<ItemType>::setRightChildPtr(BinaryNode<ItemType>* rightPtr) {
    this->rightChildPtr = rightPtr;
}