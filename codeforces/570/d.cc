//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
struct Node {
	int f,size,depth;
	int v,k;
	vector<int> son;
	Node(){}
};
int getc() {
	char ch=getchar();
	while(!isalpha(ch)) ch=getchar();
	return ch-'a'+1;
}
const int maxn=500005;
Node node[maxn];
int cnt=0;
int order[maxn];
struct Da{
	int ord,sum[30];
	Da() {
		ord=0;
		memset(sum,0,sizeof(sum));
	}
	bool operator < (const Da &a) const {
		return ord<a.ord;
	}
};
typedef vector<Da> ME;
ME ps[maxn];
void add(int d,int cur,int v) {
	Da temp;
	if(ps[d].empty()) {
		temp.ord=cur;
		temp.sum[v]++;
	} else {
		temp.ord=cur;
		rep(i,1,26,1) {
			temp.sum[i]=ps[d].back().sum[i];
		}
		temp.sum[v]++;
	}
	ps[d].pb(temp);
}
void dfs(int pos) {
	node[pos].depth=node[node[pos].f].depth+1;
	node[pos].k=++cnt;
	add(node[pos].depth,cnt,node[pos].v);
	order[cnt]=pos;
	for(int i=0;i<node[pos].son.size();++i) {
		dfs(node[pos].son[i]);
		node[pos].size+=node[node[pos].son[i]].size;
	}
	node[pos].size++;
}
int n,m;
void Query(int pos,int depth) {
	int l=node[pos].k;
	int r=l+node[pos].size-1;
	Da temp;
	temp.ord=l;
	int no=0;
	int al=lower_bound(ps[depth].begin(),ps[depth].end(),temp)-ps[depth].begin(); al--; temp.ord=r;
	int ar=lower_bound(ps[depth].begin(),ps[depth].end(),temp)-ps[depth].begin(); ar=min(ar+1,(int)ps[depth].size()-1);
	while(ps[depth][ar].ord>r) ar--;
	
	for(int i=1;i<=26;++i) {
		no+=((ps[depth][ar].sum[i]-ps[depth][al].sum[i])%2);
	}
	if(no>1) puts("No");
	else puts("Yes");
}
int main() {
	R(n); R(m);
	rep(i,2,n,1) {
		R(node[i].f);
		node[node[i].f].son.pb(i);
	}
	Da temp; temp.ord=0;
	memset(temp.sum,0,sizeof(temp.sum));
	rep(i,1,n,1) {
		ps[i].pb(temp);
		node[i].v=getc();
	}
	dfs(1);
	while(m--) {
		int pos,dep; R(pos); R(dep);
		Query(pos,dep);
	}
	return 0;
}
