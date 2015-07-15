#include<iostream>
#include<cstdio>
using namespace std;
const int N=1200000001;
#define LL long long
LL pri[N],pcnt;
LL phi[N];
void getphi(){
	phi[1]=1;
	printf("%lld,",phi[1]);
	for(LL i=2;i<N;++i){
		if(!phi[i]){ pri[pcnt++]=i; phi[i]=i-1; }
		for(LL j=0;i*pri[j]<N && j<pcnt;++j){
			if(i%pri[j]==0){
				phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
			else phi[i*pri[j]]=phi[i]*(pri[j]-1);
		}
		printf("%lld,",phi[i]);
	}
}

int main(){
	getphi();
}
