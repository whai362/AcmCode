#include<cstdio>
using namespace std;
bool hash[1000];
int c[50];
int main(){
	int i,j,l,n,k;
	scanf("%d%d",&n,&k);
	for(i=0;i<k;++i){
		scanf("%d",&c[i]);
		hash[c[i]]=1;
	}
	for(i=0;i<k;++i){
		printf("%d",c[i]);
		l=n-1;
		for(j=1;j<=n*k;++j){
			if(!hash[j] && l) printf(" %d",j),hash[j]=1,l--;
		}
		printf("\n");
	}
	return 0;
}
