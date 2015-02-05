#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	if(n%2==0){
		puts("white");
		puts("1 2");
	}
	else{
		puts("black");
	}
	return 0;
}
