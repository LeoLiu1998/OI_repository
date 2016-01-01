/* ID: yeguang2
PROG : comehome
LANG : C++11
*/
#define PROB "comehome"
#include <bits/stdc++.h>
using namespace std;
void Redirect() {
	freopen(PROB".in","r",stdin);
#ifndef YGHDEBUG
	freopen(PROB".out","w",stdout);
#endif
}
int c2int(char a) {
//	assert(isalpha(a));
	if(a>='a'&&a<='z') {
		return (int)a-'a' +1;
	} else if(a>='A'&&a<='Z'){
		return (int)a-'A'+27;
	}
	return INT_MAX;
}
int a[105][105];
int m;
int n=52;

void add_edge(int u,int v,int w) {
	a[u][u]=a[v][v]=0;
	a[u][v]=a[v][u]=min(a[v][u],w);
}
int ans=INT_MAX,ans_pos;
void floyed() {
	for(int k=1;k<=n;++k) {
		for(int i=1;i<=n;++i) {
			for(int j=1;j<=n;++j) {
				if(a[i][k]+a[k][j]<a[i][j]) {
					a[i][j]=a[i][k]+a[k][j];
				}
			}
		}
	}
}

int main() {
	Redirect();
	scanf("%d",&m);
	memset(a,0x3f,sizeof a);
	for(int i=1;i<=m;++i) {
		char ch=0; while(!isalpha(ch)) ch=getchar();
		int x=c2int(ch);
		ch=0; while(!isalpha(ch)) ch=getchar();
		int y=c2int(ch);
		int len; scanf("%d",&len);
		add_edge(x,y,len);
	}
	floyed();
	for(int i=1;i<=25;++i) {
		if(ans>a[i+26][52]) {
			ans_pos=i;
			ans=a[i+26][52];
		}
	}
	cout<<(char)(ans_pos-1+'A')<<" "<<ans<<endl;
}
