#include<stdio.h>
#include<math.h>
using namespace std;
int main(){
	int a,b,n,m,t,x,y;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&x,&y);
		n=y-x;
		m=sqrt(n);
		if(n==0) printf("%d\n",0);
		else if(m*m==n) printf("%d\n",2*m-1);
		else{
			a=m*m,b=m*m+m;
			if(n>a&&n<=b) printf("%d\n",2*m);
			a=m*m+m,b=(m+1)*(m+1);
			if(n>a&&n<=b) printf("%d\n",2*m+1);
		}
	}
	return 0;
}
