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
using namespace std;
struct BigInt{
	int num[5010],len;
	
	BigInt(int _ = 0) {
		memset(num,0,sizeof(num));
		num[len = 1] = _;
	}
	BigInt operator *(int a)const {
		BigInt re;
		re.len = len;
		int temp = 0;
		for(int i = 1; i <= len; ++i) {
			re.num[i] = num[i] * a + temp;
			temp = re.num[i] / 10;
			re.num[i] %= 10;
		}
		while(temp)
			re.num[++re.len] = temp % 10,temp /= 10;
		return re;
	}
};

int n;

int main()
{
	cin >> n;
	BigInt ans(1);
	if(n % 3 == 0)
		for(int i = 1; i <= n / 3; ++i)
			ans = ans * 3;
	else if(n % 3 == 1) {
		for(int i = 1; i <= (n - 1) / 3 - 1; ++i)
			ans = ans * 3;
		ans = ans * 4;
	}
	else {
		for(int i = 1; i <= (n - 1) / 3; ++i)
			ans = ans * 3;
		ans = ans * 2;
	}
	cout << ans.len << endl;
	for(int i = ans.len,T = 1; T <= min(100,ans.len); ++T,--i)
		printf("%d",ans.num[i]);
	puts("");
	return 0;
}
