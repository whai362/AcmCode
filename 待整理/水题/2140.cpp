#include<stdio.h>
#include<math.h>
using namespace std;
int main(){
	int count,i,m,n;
	scanf("%d",&n);
	m=n/2;
	count=1;
	for(i=2;i<=m;++i){
		if(i%2){
			if(n%i==0&&n/i>i/2) ++count;
		}
		else{
		  if(n%i==i/2&&n/i>=i/2) ++count;
		}
	}
	printf("%d\n",count);
	return 0;
}
