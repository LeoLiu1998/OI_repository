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
int ans[27][27];
int a[27][27];
bool nem[30];
int n,r,c;
set<char> s;
int lv[30],rv[30];
void Fill(int x) {
	memset(lv,-1,sizeof lv); memset(rv,-1,sizeof rv);
	int cl=-1;
	for(int i=1;i<=c;++i) {
		if(a[x][i]!=-1) {
			cl=i;
		}
		lv[i]=cl;
	}
	int cr=-1;
	for(int i=c;i;--i) {
		if(a[x][i]!=-1) {
			cr=i;
		}
		rv[i]=cr;
	}
	for(int i=1;i<=c;++i) {
		if(a[x][i]!= -1) continue;
		a[x][i]= (lv[i]==-1)? a[x][rv[i]]:a[x][lv[i]];
	}
}
void Print() {
	for(int i=1;i<=r;++i) {
		int pos=i;
		if(!nem[i]) {
			pos= (lv[i]==-1)? rv[i]:lv[i];
		}
		for(int j=1;j<=c;++j) {
			putchar(a[pos][j]+'A'-1);
		}
		puts("");
	}
}
int main() {
	int T; R(T);
	for(int i=1;i<=T;++i) {
		R(r); R(c);
		memset(a,0,sizeof a);
		memset(nem,0,sizeof nem);
		for(int j=1;j<=r;++j) {
			for(int k=1;k<=c;++k) {
				char ch=getchar();
				while((ch!='?')&&(!isalpha(ch))) ch=getchar();
				if(ch=='?') {
					a[j][k]=-1;
				} else {
					a[j][k]=ch-'A'+1;
					s.insert(ch);
				}
			}
			for(int k=1;k<=c;++k) {
				if(a[j][k]!=-1) {
					nem[j]=1;
					break;
				}
			}
		}
		n=s.size();
		for(int j=1;j<=r;++j) {
			if(nem[j]) {
				Fill(j);
			}
		}
		memset(lv,-1,sizeof lv);
		memset(rv,-1,sizeof rv);
		int tmp=-1;
		for(int j=1;j<=r;++j) {
			if(nem[j])  {
				tmp=j;
			}
			lv[j]=tmp;
		}
		tmp=-1;
		for(int j=n;j;--j) {
			if(nem[j]) tmp=j;
			rv[j]=tmp;
		}
		printf("Case #%d:\n",i);
		Print();
	}
}

