//
// Created by Sean Grady on 8/2/2022.
//

#include "AVLTree.h"


\
AVLTree::AVLTree(const AVLTree & data){
    *this = data;

}


void AVLTree::Insert(string &data){
    PrivateInsert(data, this->root);
}
