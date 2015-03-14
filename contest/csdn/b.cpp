#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define LL __int64
const int N=1e4+5;
const LL INF=100000000000LL;
struct Dt{
	int x,i;
}a[N];
LL st[3],en[3];
int cnt[105];
void init(int n){
	memset(cnt,0,sizeof(cnt));
	memset(st,0,sizeof(st));
	memset(en,0,sizeof(st));
	int pt,mv;
	for(int i=0;i<n;++i){
		pt=i/50;
		mv=i%50;
		en[pt]|=(1LL<<mv);
	}
}
bool cmp(Dt a,Dt b){
	return a.x<b.x;
}
bool ok(){
	for(int i=0;i<3;++i)
		if(st[i]!=en[i]) return false;
	return true;
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		init(n);
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j){
				scanf("%d",&a[i*m+j].x);
				a[i*m+j].i=i;
			}
		sort(a,a+n*m,cmp);
		//for(int i=0;i<n*m;++i)
		//	cout<<a[i].x<<' ';
		//cout<<endl;
		int p=0,q=-1;
		LL ans=INF;
		int pt,mv;
		while(q<n*m){
			while(q<n*m && !ok()){
				++q;
				if(cnt[a[q].i]==0){
					pt=a[q].i/50;
					mv=a[q].i%50;
					st[pt]|=(1LL<<mv);
				}
				++cnt[a[q].i];
			}
			//cout<<p<<' '<<q<<endl;
			if(q>=n*m) break;
			ans=min(ans,(LL)a[q].x-a[p].x);
			--cnt[a[p].i];
			if(cnt[a[p].i]==0){
				pt=a[p].i/50;
				mv=a[p].i%50;
				st[pt]^=(1LL<<mv);
			}
			++p;
		}
		printf("%d\n",(int)ans);
	}
	return 0;
}
