#include<cstdio>
using namespace std;
int hash[105];
int main(){
	int a,i,n,cnt;
	scanf("%d",&n);
	cnt=0;
	for(i=0;i<n;++i){
		scanf("%d",&a);
		++hash[a];
	}
	for(i=0;i<=100;++i){
		if(hash[i]>=2) cnt+=hash[i]/2;
	}
	printf("%d\n",cnt/2);
	return 0;
}
