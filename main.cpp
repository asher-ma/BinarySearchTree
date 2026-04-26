#include <iostream>
#include "BinaryTreeAbstract.h"
#include "BinaryTree.h"

using namespace std;

int main(){
    // Test isEmpty() on empty tree
    BinaryTree<int>* emptyTree = new BinaryTree<int>();
    cout << "isEmpty (expect 1): " << emptyTree->isEmpty() << endl;
    cout << "getHeight (expect 0): " << emptyTree->getHeight() << endl;

    // Test with root only
    BinaryTree<int>* tree = new BinaryTree<int>(10);
    cout << "isEmpty (expect 0): " << tree->isEmpty() << endl;
    cout << "getHeight (expect 1): " << tree->getHeight() << endl;

    delete emptyTree;
    delete tree;

    return 0;
}