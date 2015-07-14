#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;

#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}

#include<ext/rope>
using namespace __gnu_cxx;
int n,now,len;
rope <char> a,b,tmp;
char s[2000000],rs[2000000];
int main()
{
	R(n);
	int x;
	while(n--)
	{
		scanf("%s",s);
		switch(s[0])
		{
		case 'M':R(now);break;
		case 'P':now--;break;
		case 'N':now++;break;
		case 'G':printf("%c\n",a[now]);break;
		case 'I':
		{
			R(x);len=a.length();
			for(int i=0;i<x;i++)
			{
				s[i]=getchar();
				while(s[i]=='\n')
					s[i]=getchar();
				rs[x-i-1]=s[i];
			}
			rs[x]=s[x]=0;
			a.insert(now,s);
			b.insert(len-now,rs);
			break;
		}
		case 'D':
		{
			R(x);len=a.length();
			a.erase(now,x);
			b.erase(len-now-x,x);
			break;
		}
		case 'R':
		{
			R(x);len=a.length();
			tmp=a.substr(now,x);
			a=a.substr(0,now)+b.substr(len-now-x,x)+a.substr(now+x,len-now-x);
			b=b.substr(0,len-now-x)+tmp+b.substr(len-now,now);
			break;
		}
		}
	}
	return 0;
}
