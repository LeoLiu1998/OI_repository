/**************************************************************
    Problem: 1666
    User: yeguanghao
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1272 kb
****************************************************************/
 
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
int n;
int main()
{
    int cnt=0;
    cin>>n;
    while(n-1){
        if(n%2){
            n*=3;
            ++n;
        } else {
            n>>=1;
        }
        cnt++;
    }
    cout<<cnt<<endl;
}
