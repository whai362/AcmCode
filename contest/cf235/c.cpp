#include<cstdio>
using namespace std;
int main(){
	int i,n,m,f;
	scanf("%d%d",&n,&m);
	if(2*n+2<m || m<=n-2){
		printf("-1\n");
		return 0;
	}
	else if(n<m){
		int t=m-n;
		if(t<=n){	//4 8
			for(i=0;i<t;++i)
				printf("110");
			n-=t;
			for(i=0;i<n;++i)
				printf("10");
			if(2*t+n<m)
				printf("1");
			printf("\n");
		}
		else{
			for(i=0;i<n;++i)
				printf("110");
			m-=2*n;
			for(i=0;i<m;++i)
				printf("1");
			printf("\n");
		}
		return 0;
	}
	else if(n==m){
		for(i=0;i<n;++i)
			printf("10");
		printf("\n");
		return 0;
	}
	else if(n==m+1){
		for(i=0;i<m;++i)
			printf("01");
		printf("0");
		printf("\n");
		return 0;
	}
}
