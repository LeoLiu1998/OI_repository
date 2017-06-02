#include<bits/stdc++.h>
using namespace std;
string Ans(bool suc) {
	if(suc) return "Possible";
	else return "Impossible";
}

bool Check(vector<string> &s,vector<int> &Pre,int prl,int prr,vector<int> &In,int il,int ir,vector<int> &Post, int psl,int psr) {
	int cnt[60];
	memset(cnt,0,sizeof cnt);
	if(Pre[prl]!=Post[psr]) {
		return 0;
	}
	int root=Pre[prl];
	int ll,rl;
	for(int i=il;i<=ir;++i) {
		if(In[i]==root) {
			ll=i-il;
			rl=rl-i;
		}
	}
	for(int i=0;i<ll;++i) {
		cnt[Pre[prl+1+i]]++;
		cnt[In[il+i]]++;
		cnt[Post[psl+i]]++;
	}
	for(int i=1;i<=50;++i) {
		if(cnt[i]%3) return 0;
	}
	if(s[0]=="Pre") {
		if(s[4]=="Post") {
			if(!Check(s,Pre,prl+1,prl+ll,In,il,il+ll-1,Post,psl,psl+ll-1)) {
				return 0;
			}
		} else {
			if(!Check(s,Pre,prl+1,prl+ll,Post,psl,psl+ll-1,In,il,il+11-1)) {
				return 0;		
			}
		}
	} else if(s[0]=="Post") {
		if(s[2]=="Pre") {
			if(!Check(s,In,il,il+ll-1,Post,psl,psl+ll-1,Pre,prl+1,prl+ll)) {
				return 0;
			}
		} else {
			if(!Check(s,Post,psl,psl+ll-1,In,il,il+ll-1,Pre,prl+1,prl+ll)) {
				return 0;
			}
		}
	} else {
		//s0=In
		if(s[2]=="Pre") {
			if(!Check(s,In,il,il+ll-1,Pre,prl+1,prl+ll,Post,psl,psl+ll-1)) {
				return 0;
			}
		} else {
			if(!Check(s,Post,psl,psl+ll-1,Pre,prl+1,prl+ll,In,il,il+ll-1)) {
				return 0;
			}
		}
	}
	if(s[1]=="Pre") {
		if(s[5]=="Post") {
			if(!Check(s,Pre,prl+ll+1,prr,In,il+ll,ir,Post,psl+ll,psr)) {
				return 0;
			}
		} else {
			if(!Check(s,Pre,prl+ll+1,prr,Post,psl+ll,psr,In,il+ll,ir)) {
				return 0;
			}
		} 
	} else if(s[1]=="In") {
		if(s[5]=="Post") {
			if(!Check(s,In,il+ll,ir,Pre,prl+ll+1,prr,Post,psl+ll,psr)) {
				return 0;
			} 
		} else {
			if(!Check(s,Post,psl+ll,psr,Pre,prl+11+1,prr,In,il+ll,ir)) {
				return 0;
			}
		}
	} else {
		//s[1]=="Post"
		if(s[5]=="In") {
			if(!Check(s,In,il+ll,ir,Post,psl+ll,psr,Pre,prl+ll+1,prr)) {
				return 0;
			}
		} else {
			if(!Check(s,Post,psl+ll,psr,In,il+ll,ir,Pre,prl+ll+1,prr)) {
				return 0;
			}
		}
	}
	return 1;
}

class InPrePost {
	public: string isPossible(vector<string>s, vector<int> a1,vetcor<int> a2,vector<int> a3) {
		int r=a1.size()-1;
		return Ans(Check(s,a1,0,r,a2,0,r,a3,0,r));
	}
};
