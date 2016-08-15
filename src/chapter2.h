#ifndef CHAPTER2_H
#define CHAPTER2_H
#include "publicHeader.h"

namespace chapter2 {
	using namespace std;
	class Node {
	public:
		int value;
		Node *next;
		Node(int v = 0) :value(v), next(NULL) {}
	};
	class singleList {
		friend ostream& operator<<(ostream&os, const singleList&);
	public:
		singleList() :head(NULL) {}
		singleList(initializer_list<int> il) {
			head = NULL;
			for (auto elem : il)
				insert(elem);
		}

		~singleList() {			
			clear();
		}
		void insert(int val) {
			if (!head)
			{
				head = new Node(val);
				return;
			}
			Node *tmp = new Node(val);
			tmp->next = head;
			head = tmp;
		}
		void clear() {
			if (!head)
				return;
			Node *next = head->next;
			Node *curPtr = head;
			while (curPtr) {
				delete curPtr;
				curPtr = next;
				if (!curPtr)
					break;
				next = next->next;
			}
			head = NULL;
		}

		void removeLastKthNode(int lastk) {
			head = removeLastKthNodeAux(lastk);
		}

		void removeMidNode() {
			head = removeMidNodeAux();
		}
		void removeByRatio(int a, int b) {
			head = removeByRatioAux(a, b);
		}
		void reverseList() {
			Node *prev = NULL, *next = NULL;
			while (head) {
				next = head->next;
				head->next = prev;
				prev = head;
				head = next;
			}
			head = prev;
		}

		void reversePart(int from, int to) {
			int len = 0;
			Node *node1 = head;
			Node *fprev = NULL, *tpos = NULL;
			while (node1) {//�ҵ���from���ڵ���ǰ���͵�to���ڵ��ĺ���
				len++;
				fprev = (len == from - 1) ? node1 : fprev;
				tpos = (len == to + 1) ? node1 : tpos;
				node1 = node1->next;
			}
			if (from > to || from<1 || to>len)
				return;
			node1 = (fprev == NULL) ? head : fprev->next;
			Node *node2 = node1->next;
			node1->next = tpos;
			Node *next = NULL;
			while (node2!=tpos) {
				next = node2->next;
				node2->next = node1;
				node1 = node2;
				node2 = next;
			}
			if (fprev) {
				fprev->next = node1;		
				return;
			}
			head = node1;
		}

		bool isPalindrome1() {
			if (!head || !head->next)
				return true;
			Node *right = head->next;
			Node *cur = head;
			while (cur->next&&cur->next->next) {
				right = right->next;
				cur = cur->next->next;
			}
			stack<Node*> s;
			while(right){
				s.push(right);
				right = right->next;
			}
			cur = head;
			while (!s.empty()) {
				if (cur->value != s.top()->value) {
					return false;
				}
				s.pop();
				cur = cur->next;				
			}
			return true;
		}

		bool isPalindrome3() {
			if (!head || !(head->next))
				return true;

			Node *n1 = head, *n2 = head;
			while (n2->next&&n2->next->next) {
				n1 = n1->next; n2 = n2->next->next;
			}

			n2 = n1->next;//�Ұ��ߵ�һ���ڵ㣬n2Ϊ�м��ڵ�
			n1->next = NULL;
			Node *n3 = NULL;
			while (n2) {
				n3 = n2->next;
				n2->next = n1;
				n1 = n2;
				n2 = n3;
			}
			n3 = n1;//�����Ұ�������һ���ڵ�
			n2 = head;//����ͷ����
			bool res = true;
			while (n1&&n2) {
				if (n1->value != n2->value) {
					res = false;
					break;
				}
				n1 = n1->next; n2 = n2->next;
			}
			n1 = n3->next;
			n3->next = NULL;
			while (n1) {
				n2 = n1->next;
				n1->next = n3;
				n3 = n1;
				n1 = n2;
			}
			return res;
		}

		void listPartition(int pivot) {
			Node *smallHead = NULL, *smallTail = NULL;
			Node *equalHead = NULL, *equalTail = NULL;
			Node *greaterHead = NULL, *greaterTail = NULL;
			Node *next = NULL, *cur = head;
			while (cur) {//����������pivot���ֳ���������������
				next = cur->next;
				cur->next = NULL;
				if (cur->value < pivot) {
					if (smallHead == NULL) {
						smallTail=smallHead = cur;
					}
					else {
						smallTail->next = cur;
						smallTail = cur;
					}
				}
				else if (cur->value == pivot) {
					if (equalHead == NULL) {
						equalTail = equalHead = cur;
					}
					else {
						equalTail->next = cur;
						equalTail = cur;
					}
				}
				else {
					if (greaterHead == NULL) {
						greaterHead = greaterTail = cur;
					}
					else {
						greaterTail->next = cur;
						greaterTail = cur;
					}
				}
				cur = next;
			}
			if (smallTail) {
				smallTail->next = equalHead;
				equalTail = (equalTail == NULL) ? smallTail : equalTail;
			}
			if (greaterTail) {
				equalTail->next = greaterHead;
			}
			head = (smallHead != NULL) ? smallHead : ((equalHead != NULL) ? equalHead : greaterHead);
		}

		void addList1(singleList &rhs) {
			stack<int> s1, s2;
			Node *cur = head;
			while (cur) {
				s1.push(cur->value);
				cur = cur->next;
			}
			cur = rhs.head;
			while (cur) {
				s2.push(cur->value);
				cur = cur->next;
			}
			int ca = 0, n1 = 0, n2 = 0;
			int n = 0;
			Node *node = NULL;
			Node *prev = NULL;
			while (!s1.empty() || !s2.empty()) {				
				if (!s1.empty())
				{
					n1 = s1.top(); s1.pop();
				}
				else
					n1 = 0;
				if (!s2.empty()) {
					n2 = s2.top(); s2.pop();
				}
				else
					n2 = 0;
								
				n = n1 + n2 + ca;
				prev = node;
				node = new Node(n%10);
				node->next = prev;
				ca = n / 10;
			}
			if (ca == 1) {
				prev = node;
				node = new Node(1);
				node->next = prev;
			}
			clear();
			head = node;
			return;
		}

		void reverseKNodes1(int k) {
			if (k < 2 || !head)
				return;
			stack<Node*> s;
			Node *newHead = head;
			Node *cur = head,*prev=NULL,*next=NULL;
			while (cur) {
				next = cur->next;
				s.push(cur);
				if (s.size() == k) {
					prev = resign1(s, prev, next);
					newHead = (newHead == head) ? cur : newHead;
				}
				cur = next;
			}
			head = newHead;
		}

		void reverseKNodesV2(int k);

		void removeRep(){
			Node *cur=head,*prev=NULL,*next=NULL;
			while(cur){
				
				prev=cur;
				next=cur->next;
				while(next){
					if(cur->value==next->value){
						Node *tmp=next;
						
						prev->next=next->next;
						next=prev->next;
						delete tmp;
						prev=next;
					}
					else
						prev=next;
					
					next=next->next;
				}
				cur=cur->next;
			}
			cout<<"done"<<endl;
		}
	private:
		Node* resign1(stack<Node*>&s, Node *left, Node *right) {
			Node *cur = s.top();
			s.pop();
			if (left)
				left->next = cur;
			Node *next = NULL;
			while (!s.empty()) {
				next = s.top();
				s.pop();
				cur->next = next;
				cur = next;
			}
			cur->next = right;
			return cur;
		}

		Node* removeLastKthNodeAux(int lastk) {
			if (!head || lastk < 1)
				return head;
			Node *cur = head;
			while (cur) {
				lastk--;
				cur = cur->next;
			}
			if (lastk == 0)
			{
				Node *delPtr = head;
				head = head->next;
				delete delPtr;
			}
			if (lastk < 0) {
				cur = head;
				while (++lastk != 0) {
					cur = cur->next;
				}
				Node *delPtr = cur->next;
				cur->next = cur->next->next;
				delete delPtr;
			}
			return head;
		}

		Node* removeMidNodeAux() {
			if (!head || !(head->next))
				return head;
			if (head->next->next == NULL)
				return head->next;
			Node *pre = head;
			Node *cur = head->next->next;
			while (cur->next&&cur->next->next) {
				pre = pre->next;
				cur = cur->next->next;
			}
			Node *delPtr = pre->next;
			pre->next = pre->next->next;
			delete delPtr;
			return head;
		}

		Node* removeByRatioAux(int a, int b) {
			if (a<1 || a>b)
				return head;
			int n = 0;
			Node *cur = head;
			while (cur) {
				n++;
				cur = cur->next;
			}
			n = (int)ceil((double)(a*n) / (double)(b));
			if (n == 1) {
				Node *delPtr = head;
				head = head->next;
				delete delPtr;
			}
			if (n > 1) {
				cur = head;
				while (--n != 1) {
					cur = cur->next;
				}
				Node *delPtr = cur->next;
				cur->next = cur->next->next;
				delete delPtr;
			}
			return head;
		}
		
		void reversePartAux(Node *left,Node *start,Node *end,Node *right){
			Node *prev=start,*cur=start->next;
			Node *next=NULL;
			while(cur!=right){
				next=cur->next;
				cur->next=prev;
				prev=cur;
				cur=next;
			}
			if(left)
				left->next=end;
			start->next=right;
		}
		Node *head;
	};	

	ostream& operator<<(ostream&os, const singleList&);

	class loopList {
		friend 	ostream& operator<<(ostream&os, const loopList &sl) ;
	public:
		loopList():head(NULL){}
		~loopList() { clear(); }
		void insert(int val) {
			if (!head)
			{
				head = new Node(val);
				head->next = head;
				return;
			}
			Node *cur = head;
			while (cur->next != head)
				cur = cur->next;
			Node *tmp = new Node(val);
			tmp->next = head;
			cur->next = tmp;
		}
		void clear() {
			if (!head)
				return;
			Node *last = head;
			while (last->next != head)
				last = last->next;
			Node *cur = head,*next=head->next;
			while (cur != last) {
				delete cur;
				cur = next;
				next = next->next;
			}
			delete last;
			head = NULL;
		}
		void josephusKill(int m) {
			if (!head || head->next == head || m < 1)
				return;
			Node *cur = head->next;
			int len = 1;
			while (cur != head) {
				++len;
				cur = cur->next;
			}
			int suviveId = getLiveNodeId(len, m);
			cur = head;
			Node *prev = NULL;

			while (--suviveId != 0) {
				prev = cur;
				cur = cur->next;
			}
			if (cur == head)
			{
				Node *last = head;
				while (last->next != head)
					last = last->next;
				last->next = head->next;
				head = head->next;
			}
			else {
				prev->next = cur->next;
			}
			clear();
			cur->next = cur;
			head = cur;
		}

	private:
		int getLiveNodeId(int len, int m) {
			if (len == 1)
				return 1;
			return (getLiveNodeId(len - 1, m) + m - 1) % len + 1;
		}
		Node *head;
	};
	ostream& operator<<(ostream&os, const loopList &sl);

	struct randNode {
		int val;
		randNode *randptr;
		randNode *next;
		randNode(int val):val(val),randptr(NULL),next(NULL){}
	};
	randNode* createRandListInstance();
	void destroyRandNodeList(randNode *head);
	ostream& printRandNodeList(ostream &os, randNode *head);
	randNode* copyrandList(randNode *head);

}
#endif