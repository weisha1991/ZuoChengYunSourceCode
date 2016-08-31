#include "manacher.h"
#include <numeric>
#include <limits.h>
using namespace std;

string manacherString(string str){
	string ret(str.size()*2+1,' ');	
	int index=0;
	for(int i=0;i<ret.size();++i){
		ret[i]=((i&1)==0)?'#':str[index++];
	}
	return ret;
}

int maxLongestPalidromeStringLen(string str){
	if(str.empty())
		return 0;
		
	string manacherStr=manacherString(str);
	vector<int> pArr(manacherStr.size());
	int index=-1,pR=-1;
	int maxVal=INT_MIN;
	cout<<"源字符串:"<<str<<endl;
	cout<<"manacher格式化字符串"<<manacherStr<<endl;
	for(int i=0;i<manacherStr.size();++i){
		pArr[i]=pR>i?min(pArr[2*index-1],pR-i):1;
		while(i+pArr[i]<manacherStr.size()&&i-pArr[i]>-1){
			if(manacherStr[i+pArr[i]]==manacherStr[i-pArr[i]])
				pArr[i]++;
			else
				break;
		}
		if(i+pArr[i]>pR){
			pR=i+pArr[i];
			index=i;
		}
		maxVal=max(maxVal,pArr[i]);
	}
	return maxVal-1;
}


