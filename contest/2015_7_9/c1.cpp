#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define LL __int64
const int N=1e5+5;
int a[N];
vector<int> fac[N];
int fac_cnt[N];
int cnt[N];
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

void deal(int id,int x){
	for(int i=1;i*i<=x;++i){
		if(x%i==0){
			fac[id].push_back(i);
			++fac_cnt[i];
			int tmp=x/i;
			if(i!=tmp){
				fac[id].push_back(tmp);
				++fac_cnt[tmp];
			}
		}
	}
}
void gao(int n){
	for(int i=0;i<N;++i){
		fac[i].clear();
		fac_cnt[i]=0;
		cnt[i]=0;
	}
	for(int i=0;i<n;++i){
		deal(i,a[i]);
	}
	for(int i=0;i<n;++i){
		//cout<<fac[i].size()<<endl;
		for(int j=0;j<fac[i].size();++j){
			cnt[i]+=mu[fac[i][j]]*fac_cnt[fac[i][j]];
		}
	}
	//for(int i=0;i<n;++i){
	//	cout<<cnt[i]<<endl;
	//}
	LL ans=0;
	for(int i=0;i<n;++i){
		if(a[i]==1) --cnt[i];
		ans+=(LL)cnt[i]*(n-1-cnt[i]);
	}
	cout<<(LL)n*(n-1)*(n-2)/6-ans/2<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	getMu();
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		gao(n);
	}
	return 0;
}
