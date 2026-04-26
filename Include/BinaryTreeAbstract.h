#ifndef _BINARY_TREE_ABSTRACT_H_
#define _BINARY_TREE_ABSTRACT_H_

#include "BinaryNode.h"

template < class ItemType>
class BinaryTreeAbstract {
    protected:
        BinaryNode<ItemType>* rootPtr;

    public :
        virtual bool isEmpty() const = 0;
        virtual int getHeight() const = 0;    
        virtual int getNumberOfNodes() const = 0;    
        virtual ItemType getRootData() const = 0;    
        virtual void setRootData( const ItemType& newData) = 0;
        virtual bool remove( const ItemType& data) = 0;   
        virtual void clear() = 0;    
        virtual ItemType getEntry( const ItemType& anEntry) const = 0;    
        virtual bool contains( const ItemType& anEntry) const = 0;

        virtual void preorderTraverse( void visit(ItemType&)) const = 0;
        virtual void inorderTraverse( void visit(ItemType&)) const = 0;
        virtual void postorderTraverse( void visit(ItemType&)) const = 0;

}; // end BinaryTree Abstract Class 

#endif
