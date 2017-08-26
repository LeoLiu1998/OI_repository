//This sourcecode is under GPLv3
//http://yeguanghao.xyz
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PROB
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
void Redirect() {
	freopen(PROB".in","r",stdin);
#ifndef YGHDEBUG
	freopen(PROB".out","w",stdout);
#endif
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
unordered_map<ll,int> hm;
int T;
int colo(char ch) {
	if(ch=='R') return 0;
	else if(ch=='G') return 1;
	else if(ch=='B') return 2;
	else return 3;
}

char col(int x) {
	if(!x) return 'R';
	if(x==1) return 'G';
	else if(x==2) return 'B';
	else return 'Y';
}

struct Stu{
	int data[16];
	Stu() {
		memset(data,0,sizeof data);
	}
};
ll Convert(const Stu &x) {
	ll ret=0;
	for(int i=0;i<16;++i) {
		ret=ret*4;
		ret+=x.data[i];
	}
	return ret;
}
Stu Convert(ll x) {
	Stu ret;
	for(int i=15;i>=0;--i) {
		ret.data[i]=x%4;
		x/=4;
	}
	return ret;
}

void Print(Stu x) {
	for(int i=0;i<16;++i) {
		putchar(col(x.data[i]));
		if((i+1)%4==0) puts("");
	}
	puts("--------------------");
}

void Print(ll x) {
	Print(Convert(x));
}

queue<ll>q;
Stu s,t;
ll tn;

ll RMove(Stu sta,int k) {
	int l=(k-1)*4;
	int r=4*k-1;
	int lv=sta.data[l];
	for(int i=l;i<r;++i) {
		sta.data[i]=sta.data[i+1];
	}
	sta.data[r]=lv;
	return Convert(sta);
}

ll CMove(Stu sta,int k) {
	int p[]={0,4,8,12};
	k--;
	for(int i=0;i<4;++i) {
		p[i]+=k;
	}
	int lv=sta.data[p[0]];
	for(int i=0;i<3;++i) {
		sta.data[p[i]]=sta.data[p[i+1]];
	}
	sta.data[p[3]]=lv;
	return Convert(sta);
}

ll RMoveR(Stu sta,int k) {
	int l=(k-1)*4;
	int r=4*k-1;
	int rv=sta.data[l];
	for(int i=r;i>l;--i) {
		sta.data[i]=sta.data[i-1];
	}
	sta.data[l]=rv;
	return Convert(sta);
}

ll CMoveR(Stu sta,int k) {
	int p[]={0,4,8,12};
	k--;
	for(int i=0;i<4;++i) {
		p[i]+=k;
	}
	int lv=sta.data[p[3]];
	for(int i=3;i>=1;--i) {
		sta.data[p[i]]=sta.data[p[i-1]];
	}
	sta.data[p[0]]=lv;
	return Convert(sta);
}


int main() {
	for(int i=0;i<16;++i) {
		t.data[i]=i/4;
	}
	tn=Convert(t);
	char ovo=0;
	while(~scanf("%c",&ovo)) {
		if(!isalpha(ovo)) continue;
		for(int i=0;i<16;++i) {
			char ch;
			if(!i) ch=ovo; else ch=0;
			while(!isalpha(ch)) ch=getchar();
			s.data[i]=colo(ch);
		}
		ll sn=Convert(s);
		hm.clear();
		hm[sn]=0;
		while(q.size()) q.pop();
		q.push(sn);
		while(q.size()) {
			ll cur=q.front();
			//Print(cur);
			//Pn(hm[cur]);
			q.pop();
			Stu cs=Convert(cur);
			for(int i=1;i<=4;++i) {
				ll nex=CMove(cs,i);
			//	Print(nex);
				if(!hm.count(nex)) {
					hm[nex]=hm[cur]+1;
					q.push(nex);
				}
				else {
					if(hm[nex]>hm[cur]+1) {
						hm[nex]=hm[cur]+1;
						q.push(nex);
					}
				}
				nex=RMove(cs,i);
			//	Print(nex);
				if(!hm.count(nex)) {
					hm[nex]=hm[cur]+1;
					q.push(nex);
				} else {
					if(hm[nex]>hm[cur]+1) {
						hm[nex]=hm[cur]+1;
						q.push(nex);
					}
				}
				nex=CMoveR(cs,i);
			//	Print(nex);
				if(!hm.count(nex)) {
					hm[nex]=hm[cur]+1;
					q.push(nex);
				} else {
					if(hm[nex]>hm[cur]+1) {
						hm[nex]=hm[cur]+1;
						q.push(nex);
					}
				}
				nex=RMoveR(cs,i);
			//	Print(nex);
				if(!hm.count(nex)) {
					hm[nex]=hm[cur]+1;
					q.push(nex);
				} else {
					if(hm[nex]>hm[cur]+1) {
						hm[nex]=hm[cur]+1;
						q.push(nex);
					}
				}
			//	puts("-------------------------------");
			}
			if(hm.count(tn)) {
				break;
			}
		}
		Pn(hm[tn]);
	}
}

