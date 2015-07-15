#ifdef YGHDEBUG
#include <iostream>
#endif
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <cctype>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <vector>
#define PROB "" 
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

inline void Redirect() {
#ifndef YGHDEUG
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
#endif
}
const int maxl=25;
int a[4][2*maxl][2*maxl];//0 a, 1 b 2c 3d
int pos[4][2*maxl][2*maxl];
const int maxn=1500;
int vis[maxn][maxn];
int dp[maxn][4][maxn];
int c[maxn][4];
struct Node{
	int v;
	vector<int> nei;
	Node(){
		v=0;
		nei.clear();
	}
};
Node node[maxn];
int n;
int cnt=0;
void init();
int ans=0;
void dfs();
int main() {
	R(n);
	for(int i=0;i<4;++i) {
		for(int j=1;j<=n;++j) {
			for(int k=1;k<=2*j-1;k++) {
				R(a[i][j][k]);
				cnt++;
				pos[i][j][k]=cnt;
				node[pos[i][j][k]].v=a[i][j][k];
			}
		}
	}
	cnt--;
	init();
	dfs();
	Pn(ans);
}
int tree_dp(int i,int l1,int l2){
	int from=0;
	while(node[i].nei[from]!=l2) from++;
	if(dp[i][from][l1]>0) return dp[i][from][l1];
	int l,r;
	if(l1>l2) {
		l=l2+1;
		r=l1;
	} else {
		l=l1;
		r=l2-1;
	}
	int lmax=0,rmax=0;
	for(int j=0;j<=2;++j) {
		if(j!=from&&(l<=node[i].nei[j]&&node[i].nei[j]<=r))
			if(node[i].nei[j]<i)
				lmax=max(lmax,tree_dp(node[i].nei[j],l,i));
			else
				rmax=max(rmax,tree_dp(node[i].nei[j],r,i));
	}
	dp[i][from][l1]=lmax+rmax+1;
	return dp[i][from][l1];
}
void dfs(){
	rep(i,1,n*n*4,1) {
		int lm=0,rm=0;
		rep(j,0,2,1) {
			if(node[i].nei[j]<i) {
				lm=max(lm,tree_dp(node[i].nei[j],1,i));
			} else
				rm=max(rm,tree_dp(node[i].nei[j],n*n*4,i));
		}
		ans=max(ans,lm+rm+1);
	}
}
struct Pos{
	int panel,x,y;
	Pos(int _panel=0,int _x=0,int _y=0):panel(_panel),x(_x),y(_y){}
};
#define pb push_back
void link2(Pos pa,Pos b) {
	node[a[pa.panel][pa.x][pa.y]].nei.pb(a[b.panel][b.x][b.y]);
	node[a[b.panel][b.x][b.y]].nei.pb(a[pa.panel][pa.x][pa.y]);
}
void link(int a,int b)
{
	if (!vis[a][b]){
		vis[a][b]=1;
		node[a].nei.pb(b);//c[a][++c[a][0]]=b;
	}if (!vis[b][a]){
		vis[b][a]=1;
		node[b].nei.pb(a);//c[b][++c[b][0]]=a;
	}
}
/*void init() {
	int l,r;
	for(int i=1;i<=n;++i) {
		l=1;
		r=2*i-1;
		link(Pos(0,i,l),Pos(2,i,r));// edge of AC
		link(Pos(0,i,r),Pos(1,i,l));//edge of AB
		link(Pos(1,i,r),Pos(2,i,l));//edge of BC
		link(Pos(2,n,2*i-1),Pos(3,n,2*i-1));//edge of Dc
		link(Pos(3,i,l),Pos(0,n,2*i-1));//edge DA
		link(Pos(3,i,r),Pos(1,n,2*i-1));//DB
	}
	for(int i=0;i<4;++i) {
		for(int j=2;j<=n;++j) {
			for(int k=2;k<=2*j-1;k+=2) {
				link(Pos(i,j,k),Pos(i,j-1,k-1));
				link(Pos(i,j,k),Pos(i,j,k-1));
				link(Pos(i,j,k),Pos(i,j,k+1));
			}
		}
	}
}
*/
void init()
{
    for (int k=0;k<=3;k++)
        for (int i=2;i<n;i++)
            for (int j=2;j<i*2-1;j++)
            {
                link(a[k][i][j],a[k][i][j-1]);
                link(a[k][i][j],a[k][i][j+1]);
                if (j%2)
                    link(a[k][i][j],a[k][i+1][j+1]);
                else
                    link(a[k][i][j],a[k][i-1][j-1]);
            }
    for (int k=0;k<=3;k++)
        for (int j=2;j<=n*2-1;j+=2)
        {
            link(a[k][n][j],a[k][n][j-1]);
            link(a[k][n][j],a[k][n][j+1]);
            link(a[k][n][j],a[k][n-1][j-1]);
        }
    for (int k=1,i=1;k<=n;k++,i++)
    {
        link(a[0][i][1],a[2][i][i*2-1]);
        link(a[0][i][i*2-1],a[1][i][1]);
        link(a[1][i][i*2-1],a[2][i][1]);
    }
    for (int j=1;j<=n*2-1;j+=2)
    {
        link(a[0][n][j],a[3][n-(j/2)][1]);
        link(a[1][n][j],a[3][j/2+1][((j/2)+1)*2-1]);
        link(a[2][n][j],a[3][n][n*2-j]);
    }
}
