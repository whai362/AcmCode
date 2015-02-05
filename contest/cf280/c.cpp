#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL __int64
struct Data{
	LL a,b;
}d[100005];
bool cmp(Data a,Data b){
	return a.b<b.b;
}
int main(){
	int n;
	LL r,avg;
	LL need=0;
	scanf("%d%I64d%I64d",&n,&r,&avg);
	for(int i=0;i<n;++i){
		scanf("%I64d%I64d",&d[i].a,&d[i].b);
		need+=avg-d[i].a;
	}
	sort(d,d+n,cmp);
	LL ans=0;
	for(int i=0;need>0 && i<n;++i){
		if(r-d[i].a<need){
			ans+=(r-d[i].a)*d[i].b;
			need-=(r-d[i].a);
		}
		else{
			ans+=need*d[i].b;
			break;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
