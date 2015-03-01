#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL long long
const int N=1e6+5;
int mu[N];
//O(nlog(n))
void getMu(){
	for(int i=1;i<N;++i){
		int target=i==1?1:0;
		int delta=target-mu[i];
		mu[i]=delta;
		for(int j=2*i;j<N;j+=i)
			mu[j]+=delta;
	}
}
int sum[N];
void predo(){
	sum[0]=0;
	for(int i=1;i<N;++i)
		sum[i]=sum[i-1]+mu[i];
}
LL deal(LL a[],int len){
	LL ret=0;
	sort(a,a+len);
	LL last;
	for(int i=1;i<=a[0];i=last+1){
		last=a[0]/(a[0]/i);
		for(int j=1;j<len;++j) last=min(last,a[j]/(a[j]/i));
		LL tmp=sum[last]-sum[i-1];
		for(int j=0;j<len;++j) tmp*=a[j]/i;
		ret+=tmp;
	}
	return ret;
}
LL a[15];
LL gao(LL x,LL y,LL z){
	LL ret=3;
	a[0]=x,a[1]=y,a[2]=z;
	ret+=deal(a,3);
	a[0]=x,a[1]=y;
	ret+=deal(a,2);
	a[0]=y,a[1]=z;
	ret+=deal(a,2);
	a[0]=x,a[1]=z;
	ret+=deal(a,2);
	return ret;
}
int main(){
	getMu();
	//for(int i=1;i<=10;++i) cout<<mu[i]<<' ';
	//cout<<endl;
	predo();
	LL x,y,z;
	while(scanf("%lld%lld%lld",&x,&y,&z)!=EOF){
		printf("%lld\n",gao(x-1,y-1,z-1));
	}
}
