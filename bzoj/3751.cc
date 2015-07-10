#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;

#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const int maxn=105;
int n,m;
int prime[5]={89119,74323,9607,20507,20719};
int a[maxn][5];
void get(int k) {
	int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {
		rep(i,0,4,1) {
			a[k][i]=a[k][i]*10+ch-'0';
			a[k][i]%=prime[i];
		}
		ch=getchar();
	}
	if(f==-1) {
		rep(i,0,4,1) {
			a[k][i]=prime[i]-a[k][i];
		}
	}
}
const int maxm=100500;
int mem[maxm][5];
bool solve(int cur_ans,int prime_pos) {
	if(mem[cur_ans][prime_pos]!=-1)
		return mem[cur_ans][prime_pos];
	long long cur_result=0;
	int cur_prime=prime[prime_pos];
	for(int i=n;i>=0;--i) {
		cur_result+=a[i][prime_pos];
		if(i!=0)
			cur_result*=cur_ans;
		cur_result%=cur_prime;
	}
	cur_result%=cur_prime;
	return  mem[cur_ans][prime_pos]=(cur_result==0) ;
}
int main() {
	R(n); R(m);
	rep(i,0,n,1) {
		get(i);
	}
	memset(mem,-1,sizeof(mem));
	vector<int> ans;
	rep(i,0,m,1) {
	//	if(clock()>=950*CLOCKS_PER_SEC) break;
		rep(j,0,4,1) {
			if(!solve(i%prime[j],j)){
				goto next;
			}
		}
		ans.push_back(i);
next:
		continue;
	}
	Pn(int(ans.size()));
	rep(i,0,ans.size()-1,1) {
		Pn(ans[i]);
	}
}
