#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
int n,h[80005];
struct qq
{
        int id,v;
}q[80005];
int main()
{
    scanf("%d",&n);
        for (int i=n;i>=1;i--)
                scanf("%d",&h[i]);
        long long ans=0;
        int r=1;
        q[1].v=h[1],q[1].id=1;
        q[0].id=0;
        for (int i=2;i<=n;i++)
        {
                while (r>=1&&q[r].v<h[i])
                        r--;
                ans=ans+i-(q[r].id+1);
                while (r>=1&&q[r].v==h[i])
                        r--;
                q[++r].id=i,q[r].v=h[i];
        }
        cout<<ans<<endl;
        return 0;
}
