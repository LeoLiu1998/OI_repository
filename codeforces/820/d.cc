#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;
int n;
const int maxn=1000010;
int a[maxn];
struct yjq{
 int p,t;
 bool operator < (const yjq &an) const {
  if (t!=an.t)
   return t>an.t;
  else
   return p<an.p;
 }
} tmp;
priority_queue<yjq> st;
int add;
int decr;
LL ans;
LL res;

int main()
{
 scanf("%d",&n);
 for (int i=1; i<=n; i++){
  scanf("%d",a+i);
  ans+=max(a[i]-i,i-a[i]);
  if (a[i]<=i) add++;
  else {
   decr++;
   tmp.p=a[i];
   tmp.t=a[i]-i;
//   printf("%d %d ins\n",a[i],a[i]-i);
   st.push(tmp);
  }
 }
 res=ans;
 int t=0;
 int num=0;
// cout<<"!!"<<ans<<endl;
 for (int i=n; i>1; i--){
//  printf("- %d %d\n",add,decr);
//  printf("=== %d\n",st.top().t);
  while ((!st.empty())&&st.top().t==t){
   decr--;
   add++;
   st.pop();
  }
//  printf("-- %d %d\n",add,decr);
  tmp.t=a[i]+t;
  tmp.p=a[i];
  st.push(tmp);
  add--;
  decr++;
  ans+=a[i]-1-(n-a[i])+add-decr+1;
  
  t++;
  if (ans<res){
   res=ans;
   num=t;
  }
// cout<<"ans "<<ans<<" "<<t<<endl;
 }
 cout<<res<<" "<<num<<endl;
 
 return 0;
}