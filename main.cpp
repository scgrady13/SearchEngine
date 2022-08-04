#include <iostream>
#include "AVLTree.h"
using namespace std;
int main() {



    AVLTree tree;
    string temp = "abc";
    tree.Insert(temp);
    for(int i = 0; i < 10; i++){
        temp[0]++;
        tree.Insert(temp);
    }
    tree.printTree();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
