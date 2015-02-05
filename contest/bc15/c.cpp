#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
const int N=1005,
	  M=100005;
LL a[2*N];
LL ans[M];
int main(){
	int n,m;
	LL r,c;
	LL sum=0;
	scanf("%d",&n);
	for(int i=0;i<=2*n-2;++i){
		scanf("%I64d",&a[i]);
	}
	scanf("%d",&m);
	sum=0;
	for(int i=0;i<m;++i){
		scanf("%I64d%I64d",&r,&c);
		if(i==0){
			r%=n;
			c%=n;
		}
		else{
			r=(r+ans[i-1])%n;
			c=(c+ans[i-1])%n;
		}
		ans[i]=a[r+c];
		cout<<ans[i]<<endl;
		sum+=ans[i];
	}
	printf("%I64d\n",sum);
}
