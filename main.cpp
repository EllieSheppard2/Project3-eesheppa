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
    outFile << "Depths for in order values" << endl;
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
    outFile << "Depths for randomized list" << endl;
    std::vector<int> values{44, 78, 2, 58, 56, 45, 12, 55, 66, 39, 34, 26, 85, 86, 75, 32, 88, 74, 40, 19, 54, 38, 47, 65, 3, 50, 77, 82, 95, 84, 6, 60, 94, 96, 70, 73, 93, 90, 15, 27, 36, 23, 46, 83, 1, 62, 42, 76, 22, 67, 92, 4, 28, 99, 48, 25, 11, 16, 100, 43, 87, 81, 5, 79, 9, 89, 8, 49, 51, 59, 61, 20, 29, 37, 14, 13, 18, 53, 57, 69, 68, 64, 52, 30, 7, 98, 80, 41, 10, 24, 31, 17, 35, 33, 97, 71, 21, 91, 72, 63};
    BinarySearchTree<int> btree2;
    AVLTree<int> atree2;
    SplayTree<int> stree2;
    for (int value:values) {
        btree2.add(value);
        atree2.add(value);
        stree2.add(value);
    }
    for (int value: values) {
        int depth = 0;
        bool find = btree2.find(value, depth);
        if (find) {
            outFile << value << " found in binary search tree at the depth: " << depth << endl;
        }
        else {
            outFile << value << " not found " <<endl;
        }
    }
    for (int value: values) {
        int depth = 0;
        bool find = atree2.find(value, depth);
        if (find) {
            outFile << value << " found in AVL tree at the depth: " << depth << endl;
        }
        else {
            outFile << value << " not found " <<endl;
        }
    }
    for (int value: values) {
        int depth = 0;
        bool find = stree2.find(value, depth);
        if (find) {
            outFile << value << " found in splay tree at the depth: " << depth << endl;
        }
        else {
            outFile << value << " not found " <<endl;
        }
    }
    outFile.close();
}