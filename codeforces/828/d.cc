using namespace std;

inline void splay(int &v){
 v=0;char c=0;int p=1;
 while(c<'0' || c>'9'){if(c=='-')p=-1;c=getchar();}
 while(c>='0' && c<='9'){v=(v<<3)+(v<<1)+c-'0';c=getchar();}
 v*=p;
}
int n,k;
int a[200010],b[200010],s[200010],t;
int main(){
 //freopen("xxx.in","r",stdin);
 cin>>n>>k;
 if(n-k==1){
  cout<<2<<endl;
  for(int i=2;i<=n;i++){
   printf("%d %d\n",1,i);
  }
  return 0;
 }
 if(n-k==2){
  printf("3\n");
  printf("1 2\n2 3\n");
  for(int i=4;i<=n;i++){
   printf("3 %d\n",i);
  }
  return 0;
 }
 for(int i=1;i<=n;i++)s[i]=1;
 int now=0,ans=2;
 for(int i=2;i<=n-k;i++){
  now++;if(now==k+1)now=1;
  if(now==1||now==2)ans++;
  a[++t]=i;b[t]=s[now];
  s[now]=i;
 }
 now=0;
 for(int i=n-k+1;i<=n;i++){
  now++;if(now==k+1)now=1;
  a[++t]=i;b[t]=s[now];
 }
 cout<<ans<<endl;
 for(int i=1;i<=n-1;i++){
  printf("%d %d\n",a[i],b[i]);
 }
}