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
struct Node {
	char c;
	Node * fail;
	Node * son[27];
	int t;
	Node(){
		fail=NULL; memset(son,NULL,sizeof son);
		c=0; t=0;
	}
	void Init() {
		fail=NULL; memset(son,NULL,sizeof son);
		c=0; t=0;
	}

};
int cnt=0;
const int maxn=5e5+50;
Node node[maxn];
char p[10005][55];
char str[2*maxn];
int n;
void Insert(char *s, int k) {
	Node * p= &node[0];
	int len=strlen(s);
	for(int i=0;i<len;++i) {
		int pos=s[i]-'a';
		if(p->son[pos]==NULL) {
			p->son[pos]= &node[++cnt];
			p->son[pos]->c=s[i];
		}
		p=p->son[pos];
		if(i+1==len) p->t+=1;
	}
	return ;
}
void Build() {
	queue<Node*> q;
	q.push(&node[0]);
	while(q.size()) {
		Node * cur=q.front();
		q.pop();
		for(int i=0;i<26;++i) {
			if(cur->son[i]!=NULL) {
				if(cur==&node[0]) {
					cur->son[i]->fail=cur;
				} else {
					Node * f= cur->fail;
					while(f!=NULL) {
						if(f->son[i]!=NULL) {
							cur->son[i]->fail=f->son[i];
							break;
						}
						f=f->fail;
					}
					if(f==NULL) cur->son[i]->fail=&node[0];
				}
				q.push(cur->son[i]);
			}
		}
	}
}
void Query() {
	Node * p=&node[0];
	int ans=0;
	for(int i=0;str[i];++i) {
		int pos=str[i]-'a';
		while(p->son[pos]==NULL&p!=&node[0]) p=p->fail;
		p=p->son[pos];
		if(p==NULL) p=&node[0];
		Node * t=p;
		while(t!=&node[0]) {
			ans+=t->t;
			t->t=0;
			t=t->fail;
		}
	}
	Pn(ans);
}
int main() {
	int M;R(M);
	while(M--) {
		for(int i=0;i<=cnt;++i) {
			node[i].Init();
		} cnt=0;
		memset(p,0,sizeof p); 
		memset(str,0,sizeof str);
		R(n);
		for(int i=1;i<=n;++i) {
			scanf("%s",p[i]);
			Insert(p[i],i);
		}
		scanf("%s",str);
		Build();
		Query();
	}
}

