#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
const int N=200001;
char *cp=(char *)malloc(6000000);
struct circle {
    int x,y,r; 
    circle(int x=0,int y=0,int r=0)
        :x(x),y(y),r(r){}
} c[N];
struct point {
    int p,x,k;
    point(int p=0,int x=0,int k=0)
        :p(p),x(x),k(k){}
} p[N<<1];
struct height {
    int p,k;
    height(int p=0,int k=0)
        :p(p),k(k){}
};
int n,tot,tmp,k[N];
set<height> s;
long long ans;
inline void in (int &x) {
    int f=1; 
    for (;*cp<'0'||*cp>'9';cp++)
        if (*cp=='-') f=-1;
    for (x=0;*cp>='0'&&*cp<='9';cp++)
        x=x*10+*cp-48; 
    x*=f;
}
inline bool cmp(point a,point b){
    return a.x<b.x;
}
inline long long cal(long long x){
    return x*x;
}
inline long long mul(long long x,long long y){
     return x*y;
}
bool operator < (const height a,const height b){
    double x=(double)c[a.p].y+(double)a.k*sqrt(cal(c[a.p].r)-cal(tmp-c[a.p].x));
    double y=(double)c[b.p].y+(double)b.k*sqrt(cal(c[b.p].r)-cal(tmp-c[b.p].x));
    return x!=y?x<y:a.k<b.k;
}
int main() {
//  freopen("circle.in","r",stdin); 
//  freopen("circle.out","w",stdout);
    fread(cp,1,6000000,stdin);
    in(n); int x,y,z; 
    for (int i=1;i<=n;i++) {
        in(x),in(y),in(z); 
        c[i]=circle(x,y,z); 
        p[++tot]=point(i,x-z,1); 
        p[++tot]=point(i,x+z,-1); 
    }
    sort(p+1,p+1+tot,cmp);
    for (int i=1;i<=tot;i++) {
        tmp=p[i].x;
        if (p[i].k==1) {
            set<height>:: iterator it;
            it=s.upper_bound(height(p[i].p,1));
            if (it==s.end())
                k[p[i].p]=1;
            else 
                if (it->k==1)
                    k[p[i].p]=k[it->p]*(-1);
                else
                    k[p[i].p]=k[it->p];
            s.insert(height(p[i].p,1)); 
            s.insert(height(p[i].p,-1)); 
        }else {
            s.erase(height(p[i].p,1)); 
            s.erase(height(p[i].p,-1)); 
        }
    }
    for (int i=1;i<=n;i++)  
        ans=ans+mul(k[i],cal(c[i].r)); 
    printf("%lld\n",ans);
    return 0; 
}
