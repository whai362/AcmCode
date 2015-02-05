#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL __int64
const int N=200005;
const int inf=0x3f3f3f3f;
struct Data{
	LL p;
	int s;
	Data(){};
	Data(int _p,int _s){
		p=_p;
		s=_s;
	}
}a[2*N];
bool cmp(Data a,Data b){
	return a.p<b.p;
}
int main(){
	int n;
	int m;
	int cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%I64d",&a[cnt].p);
		a[cnt++].s=1;
	}
	scanf("%d",&m);
	for(int i=0;i<m;++i){
		scanf("%I64d",&a[cnt].p);
		a[cnt++].s=2;
	}
	sort(a,a+cnt,cmp);
	//for(int i=0;i<cnt;++i){
	//	cout<<d[i].p<<' 'd[i].s<<endl;
	//}
	int c1=0,c2=0;
	int ans=-inf,s1,s2,tmp,t1,t2;
	t1=c1*2+(n-c1)*3;
	t2=c2*2+(m-c2)*3;
	tmp=t1-t2;
	if(tmp>ans){
		ans=tmp;
		s1=t1;
		s2=t2;
	}
	for(int i=0;i<cnt;++i){
		int j=i;
		while(a[j].p==a[i].p){
			if(a[j].s==1) ++c1;
			else ++c2;
			++j;
		}
		t1=c1*2+(n-c1)*3;
		t2=c2*2+(m-c2)*3;
		tmp=t1-t2;
		if(tmp>ans){
			ans=tmp;
			s1=t1;
			s2=t2;
		}
		i=j-1;
	}
	printf("%d:%d\n",s1,s2);
	return 0;
}
