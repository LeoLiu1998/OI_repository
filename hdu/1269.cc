//This sourcecode is under GPLv3
//yeguanghao
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
const int maxn=100050;
int n,m;
typedef vector<int> Node;
Node node[maxn];
stack<int> sta;
int cnt;
int scnt;
int dfn[maxn];
int low[maxn];
bool instack[maxn];
#define pb push_back
void init(){
	scnt=cnt=0;
	while(sta.size()) sta.pop();
	rep(i,0,n,1) {
		node[i].clear();
	}
	memset(instack,0,sizeof(instack));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
}
void tarjan(int pos) {
	dfn[pos]=low[pos]=++cnt;
	instack[pos]=1;
	sta.push(pos);
	for(int i=0;i<node[pos].size();++i) {
		int cur=node[pos][i];
		if(!dfn[cur]) {
			tarjan(cur);
			low[pos]=min(low[pos],low[cur]);
		} else if(instack[cur]&&dfn[cur]<low[pos]) {
			low[pos]=dfn[cur];
		}
	}
	int temp;
	if(dfn[pos]==low[pos]) {
		scnt++;
		do {
			temp=sta.top();
			instack[temp]=0;
			sta.pop();
		}while(temp!=pos);
	}
}
int main() {
	while((~scanf("%d%d",&n,&m))&&(n||m)) {
		init();
		int a,b;
		rep(i,1,m,1) {
			R(a); R(b);
			node[a].pb(b);
		}
		rep(i,1,n,1){
			if(!dfn[i]) tarjan(i);
		}
		if(scnt!=1) puts("No");
		else puts("Yes");
	}
}
