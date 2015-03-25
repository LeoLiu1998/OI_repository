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
int main()
{
	int a;
	cin>>a;
    int n=1;
    double x,y;
    while (cin>>x>>y)
    {
        double time=(x*x+y*y)/50.0*3.1415926*0.5;
        if(time-floor(time)>0.0000001)	time++;
        cout<<"Property "<<n<<": This property will begin eroding in year "<<floor(time)<<".\n";
		n++;
    }
    cout<<"END OF OUTPUT.";
	return 0;
}
