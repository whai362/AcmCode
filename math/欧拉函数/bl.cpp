#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	long long n;
	cin>>n;
	int lim=sqrt(n);
	int flag=0;
	int s=1;
	for(int i=2;i<=lim;++i){
		if(n%i==0){
			flag=1;
			s=i;
			break;
		}
	}
	cout<<flag<<' '<<s<<endl;
	return 0;
}
