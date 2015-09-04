#include <iostream>
#include <algorithm>
#include <set>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdlib>
#include<cstdio>
using namespace std;
#define LOCAL
typedef long long ll;
int main()
{
    ll num;
    cin>>num;
    ll arr[100005];
    for(int i=0;i<num;++i)
    {
        cin>>arr[i];
        while(arr[i]%2==0)
            arr[i]/=2;
        while(arr[i]%3==0)
            arr[i]/=3;
    }
    sort(arr,arr+num);
    int flag=1;
    ll tmp=arr[0];
    for(int i=0;i<num;++i)
    {
        if(arr[i]!=tmp)
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}