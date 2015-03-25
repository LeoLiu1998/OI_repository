//Copyright (c)2014 Ye Guanghao
//This sourcecode is licensed under GPLv3
#include<iostream>
#include<cstdio>
#include<iomanip>
#include<climits>
#include<cmath>
#include<set>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<map>
using namespace std;
vector <string> a;
int main()
{
    int n,length;
    cin>>n>>length;
    for (int i=1;i<=n ;i++ )
    {
		string temp;
		cin>>temp;
		a.push_back(temp);
    }
    sort(a.begin(),a.end());
    for (int i=n-1;i>=0 ;i++ )
    {
		cout<<a[i]<<endl;
    }
	return 0;
}
