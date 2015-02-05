#include<cstdio>
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
struct data{
	int f,v;
}d[105];
bool cmp(data a,data b){
	return a.v<b.v;
}
int main(){
	int cnt=0,i,j,n,k,q,t,tmp;
	double sum,_min,_max;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;++i){
		scanf("%d",&d[i].v);
		d[i].f=0;
	}
	tmp=n/k;
	scanf("%d",&q);
	_min=0x3f3f3f3f;
	_max=0;
	for(i=0;i<q;++i){
		sum=0;
		for(j=0;j<tmp;++j){
			scanf("%d",&t);
			sum+=d[t-1].v;
			d[t-1].f=1;
		}
		_min=min(_min,sum/tmp);
		_max=max(_max,sum/tmp);
	}
	sort(d,d+n,cmp);
	sum=0;
	for(i=0;i<n;++i){
		if(d[i].f==1) ++cnt;
	}
	if(cnt/tmp<=k){
		for(i=0,j=0;i<n && j<tmp;++i){
			if(d[i].f==0) sum+=d[i].v,++j;
		}
		_min=min(_min,sum/tmp);
		sum=0;
		for(i=n-1,j=0;i>=0 && j<tmp;--i){
			if(d[i].f==0) sum+=d[i].v,++j;
		}
		_max=max(_max,sum/tmp);
	}
	cout<<fixed<<setprecision(10)<<_min<<' '<<_max<<endl;
	return 0;
}
