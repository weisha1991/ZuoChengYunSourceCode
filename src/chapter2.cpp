#include "chapter2.h"

namespace chapter2 {
	ostream& operator<<(ostream&os, const singleList &sl) {
		Node *cur = sl.head;
		while (cur) {
			if (cur->next)
				os << cur->value << ",";
			else
				os << cur->value ;
			cur = cur->next;
		}
		return os;

	}

	ostream& operator<<(ostream&os, const loopList &sl) {
		Node *cur = sl.head;
		while (cur->next!=sl.head) {			
			os << cur->value << ",";			
			cur = cur->next;
		}
		cout << cur->value;
		return os;
	}

	void singleList::reverseKNodesV2(int k){
		if(k<2||!head)
			return;
		// cout<<"call me"<<endl;
		Node *cur=head,*start=NULL,*prev=NULL,*next=NULL;
		int count=1;
		while(cur){
			next=cur->next;
			if(count==k){
				// cout<<"reverse"<<endl;
				start=(prev==NULL)?head:prev->next;
				head=(prev==NULL)?cur:head;
				reversePartAux(prev,start,cur,next);
				prev=start;
				count=0;
			}
			count++;
			cur=next;
		}

	}
	randNode* createRandListInstance() {
		randNode *head = new randNode(1);
		head->next = new randNode(2);
		head->next->next = new randNode(3);
		head->randptr = head->next->next;
		head->next->randptr = NULL;
		head->next->next->randptr = head;
		return head;
	}
	randNode* copyrandList(randNode *head) {
		if (!head)
			return head;
		randNode *cur = head;
		randNode *next = NULL;
		while (cur) {
			next = cur->next;
			cur->next = new randNode(cur->val);
			cur->next->next = next;
			cur = next;
		}
		cur = head;
		randNode *curCopy = NULL;
		while (cur) {
			next = cur->next->next;
			curCopy = cur->next;
			curCopy->randptr = (cur->randptr == NULL) ? NULL : cur->randptr->next;
			cur = next;
		}
		randNode *res = head->next;
		cur = head;
		while (cur) {
			next = cur->next->next;
			curCopy = cur->next;
			cur->next = next;
			curCopy->next = (next) ? next->next : NULL;
			cur = next;
		}
		return res;
	}

	void destroyRandNodeList(randNode *head) {
		randNode *next = NULL;
		while (head) {
			next = head->next;
			delete head;
			head = next;
		}
	}

	ostream& printRandNodeList(ostream &os, randNode *head) {
		while (head) {
			os << head->val << ",";
			head = head->next;
		}
		return os;
	}

	void inorderSaveInqueue(treeNode *root,queue<treeNode*>&q){
		if(root){
			inorderSaveInqueue(root->left,q);
			q.push(root);
			inorderSaveInqueue(root->right,q);
		}
	}

	treeNode* btreeConverToDoubleListV1(treeNode *root){
		queue<treeNode*> q;
		inorderSaveInqueue(root,q);
		treeNode *head=q.front();
		treeNode *prev=head;
		prev->left=NULL;
		treeNode *cur=NULL;
		while(!q.empty()){
			cur=q.front();
			q.pop();
			prev->right=cur;
			cur->left=prev;
			prev=cur;
		}
		prev->right=NULL;
		return head;
	}
}