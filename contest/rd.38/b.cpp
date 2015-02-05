#include<cstdio>
using namespace std;
#define M 1073741824
int hash[1000005];
int main(){
	int i,j,k,a,b,c,count=0,tmp;
	scanf("%d%d%d",&a,&b,&c);
	tmp=a*b*c;
	for(i=1;i<=tmp;++i){
		for(j=1;i*j<=tmp;++j){
			++hash[i*j];
		}
	}
	for(i=1;i<=a;++i)
	  for(j=1;j<=b;++j)
		for(k=1;k<=c;++k){
			count=(count+hash[i*j*k]%M)%M;
		}
	printf("%d\n",count);
	return 0;
}
