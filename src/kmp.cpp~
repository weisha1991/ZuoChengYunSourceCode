#include "kmp.h"

vector<int> getNextArray(const string &match){
	vector<int>	 ret;
	if(match.empty())
		return ret;
	ret.resize(match.size(),0);
	ret[0]=-1;
	ret[1]=0;
	int cn=0;//cn代表当前next[pos]长度前缀的下一个字符
	int pos=2;
	while(pos<match.size()){
		if(match[pos-1]==match[cn]){//如果cn位置的字符等于pos前一位置的字符,则next[pos]=next[pos]+1;
			ret[pos++]=++cn;
		}
		else if(cn>0){//不相等则找cn位置之前字符串的最长前缀的下一个字符
			cn=ret[cn];
		}
		else
			ret[pos++]=0;
	}
	return ret;
}


int kmpMatch(const string &s,const string &match){
	if(s.empty()||match.empty()||s.size()<match.size())
		return -1;
	
	int mi=0,si=0;
	vector<int> next=getNextArray(match);
	cout<<"next array:";
	for(auto num:next)
		cout<<num<<" ";
	cout<<endl; 
	while(si<s.size()&&mi<match.size()){
		if(s[si]==match[mi])
		{
			si++;
			mi++;
		}
		else if(next[si]==-1)
			si++;
		else{
			mi=next[mi];
		}
	}
	return (mi==match.size())?(si-mi):-1;
}
