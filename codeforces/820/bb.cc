//Copyright(c)2017 Mstdream
#include<bits/stdc++.h>
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
 double hahaha;
 cin>>n>>a;
 r=1,t=2;
 p1.x=1,p1.y=0,p2.x=0,p2.y=0;
 hahaha=1.0/n*pi;
 if(t-r>n/2)hahaha+=3*pi/2;
 else hahaha-=pi/2;
 p3.x=(p1.x+p2.x)/2;
 p3.y=(p1.y+p2.y)/2;
 p4.x=p3.x-(p3.y-p1.y)*tan(hahaha);
 p4.y=p3.y+(p3.x-p1.x)*tan(hahaha);
 r--;t--;
 m1[r]=p1;
 hahaha=2.0/n*pi;
 for(int i=r+1;;i++){
  if(i%n==r)break;
  m1[i%n].x=p4.x+(m1[(i-1+n)%n].x-p4.x)*cos(-hahaha)-(m1[(i-1+n)%n].y-p4.y)*sin(-hahaha);
  m1[i%n].y=p4.y+(m1[(i-1+n)%n].x-p4.x)*sin(-hahaha)+(m1[(i-1+n)%n].y-p4.y)*cos(-hahaha);
 }
 for(int i=0;i<n;i++){
  x[i+1]=check(m1[i].x);
  y[i+1]=check(m1[i].y);
 }
 double ans=1e18;
 for(int i=n;i>=3;i--){
  int l=2,r=i-1;
  while(l!=r){
   int mid=l+r>>1;
   if(an(1,i,mid)<a)l=mid+1;
   else r=mid;
  }
  if(fabs(an(1,i,l)-a)<ans){
   ans=fabs(an(1,i,l)-a);
   ans1=1,ans2=i,ans3=l;
  }
 }
 printf("%d %d %d",ans1,ans2,ans3);
}
