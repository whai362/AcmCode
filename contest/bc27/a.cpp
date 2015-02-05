#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Data{
	int x[3];
	int d;
	int id;
}d[105];
bool cmp(Data a,Data b){
	return a.d>b.d;
}
bool cmp1(Data a,Data b){
	return a.id<b.id;
}
int main(){
	int n;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			d[i].id=i;
			d[i].d=0;
			for(int j=0;j<3;++j){
				scanf("%d",&d[i].x[j]);
				d[i].d=max(d[i].d,d[i].x[j]);
			}
		}
		sort(d+1,d+1+n,cmp);
		for(int i=1;i<=n;++i){
			d[i].d=i;
		}
		sort(d+1,d+1+n,cmp1);
		for(int i=1;i<=n;++i){
			printf("%d%c",d[i].d,i==n?'\n':' ');
		}
	}
	return 0;
}
