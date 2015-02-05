#include <stdio.h>
long long s[200000];
long long min(long long a,long long b,long long c){
	if(a>b) {
		if(b>c) return c;
		else return b;
	}
	else{
		if(a>c) return c;
		else return a;
	}
}
int main(){
	int i,n,p1,p2,p3;
	long long t1,t2,t3;
	int i1,i2,i3;
	while(scanf("%d%d%d%d",&p1,&p2,&p3,&n)==4) {
		i1=1;i2=1;i3=1;
		s[1]=1;
		for(i=2;i<=n+1;i++) {
			t1=p1*s[i1];
			t2=p2*s[i2];
			t3=p3*s[i3];
			s[i]=min(t1,t2,t3);
			if(s[i]==t1) i1++;
			if(s[i]==t2) i2++;
			if(s[i]==t3) i3++;
		}
		printf("%lld\n",s[n+1]);
	}
	return 0;
}
