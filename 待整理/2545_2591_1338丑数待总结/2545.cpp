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
	long long a,b,c,i,p1,p2,p3,t1,t2,t3,count=0;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&i);
	p1=p2=p3=0,num[count]=1;
	while(1){
		if(count==i) break;
		++count;
		t1=num[p1]*a;
		t2=num[p2]*b;
		t3=num[p3]*c;
		num[count]=min(t1,t2,t3);
		if(num[count]==t1) ++p1;
		if(num[count]==t2) ++p2;
		if(num[count]==t3) ++p3;
	}
	printf("%lld\n",num[count]);
	return 0;
}
