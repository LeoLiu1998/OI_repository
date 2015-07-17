//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define Prob "dinner"
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void Redirect() {
#ifndef YGHDEUG
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
#endif
}
#define pb push_back
const int maxn=10;
int maxs=2<<10;
int n,s;
int ans=0;
int gcd(int a,int b){
	if(!(a%b)) return b;
	return gcd(b,a%b);
}
vector<int> get(int k) {
	vector<int> ret;
	for(int i=1;(1<<(i-1))<=k;++i){
		if((1<<(i-1))&k) {
			ret.pb(i+1);
		}
	}
	return ret;
}
bool check(int a,int b){
	vector<int> va=get(a);
	vector<int> vb=get(b);
	for(int i=0;i<va.size();++i) {
		for(int j=0;j<vb.size();++j) {
			if(gcd(va[i],vb[j])!=1) {
				return 0;
			}
		}
	}
/*	cout<<"a:";
	for(int i=0;i<va.size();++i)
		Ps(va[i]);
	cout<<"\nb:";
	for(int i=0;i<vb.size();++i) 
		Ps(vb[i]);
	puts("\n");*/
	return 1;
}
vector <int> temp;
int main() {
	Redirect();
	cin>>n;
	s=(1<<(n-1))-1;
	for(int i=0;i<=s;++i) {
		for(int j=0;j<=s;++j) {
			ans+=check(i,j);
		}
	}
	Pn(ans);
}
