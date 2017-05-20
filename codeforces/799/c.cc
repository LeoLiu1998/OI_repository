//This sourcecode is under GPLv3
//http://yeguanghao.xyz
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define PROB
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
void Redirect() {
	freopen(PROB".in","r",stdin);
#ifndef YGHDEBUG
	freopen(PROB".out","w",stdout);
#endif
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int n,c,d;
int nc,nd;
const int maxn=100010;
pii df[maxn];
pii cf[maxn];
pii pdf[maxn];
pii pcf[maxn];
int dfc,cfc;
int Findd(int v) {
	pii q=mp(v,INT_MAX);
	int x=lower_bound(df+1,df+dfc+1,q)-df;
	while(df[x].fi>v) x--;
	return min(dfc,x);
}
int Findc(int v) {
	pii q=mp(c,INT_MAX);
	int x=lower_bound(cf+1,cf+cfc+1,q)-cf;
	while(cf[x].fi>v) x--;
	return min(cfc,x);
}
int main() {
	R(n); R(c); R(d);
	for(int i=1;i<=n;++i) {
		pii temp; R(temp.se); R(temp.fi);
		char ch=0; while(!isalpha(ch)) ch=getchar();
		if(ch=='C') {
			cf[++cfc]=temp;
		} else {
			df[++dfc]=temp;
		}
	}
	sort(df+1,df+dfc+1);
	sort(cf+1,cf+cfc+1);
//	if((cfc>=2&&(cf[1].fi+cf[2].fi<c))&&(dfc>=2&&(df[1].fi+df[2].fi<d))&&(!(df[1].fi<d&&cf[1].fi<c))) {
//		puts("0"); return 0;
//	}
	if(((cfc>=2)&&(cf[1].fi+cf[2].fi<=c))||((dfc>=2)&&(df[1].fi+df[2].fi<=d))) {
		goto NEX;
	}
	if((df[1].fi<=d)&&(cf[1].fi<=c)) {
		goto NEX;
	}
	puts("0"); return 0;	
NEX:	pdf[1]=mp(1,0);
	for(int i=2;i<=dfc;++i) {
		pdf[i]=pdf[i-1];
		if(df[i].se>df[pdf[i].se].se) {
			pdf[i].se=i;
			if(df[pdf[i].se].se>df[pdf[i].fi].se) {
				swap(pdf[i].fi,pdf[i].se);
			}
		}
	}
	pcf[1]=mp(1,0);
	for(int i=2;i<=cfc;++i) {
		pcf[i]=pcf[i-1];
		if(cf[i].se>cf[pcf[i].se].se) {
			pcf[i].se=i;
			if(cf[pcf[i].se].se>cf[pcf[i].fi].se) {
				swap(pcf[i].fi,pcf[i].se);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=dfc;++i) {
		int cur_b=0;
		if(df[i].fi>d) break;
		cur_b=df[i].se;
		//cur_b+=max(Findd(d-df[i].fi),Findc(c));
		int pd=Findd(d-df[i].fi);
		int pdv= (pdf[pd].fi==i) ? df[pdf[pd].se].se : df[pdf[pd].fi].se;
		int pc=Findc(c);
		int pcv=cf[pcf[pc].fi].se;
		cur_b+=max(pdv,pcv);
		ans=max(ans,cur_b);
	}
	for(int i=1;i<=cfc;++i) {
		int cur_b=0;
		if(cf[i].fi>c) break;
		cur_b=cf[i].se;
		int pc=Findc(c-cf[i].fi);
		int pcv=(pcf[pc].fi==i) ? cf[pcf[pc].se].se : cf[pcf[pc].fi].se;
		ans=max(ans,cur_b+pcv);
	}
	Pn(ans);

}

