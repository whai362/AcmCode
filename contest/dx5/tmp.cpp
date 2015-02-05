#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	int sum;
	for(int n=2;n<=100;++n){
		sum=0;
		for(int i=1;i<n;++i){
			sum+=i^(n-i);
		}
		printf("%d %d\n",n,sum);
	}
	puts("");
	return  0;
}


