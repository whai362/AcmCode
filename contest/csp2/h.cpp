#include<cstdio>
#include<iostream>
using namespace std;
int a,b,ans[105],cnt;
void gao(){
	cnt=0;
	while(b>0){
		ans[cnt++]=b%a;
		//cout<<b%a<<endl;
		b/=a;
	}
}
int main(){
	int n,T;
	scanf("%d",&T);
	while(T--){
	scanf("%d%d",&a,&n);
	for(int i=0;i<n;++i){
		scanf("%d",&b);
		gao();
		//cout<<cnt<<endl;
		for(int j=cnt-1;j>=0;--j){
			printf("%d",ans[j]);
		}
		puts("");
	}
	}
	return 0;
}
