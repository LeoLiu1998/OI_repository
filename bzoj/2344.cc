#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int n,m;

bool use[210][210];

int main()
{

	scanf("%d%d",&n,&m);
	for (int a=1;a<=m;a++)
	{
		int s,e;
		scanf("%d%d",&s,&e);
		use[s][e]=use[e][s]=true;
	}
	int ans=0;
	for (int a=1;a<=n;a++)
		for (int b=a+1;b<=n;b++)
			if (!use[a][b])
				for (int c=b+1;c<=n;c++)
					if (!use[a][c] && !use[b][c]) ans++;
	printf("%d\n",ans);

	return 0;
}

