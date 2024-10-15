#include "AVLTree.h"
#include "BinarySearchTree.h"
#include "SplayTree.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {

    std::ofstream outFile("/Users/elliesheppard/Project3-eesheppa/data/treeDepths");
    if (!outFile) {
        cout << "Error opening output file" << endl;
    }
    BinarySearchTree<int> btree;
    AVLTree<int> atree;
    SplayTree<int> stree;
    for (int i = 1; i < 101; i++) {
        btree.add(i);
        atree.add(i);
        stree.add(i);
    }
    for (int i = 1; i < 101; i++) {
        int depth = 0;
        bool find = btree.find(i, depth);
        if (find) {
            outFile << i << " found in binary search tree at the depth: " << depth << endl;
        }
        else {
            outFile << i << " not found " <<endl;
        }
    }
    for (int i = 1; i < 101; i++) {
        int depth = 0;
        bool find = atree.find(i, depth);
        if (find) {
            outFile << i << " found in AVL tree at the depth: " << depth << endl;
        }
        else {
            outFile << i << " not found " <<endl;
        }
    }
    for (int i = 1; i < 101; i++) {
        int depth = 0;
        bool find = stree.find(i, depth);
        if (find) {
            outFile << i << " found in splay tree at the depth: " << depth << endl;
        }
        else {
            outFile << i << " not found " <<endl;
        }
    }
    outFile.close();
}