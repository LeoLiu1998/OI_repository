//Copyright(c)2017 Mstdream
#include<bits/stdc++.h>
using namespace std;
inline void splay(int &v){
 v=0;char c=0;int p=1;
 while(c<'0' || c>'9'){if(c=='-')p=-1;c=getchar();}
 while(c>='0' && c<='9'){v=(v<<3)+(v<<1)+c-'0';c=getchar();}
 v*=p;
}
int a,b,l,r;
int p[1000],x[1000];
int main(){
 //freopen("xxx.in","r",stdin);
 cin>>a>>b>>l>>r;
 int t=(a+b)*2;
 int x_=l/t*t;
 l-=x_,r-=x_;
 if(r>t*4){
  int p=r%t;
  r=p+3*t;
 }
 for(int i=1;i<=a;i++)x[i]=i;
 for(int i=a+1;i<=a+b;i++)x[i]=a;
 for(int i=b+1;i<=a+b;i++)p[x[i]]=1;
 int now=1;
 for(int i=a+b+1;i<=a+a+b;i++){
  while(p[now])now++;
  x[i]=now;
  p[now]=1;
 }
 for(int i=a+a+b+1;i<=a+a+b+b;i++)x[i]=x[a+a+b];
 for(int i=1;i<=t;i++){
  x[i+t]=x[i+t+t]=x[i+t+t+t]=x[i];
 }
 memset(p,0,sizeof p);
 int ans=0;
 for(int i=l;i<=r;i++){
  p[x[i]]=1;
 }
 for(int i=1;i<=26;i++)if(p[i])ans++;
 cout<<ans<<endl;
}
