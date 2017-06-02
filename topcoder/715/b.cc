#include<bits/stdc++.h>
using namespace std;
class MaximumRangeDiv2{
	public: int findMax(string s) {
		int ma=0,mi=0,cur=0;
		for(int i=0;i<s.size();++i) {
			if(s[i]=='+') {
				cur++;
			} else {
				cur--;
			}
			ma=max(cur,ma);
			mi=min(cur,mi);
		}
		return ma-mi;
	}
};