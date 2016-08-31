#ifndef KMP_H
#define KMP_H
#include "publicHeader.h"

using namespace std;


vector<int> getNextArray(const string &match);
int kmpMatch(const string &s,const string &match);


#endif
