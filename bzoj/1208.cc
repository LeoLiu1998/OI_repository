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
set<int> pet,people;
int n;
int ans=0;
int qd,hd;
set<int>::iterator itr;
void SolvePet(int k) {
	if(people.size()) {
		itr=people.lower_bound(k);
		if(itr!=people.begin()){
			itr--;
			qd=abs(k-*itr);
			itr++;
			hd=abs(k-*itr);
			if(qd<=hd) itr--;
		}
		ans+=abs(*itr-k);
		ans%=1000000;
		people.erase(*itr);
	} else {
		pet.insert(k);
	}
}
void SolvePeo(int k) {
	if(pet.size()) {
		itr=pet.lower_bound(k);
		if(itr!=pet.begin()){
			itr--;
			qd=abs(k-*itr);
			itr++;
			hd=abs(k-*itr);
			if(qd<=hd) itr--;
		}
		ans+=abs(*itr-k);
		ans%=1000000;
		pet.erase(*itr);
	} else {
		people.insert(k);
	}
}
int main() {
	R(n);
	register int cmd=-1,v;
	while(n--) {
		R(cmd); R(v);
		if(cmd==0) {
			SolvePet(v);
		} else {
			SolvePeo(v);
		}
	}
	Pn(ans);
}
