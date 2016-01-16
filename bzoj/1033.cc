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
int a[8],b[8],la[8],lb[8],c[8],C[8],g[8],age[8],cake[8],now,num;
int f[10][10],da[25],db[25],d[25],n,m,t,T,tot,dat,r,caked,i,j;
int dx[5]={0,1,0,-1,0},dy[5]={1,0,-1,0,0};

void birth()
{
	for(int i=1;i<=now;i++)
		if(!a[i]&&!b[i]) return;
	now++; num++;
	a[now]=b[now]=la[now]=lb[now]=cake[now]=0;
	g[now]=(num+5)/6,age[now]=1;
	c[now]=C[now]=int(4*pow(1.1,g[now]));
}

void move(int p)
{
	int i,j,x,y,z,temp=-1,go=4,v[5];
	for(i=0;i<4;i++)
	{
		x=a[p]+dx[i],y=b[p]+dy[i],z=1;
		if(x<0||y<0||x>n||y>m||x==la[p]&&y==lb[p]) z=0;
		for(j=1;z&&j<=tot;j++) if(da[j]==x&&db[j]==y) z=0;
		for(j=1;z&&j<=now;j++) if(a[j]==x&&b[j]==y) z=0;
		if((v[i]=z)&&temp<f[x][y]) temp=f[x][y],go=i;
	}
	if(age[p]%5==0&&go<4)
	{
		for(i=(go+3)&3;i!=go;i=(i+3)&3) if(v[i]) break;
		if(!v[go=i]) go=4;
	}
	la[p]=a[p],lb[p]=b[p],a[p]+=dx[go],b[p]+=dy[go];
	if(a[p]==n&&b[p]==m&&!caked) cake[p]=caked=1,c[p]=min(C[p],c[p]+int(C[p]/2.0));
}

int dist(int a,int b,int c,int d)
{
	return (a-c)*(a-c)+(b-d)*(b-d);
}

void target(int p)
{
	int i,dis,td=1<<30,ta;
	for(i=1;i<=now;i++)
	{
		dis=dist(da[p],db[p],a[i],b[i]);
		if(cake[i]&&dis<=r*r) {d[p]=i; return;}
		if(dis<td||dis==td&&age[i]>age[ta]) td=dis,ta=i;
	}
	if(td>r*r) d[p]=0; else d[p]=ta;
}

bool cross(int ax,int ay,int bx,int by,int cx,int cy)
{
	if(dist(ax,ay,cx,cy)>r*r) return 0;
	int abx=bx-ax,aby=by-ay,acx=cx-ax,acy=cy-ay,dot,len,dis;
	dot=abx*acx+aby*acy,len=dist(ax,ay,bx,by);
	if(dot<0) return dist(ax,ay,cx,cy)*4<=1;
	else if(dot>len) return dist(bx,by,cx,cy)*4<=1;
	else{
		dis=(ax-cx)*(by-cy)-(bx-cx)*(ay-cy);
		return dis*dis*4<=len;
	}
}

void attack(int p)
{
	if(!d[p]) return;
	for(int i=1;i<=now;i++)
		if(cross(da[p],db[p],a[d[p]],b[d[p]],a[i],b[i])) c[i]-=dat;
}

void died()
{
	int i,j;
	for(i=1;i<=now;i++)
		if(c[i]<0)
		{
			if(cake[i]) caked=0;
			for(j=i;j<now;j++) a[j]=a[j+1],b[j]=b[j+1],la[j]=la[j+1],lb[j]=lb[j+1],c[j]=c[j+1],C[j]=C[j+1],g[j]=g[j+1],age[j]=age[j+1],cake[j]=cake[j+1];
			now--,i--;
		}
}

bool over()
{
	for(int i=1;i<=now;i++)
		if(cake[i]&&!a[i]&&!b[i]) return 1;
	return 0;
}

int main()
{
	R(n); R(m); R(tot); R(dat); R(r);
	for(i=1;i<=tot;i++) {
		R(da[i]); R(db[i]);
	}
	R(T);
	for(t=1;t<=T;t++)
	{
		if(now<6) birth();
		for(i=1;i<=now;i++) f[a[i]][b[i]]+=cake[i]?5:2;
		for(i=1;i<=now;i++) move(i);
		for(i=1;i<=tot;i++) target(i),attack(i);
		died();
		if(over()) break;
		for(i=0;i<=n;i++)
			for(j=0;j<=m;j++) if(f[i][j]) f[i][j]--;
		for(i=1;i<=now;i++) age[i]++;
	}
	if(t>T) puts("The game is going on"); else printf("Game over after %d seconds\n",t);
	cout<<now<<endl;
	for(i=1;i<=now;i++) printf("%d %d %d %d %d\n",age[i]-1,g[i],c[i],a[i],b[i]);
	return 0;
}
