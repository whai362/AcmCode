#include<cstdio>
#include<cstring>
using namespace std;
short prime[1300000];
bool is_prime(int n){
	if(prime[n]==1) return true;
	if(prime[n]==-1) return false;
	if(n==2 || n==3) return true;
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
	int count,i,n;
	memset(prime,0,sizeof(prime));
	while(scanf("%d",&n) && n){
		count=0;
		if(is_prime(n)){
			printf("0\n");
		}
		else{
			++count;
			for(i=n-1;!is_prime(i) && i;--i) ++count;
			for(i=n+1;!is_prime(i);++i) ++count;
			printf("%d\n",count+1);
		}
	}
	return 0;
}
