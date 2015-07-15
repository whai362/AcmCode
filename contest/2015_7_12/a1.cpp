#include<iostream>
#include<cstdio>
using namespace std;
const int n=3005;
const int inf=0x3f3f3f3f;
int a[n];
int a[n];
int b[n];

int deal(int p,int q,int sub,int n,int m){
	//cout<<p<<' '<<q<<' '<<sub<<endl;
	int p=n-1,q=q;
	int ret=inf;

	cout<<">>>"<<endl;
	for(int i=p-1;i>=0;--i)
		cout<<a[i]<<' ';
	cout<<endl;
	for(int i=q;i<n;++i)
		cout<<b[i]-sub<<' ';
	cout<<endl;
	cout<<"<<<"<<endl;

	for(int i=p-1;i>=0;--i){
		if(a[i]>m) break;
		while(q<n && b[q]-sub<=a[i]) ++q;
		--q;
		if(q<q) break;
		if(b[q]-sub<=a[i]) ret=min(a[i]-(b[q]-sub),ret);
		if(q==n-1) break;
	}
	for(int i=q;i<n;++i){
		if(b[i]-sub>m) break;
		while(p>=0 && a[p]<=b[i]-sub) --p;
		++p;
		if(p>=n) break;
		if(a[p]<=b[i]-sub) ret=min(b[i]-sub-a[p],ret);
		if(p==0) break;
	}
	return ret;
}
//×¢Òâm
void gao(int n,int m){
	b[1]=a[1];
	for(int i=2;i<n;++i){
		b[i]=b[i-1]+1+a[i];
	}
	a[0]=a[0];
	int p=1,q=1;
	int minn=inf;
	int sub=0;
	while(p<n){
		minn=min(minn,deal(p,q,sub,n,m));
		//a[p]=a[p-1]+1+a[p];
		for(int i=0;i<p;++i){
			a[i]+=1+a[p];
		}
		a[p]=a[p];
		++p;
		sub+=a[q]+1;
		++q;
	}
	cout<<"ans"<<minn<<endl;

}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
			cout<<a[i]<<' ';
		}
		cout<<endl;
		gao(n,m);
	}
}
