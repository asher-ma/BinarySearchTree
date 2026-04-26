#include "BinaryTreeAbstract.h"
#include "BinaryTree.h"

// Constructors
template <typename ItemType>
BinaryTree<ItemType>::BinaryTree(){}

template <typename ItemType>
BinaryTree<ItemType>::BinaryTree(const ItemType& rootItem) {
    this->rootPtr = new BinaryNode<ItemType>(rootItem);
}

// BinaryTree(const ItemType& rootItem,
//         const BinaryTree<ItemType>* leftTreePtr,
//         const BinaryTree<ItemType>* rightTreePtr);

// BinaryTree(const BinaryNodeTree<ItemType>& tree);

// Destructor
template <typename ItemType>
BinaryTree<ItemType>::~BinaryTree() {}

// Members
// Returns true if tree is empty
template <typename ItemType>
bool BinaryTree<ItemType>::isEmpty() const {
    if (this->rootPtr == nullptr){
        return true;
    }
    return false;
}

// Returns height of tree
template <typename ItemType>
int BinaryTree<ItemType>::getHeight() const {
    return getHeightHelper(this->rootPtr);
}

// Finds height by recursing down each branch and returning length of longest path
template <typename ItemType>
int BinaryTree<ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr) const {
    if (subTreePtr == nullptr){
        return 0;
    } else {
        return max(1+getHeightHelper(subTreePtr->getRightChildPtr()),
            1+getHeightHelper(subTreePtr->getLeftChildPtr()));
    }
}

// Returns number of nodes in tree
template <typename ItemType>
int BinaryTree<ItemType>::getNumberOfNodes() const {
    return getNumberOfNodesHelper(this->rootPtr);
}

// Finds number of nodes by recursing down each branch and summing length of each path
template <typename ItemType>
int BinaryTree<ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const {
    if (subTreePtr == nullptr){
        return 0;
    } else {
        return 1+getNumberOfNodesHelper(subTreePtr->getRightChildPtr()) +
            getNumberOfNodesHelper(subTreePtr->getLeftChildPtr());
    }
}

// Gets item stored in node
template <typename ItemType>
ItemType BinaryTree<ItemType>::getRootData() const {
    return this->rootPtr->getItem();
}

// Sets node item to provided data
template <typename ItemType>
void BinaryTree<ItemType>::setRootData( const ItemType& newData) {
    this->rootPtr->setItem(newData);
}

// Pure virtual method placeholders (to avoid compilation errors):
// TODO: Implement these
template <typename ItemType>
bool BinaryTree<ItemType>::add( const ItemType& newData) {
    return false;
}

template <typename ItemType>
bool BinaryTree<ItemType>::remove( const ItemType& data) {
    return false;
}

template <typename ItemType>
void BinaryTree<ItemType>::clear() {}

//TODO: search tree - find node with value - return value
template <typename ItemType>
ItemType BinaryTree<ItemType>::getEntry( const ItemType& anEntry) const {
    return anEntry;
}

template <typename ItemType>
bool BinaryTree<ItemType>::contains( const ItemType& anEntry) const {
    return false;
}

// Traversals
template <typename ItemType>
void BinaryTree<ItemType>::preorderTraverse( void visit(ItemType&)) const {}

template <typename ItemType>
void BinaryTree<ItemType>::inorderTraverse( void visit(ItemType&)) const {}

template <typename ItemType>
void BinaryTree<ItemType>::postorderTraverse( void visit(ItemType&)) const {}