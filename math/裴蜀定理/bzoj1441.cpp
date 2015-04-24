#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int ans;
	int a;
	for(int i=0;i<n;++i){
		scanf("%d",&a);
		if(a==0) continue;
		if(a<0) a=-a;
		if(i==0) ans=a;
		else ans=__gcd(ans,a);
	}
	printf("%d\n",ans);
	return 0;
}
