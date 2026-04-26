#include <iostream>
#include "BinaryTreeAbstract.h"
#include "BinaryTree.h"

using namespace std;

int main(){
    BinaryTree<int>* tree = new BinaryTree<int>(10);

    cout << tree->getHeight() << endl;

    delete tree;

    return 0;
}