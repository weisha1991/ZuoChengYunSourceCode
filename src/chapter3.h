#ifndef CHAPTER3_H
#define CHAPTER3_H
#include "publicHeader.h"
#include "chapter2.h"
namespace chapter3{
    using chapter2::treeNode;
    using namespace std;
    string getSpace(int cnt);
    void printInorder(treeNode *head,int height,string to,int len);
    void printTree(treeNode *root);

}


#endif