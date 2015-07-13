#include<cstdio>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
const int maxn=1e5+10;
rope<char> *his[maxn];
int n;
int d[maxn];
inline int lowbit(int x){
	return x&-x;
}
inline void updata(int x){
	while(x<=n){
		d[x]++;
		x+=lowbit(x);
	}
}
inline int get(int x){
	int res=0;
	while(x){
		res+=d[x];
		x-=lowbit(x);
	}return res;
}
inline char getC(){
	char ch=getchar();
	while(!isalpha(ch))ch=getchar();
	return ch;
}
inline int getint(){
	int res=0;
	char ch,ok=0;
	while(ch=getchar()){
		if(isdigit(ch)){
			res*=10;res+=ch-'0';ok=1;
		}else if(ok)break;
	}return res;
}
void deb(rope<char> s){
	for(int i=0;i<s.length();i++)
	cout<<s[i];puts("");
}
int main(){
	n=getint();
	his[0]=new rope<char>();
	for(int i=1;i<=n;i++){
		his[i]=new rope<char>(*his[i-1]);
//		deb(*his[i]);
		char opt=getC();
		if(opt=='A'){
			char x=getC();
			his[i]->push_back(x);
			updata(i);
		}else
		if(opt=='U'){
			updata(i);
			int x=getint();
			int l=1,r=i,mid,now=get(i);
			while(l<r){
				mid=(l+r)>>1;
				if(now-get(mid)>x)
					l=mid+1;
				else
					r=mid;
			}
			his[i]=his[l-1];
			
		}else
		if(opt=='Q'){
			int x=getint()-1;
			putchar(his[i]->at(x));
			putchar('\n');	
		}
//		deb(*his[i]);
	}
	return 0;
}
