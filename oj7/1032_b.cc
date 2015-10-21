#include<cstdio>
#include<algorithm>
#define INF 2147483647
using namespace std;

struct Q{
	int l,r;	
	bool operator< (Q c)const{
		return l<c.l;	
	}
};

Q d[10001];

int main(){
//	freopen("plot.in","r",stdin);
//	freopen("plot.out","w",stdout);
	int n;
	scanf("%d",&n);
	for (int i=0;	i<n;	i++)	scanf("%d%d",&d[i].l,&d[i].r);	
	d[n].l=INF;	d[n].r=0;
	n++;
	sort(d,d+n);
	int last=0;
	int ans=INF;
	for (int i=0;	i<n;	i++){
		if (d[i].l>last)	ans-=d[i].l-last;
		last=max(last,d[i].r);	
	}
	printf("%d",ans);
}
