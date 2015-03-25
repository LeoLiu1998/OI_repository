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
double aim;
int main()
{
    while(cin>>aim)
	{
		if(aim==0)	break;
        int ans=2;
        while (aim>0)
        {
        	aim-=1.0/ans;
        	ans++;
        }
        ans--;
        cout<<ans-1<<" card(s)"<<endl;
	}
	return 0;
}
