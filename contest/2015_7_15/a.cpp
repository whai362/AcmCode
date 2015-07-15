#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=105;
struct Dt{
	int p;
	int q;
	int m;
}a[MAXN];
int main(){
	int N, T, M;
	int cas=0;
	while(scanf("%d%d%d", &N, &T, &M) && (N || T || M)){
		memset(a, 0, sizeof(a));
		int id, p, q;
		for(int i=0;i<N;++i){
			scanf("%d%d%d", &id,  &p, &q);
			a[id].p=p;
			a[id].q=q;
		}
		int ans=0;
		for(int i=0;i<T;++i){
			int id;
			int tot;
			scanf("%d%d", &id, &tot);
			if(tot>=M) a[id].m=1;
		}
		//for(int i=0;i<=5;++i){
		//	cout<<a[i].m<<' '<<a[i].p<<' '<<a[i].q<<endl;
		//}
		for(int i=0;i<=N;++i){
			ans+=a[i].m+a[i].p+a[i].q;
		}
		printf("Case %d: ", ++cas);
		cout<<ans<<endl;
	}
	return 0;
}
