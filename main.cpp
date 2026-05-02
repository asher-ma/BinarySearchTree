#include <iostream>
#include "BinaryTreeAbstract.h"
#include "BinaryTree.h"

using namespace std;

void printItem(int& item) {
    cout << item << " ";
}

int main(){
    // Test add()
    BinaryTree<int>* tree = new BinaryTree<int>();

    tree->add(5);
    tree->add(10);
    tree->add(15);
    tree->add(20);
    
    tree->preorderTraverse(printItem);
    cout << endl;
    tree->inorderTraverse(printItem);
    cout << endl;
    tree->postorderTraverse(printItem);
    cout << endl;
    
    delete tree;

    return 0;
}