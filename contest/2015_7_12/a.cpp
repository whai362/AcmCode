#include<iostream>
#include<cstdio>
using namespace std;
const int N=3005;
const int INF=0x3f3f3f3f;
int a[N];
int A[N];
int B[N];

int deal(int P,int Q,int sub,int n,int m){
	//cout<<P<<' '<<Q<<' '<<sub<<endl;
	int p=n-1,q=Q;
	int ret=INF;

	cout<<">>>"<<endl;
	for(int i=P-1;i>=0;--i)
		cout<<A[i]<<' ';
	cout<<endl;
	for(int i=Q;i<n;++i)
		cout<<B[i]-sub<<' ';
	cout<<endl;
	cout<<"<<<"<<endl;

	for(int i=P-1;i>=0;--i){
		if(A[i]>m) break;
		while(q<n && B[q]-sub<=A[i]) ++q;
		--q;
		if(q<Q) break;
		if(B[q]-sub<=A[i]) ret=min(A[i]-(B[q]-sub),ret);
		if(q==n-1) break;
	}
	for(int i=Q;i<n;++i){
		if(B[i]-sub>m) break;
		while(p>=0 && A[p]<=B[i]-sub) --p;
		++p;
		if(p>=n) break;
		if(A[p]<=B[i]-sub) ret=min(B[i]-sub-A[p],ret);
		if(p==0) break;
	}
	return ret;
}
//×¢Òâm
void gao(int n,int m){
	B[1]=a[1];
	for(int i=2;i<n;++i){
		B[i]=B[i-1]+1+a[i];
	}
	A[0]=a[0];
	int p=1,q=1;
	int minn=INF;
	int sub=0;
	while(p<n){
		minn=min(minn,deal(p,q,sub,n,m));
		//A[p]=A[p-1]+1+a[p];
		for(int i=0;i<p;++i){
			A[i]+=1+a[p];
		}
		A[p]=a[p];
		++p;
		sub+=a[q]+1;
		++q;
	}
	cout<<"ans"<<minn<<endl;

}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
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
