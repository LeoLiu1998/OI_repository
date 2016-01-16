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
char alpha[]={'B','E','S','I','G','O','M'};
int convert(char ch) {
	for(int i=0;i<7;++i) {
		if(alpha[i]==ch) return i;
	}
	return -1;
}
char getc() {
	char ch=getchar();
	while(!isalpha(ch)) ch=getchar(); return ch;
}
vector<pii> s[7];
int ss[7][7];
ll ans=0;
int cho[10];
int chn[10];
bool check() {
	long long cur=(cho[0]+2*cho[1]+cho[2]*2+cho[3])*(cho[4]+cho[5]+cho[1]+cho[2])*(cho[5]*2+cho[6]);
	return (cur%7==0);
}
void dfs(int k) {
	if(k==7) {
		if(check())  {
			ll del=1;
			for(int i=0;i<7;++i) del*=chn[i];
			ans+=del;
		}
	} else {
		for(int i=0;i<s[k].size();++i) {
			cho[k]=s[k][i].fi;
			chn[k]=s[k][i].se;
			dfs(k+1);
		}
	}
}
int main() {
	int n; R(n);
	for(int i=1;i<=n;++i) {
		char ch=getc();
		int pos=convert(ch);
		int temp; R(temp);
		ss[pos][(((temp%7)+7)%7)]++;
	}
	for(int i=0;i<7;++i) {
		for(int j=0;j<7;++j) {
			if(!ss[i][j]) continue;
			s[i].pb(mp(j,ss[i][j]));
		}
	}
	dfs(0);
	cout<<ans<<endl;
}

