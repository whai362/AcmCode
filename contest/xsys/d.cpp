#include<cstdio>
#include<iostream>
using namespace std;
long long c(int n,int k){
	int i;
	long long ans=1;
	for(i=0;i<k;++i){
		ans*=(long long)(n-i);
	}
	for(i=1;i<=k;++i){
		ans/=(long long)i;
	}
	return ans;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
	if(n==3) printf("1\n");
	else if(n==4) printf("8\n");
	else if(n==5) printf("35\n");
	else{
		cout<<c(n,3)+4*c(n,4)+5*c(n,5)+c(n,6)<<endl;
	}
	}
	return 0;
}
