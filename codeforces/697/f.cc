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
inline void R(ll &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if (ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
	x*=f;
}
struct Node {
	Node * son[27];
	Node * fail;
	int v;
	Node() {
		memset(son,NULL,sizeof  son);
		fail=NULL;
		v=-1;
	}
};
const int maxn=303;
Node node[maxn];
Node * root;
int cnt=0;
int n;
ll l;
char s[205][205];
int a[205];
void Insert(char s[],int v) {
	Node * p=root;
	int len=strlen(s);
	for(int i=0;i<len;++i) {
		int idx=s[i]-'a';
		if(p->son[idx]==NULL) {
			p->son[idx]=&node[++cnt];
//			cout<<"f:"<<(p-root)<<" c:"<<s[i]<<" cur:"<<cnt<<endl;
		}
		p=p->son[idx];
	}
	if(p->v==-1) p->v=v;
	else p->v+=v;
}
void AC_Build() {
	queue<Node*> q;
	q.push(root);
	while(q.size()) {
		Node * cur=q.front();
		//cout<<cur-root<<" fail:"<<(cur->fail)-root<<endl;
		q.pop();
		for(int i=0;i<26;++i) {
			if(cur->son[i]!=NULL) {
				if(cur==root) {
					cur->son[i]->fail=root;
				} else {
					Node * t=cur->fail;
					while(t!=NULL) { 
						if(t->son[i]!=NULL) {
							cur->son[i]->fail=t->son[i];
							break;
						}
						t=t->fail;
					}
					if(t==NULL) {
						cur->son[i]->fail=root;
					}
				}
				q.push(cur->son[i]);
			}
		}
	}
}
bool vis[maxn];
ll trans[maxn][maxn];
inline int Pos(Node * p) {
	return (p-root);
}
void DFS(Node * p) {
	if(p==NULL||vis[Pos(p)]) return;
	DFS(p->fail);
	for(int i=0;i<=cnt;++i) {
		trans[Pos(p)][i]=max(trans[Pos(p)][i],trans[Pos(p->fail)][i]);
	}
	for(int i=0;i<26;++i) {
		/*if(p->son[i]!=NULL) {
			if
			trans[Pos(p)][Pos(p->son[i])]=max(trans[Pos(p)][Pos(p->son[i])],(ll)(p->son[i]->v));
			if(!(~trans[Pos(p)][Pos(p->son[i])])) {
				trans[Pos(p)][Pos(p->son[i])]=0;
			}/

		}*/
		ll sum=0;
		Node * q=p->son[i];
		if(q==NULL) continue;
		while(q!=root) {
			sum+=q->v>0? q->v:0;
			q=q->fail;
		}
		trans[Pos(p)][Pos(p->son[i])]=max(trans[Pos(p)][Pos(p->son[i])],sum);
		if(!(~trans[Pos(p)][Pos(p->son[i])])) 
			trans[Pos(p)][Pos(p->son[i])]=0;
	}
	vis[Pos(p)]=1;
	for(int i=0;i<26;++i) {
		if(p->son[i]!=NULL) 
			DFS(p->son[i]);
	}
	return ;
}
void Calc() {
	memset(trans,-1,sizeof trans);
	for(int i=0;i<26;++i) {
		if(root->son[i]!=NULL) {
			trans[0][(root->son[i])-root]=(~root->son[i]->v)?root->son[i]->v:0;
		}
	}
	vis[0]=1;
	for(int i=0;i<26;++i) {
		DFS(root->son[i]);
	}
}
ll ans[maxn][maxn];
ll tmp[maxn][maxn];
void qpow(ll l) {
	for(int i=0;i<=cnt;++i) ans[i][i]=0;
	while(l) {
		if(l&1) {
			memset(tmp,-1,sizeof tmp);
			for(int k=0;k<=cnt;++k) {
				for(int i=0;i<=cnt;++i) {
					for(int j=0;j<=cnt;++j) {
						if(~ans[i][k] && ~trans[k][j]) {
							tmp[i][j]=max(tmp[i][j],ans[i][k]+trans[k][j]);
						}
					}
				}
			}
			for(int i=0;i<=cnt;++i) {
				for(int j=0;j<=cnt;++j) {
					ans[i][j]=tmp[i][j];
				}
			}
		}
		memset(tmp,-1,sizeof tmp);
		for(int k=0;k<=cnt;++k) {
			for(int i=0;i<=cnt;++i) {
				for(int j=0;j<=cnt;++j) {
					if(~trans[i][k] && ~trans[k][j]) {
						tmp[i][j]=max(tmp[i][j],trans[i][k]+trans[k][j]);
					}
				}
			}
		}
		for(int i=0;i<=cnt;++i) {
			for(int j=0;j<=cnt;++j) {
				trans[i][j]=tmp[i][j];
			}
		}
		l>>=1;
	}
}
void prt(ll s[][maxn]) {
	for(int i=-1;i<=cnt;++i) {
		printf("% 4lld",(ll)i);
	}
	puts("");
	for(int i=0;i<=cnt;++i) {
		printf("% 4lld",i);
		for(int j=0;j<=cnt;++j)
			printf("% 4lld",s[i][j]);
		puts("");
	}
}
int main() {
	R(n); R(l); root=&node[0];
	for(int i=1;i<=n;++i) {
		R(a[i]);
	}
	for(int i=1;i<=n;++i) {
		scanf("%s",s[i]);
		Insert(s[i],a[i]);
	}
	AC_Build();
	Calc();
	//prt(trans);
	memset(ans,-1,sizeof ans);
	qpow(l);
	ll ret=0;
	for(int i=0;i<=cnt;++i) {
		ret=max(ret,ans[0][i]);
	}
	cout<<ret<<endl;
}

