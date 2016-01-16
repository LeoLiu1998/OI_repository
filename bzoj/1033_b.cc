//This sourcecode is under GPLv3
//yeguanghao
#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define x first
#define y second
int n,m,s,t;
typedef pii Fort;
int damage,range;
Fort fort[25];
int info[10][10];
bool vis[10][10];
struct Ant {
	pii pos;
	int life;
	bool cake;
	int t;
};
bool cake_remain=1;
int cnt=0;
vector <Ant> ant;
int level_life[40000];
void Solve(int);
void Print_End(int);
int main() {
	level_life[1]=4;
	R(n); R(m); R(s); swap(n,m); R(damage); R(range); 
	for(int i=1;i<=s;++i) {
		int a,b; R(a); R(b); swap(a,b);
		fort[i]=mp(a,b);
	}
	R(t); 
	for(int i=1;i<=t;++i) {
		Solve(i);
	}
	printf("The game is going on\n");
	Print_End(t);
}
double last_life=1.1;
int last_level=1;
void Gen_Ant() {
	if(ant.size()>=6) return ;
	Ant smg; cnt++; smg.pos=mp(0,0); smg.cake=0;
	vis[0][0]=1;
	smg.t=cnt;
	int level= (cnt-1)/6 +1;
	if(level==last_level) {
		smg.life=floor(4*last_life);
	} else {
		last_level++;
		last_life*=1.1;
		smg.life=floor(4*last_life);
		level_life[last_level]=floor(4*last_life);
	}
	ant.push_back(smg);
}
void Leave_Info() {
	for(size_t i=0;i<ant.size();++i) {
		info[ant[i].pos.fi][ant[i].pos.se] +=(ant[i].cake? 5:2);
	}
}
int target;
int mov[4][4]={{1,0},{0,-1},{0,1},{0,1}};
pii mov_choose; // 0 is left , 1 is up,2 right,3dowb
int ma;
pii add_pos(pii a,int k) {
	pii ret;
	ret.x=a.x+mov[k][0];
	ret.y=a.y+mov[k][1];
	return ret;
}

bool check(pii pos) {
	if(pos.x<0||pos.x>n) return 0;
	if(pos.y<0||pos.y>m) return 0;
	return (!vis[pos.x][pos.y]);
}
void Move(int k) {
	ma=-182332424;
	pii pos=ant[k].pos;
	for(int i=0;i<4;++i) {
		pii next_pos=add_pos(pos,i);	
		if(!check(next_pos)) continue;
		if(info[next_pos.x][next_pos.y]>ma) {
			ma=info[next_pos.x][next_pos.y];
			mov_choose=next_pos;
		}
	}
	vis[pos.x][pos.y]=0;
	vis[mov_choose.x][mov_choose.y]=1;
	ant[k].pos=mov_choose;
	if(ant[k].pos==mp(n,m)&&cake_remain) {
		ant[k].cake=1; cake_remain=0;
		ant[k].life+= level_life[ (ant[k].t-1)/6 +1] >> 1;
		target=k;
	}
}

void Turn_Move(int k) {
	ma=-1; pii pos=ant[k].pos; int direction=0;
	pii next_pos;
	for(int i=0;i<4;++i) {
		next_pos=add_pos(pos,i);
		if(!check(next_pos)) continue;
		if(info[next_pos.x][next_pos.y]>ma) {
			direction=i;
			ma=info[next_pos.x][next_pos.y];
		}
	}
	direction--;
	for(;;direction--) {
		if(direction< 0) direction +=4;
		next_pos= add_pos(pos,direction);
		if(check(next_pos)) break;
	}
	vis[pos.x][pos.y]=0;
	ant[k].pos=next_pos;
	vis[next_pos.x][next_pos.y]=1;
	if(ant[k].pos==mp(n,m)&&cake_remain) {
		ant[k].cake=1; cake_remain=0;
		ant[k].life+= level_life[ (ant[k].t-1)/6 +1] >> 1;
		target=k;
	}
} 

void Ant_Move(int k) {
	for(size_t i=0;i<ant.size();++i) {
		if((k-ant[i].t+1)%5==0) 
			Turn_Move(i);
		else Move(i);
	}
}
double Dist(int i,int j) {
	return hypot(fort[i].x-ant[j].pos.x,fort[i].y-ant[j].pos.y);
}
void Attack(int k) {
	double dis=HUGE_VAL,near;
	for(size_t i=0;i<ant.size();++i) {
		if(Dist(k,i)<dis) {
			dis=Dist(k,i);
			near=i;
		}
	}
	if(Dist(k,near)<= range) {
		ant[near].life-=damage;
	}
	return ; 
}

void Remove(int k) {
	vis[ant[k].pos.x][ant[k].pos.y]=0;
	ant.erase(ant.begin()+k);
	if((!cake_remain)&&target>k) target--;
}
vector<Ant> temp;
bool check_Ant(int k) {
	if(ant[k].life >=0) {
		temp.pb(ant[k]);
		if((!cake_remain)&&(k==target))  {
			target=temp.size()-1;
		}
	}
	if((!cake_remain)&&target==k) cake_remain=1;
	return 1;
}

void Fort_Attack() {
	for(int i=1;i<=s;++i) {
		if(!cake_remain) {
			double dist=hypot(fort[i].x-ant[target].pos.x,fort[i].y-ant[target].pos.x);
			if(dist <= range )
			ant[target].life-=damage;
		}
		else Attack(i);
	}
	if(!cake_remain) {
		check_Ant(target);
	}
	temp.clear();
	for(size_t i=0;i<ant.size();++i) {
		check_Ant(i);
	}
	ant.clear();
	for(size_t i=0;i<temp.size();++i) {
		ant.pb(temp[i]);
	}
}

bool Check_End() {
	if((!cake_remain)&&ant[target].pos==mp(0,0)) {
		return 1;
	}
	return 0;
}
void Solve(int k) {
	Gen_Ant();
	Leave_Info();
	Ant_Move(k);
	Fort_Attack();
	if(Check_End()) {
		printf("Game over after %d seconds\n",k);
		Print_End(k);
	}	
}

void Print_End(int t) {
	Pn(ant.size());
	for(size_t i=0;i<ant.size();++i) {
		Ps(t+1-ant[i].t); Ps((ant[i].t-1)/6 +1); Ps(ant[i].life);  Ps(ant[i].pos.y); Pn(ant[i].pos.x);
	}
	exit(0);
}
