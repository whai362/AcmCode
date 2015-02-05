#include<stdio.h>
using namespace std;
long long num[200000];
long long min(long long a,long long b,long long c){
	long long t;
	if(a>b) t=a,a=b,b=t;
	if(a>c)	t=a,a=c,c=t;
	return a;
}
int main(){
	long long i,p1,p2,p3,t1,t2,t3,count=0;
	while(scanf("%lld",&i)&&i){
		if(num[i-1]) printf("%lld\n",num[i-1]);
		else{
		count=0;
		p1=p2=p3=0,num[count++]=1;
		while(1){
			if(count==i) break;
			t1=num[p1]*2;
			t2=num[p2]*3;
			t3=num[p3]*5;
			num[count]=min(t1,t2,t3);
			if(num[count]==t1) ++p1;
			if(num[count]==t2) ++p2;
			if(num[count]==t3) ++p3;
			++count;
		}
		printf("%lld\n",num[count-1]);
		}
	}
	return 0;
}

