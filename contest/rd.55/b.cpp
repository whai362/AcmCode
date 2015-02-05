#include<cstdio>
#include<cstring>
using namespace std;
int prime[100000];
int ans[505][505];
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
	int a,i,j,k,n,m,_min=0x3f3f3f3f,tmp;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i){
		for(j=0;j<m;++j){
			scanf("%d",&a);
			for(k=a;;++k){
				if(is_prime(k)) break;
			}
			ans[i][j]=k-a;
		}
	}
	for(i=0;i<n;++i){
		tmp=0;
		for(j=0;j<m;++j){
			tmp+=ans[i][j];
		}
		if(tmp<_min) _min=tmp;
	}
	for(j=0;j<m;++j){
		tmp=0;
		for(i=0;i<n;++i){
			tmp+=ans[i][j];
		}
		if(tmp<_min) _min=tmp;
	}
	printf("%d\n",_min);
	return 0;
}
