#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL __int64
const int N=1e5+5;
struct Data{
	LL r,e,l;
}a[N];
bool cmp(Data a,Data b){
	return a.e<b.e;
}
void gao(int n){
	sort(a,a+n,cmp);
	LL use=0,now=0;
	for(int i=0;i<n;++i){
		//cout<<a[i].r<<' '<<a[i].e<<' '<<a[i].l<<endl;
		now=a[i].e;
		LL tmp=now-use;
		//cout<<tmp<<endl;
		if(a[i].r>tmp){
			puts("NO");
			return ;
		}
		use+=a[i].r+a[i].l;
	}
	puts("YES");
}
int main(){
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%I64d%I64d%I64d",&a[i].r,&a[i].e,&a[i].l);
		}
		printf("Case #%d: ",++cas);
		gao(n);
	}
}
