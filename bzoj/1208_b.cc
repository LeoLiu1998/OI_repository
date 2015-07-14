 #include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
#define rep(i,l,r) for (int i=l; i<=r; i++)
#define drep(i,r,l) for (int i=r; i>=l; i--)
#define mod 1000000
#define oo 2147483647
int n,ans,now;
set<int>bst;
int main()
{   
 //   freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    scanf("%d",&n);
    bst.insert(oo);
    bst.insert(-oo);
    rep(i,1,n)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if (bst.size()==2)
        {
            now=x;
            bst.insert(y);
        }
        else if (now!=x)
        {
            int l=* --bst.lower_bound(y),r=* bst.lower_bound(y);
            if (abs(l-y) <= abs(y-r) && l>-oo) ans=(ans+abs(l-y))%mod,bst.erase(l);
            else ans=(ans+abs(y-r))%mod,bst.erase(r);
        }
        else if (now==x) bst.insert(y);
    }
    printf("%d\n",ans);
//  fclose(stdin); fclose(stdout);
    return 0;
}