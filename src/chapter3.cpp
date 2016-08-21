#include "chapter3.h"
#include <sstream>

namespace chapter3{


    string getSpace(int cnt){
        string space;
        for(int i=0;i<cnt;++i)
            space.push_back(' ');
        return space;
    }
    void printInorder(treeNode *head,int height,string to,int len){
        if(!head)
            return;
        printInorder(head->right,height+1,"v",len);
        string val;
        std::ostringstream os(val);
        os<<to<<head->value<<to;
        int lenM=val.size();
        int lenL=(len-lenM)/2;
        int lenR=len-lenM-lenL;
        val=getSpace(lenL)+val+getSpace(lenR);
        cout<<getSpace(height*len)+val<<endl;
        printInorder(head->left,height+1,"^",len);
    }
    void printTree(treeNode *root){
        cout<<"Binany Tree:"<<endl;
        printInorder(root,0,"H",17);
        
    }

    void preorderWalk(treeNode *root){
        if(root){
            stack<treeNode*> s;
            s.push(root);
            while(!s.empty()){
                treeNode *cur=s.top();
                cout<<cur->value<<",";
                s.pop();
                if(cur->right)
                    s.push(cur->right);
                if(cur->left)
                    s.push(cur->left);
            }
            cout<<endl;
        }
    }

    void inorderWalk(treeNode *root){
        if(root){
            stack<treeNode*> s;            
            while(!s.empty()||root){
                if(root){
                    s.push(root);
                    root=root->left;
                }
                else{
                    root=s.top();
                    s.pop();
                    cout<<root->value<<" ";
                    root=root->right;
                }
            }
            cout<<endl;
        }
    }
    // 使用两个栈
    void postrderWalkV1(treeNode *root){
        if(root){
            stack<treeNode*> s1;
            stack<treeNode*> s2;
            s1.push(root);
            while(!s1.empty()){
                treeNode *cur=s1.top();
                s1.pop();
                s2.push(cur);
                if(cur->right)
                    s1.push(cur->right);
                if(cur->left)
                    s2.push(cur->left);
            }
            while(!s2.empty()){
                treeNode *cur=s2.top();
                cout<<cur->value<<" ";
                s2.pop();
            }
            cout<<endl;
        }
    }

    void postorderWalk(treeNode *root){
        if(root){
         
            stack<treeNode*> s;
            s.push(root);
            treeNode *cur=NULL;
            treeNode *h=root;//最近访问过的点
            
            while(!s.empty()){
                cur=s.top();
                if(cur->left&&h!=cur->left&&h!=cur->right)//表明左子树和右子树都没有处理过
                    s.push(cur->left);
                else if(cur->right&&h!=cur->right)//表明右子树没有处理过
                    s.push(cur->right);
                else{//左右子树已经处理
                    cout<<s.top()->value<<" ";
                    s.pop();
                    h=cur;
                }
            }
            cout<<endl;
        }
    }
}