#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int t;
	int l;
	long long n;
	scanf("%d",&t);
	for(l=1;l<=t;++l){
		cin>>n;
		if(n<=2){
			cout<<"Case "<<l<<": no solution"<<endl;
		}
		else{
			long long tmp=n-1;
			cout<<"Case "<<l<<": "<<2*tmp<<' '<<tmp<<' '<<1<<endl;
		}
	}
	return 0;
}

