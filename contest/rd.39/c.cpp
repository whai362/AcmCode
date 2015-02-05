#include<cstdio>
using namespace std;
int prime[1000000];
bool is_prime(int n){
	if(prime[n]==1) return true;
	if(prime[n]==-1) return false;
	if(n==1) return false;
	if(n==2||n==3) return true;
	for(int i=2;i*i<=n;++i){
		if(n%i==0){
			prime[n]=-1;
			return false;
		}
	}
	prime[n]=1;
	return true;
}
int main(){
	int i,a,b,k;
	scanf("%d%d%d",&a,&b,&k);
	for(i=a;i<=b && k;++i){
		if(is_prime(i)) --k;
	}
	if(!k) printf("%d\n",b-i+1);
	else printf("-1\n");
	return 0;
}
