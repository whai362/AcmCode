#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int ans=0,i,n,m,k,lower,upper;
	scanf("%d%d",&n,&k);
	lower=n*(k-1)/k;
	upper=n;
	while(lower!=upper-1 && ans!=n){
		i=(lower+upper)/2;
		ans=0,m=i;	
		while(m){
			ans+=m;
			m=m/k;
		}
		if(ans>n) upper=i;
		else if(ans<n) lower=i;
	}
	if(ans==n) printf("%d\n",i);
	else printf("%d\n",upper);
	return 0;
}
