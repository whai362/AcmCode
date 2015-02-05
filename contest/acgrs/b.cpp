#include<cstdio>
#include<iostream>
using namespace std;
long long pow(int n,int m){
	long long tmp=n,res=1LL;
	while(m){
		if(m&1){
			res*=tmp;
		}
		tmp*=tmp;
		m>>=1;
	}
	return res;
}
int main(){
	int n,m,nn,mm,flag;
	long long a;
	while(scanf("%d%d%lld",&n,&m,&a)!=EOF){
	nn=n,mm=m;
	flag=0;
	long long tmp=pow(n,m);
	while(tmp<a){
		flag=1;
		tmp*=n;
		++m;
	}
	if(flag) --m;
	flag=0;
	while(pow(n,m)<a){
		flag=1;
		++n;
	}
	if(flag) --n;
	int cnt=n-nn+m-mm;
	if(cnt%2) printf("win\n");
	else printf("lose\n");
	}
	return 0;
}
