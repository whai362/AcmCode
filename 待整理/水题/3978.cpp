#include<cstdio>
using namespace std;
#define N 100005
bool prime[N];
bool is_prime(int n){
	int i;
	if(prime[n]) return 1;
	if(n==2 || n==3) return 1;
	for(i=2;i*i<=n;++i)
	  if(n%i==0) return 0;
	prime[n]=1;
	return 1;
}
int main(){
	int a,b,count,i;
	while(scanf("%d%d",&a,&b) && (a!=-1 || b!=-1)){
		count=0;
		if(a<2) a=2;
		for(i=a;i<=b;++i)
		  if(is_prime(i)) ++count;
		printf("%d\n",count);
	}
	return 0;
}
