#include "chapter1.h"

namespace chapter1 {
	long CatDogQueue::count = 0;
	void sortStackByStack(stack<int> &s) {
		stack<int> helper;
		while (!s.empty()) {
			int cur = s.top();
			s.pop();
			while (!helper.empty() && cur>helper.top()) {
				s.push(helper.top());
				helper.pop();
			}
			helper.push(cur);
		}
		while (!helper.empty()) {
			s.push(helper.top());
			helper.pop();
		}

	}

	int getNum(vector<int> &arr,int num) {
		if (arr.empty())
			return 0;
		deque<int> qmax;//qmax维持子数组i....j的最大值
		deque<int> qmin;//qmin维持子数组的最小值；
		int i = 0, j = 0, res = 0;
		while (i < arr.size()) {
			while (j < arr.size()) {
				while (!qmin.empty() && arr[qmin.back()] >= arr[j])
					qmin.pop_back();
				qmin.push_back(j);
				while (!qmax.empty() && arr[qmax.back()] <= arr[j])
					qmax.pop_back();
				qmax.push_back(j);
				if (arr[qmax.front()] - arr[qmin.front()] > num)
					break;
				++j;
			}

			if (qmin.front() == i)
				qmin.pop_front();
			if (qmax.front() == i)
				qmax.pop_front();
			res += j - i;
			++i;
		}
		return res;
	}

	int process(int num, string left, string mid, string right, string from, string to) {
		if (num == 1) {
			if (from == mid || to == mid) {
				cout << "move 1 from " << from << " to " << to << endl;
				return 1;
			}
			else {
				cout << "move 1 from " << from << " to " << mid << endl;
				cout << "move 1 from " << mid << " to " << to << endl;
				return 2;
			}
		}

		if (from == mid || to == mid) {
			string another = (from == left || to == left) ? right : left;
			int part1 = process(num - 1, left, mid, right, from, another);
			int part2 = 1;
			cout << "Move " << num << " from " << from << " to " << to << endl;
			int part3 = process(num - 1, left, mid, right, another, to);
			return part1 + part2 + part3;
		}
		else {
			int part1 = process(num - 1, left, mid, right, from, to);
			int part2 = 1;
			cout << "Move " << num << " from " << from << " to " << mid << endl;
			int part3 = process(num - 1, left, mid, right, to, from);
			int part4 = 1;
			cout << "Move " << num << " from " << mid << " to " << to << endl;
			int part5 = process(num - 1, left, mid, right, from, to);
			return part1 + part2 + part3 + part4 + part5;
		}

	}

	int hanoiProblem1(int num, string left, string mid, string right) {
		if (num < 1)
			return 0;
		return process(num,left,mid,right,left,right);
	}

	void getMaxWindow(vector<int> &arr, int w, vector<int> &out) {
		if (arr.empty() || w < 1 || arr.size() < w)
			return;
		deque<int> qmax;
		out.assign(arr.size() - w + 1, 0);
		int index = 0;
		for (int i = 0; i < arr.size(); ++i) {
			while (!qmax.empty() && arr[qmax.back()] <= arr[i])
				qmax.pop_back();
			qmax.push_back(i);
			if (qmax.front() == i - w)
				qmax.pop_front();
			if (i >= w - 1)
				out[index++] = arr[qmax.front()];
		}
	}

	void popStackSetMap(stack<Node*> &s, unordered_map<Node*, Node*> &map) {
		Node *popNode = s.top();
		s.pop();
		if (s.empty())
			map.insert(make_pair(popNode, nullptr));
		else
			map.insert(make_pair(popNode, s.top()));
	}


	pair<Node*,Node**> getMaxTree(vector<int> &arr)
	{		
		Node **nodeVec = new Node*[arr.size()];
		for (int i = 0; i < arr.size(); ++i)
			nodeVec[i] = new Node(arr[i]);
		stack<Node*> s;
		unordered_map<Node*, Node*> lBig;
		unordered_map<Node*, Node*> rBig;

		for (int i = 0; i != arr.size(); ++i) {
			Node* curNode = nodeVec[i];
			while (!s.empty() && s.top()->value < curNode->value)
				popStackSetMap(s, lBig);
			s.push(curNode);
		}
		while (!s.empty())
			popStackSetMap(s, lBig);

		for (int i = arr.size() - 1; i != -1; --i) {
			Node* curNode = nodeVec[i];
			while (!s.empty() && s.top()->value < curNode->value)
				popStackSetMap(s, rBig);
			s.push(curNode);
		}
		while (!s.empty())
			popStackSetMap(s, rBig);
		Node *root = nullptr;
		for (int i = 0; i != arr.size(); ++i) {
			Node *curNode = nodeVec[i];
			Node *left = lBig.find(curNode)->second;
			Node *right = rBig.find(curNode)->second;
			if (!left && !right)
				root = curNode;
			else if (!left) {
				if (right && !right->left)
					right->left = curNode;
				else
					right->right = curNode;
			}
			else if (!right) {
				if (left && !left->left)
					left->left = curNode;
				else
					left->right = curNode;
			}
			else {
				Node *parent = (left->value < right->value) ? left : right;
				if (!parent->left)
					parent->left = curNode;
				else
					parent->right = curNode;
			}
		}
		return make_pair(root,nodeVec);	
	}


	int maxRecFromBottom(const vector<int> &height) {
		if (height.empty())
			return 0;

		int maxArea = 0;
		stack<int> s;
		for (int i = 0; i < height.size(); ++i) {
			while (!s.empty() && height[i] <= height[s.top()]) {
				int j = s.top();
				s.pop();
				int k = s.empty() ? -1 : s.top();
				int curArea = (i - k - 1)*height[j];
				maxArea = max(maxArea, curArea);
			}
			s.push(i);
		}
		while (!s.empty()) {
			int j = s.top();
			s.pop();
			int k = s.empty() ? -1 : s.top();
			int curArea = (height.size() - k - 1)*height[j];
			maxArea = max(maxArea, curArea);
		}
		return maxArea;
	}

	int maxRecSize(const vector<vector<int>> &mat) {
		if (mat.empty())
			return 0;
		int maxArea = 0;
		vector<int> height(mat[0].size(), 0);
		for (int i = 0; i < mat.size(); ++i) {
			for (int j = 0; j < mat[0].size(); ++j) {
				height[j] = (mat[i][j] == 0) ? 0 : height[j] + 1;
			}
			maxArea = max(maxRecFromBottom(height), maxArea);
		}
		return maxArea;
	}
}