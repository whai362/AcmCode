#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
#define N 16000
long long t,s[N];
bool ok(long long n){
	long long tmp;
	t=sqrt(2*n);
	tmp=(t+1)*t/2;
	while(tmp>n){
		--t;
		tmp=(t+1)*t/2;
	}
	if(tmp==n) return 1;
	return 0;
}
int main(){
	int i,j,n,flag,T;
	long long t1,t2,t3,tmp;
	for(i=1;i<N;++i){
		s[i]=s[i-1]+i;
	}
	scanf("%d",&T);
	while(T--){
	scanf("%d",&n);
	if(ok(n)){
		printf("%I64d\n",t);
	}
	else{
		for(i=1;s[i]<=n;++i){
			tmp=n-s[i];
			flag=ok(s[i]);
			t1=t;
			flag&=ok(tmp);
			t2=t;
			if(flag){
				printf("%I64d %I64d\n",t1,t2);
				break;
			}
		}
		if(s[i]>n){
			for(i=1;s[i]<=n;++i){
				for(j=1;s[j]+s[i]<=n;++j){
					tmp=n-s[i]-s[j];
					flag=ok(s[i]);
					t1=t;
					flag&=ok(s[j]);
					t2=t;
					flag&=ok(tmp);
					t3=t;
					if(flag){
						printf("%I64d %I64d %I64d\n",t1,t2,t3);
						break;
					}
				}
				if(flag) break;
			}
		}
	}
	}
	return 0;
}
