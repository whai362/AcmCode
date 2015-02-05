#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
#define LL __int64
LL p;
LL work(LL x,LL y){
	if (x<0||y<0) return 0;
	LL r1,r2,q1,q2;
	q1=x/p;r1=x%p;
	q2=y/p;r2=y%p;
	LL a,b,c,d;
	a=r1,b=p-1-r1,c=r2,d=p-1-r2;
	LL ret=(q1+1)*(q2+1);
	//LL tmp;
	//if (a>d) tmp=a,a=c,c=tmp,tmp=b,b=d,d=tmp;
	if (a==d) ret+=a*(q1+1)*q2+b*q1*(q2+1);
	else {
		if (a<d) ret+=a*(q1+1)*q2+(d-a)*q1*q2+c*q1*(q2+1);
		else {
			ret+=d*(q1+1)*q2+(a-d)*(q1+1)*(q2+1)+b*(q1)*(q2+1);
		}
	}
	return ret;
}
void exgcd(LL a,LL b,LL &x,LL &y,LL &d){
	if (b==0){
		x=1;
		y=0;
		d=a;
		return ;
	}
	exgcd(b,a%b,y,x,d);
	y-=a/b*x;
}

int main(){
	int cases;
	LL a,b,c,d,m;
	scanf("%d",&cases);
	for (int cas=1;cas<=cases;cas++){
		scanf("%I64d %I64d %I64d %I64d %I64d %I64d",&a,&b,&c,&d,&p,&m);
		if (m>0) c=c+p-m;
		if (m>0) d=d+p-m;
		//cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<p<<' '<<m<<endl;
		LL ans1=work(b,d)-work(a-1,d)-work(b,c-1)+work(a-1,c-1);
		LL ans2=(b-a+1)*(d-c+1);
		//printf("Case #%d: %I64d/%I64d\n",cas,ans1,ans2);
		LL x,y,d;
		exgcd(ans1,ans2,x,y,d);
		printf("Case #%d: %I64d/%I64d\n",cas,ans1/d,ans2/d);
	}
	return 0;
}

