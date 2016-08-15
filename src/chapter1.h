#ifndef CHATER1_H
#define CHATER1_H
#include "publicHeader.h"

namespace chapter1 {
	using namespace std;
	void sortStackByStack(stack<int> &s);
	int getNum(vector<int> &arr, int num);
	int hanoiProblem1(int num, string left, string mid, string right);
	int process(int num, string left, string mid, string right, string from, string to);
	void getMaxWindow(vector<int> &arr, int w, vector<int> &out);
	struct Node;
	void popStackSetMap(stack<Node*> &s, unordered_map<Node*, Node*> &map);
	int maxRecSize(const vector<vector<int>> &mat);
	int maxRecFromBottom(const vector<int> &height);

	pair<Node*, Node**> getMaxTree(vector<int> &arr);

	class MinStack {
	public:
		void push(int val) {
			if (stackMin.empty())
				stackMin.push(val);
			else if (val <= stackMin.top())
				stackMin.push(val);
			stackData.push(val);
		}
		int pop() {
			int val = stackData.top();
			stackData.pop();
			if (val == stackMin.top())
				stackMin.pop();
			return val;
		}

		int getMin() {
			return stackMin.top();
		}
	private:
		stack<int> stackData;
		stack<int> stackMin;
	};

	class TwoStacksQueue {
	public:
		void push_back(int val){
			stackPush.push(val);
		}
		int pop_front() {
			if (stackPush.empty() && stackPop.empty())
				throw runtime_error("stack is empty");
			else if (stackPop.empty()) {
				while (!stackPush.empty()) {
					stackPop.push(stackPush.top());
					stackPush.pop();
				}
			}
			int ret = stackPop.top();
			stackPop.pop();
			return ret;
		}
		int front() {
			
			if (stackPush.empty() && stackPop.empty())
				throw runtime_error("stack is empty");
			else if (stackPop.empty()) {
				while (!stackPush.empty()) {
					stackPop.push(stackPush.top());
					stackPush.pop();
				}
			}
			return stackPop.top();
		}
	private:
		stack<int> stackPush;
		stack<int> stackPop;
	};

	class reverseStackFunc {
	public:
		//reverseStackFunc(stack<int>&is):s(is){}
		
		void operator()(stack<int> &s) {
			reverse(s);
		}

	private:
		void reverse(stack<int> &s) {
			if (s.empty())
				return;
			int lastElem = getAndRemoveLastElem(s);
			reverse(s);
			s.push(lastElem);
		}
		int getAndRemoveLastElem(stack<int> &s) {
			int ret = s.top();
			s.pop();
			if (s.empty())
				return ret;
			else {
				int lastElem = getAndRemoveLastElem(s);
				s.push(ret);
				return lastElem;
			}
		}

	};

	class Pet {
	private:
		string typeStr;
	public:
		Pet(string &s):typeStr(s){}
		string getType()const { return typeStr; }
	};

	class Dog :public Pet {
	public:
		Dog(string s):Pet(s){}
	};
	
	class Cat :public Pet {
	public:
		Cat(string name):Pet(name){}
	};

	class PetEnqueue {
	private:
		shared_ptr<Pet> petPtr;
		long timeStamp;
	public:
		PetEnqueue(shared_ptr<Pet> p,long count):petPtr(p),timeStamp(count){}
		shared_ptr<Pet> getPet() { return petPtr; }
		long getTimeStamp() { return timeStamp; }
		string getType() { return petPtr->getType(); }
	};

	class CatDogQueue {
	private:
		queue<PetEnqueue> dogQ;
		queue<PetEnqueue> catQ;
		static long count;
	public:
		void add(shared_ptr<Pet> ptr) {
			if (ptr->getType() == "dog") {
				dogQ.push(PetEnqueue(ptr, count++));
			}
			else if (ptr->getType() == "cat")
				catQ.push(PetEnqueue(ptr, count++));
			else
				throw runtime_error("pet type does not exist!");
		}

		shared_ptr<Pet> pollAll() {
			shared_ptr<Pet> ret;
			if (!dogQ.empty() && !catQ.empty()) {
				if (dogQ.back().getTimeStamp() < catQ.back().getTimeStamp())
				{

					ret=dogQ.back().getPet();
					dogQ.pop();
					return ret;
				}
				else {
					ret= catQ.back().getPet();
					catQ.pop();
					return ret;
				}
			}
			else if (!dogQ.empty())
			{
				ret=dogQ.back().getPet();
				dogQ.pop();
				return ret;
			}
			else if (!catQ.empty()) {
				ret=catQ.back().getPet();
				catQ.pop();
				return ret;
			}
			else
				throw runtime_error("queue is empty");
			return ret;
		}
		shared_ptr<Pet> pollDog() {
			if (!dogQ.empty()) {
				auto ret = dogQ.front().getPet();
				 dogQ.pop();
				 return ret;
			}
		}
		
		shared_ptr<Pet> pollCat(){
			if (!catQ.empty()) {
				auto ret=catQ.front().getPet();
				catQ.pop();
				return ret;
			}
		}
	};

	struct Node {
		Node *left;
		Node *right;
		int value;
		
		Node(int v=0):left(NULL),right(NULL),value(v){}
	};


}
#endif