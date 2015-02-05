#include<cstdio>
#include<iostream>
using namespace std;
#define K 10005
double s[K];
int main(){
	int n,m,k;
	double p;
	int i;
	s[0]=0;
	scanf("%d%d%d",&m,&n,&k);
	for(i=1;i<=k;++i){
		scanf("%lf",&p);
		s[i]=s[i-1]+p;
	}
	int f=0;
	double sm,sn;
	for(i=max(n,m);i<=k;++i){
		sm=(s[i]-s[i-m])/m;
		sn=(s[i]-s[i-n])/n;
		if(f==0){
			if(sm>sn){
				printf("BUY ON DAY %d\n",i);
				f=1;
			}
			else{
				printf("SELL ON DAY %d\n",i);
				f=-1;
			}
		}
		else{
			int tmp_f;
			if(sm>sn) tmp_f=1;
			else tmp_f=-1;
			if(tmp_f!=f){
				if(tmp_f<0)
					printf("SELL ON DAY %d\n",i);
				else
					printf("BUY ON DAY %d\n",i);
			}
			f=tmp_f;
		}
	}
	return 0;
}
