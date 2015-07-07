#include <iostream>
#include <cstdlib>
using namespace std;
const int N=1e6+5;
const int INF=1000000000;
int fac[N],cnt;

int get_cnt(int x){
	int ret=0;
	while(x%2==0){
		x/=2;
		++ret;
	}
	while(x%3==0){
		x/=3;
		++ret;
	}
	while(x%5==0){
		x/=5;
		++ret;
	}
	if(x!=1) return INF;
	return ret;
}

int deal(int a,int b){
	//int Min = min(a,b);
	int lim = sqrt(max(a,b));
	for(int i=1; i<=lim; ++i){
		//if(a%i==0 && b%i==0)
		//	fac[cnt++]=i;
	}
	int ans=INF;
	for(int i=0;i<cnt;++i){
		int a1=a/fac[i];
		int b1=b/fac[i];
		int count_a1=get_cnt(a1);
		int count_b1=get_cnt(b1);
		ans=min(ans,count_a1+count_b1);
	}
	if(ans==INF) ans=-1;
	return ans;
}
void init(){
	cnt=0;
}
int main(){
	int a,b;
	while(cin>>a>>b){
		init();
		int ans=deal(a,b);
		cout<<ans<<endl;
	}
	return 0;
}
