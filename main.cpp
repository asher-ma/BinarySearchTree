#include <iostream>
#include "AvlTree.h"
#include "BinarySearchTree.h"

void printItem(int& item) {
    std::cout << item << " ";
}

void printTrees(AvlTree<int>& avl, BinarySearchTree<int>& bst) {
    // std::cout << "AVL Inorder:    ";
    // avl.inorderTraverse(printItem);
    
    std::cout << "AVL Preorder:   ";
    avl.preorderTraverse(printItem);

    // std::cout << "\nAVL Postorder:  ";
    // avl.postorderTraverse(printItem);

    // std::cout << "\nBST Inorder:    ";
    // bst.inorderTraverse(printItem);

    std::cout << "\nBST Preorder:   ";
    bst.preorderTraverse(printItem);

    std::cout << "\nAVL Height: " << avl.getHeight() << ", BST Height: " << bst.getHeight() << "\n";
}

int main() {

    // LL Rotation
    // Insert in descending order for rightright heavy tree
    // Rotation makes root 20
    AvlTree<int> avl;
    BinarySearchTree<int> bst;
    std::cout << "--- LL Rotation (insert 30, 20, 10) ---\n";
    avl.add(30);
    avl.add(20);
    avl.add(10);
    bst.add(30);
    bst.add(20);
    bst.add(10);

    printTrees(avl, bst);

    avl.clear();
    bst.clear();

    // RR Rotation
    // Insert in ascending order for leftleft heavy tree
    // Rotation makes root 20
    std::cout << "\n--- RR Rotation (insert 10, 20, 30) ---\n";
    avl.add(10);
    avl.add(20);
    avl.add(30);
    bst.add(10);
    bst.add(20);
    bst.add(30);

    printTrees(avl, bst);

    avl.clear();
    bst.clear();

    // LR Rotation
    // Insert 30, 10, 20 for leftright heavy tree
    // Rotations make root 20
    std::cout << "\n--- LR Rotation (insert 30, 10, 20) ---\n";
    avl.add(30);
    avl.add(10);
    avl.add(20);
    bst.add(30);
    bst.add(10);
    bst.add(20);

    printTrees(avl, bst);

    avl.clear();
    bst.clear();

    // RL Rotation
    // Insert 10, 30, 20 for rightleft heavy tree
    // Rotations make root 20
    std::cout << "\n--- RL Rotation (insert 10, 30, 20) ---\n";
    avl.add(10);
    avl.add(30);
    avl.add(20);
    bst.add(10);
    bst.add(30);
    bst.add(20);

    printTrees(avl, bst);

    avl.clear();
    bst.clear();

    // Larger tree: all rotations triggered, compare height vs BST
    std::cout << "\n--- Large Sequential Insert (1 -> 10) ---\n";
    for (int i = 1; i <= 10; i++) {
        avl.add(i); bst.add(i);
    }
    printTrees(avl, bst);

    std::cout << " -BST becomes linked list; AVL stays balanced\n";

    avl.clear();
    bst.clear();

    // Remove test
    std::cout << "\n--- Remove from AVL (insert 10,20,30,40,50 then remove 30) ---\n";

    for (int i = 10; i <= 50; i+=10) {
        avl.add(i); bst.add(i);
    }
    
    avl.remove(30);
    bst.remove(30);
    printTrees(avl, bst);

    return 0;
}