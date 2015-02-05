#include<cstdio>
#include<iostream>
#include<iomanip>
using namespace std;
const double eps=1e-7; 
const int N=10005;
double len[N];
double _abs(int a){
	if(a>=0){
		return a;
	}
	return -a;
}
int main(){
	int n,k;
	double _min=1e18;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;++i){
		scanf("%lf",&len[i]);
	}
	double l,r,mid;
	l=0,r=100000;
	for(int i=0;i<100;++i){
		int cnt=0;
		mid=(l+r)/2;
		for(int j=0;j<n;++j){
			cnt+=(int)(len[j]/mid);
		}
		if(cnt>=k){
			l=mid;
		}
		else{
			r=mid;
		}
	}
	if(mid+eps>=0.01)
		cout<<fixed<<setprecision(2)<<(mid+eps-0.005)<<endl;
	else
		printf("0.00\n");
	return 0;
}
