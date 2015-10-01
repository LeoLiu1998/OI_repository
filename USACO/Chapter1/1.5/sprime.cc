/*ID: yeguang2
PROG: sprime
LANG: C++
*/
//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
inline void R(int &x) {
    x=0; int f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    x*=f;
}
set<int> ans;
bool is_prime(int k) {
    for(int i=2;i*i<=k;++i) {
        if(k%i==0) return 0;
    } 
    return 1;
}
int n;
int p[11];
void dfs(int dn,int cur) {
    if(!is_prime(cur)) return ;
    if(dn==n) {
        ans.insert(cur);
        return ;
    }
    for(int i=1;i<=9;++i) {
        dfs(dn+1,cur*10+i); 
    }
}

int main() {
    freopen("sprime.in","r",stdin);
    freopen("sprime.out","w",stdout);
    R(n);
    p[0]=1;
    rep(i,1,9,1)  {
        p[i]=10*p[i-1];
    }
    rep(i,2,9,1) {
        dfs(1,i);
    }
    for(set<int>::iterator it=ans.begin();it!=ans.end();++it) {
        Pn(*it);
    }
}
