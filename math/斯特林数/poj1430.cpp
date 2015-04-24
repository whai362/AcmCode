#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL __int64
int jiou(int n,int k){
	return ((n-k)&k)>0?0:1;
}
LL sti[25][25];
void predo(int n){
	sti[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j){
			sti[i][j]=(LL)j*sti[i-1][j]+sti[i-1][j-1];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j){
			cout<<sti[i][j]%2<<' ';
		}
		cout<<endl;
	}
}
int main(){
	//predo(20);
	int T;
	int n,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		if(n==k){
			puts("1");
			continue;
		}
		if(k%2==0) --n,--k;
		int a=n-k;
		int b=(k+1)/2-1;
		a=a+b;
		//cout<<a<<' '<<b<<endl;
		printf("%d\n",jiou(a,b));
	}
	return 0;
}
