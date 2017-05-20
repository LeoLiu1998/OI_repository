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
struct Data{
	char a[20];
	Data() {
		memset(a,0,sizeof a);
	}
};
int DP[1<<13];
Data s;
int l,k;

int Zip(Data x) {
	int ret=0;
	for(int i=1;i<=l;++i) {
		ret*=2;
		ret+=(x.a[i]=='+');
	}
	return ret;
}
Data Unzip(int k) {
	Data ret;
	int cnt=0;
	while(k) {
		ret.a[l-cnt++]=k%2;
		k>>=1;
	}
	return ret;
}
// 3-4 
// 1100
// 1<<4 - 1

void prt(const Data &x) {
/*	for(int i=1;i<=l;++i) {
		putchar(x.a[i]+'0');
	}
	puts("");
*/}

int Deal(int x,int l, int r) {
	int temp=0;
	for(int i=l;i<=r;++i) {
		temp^=(1<<(i-1));
	}
//	puts("");
	prt(Unzip(x));
	prt(Unzip(temp));
	x^=temp;
	prt(Unzip(x));
//	puts("");
	return x;
}

queue<int> q;
int main() {
	int T;
	R(T);
	for(int i=1;i<=T;++i) {
		memset(DP,-1,sizeof DP);
		scanf("%s",s.a+1); R(k);
		l=strlen(s.a+1);
		int cur=Zip(s);
	//	print(Unzip(cur));
		DP[cur]=0;
		while(q.size()) q.pop();
		//q.clear();
		q.push(cur);
		while(q.size()) {
			int f=q.front(); q.pop();
			prt(Unzip(f));
			for(int i=1;i+k-1<=l;++i) {
			//	print(Unzip(f));
				int nex=Deal(f,i,i+k-1);
				prt(Unzip(nex));
				if(DP[nex]!= -1) continue;
				else {
					DP[nex]=DP[f]+1;
					q.push(nex);
				}
			}
			//puts("");
			//puts("");
		}
		printf("Case #%d: ",i); 
		if((DP[(1<<(l))-1]==-1)) { // ? "IMPOSSIBLE\n":("%d\n",DP[(1<<(l+1))-1]));
			printf("IMPOSSIBLE\n");
		} else {
			printf("%d\n",DP[(1<<(l))-1]);
		}
	}
}

