/**************************************************************
    Problem: 1755
    User: yeguanghao
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1272 kb
****************************************************************/
 
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;
int main()
{
    double rat,mon,years;
    cin>>rat>>mon>>years;
    rat/=100.0;
    while(years--) mon*=(1.0+rat);
    int ans=floor(mon);
    cout<<ans;
}
