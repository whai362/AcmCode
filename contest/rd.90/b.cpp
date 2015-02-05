#include<cstdio>
using namespace std;
int hash[5005];
int main(){
	int a,ans=0,i,maxa=0,n;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",&a);
		if(a>maxa) maxa=a;
		++hash[a];
	}
	for(i=1;i<=maxa;++i){
		if(hash[i]){
			if(i<=n)
			  ans+=hash[i]-1;
			else
			  ans+=hash[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}
