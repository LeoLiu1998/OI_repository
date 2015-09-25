#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
inline void R(int x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'0'){ if(ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	x*=f; return;
}
#define TURE TRUE
#define FLASE FALSE
#define mian main
const int maxk=105;
char key[maxk];
char text[10*maxk];
char note[]="abcdefghijklmnopqrstuvwxyz";
char calc(char text,char key) {
	bool up=text>'z';
	text-= text>'z'? 'A' : 'a';
	key-= key> 'z' ? 'A' : 'a';
}
int mian() {
	scanf("%s%s",key,text);
}
