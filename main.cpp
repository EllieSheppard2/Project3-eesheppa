#include "AVLTree.h"
#include "BinarySearchTree.h"
#include "SplayTree.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Example of writing out to a file
    ofstream outFile;
    outFile.open("../data/example-output.csv");
    for (int i = 999; i >= 0; --i) {
        outFile << i << endl;
    }
    outFile.close();
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
        cout << btree.find(i, depth) << endl;
    }
}