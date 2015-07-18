//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d\n",x)
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int main()
{
          int n,k;
          int i;
          while(~scanf("%d",&n)){
                  if(n%6!= 2){
                          if(n&1){
                                  for(i=2;i<=n-1;i+=2){
                                          printf("%d\n",i);
                                  }
                                  for(i=1;i<=n;i+=2){
                                          printf("%d\n",i);
                                  }
                          }
                          else{
                                  for(i=2;i<=n;i+=2){
                                          printf("%d\n",i);
                                  }
                                  for(i=1;i<=n-1;i+=2){
                                          printf("%d\n",i);
                                  }
                          }
                  }
                  else{
                          k=n/2;
                          if(k&1){
                                  for(i=k;i<=n-1;i+=2){
                                          printf("%d\n",i);
                                  }
                                  for(i=1;i<=k-1;i+=2){
                                          printf("%d\n",i);
                                  }
                                  for(i=k+3;i<=n;i+=2){
                                          printf("%d\n",i);
                                  }
                                  for(i=2;i<=k+1;i+=2){
                                          printf("%d\n",i);
                                  }
                          }
                          else{
                                  for(i=k;i<=n;i+=2){
                                          printf("%d\n",i);
                                  }
                                  for(i=2;i<=k-2;i+=2){
                                          printf("%d\n",i);
                                  }
                                  for(i=k+3;i<=n-1;i+=2){
                                          printf("%d\n",i);
                                  }
                                  for(i=1;i<=k+1;i+=2){
                                          printf("%d\n",i);
                                  }
                          }
                  }
          	
	  }
          return 0;
}
