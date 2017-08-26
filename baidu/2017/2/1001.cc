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
int tmp[100005];
char s[1005];
char l[1005];
char r[1005];
const ll mod = (ll)(1e9)+7;
ll cur=0;
int T;
int len;
int lc,rc;

void Deal() {
	int k=r[1]-'0';
	for(int i=1;i<=k;++i) {
		for(int j=1;j<=lc;++j) {
			cur=cur*10+l[j]-'0';
			cur%=mod;
		}
	}
}
#define isalpha(x) isdigit(x)
int main() {
	R(T);
	while(T--) {
		cur=0;
		memset(s,0,sizeof s);
		scanf("%s",s+1);
		len=strlen(s+1);
		for(int i=1;i<=len;++i) {
			if(s[i]=='(') {
				int j=i+1;
				lc=0;
				for(j;isalpha(s[j]);++j) {
					l[++lc]=s[j];	
				}
				j+=3;
				rc=0;
				for(j;isalpha(s[j]);++j) {
					r[++rc]=s[j];
				}
				Deal();
				i=j;
				continue;
			} else {
				cur*=10;
				cur%=mod;
				cur+=s[i]-'0';
				cur%=mod;
				continue;
			}
		}
		cout<<cur<<endl;
	}
}

