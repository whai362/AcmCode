#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
long long s[15000];
int ok(int n){
	long long t,tmp;
	t=sqrt(2*n);
	tmp=(t+1)*t/2;
	while(tmp>n){
		--t;
		tmp=(t+1)*t/2;
	}
	if(tmp==n) return t;
	return 0;
}
bool gao(int n,int d){
	long long t1,t2;
	t1=n/d;
	t2=n%d;
	if(t2==0 && ok(t1)) return 1;
	else if(d==1) return 0;
	else{
		t2=t2*(t2-1)/2;
		t1-=t2;
		if(gao(t1,d-1)) return 1;
	}
	return 0;
}
int main(){
	long long n;
	int i;
	scanf("%I64d",&n);
	for(i=1;i<n;++i){
		if(gao(n,i)) break;
	}
	cout<<i<<endl;
	return 0;
}
