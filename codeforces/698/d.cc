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
pii operator - (const pii &a, const pii &b) {
	pii ret; ret.fi=a.fi-b.fi;
	ret.se=a.se-b.se;
	return ret;
}
int k,n;
pii mon[1005];
int ao[10][1005];
pii sto[10];
pii cur_ori;
int perm[10];
bool kil[1005];
bool tkil[1005];
int ans=0;
inline int Quadrant(pii a) {
	if(a.fi>=0&&a.se>0) return 1;
	else if(a.fi<0&&a.se>=0) return 2;
	else if(a.fi<=0&&a.se<0) return 3;
	else if(a.fi>0&&a.se<=0) return 4;
	puts("!!!");
	return 0;
	//assert(1);
}
inline ll Dis2(pii a) {
	return (ll)a.fi*a.fi+(ll)a.se*a.se;
}
inline ll Cross(pii a,pii b) {
	ll flag=(ll)a.fi*b.se-(ll)a.se*b.fi;
	return flag;
}
inline bool ADcmp(pii a, pii b) {
	int qa=Quadrant(a),qb=Quadrant(b);
	if(qa!=qb) return qa<qb;
	else {
		ll flag=Cross(a,b);
		if(flag) return flag>0;
		return Dis2(a)<Dis2(b);
	}
}
inline bool cmp(int a,int b) {	
	return ADcmp((mon[a]-cur_ori),(mon[b]-cur_ori));
}
bool Scmp(int a,int b) {
	pii pa=mon[a]-cur_ori,pb=mon[b]-cur_ori;
	int qa=Quadrant(pa),qb=Quadrant(pb);
	if(qa!=qb) return qa<qb;
	else return Cross(pa,pb)>0;
}
stack<int> s;
int shoot(int target, int kth) {
	if(kth==k+1) return -1;
	int pos=perm[kth];
	s.push(target);
	cur_ori=sto[pos];
	tkil[target]=1;
	int bg=lower_bound(ao[pos]+1,ao[pos]+n+1,target,Scmp)-ao[pos];
	int use=1;
	for(int i=bg;;i++) {
		if(ao[pos][i]==target) break;
		if(tkil[ao[pos][i]]) continue;
		int need=shoot(ao[pos][i],kth+use);
		if(need==-1) return -1;
		else use+=need;
	}
	return use;
}
int main() {
	R(k); R(n);
	for(int i=1;i<=k;++i) {
		R(sto[i].fi); R(sto[i].se);
		perm[i]=i;
	}
	for(int i=1;i<=n;++i) {
		R(mon[i].fi); R(mon[i].se);
		for(int j=1;j<=k;++j) {
			ao[j][i]=i;
		}
	}
	for(int i=1;i<=k;++i) {
		cur_ori=sto[i];
		sort(ao[i]+1,ao[i]+n+1,cmp);
	}
	do {
		for(int i=1;i<=n;++i) {
			if(kil[i]) continue;
			while(s.size()) s.pop();
			if(shoot(i,1)!=-1) {
				kil[i]=1;
				while(s.size()) {
					kil[s.top()]=1;
					s.pop();
				}
			}
			memset(tkil,0,sizeof tkil);
		}
	}while(next_permutation(perm+1,perm+k+1));
	for(int i=1;i<=n;++i) {
		if(kil[i]) ans++;
	}
	Pn(ans);
}
