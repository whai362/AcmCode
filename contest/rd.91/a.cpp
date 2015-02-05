#include<cstdio>
#include<iostream>
using namespace std;
int g[105];
int main(){
	int a,i,n;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",&a);
		//cout<<a<<endl;
		g[a]=i+1;
	}
	for(i=1;i<=n;++i){
		printf("%d ",g[i]);
	}
	return 0;
}
