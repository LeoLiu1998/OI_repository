#include<cstdio>
#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
vector <int> a;
int main()
{
	freopen("in.txt","r",stdin);
	int n;
	cin>>n;
	int temp;
	int ans=0;
	while(cin>>temp)
	a.push_back(temp);
	for(int i=0;i<a.size();i++)
	{
		if(i==0) 
		{
		ans+=a[i];
		continue;
		}
		else
		{
			ans+=abs(a[i]-a[0]);
		}
	}
	cout<<ans;
}
