//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int getc() {
	char ch=getchar();
	while(!isalpha(ch)) ch=getchar();
	return ch-'a'+1;
}
int str[250000];
int change[30];
int n,m;
int main() {
	R(n); R(m);
//	scanf("%s",str);
	for(int i=1;i<=n;++i) {
		str[i]=getc();
	}
	for(int i=1;i<=26;++i) {
		change[i]=i;
	}
	for(int i=1;i<=m;++i) {
		int u=getc(),v=getc();	
		for(int j=1;j<=26;++j) {
			if(change[j]==u) {
				change[j]=v;	
			} else if(change[j]==v) {
				change[j]=u;
			}
		}
	}
	for(int i=1;i<=n;++i) {
		putchar(change[str[i]]-1+'a');
	}
	puts("");

}

