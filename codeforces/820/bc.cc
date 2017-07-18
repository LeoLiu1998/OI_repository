}*///Copyright(c)2017 Mstdream
#include<bits/stdc++.h>
int anc[5];
struct splay_node
{
    int num,maxx,ls,rs,fath;
    bool lazy;
}p[5];
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
struct cp{
	double x,y;
	  cp(){}
	  cp(double x,double y):x(x),y(y){}
	  cp operator+(const cp&b){return cp(x+b.x,y+b.y);}
	  cp operator-(const cp&b){return cp(x-b.x,y-b.y);}
	  cp operator*(const cp&b){return cp(x*b.x-y*b.y,x*b.y+y*b.x);}
};

/*template<class K> inline void read(K& x){
  char c = getchar_unlocked();
  for(x = 0;c > '9' || c < '0'; c = getchar_unlocked());
  for(;c >= '0' && c <= '9'; c = getchar_unlocked()) x = x * 10 + c - '0';
}

template<class K> inline void write(K x){
  static char c[20]; int top = 0;
  do { c[++top] = x % 10 + '0'; x /= 10; }while(x);
  while(top) putchar_unlocked(c[top--]);
  putchar_unlocked('\n');
*/
using namespace std;
inline void splay(int &v){
 v=0;char c=0;int p=1;
 while(c<'0' || c>'9'){if(c=='-')p=-1;c=getchar();}
 while(c>='0' && c<='9'){v=(v<<3)+(v<<1)+c-'0';c=getchar();}
 v*=p;
}
#define pi acos(-1.0)
#define eps 1e-8
const int N=100010;
int n,r,t;
double a;
struct Point{
    double x,y;
}p[N],p1,p2,p3,p4;
Point m1[N];
double check(double a){
    return fabs(a)<eps?0:a;
}
double x[N],y[N];
int ans1,ans2,ans3;
double dis(int a,int b){
 return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}
double an(int a,int b,int c){
 double A=dis(b,c);
 double B=dis(a,c);
 double C=dis(a,b); 
 double cosb=(A*A+C*C-B*B)/(2*A*C);
 return acos(cosb)*180/pi;
}
int main(){
 double yjq;
 cin>>n>>a;
 r=1,t=2;
 p1.x=1,p1.y=0,p2.x=0,p2.y=0;
 yjq=1.0/n*pi;
 if(t-r>n/2)yjq+=3*pi/2;
 else yjq-=pi/2;
 p3.x=(p1.x+p2.x)/2;
 p3.y=(p1.y+p2.y)/2;
 p4.x=p3.x-(p3.y-p1.y)*tan(yjq);
 p4.y=p3.y+(p3.x-p1.x)*tan(yjq);
 r--;t--;
 m1[r]=p1;
 yjq=2.0/n*pi;
 for(int i=r+1;;i++){
  if(i%n==r)break;
  m1[i%n].x=p4.x+(m1[(i-1+n)%n].x-p4.x)*cos(-yjq)-(m1[(i-1+n)%n].y-p4.y)*sin(-yjq);
  m1[i%n].y=p4.y+(m1[(i-1+n)%n].x-p4.x)*sin(-yjq)+(m1[(i-1+n)%n].y-p4.y)*cos(-yjq);
 }
 for(int i=0;i<n;i++){
  x[i+1]=check(m1[i].x);
  y[i+1]=check(m1[i].y);
 }
 double ans=1e18;
 for(int i=n;i>=3;i--){
  int l=2,r=i-1;
  while(l!=r){
   int whx=l+r>>1;
   if(an(1,i,whx)<a)l=whx+1;
   else r=whx;
  }
  if(fabs(an(1,i,l)-a)<ans){
   ans=fabs(an(1,i,l)-a);
   ans1=1,ans2=i,ans3=l;
  }
 }
 printf("%d %d %d",ans1,ans2,ans3);
}
