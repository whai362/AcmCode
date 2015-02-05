#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int IsPrime(long long  N){
      int i, j;
      if (N==2)
          return 1;
      else if(N<2||N%2==0)
		  return 0;
      else{
          j=(int)sqrt(N+1);
          for(i = 3; i <= j; i = i + 2)
			if(N%i==0) return 0;
      }
      return 1;
}

int main(){
	int i,b,n;
	while(scanf("%d%d",&b,&n)!=EOF){
		long long m=0;
		for(i=0;i<n;++i){
			m+=pow(b,i);
		}
		if(IsPrime(m)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
