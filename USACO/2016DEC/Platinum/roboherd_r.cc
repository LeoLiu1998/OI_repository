//This sourcecode is under GPLv3
//http://yeguanghao.xyz
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define maxn 100010
#define MAX 0x7f7f7f7f

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
using namespace __gnu_pbds;
int n,k,rt;

long long now,Ans;

int P[maxn][11],num[maxn];
int anc[100];
struct Node{
 long long Val,lstV;
 int rt,lst;
 bool operator<(const Node &t)const{return Val>t.Val;}
 bool operator>(const Node &t)const{return Val<t.Val;}
 Node(long long Val=0,int rt=0,int lst=0,long long lstV=0):Val(Val),rt(rt),lst(lst),lstV(lstV) {}
};

typedef __gnu_pbds::priority_queue<Node,less<Node>,pairing_heap_tag> heap;
heap Q;
int mn[maxn*80],Id[maxn*80],ls[maxn*80],rs[maxn*80],sz;
struct splay_node
{
    int num,maxx,ls,rs,fath;
    bool lazy;
}p[5];


#define M 100001
struct Seg_Tree{
	int left,right;
	int mid() {
		return (left + right) >> 1;
	}
}tt[M*4];
int len;
int sorted[M];
int toLeft[20][M];
int val[20][M];
 
void build(int l,int r,int d,int idx) {
	tt[idx].left = l;
	tt[idx].right = r;
	if(tt[idx].left == tt[idx].right)	return ;
	int mid = tt[idx].mid();
	int lsame = mid - l + 1;//lsame表示和val_mid相等且分到左边的
	for(int i = l ; i <= r ; i ++) {
		if(val[d][i] < sorted[mid]) {
			lsame --;//先假设左边的数(mid - l + 1)个都等于val_mid,然后把实际上小于val_mid的减去
		}
	}
	int lpos = l;
	int rpos = mid+1;
	int same = 0;
	for(int i = l ; i <= r ; i ++) {
		if(i == l) {
			toLeft[d][i] = 0;//toLeft[i]表示[ tt[idx].left , i ]区域里有多少个数分到左边
		} else {
			toLeft[d][i] = toLeft[d][i-1];
		}
		if(val[d][i] < sorted[mid]) {
			toLeft[d][i] ++;
			val[d+1][lpos++] = val[d][i];
		} else if(val[d][i] > sorted[mid]) {
			val[d+1][rpos++] = val[d][i];
		} else {
			if(same < lsame) {//有lsame的数是分到左边的
				same ++;
				toLeft[d][i] ++;
				val[d+1][lpos++] = val[d][i];
			} else {
				val[d+1][rpos++] = val[d][i];
			}
		}
	}
	build(l,mid,d+1,(idx));
	build(mid+1,r,d+1,(idx));
}
int Query(int l,int r,int k,int d,int idx) {
	if(l == r) {
		return val[d][l];
	}
	int s;//s表示[ l , r ]有多少个分到左边
	int ss;//ss表示 [tt[idx].left , l-1 ]有多少个分到左边
	if(l == tt[idx].left) {
		s = toLeft[d][r];
		ss = 0;
	} else {
		s = toLeft[d][r] - toLeft[d][l-1];
		ss = toLeft[d][l-1];
	}
	if(s >= k) {//有多于k个分到左边,显然去左儿子区间找第k个
		int newl = tt[idx].left + ss;
		int newr = tt[idx].left + ss + s - 1;//计算出新的映射区间
		return Query(newl,newr,k,d+1,(idx));
	} else {
		int mid = tt[idx].mid();
		int bb = l - tt[idx].left - ss;//bb表示 [tt[idx].left , l-1 ]有多少个分到右边
		int b = r - l + 1 - s;//b表示 [l , r]有多少个分到右边
		int newl = mid + bb + 1;
		int newr = mid + bb + b;
		return Query(newl,newr,k-s,d+1,(idx));
	}
}
struct lct
{
    inline void _pushdown(int i)
    {
        p[i].lazy^=1;
        p[p[i].ls].lazy^=1;
        p[p[i].rs].lazy^=1;
        int t=p[i].ls;p[i].ls=p[i].rs;p[i].rs=t;
    }
    inline void _pushup(int i)
    {
        p[i].maxx=max(max(p[p[i].ls].maxx,p[p[i].rs].maxx),p[i].num);
    }
    inline void _zig(int i)
    {
        int j=p[i].fath,k;
        k=p[j].fath;
        if(k!=0&&j==p[k].ls)p[k].ls=i;
        else if(k!=0)p[k].rs=i;
        p[i].fath=k;
        p[j].fath=i;
        p[p[i].rs].fath=j;
        p[j].ls=p[i].rs;
        p[i].rs=j;
        anc[i]=anc[j];
        p[i].maxx=p[j].maxx;
        _pushup(j);
    }
    inline void _zag(int i)
    {
        int j=p[i].fath,k;
        k=p[j].fath;
        if(k!=0&&j==p[k].ls)p[k].ls=i;
        else if(k!=0)p[k].rs=i;
        p[i].fath=k;
        p[j].fath=i;
        p[p[i].ls].fath=j;
        p[j].rs=p[i].ls;
        p[i].ls=j;
        anc[i]=anc[j];
        p[i].maxx=p[j].maxx;
        _pushup(j);
    }
    void _splay(int i)
    {
        int j;
        while(p[i].fath!=0)
        {
            j=p[i].fath;
            if(p[p[j].fath].lazy==true)_pushdown(p[j].fath);
            if(p[j].lazy==true)_pushdown(j);
            if(p[i].lazy==true)_pushdown(i);
            if(p[j].fath==0)
            {
                if(i==p[j].ls)_zig(i);
                else _zag(i);
            }
            else if(j==p[p[j].fath].ls)
            {
                if(i==p[j].ls)_zig(j),_zig(i);
                else _zag(i),_zig(i);
            }
            else
            {
                if(i==p[j].rs)_zag(j),_zag(i);
                else _zig(i),_zag(i);
            }
        }
    }
    int _find_max(int i)
    {
        while(i!=0)
        {
            if(p[i].lazy==true)_pushdown(i);
            if(p[i].ls!=0&&p[i].maxx==p[p[i].ls].maxx)i=p[i].ls;
            else if(p[i].maxx==p[i].num)return i;
            else i=p[i].rs;
        }
        return i;
    }
    void _access(int i)
    {
        int j=0;
        while(i!=0)
        {
            _splay(i);
            if(p[i].lazy==true)_pushdown(i);
            if(p[i].rs!=0)
            {
                p[p[i].rs].fath=0;
                anc[p[i].rs]=i;
            }
            p[i].rs=j;
            p[j].fath=i;
            _pushup(i);
            j=i;i=anc[i];
        }
    }
    void _setroot(int i)
    {
        _access(i);
        _splay(i);
        p[i].lazy^=1;
    }
}T;
void update(int x,int &y,int l,int r,int k,int V,int id){
 y=++sz;ls[y]=ls[x];rs[y]=rs[x];
 if(l==r){
  mn[y]=V;Id[y]=id;return;
 }
 int M=l+r>>1;
 if(k<=M)update(ls[x],ls[y],l,M,k,V,id);else update(rs[x],rs[y],M+1,r,k,V,id);
 mn[y]=min(mn[ls[y]],mn[rs[y]]);
}

pii query(int x,int l,int r){
 if(l==r)return make_pair(l,Id[x]);
 int M=l+r>>1;
 if(mn[ls[x]]==mn[x])return query(ls[x],l,M);else return query(rs[x],M+1,r);
}

void Work(){
 for(int i=1;i<=n;i++){
  now+=P[i][1];
  update(rt,rt,1,n,i,P[i][2]-P[i][1],1);
 }
 Q.push(Node(now,rt,0,0));
 while(k--){
  long long ans=Q.top().Val;
  int rt=Q.top().rt,lst=Q.top().lst,nr,lstV=Q.top().lstV;
  Q.pop();
  Ans+=ans;//cout<<ans<<endl;
  if(lst){
   update(rt,nr,1,n,lst,MAX,num[lst]);
   pii tmp=query(nr,1,n);
   int x,y;
   x=tmp.first,y=tmp.second;
   update(nr,nr,1,n,x,P[x][y+2]-P[x][y+1],y+1);
   Q.push(Node(ans-lstV+P[x][y+1]-P[x][y],nr,x,P[x][y+1]-P[x][y]));
  }
  
  pii tmp=query(rt,1,n);
  int x=tmp.first,y=tmp.second;
  update(rt,rt,1,n,x,P[x][y+2]-P[x][y+1],y+1);
  Q.push(Node(ans+P[x][y+1]-P[x][y],rt,x,P[x][y+1]-P[x][y]));
 }
 cout<<Ans<<endl;
}

void Init(){
 scanf("%d%d",&n,&k);
 for(int i=1;i<=n;i++){
  scanf("%d",&num[i]);
  for(int j=1;j<=num[i];j++)scanf("%d",&P[i][j]);
  sort(P[i]+1,P[i]+num[i]+1);
  P[i][num[i]+1]=MAX;
 }
 mn[0]=MAX;
}

int main(){
 freopen("roboherd.in","r",stdin);
 freopen("roboherd.out","w",stdout);
 Init();
 Work();
 return 0;
}
