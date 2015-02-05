#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	long long n;
	while(cin>>n){
		while(n%2==0){
			n/=2;
		}
		if(n==1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
