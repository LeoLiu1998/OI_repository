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
char abc[]="zabcdefghijklmnopqrstuvwxy";
char ABC[]="ZABCDEFGHIJKLMNOPQRSTUVWXY";
const int maxn=10000;
char pri[maxn];
char ans[maxn];
vector<string> high_fre;
struct Word{
	string text;
	int pos;
	Word(string _a="",int _pos=0):text(_a),pos(_pos){}
};
int len=0;
vector<Word> words;
pair<int,int> ansk;
#define mp make_pair
#define rank first
#define pb push_back
#define pk second
void init();
void convert();
int getrank(int);
void getans();
int main() {
	init();
	int T=10;
	while(T--) {
		ansk=mp(-1,-1);
		memset(pri,0,sizeof(pri));
		memset(ans,0,sizeof(ans));
		words.clear();
		cin.getline(pri,maxn);
//		cout<<T<<" "<<pri<<endl;
		len=strlen(pri);
		pri[len]='\n';
		convert();
	//	for(int i=0;i<words.size();++i) {
	//		cout<<words[i].text<<endl;
	//	}
//		cout<<pri;
		rep(i,0,25,1){
			ansk=max(ansk,mp(getrank(i),i));	
		}
//		cout<<pri;
		getans();
//		if(!T){
//			pri[len]=0;
//		}
		cout<<pri;
	}
}
char cur[maxn];
int cur_start;
int cur_len;
string temp;
void convert() {
	for(int i=0;i<=len;++i) {
		if(cur_len!=0&&(!(isalpha(pri[i])||pri[i]=='\''))){
			temp=cur;
			words.pb(Word(cur,cur_start));
			memset(cur,0,sizeof(cur));
			cur_len=0;
			continue;
		} else if(!isalpha(pri[i])) {
			continue;
		} else {
			if(cur_len==0)
				cur_start=i;
			cur[cur_len]=pri[i];
			cur_len++;
		}
	}
}
char aeiou[]=" aeiou";
string rot(string str,int k) {
	for(int i=0;i<str.size();++i) {
		char ch=str[i];
		if(isalpha(ch)) {
			if(isupper(ch)) {
				ch=ch-'A'+1;
			} else if (islower(ch)){
				ch=ch-'a'+1;
			}
			ch+=k;
			ch%=26;
			str[i]=abc[ch];
		}
	}
	return str;
}
int getrank(string str,int k) {
	str=rot(str,k);
	for(int i=0;i<high_fre.size();++i) {
		if(str==high_fre[i]){
			return 150;
		}
	}
	for(int i=0;i<str.size();++i) {
		char ch=str[i];
		for(int j=1;j<=5;++j) {
			if(ch==aeiou[j])
				return 3;
		}
	}
	return 0;
}
void getans() {
	int k=ansk.pk;
	for(int i=0;i<len;++i) {
		if(isalpha(pri[i])) {
			char ch=pri[i];
			if(isupper(ch)){
				ch=ch-'A'+1;
				ch+=k;
				ch%=26;
				ch=ABC[ch];
			} else {
				ch=ch-'a'+1;
				ch+=k;
				ch%=26;
				ch=abc[ch];
			}
			pri[i]=ch;
		}
	}
}
int getrank(int k) {
	int sum=0;
	for(int i=0;i<words.size();++i) {
		sum+=getrank(words[i].text,k);
	}
	return sum;
}
void init(){
high_fre.pb("me");
high_fre.pb("good");
high_fre.pb("madam");//FUCK 10!
high_fre.push_back("the");
high_fre.push_back("of");
high_fre.push_back("and");
high_fre.push_back("to");
high_fre.push_back("in");
high_fre.push_back("that");
high_fre.push_back("it");
high_fre.push_back("is");
high_fre.push_back("was");
high_fre.push_back("for");
high_fre.push_back("on");
high_fre.push_back("you");
high_fre.push_back("he");
high_fre.push_back("be");
high_fre.push_back("with");
high_fre.push_back("as");
high_fre.push_back("by");
high_fre.push_back("at");
high_fre.push_back("have");
high_fre.push_back("are");
high_fre.push_back("this");
high_fre.push_back("not");
high_fre.push_back("but");
high_fre.push_back("had");
high_fre.push_back("his");
high_fre.push_back("they");
high_fre.push_back("from");
high_fre.push_back("she");
high_fre.push_back("which");
high_fre.push_back("or");
high_fre.push_back("we");
high_fre.push_back("an");
high_fre.push_back("there");
high_fre.push_back("her");
high_fre.push_back("were");
high_fre.push_back("one");
high_fre.push_back("do");
high_fre.push_back("been");
high_fre.push_back("all");
high_fre.push_back("their");
high_fre.push_back("has");
high_fre.push_back("would");
high_fre.push_back("will");
high_fre.push_back("what");
high_fre.push_back("if");
high_fre.push_back("can");
high_fre.push_back("when");
high_fre.push_back("so");
high_fre.push_back("no");
high_fre.push_back("said");
high_fre.push_back("who");
high_fre.push_back("more");
high_fre.push_back("about");
high_fre.push_back("up");
high_fre.push_back("them");
high_fre.push_back("some");
}
