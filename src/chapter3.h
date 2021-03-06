#ifndef CHAPTER3_H
#define CHAPTER3_H
#include "publicHeader.h"
#include "chapter2.h"
#include <unordered_map>
#include <utility>
#include <limits.h>
#include <deque>
#include "kmp.h"

namespace chapter3{
    using chapter2::treeNode;
    using namespace std;
    
    struct record{
        int l;
        int r;
        record(int left,int right):l(left),r(right){}
    };

    void BTreeDestroy(treeNode *tree);
    string getSpace(int cnt);
    void printInorder(treeNode *head,int height,string to,int len);
    void printTree(treeNode *root);
    
    void preorderWalk(treeNode *root);
    void inorderWalk(treeNode *root);
    void postrderWalkV1(treeNode *root);
    void postorderWalk(treeNode *root);
    void morrisInorder(treeNode *root);
    

    string intTostr(int val);
    int strToint(const string &s);

    vector<string> split(const string& src, string separate_character);
    string serialBypreorder(treeNode *root);
    treeNode *reconverByprevorder(queue<string> &q);
    treeNode* recoverByprevstring(string prevStr);
    string serialBylevel(treeNode *root);
    treeNode* createNodeFromstr(const string &str);
    treeNode* reconBylevel(const string &str);

    int preorderAndGotSum(treeNode *head,int sum,int preSum,
                int level,int maxLen,unordered_map<int,int> &sumMap);
    int getMaxlen(treeNode *root,int sum);

    treeNode* postOrder(treeNode *head,vector<int> &record);
    treeNode* largestSubBST(treeNode *root);

    bool isBSTNode(treeNode *h,treeNode *n,int val);
    int maxTOPO(treeNode *h,treeNode *n);   
    int bstTopoSize1(treeNode *head);

    int modifyHash(treeNode *node,int v,unordered_map<treeNode*,record> &m,bool flag);
    int postorderFind(treeNode *h,unordered_map<treeNode*,record> &m);
    int bstTopoSize2(treeNode *root);

    void printByLevel(treeNode *root);
    void printLevelAndOrient(int level,bool lr);
    void printByZigZag(treeNode *root);

    bool check(treeNode *root,treeNode *t2);
    bool contains(treeNode *t1,treeNode *t2);


    int getTreeHeight(treeNode *root,int level,bool &flag);
    bool isBalancedTree(treeNode *root);

    bool isPostArray(int arr[],int n);
    bool isPost(int arr[],int start,int end);


	bool isSubTree(treeNode *root1,treeNode *root2);
}


#endif
