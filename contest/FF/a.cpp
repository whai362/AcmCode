#include<cstdio>
#include<iostream>
using namespace std;
const int N=1e5+5;
struct Data{
	int l,r;
}d[N];
int cnt,n;
int a[N];
int gao(int i,int p){
	if(p==0){
		if(i==0) return 0;
		int pos=d[i].l;
		if(a[pos+1]-a[pos-1]>1){
			int l1=d[i-1].r-d[i-1].l+1,
				l2=d[i].r-d[i].l+1;
			return l1+l2;
		}
		return 0;
	}
	else{
		if(i==cnt-1) return 0;
		int pos=d[i].r;
		if(a[pos+1]-a[pos-1]>1){
			int l1=d[i+1].r-d[i+1].l+1,
				l2=d[i].r-d[i].l+1;
			return l1+l2;
		}
		return 0;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	cnt=0;
	d[cnt].l=0;
	for(int i=1;i<n;++i){
		if(a[i]<=a[i-1]){
			d[cnt++].r=i-1;
			d[cnt].l=i;
		}
	}
	d[cnt++].r=n-1;
	int _max=0;
	for(int i=0;i<cnt;++i){
		_max=max(_max,d[i].r-d[i].l+1);
	}
	//cout<<_max<<endl;
	if(_max!=n) ++_max;
	for(int i=0;i<cnt;++i){
		_max=max(_max,gao(i,0));
		_max=max(_max,gao(i,1));
	}
	cout<<_max<<endl;
	/*for(int i=0;i<cnt;++i){
		cout<<d[i].l<<' '<<d[i].r<<endl;
	}*/
	return 0;
}
