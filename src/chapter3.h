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
    
    void preorderWalk(treeNode *root);
    void inorderWalk(treeNode *root);
    void postrderWalkV1(treeNode *root);
    void postorderWalk(treeNode *root);
    
    string intTostr(int val);
    int strToint(const string &s);

    vector<string> split(const string& src, string separate_character);
    string serialBypreorder(treeNode *root);
    treeNode *reconverByprevorder(queue<string> &q);
    treeNode* recoverByprevstring(string prevStr);
    string serialBylevel(treeNode *root);



}


#endif