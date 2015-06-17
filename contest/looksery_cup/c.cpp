#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int c0=0;
	int c1=0;
	int a;
	for(int i=0;i<n;++i){
		scanf("%d",&a);
		if(a&1) c1++;
		else c0++;
	}
	int ans;
	if((n-k)%2==1){
		if(c1 <= (n-k)/2) ans=1;
		else if(k%2 == 0 && c0 <= (n-k)/2) ans=1;
		else ans=0;
	}
	else{
		if(k%2 == 1 && c0 <= (n-k)/2) ans=0;
		else ans=1;
		if(n==k) ans=1;
	}
	if(ans==0) puts("Stannis");
	else puts("Daenerys");
	return 0;
}
