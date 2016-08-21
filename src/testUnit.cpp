#include "testUnit.h"

void testChapter1() {
	using namespace chapter1;
	using std::cout;
	using std::endl;
	cout << "***************带有min的栈***********************" << endl;
	MinStack minS;
	for (int i = 10; i > 2; --i) {
		minS.push(i*2);
	}
	minS.pop();
	cout << minS.getMin() << endl;

	cout << "*************用栈排序另一个栈******************" << endl;
	stack<int> s;
	for (int i = 6; i >= 0; --i) {
		s.push(i);
	}
	sortStackByStack(s);
	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	cout << "****************两个栈实现一个队列************************" << endl;
	TwoStacksQueue tsq;
	tsq.push_back(2);
	tsq.push_back(3);
	tsq.push_back(1);
	tsq.push_back(19);
	cout << tsq.front() << endl;
	tsq.pop_front();
	cout << tsq.front() << endl;
	tsq.pop_front();
	cout << tsq.front() << endl;
	
	cout << "*****************栈逆序*************" << endl;
	reverseStackFunc func;
	for (int i = 6; i >= 0; --i) {
		s.push(i);
	}
	func(s);
	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	cout << "*********************最大值与最小值之差小于num的字数组个数*******" << endl;
	vector<int> arr = { 4,3,1,2 };
	cout << getNum(arr,1) << endl;

	cout << "********************猫狗队列***************************" << endl;
	CatDogQueue cdq;
	for (int i = 0; i < 10;++i) {
		cdq.add(make_shared<Dog>("dog"));
		cdq.add(make_shared<Cat>("cat"));
	}
	cdq.pollCat();
	cdq.pollAll();
	cdq.pollCat();
	cout << endl;
	cout << "***************汉诺塔问题***************" << endl;
	hanoiProblem1(2, "左", "中", "右");
	cout << "****************维护窗口数组的最大值*************" << endl;
	vector<int> arr1 = { 4,3,5,4,3,3,6,7 };
	vector<int>ret;
	getMaxWindow(arr1, 3, ret);
	for (auto n : ret)
		cout << n << ",";
	cout << endl;
	cout << "****************MaxTree构造*******************************" << endl;
	vector<int> arr2 = { 3,4,5,1,2 };
	auto root = getMaxTree(arr2);
	Node *cur = root.first;
	queue<Node*> q;
	q.push(cur);
	while (!q.empty()) {
		cur = q.front(); q.pop();
		cout << cur->value << endl;
		if (cur->left)
			q.push(cur->left);
		if (cur->right)
			q.push(cur->right);
	}
	Node** delePtr = root.second;
	for (int i = 0; i < arr2.size(); ++i) {
		delete delePtr[i];
	}
	delete [] delePtr;
	

	cout << "**********************最大1矩阵***************"<<endl;
	vector<vector<int>> mat{ {1,0,1,1},{1,1,1,1},{1,1,1,0} };
	cout << maxRecSize(mat) << endl;

	getchar();
}


void testChapter2() {
	using namespace chapter2;
	using std::cout;
	using std::endl;
	std::cout << "**********链表问题***************" << endl;
	singleList sl;
	for (int i = 5; i >=1; --i)
		sl.insert(i);
	cout << sl << endl;
	cout << "reverse from 2 to 4" << endl;
	sl.reversePart(2, 4);
	cout << sl << endl;
	cout << "reverse the list" << endl;
	sl.reverseList();
	cout << sl<<endl;
	cout << "delete last 3th node"<<endl;
	sl.removeLastKthNode(3);
	cout << sl << endl;
	cout << "remove the mid node" << endl;
	sl.removeMidNode();
	cout << sl << endl;
	cout << "remove the a/bth Node" << endl;
	sl.removeByRatio(5, 7);
	cout << sl << endl;	
	cout << "判断链表会问结构" << endl;
	singleList sl1(initializer_list<int>{1,2,3,2,1});	
	std::cout << sl1 << endl;
	cout <<std::boolalpha<< sl1.isPalindrome1() << endl;
	cout << std::boolalpha << sl1.isPalindrome3() << endl;
	singleList sl2(initializer_list<int>{1, 2, 3,3, 2, 1});
	cout << sl2 << endl;
	cout << std::boolalpha << sl2.isPalindrome1() << endl;
	cout << std::boolalpha << sl2.isPalindrome3() << endl;
	singleList sl3(initializer_list<int>{1, 3, 3, 2, 1});
	cout << sl3 << endl;
	cout << std::boolalpha << sl3.isPalindrome1() << endl;
	cout << std::boolalpha << sl3.isPalindrome3() << endl;

	cout << "约瑟夫游戏" << endl;		
	loopList ll;
	for(int i=1;i<6;++i)
		ll.insert(i);
	cout << ll << endl;
	cout << "josephus kill game (3 is killed)" << endl;
	ll.josephusKill(4);
	cout << ll << endl;

	cout << "链表的partition操作" << endl;
	singleList sl4(initializer_list<int>({ 7,9,1,8,5,2,5 }));
	cout << sl4 << endl;
	sl4.listPartition(7);
	cout << sl4 << endl;

	cout << "复制含有随机指针的链表" << endl;
	randNode *head = createRandListInstance();
	printRandNodeList(cout, head);
	cout << endl;
	randNode *headCopy = copyrandList(head);
	printRandNodeList(cout, headCopy);	
	cout << endl;
	destroyRandNodeList(headCopy);
	destroyRandNodeList(head);

	cout << "两个链表代表的整数相加，计算结果用链表表示" << endl;
	singleList lhs(initializer_list<int>{7, 3, 9});
	singleList rhs(initializer_list<int>{3, 6});
	lhs.addList1(rhs);
	cout << lhs << endl;

	cout << "每K个节点对链表进行逆序，不足K个保持不变" << endl;
	singleList sl5(initializer_list<int>{8, 7, 6, 5, 4, 3, 2, 1});
	cout << sl5 << endl;
	cout<<"版本一：使用栈"<<endl;
	sl5.reverseKNodes1(3);
	cout << sl5 << endl;
	cout<<"版本二:原地直接调整"<<endl;
	sl5.reverseKNodesV2(3);
	cout<<sl5<<endl;

	cout<<"删除重复点"<<endl;
	singleList sl6(initializer_list<int>{1,2,3,3,4,4,2,1,1});
	sl6.reverseList();
	cout<<sl6<<endl;
	sl6.removeRep();
	cout<<sl6<<endl;

	cout<<"删除所有指定元素的节点"<<endl;
	singleList sl7(initializer_list<int>{3,3,3,1,2,3,34,5,3,1});
	sl7.reverseList();
	cout<<sl7<<endl;
	sl7.removeValue(3);
	cout<<sl7<<endl;

	cout<<"单链表的选择排序"<<endl;
	singleList sl8(initializer_list<int>{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,22,12,121,3,4,5,});
	cout<<sl8<<endl;
	sl8.selectionSort();
	cout<<sl8<<endl;

	cout<<"在有序环形链表插入节点，保持有序态"<<endl;
	loopList ll1(initializer_list<int>{1,3,4});
	cout<<ll1<<endl;
	ll1.insertNum(5);
	cout<<ll1<<endl;
	ll1.insertNum(0);
	cout<<ll1<<endl;
	singleList sl9(initializer_list<int>{4,3,1});
	cout<<sl9<<endl;
	sl9.insertKeepSorted(5);
	cout<<sl9<<endl;
	sl9.insertKeepSorted(0);
	cout<<sl9<<endl;
	sl9.insertKeepSorted(2);
	cout<<sl9<<endl;

	cout<<"按照左半右半区间调整单链表结构"<<endl;
	singleList sl10(initializer_list<int>{6,5,4,3,2,1});
	cout<<sl10<<endl;
	sl10.relocate();
	cout<<sl10<<endl;
}

void testChapter3(){
	using namespace chapter3;		
	cout<<"二叉树的序列化与反序列化"<<endl;
	cout<<"1）先序遍历实现"<<endl;
	string prevStr("1!2!4!#!#!#!3!#!5!#!#!");
	treeNode *root=recoverByprevstring(prevStr);
	inorderWalk(root);
	preorderWalk(root);
	postorderWalk(root);
	string result=serialBypreorder(root);
	cout<<prevStr<<endl;
	cout<<result<<endl;
	cout<<"2)层级遍历实现"<<endl;
	string levelserial=serialBylevel(root);
	treeNode *reconRoot=reconBylevel(levelserial);
	inorderWalk(reconRoot);
	preorderWalk(reconRoot);
	postorderWalk(reconRoot);
	cout<<"美观地打印二叉树"<<endl;
	printTree(root);

	cout<<"二叉树中累计和为指定值的最长路径的长度"<<endl;
	string bstStr1("-3!3!-9!1!0!2!1!#!#!1!6!#!#!#!#!#!#!#!#!");
	treeNode *root1=reconBylevel(bstStr1);
	inorderWalk(root1);
	cout<<"sum=6,MaxLen="<<getMaxlen(root1,6)<<endl;
	cout<<"sum=-9,MaxLen="<<getMaxlen(root1,-9)<<endl;
	cout<<"sum=1,MaxLen="<<getMaxlen(root1,1)<<endl;


	cout<<"二叉树最大的bst子树"<<endl;
	string bstStr2("6!1!12!0!3!10!13!#!#!#!#!4!14!20!16!#!#!#!#!#!#!#!#!2!5!11!15!#!#!#!#!#!#!#!#!#!#!#!#!");
	treeNode *root2=reconBylevel(bstStr2);
	auto cur=root2->right;
	for(int i=0;i<2;++i)
		cur=cur->left;
	cur->left=new treeNode(2);
	cur->right=new treeNode(5);
	
	inorderWalk(root2);
	postorderWalk(root2);
	treeNode *subroot1=largestSubBST(root2);
	inorderWalk(subroot1);
	BTreeDestroy(root);
	BTreeDestroy(reconRoot);
	BTreeDestroy(root1);
	BTreeDestroy(root2);
}