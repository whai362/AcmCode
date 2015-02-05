#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n,x;
	scanf("%d%d",&n,&x);
	int l,r;
	int ans=0;
	int cur=1;
	for(int i=0;i<n;++i){
		scanf("%d%d",&l,&r);
		int bei=(l-cur)/x;
		cur=cur+bei*x;
		ans+=(r-cur+1);
		cur=r+1;
	}
	printf("%d\n",ans);
	return 0;
}
