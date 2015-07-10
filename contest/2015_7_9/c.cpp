#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define LL long long
const int N=1e5+5;
int a[N];
vector<int> fac[N];
LL fac_cnt[N];
LL cnt[N];

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
	for(int i=2;i*i<=x;++i){
		if(x%i==0){
			fac[id].push_back(i);
			++fac_cnt[i];
		}
		while(x%i==0){
			x/=i;
		}
	}
	if(x>1){
		fac[id].push_back(x);
		++fac_cnt[x];
	}
}
void gao(int n){
	for(int i=0;i<N;++i){
		fac[i].clear();
		cnt[i]=fac_cnt[i]=0;

	}
	for(int i=0;i<n;++i){
		deal(i,a[i]);
	}

	//for(int i=0;i<n;++i){
	//	cout<<fac[i].size()<<' '<<endl;
	//}
	//cout<<endl;
	//for(int i=0;i<10;++i){
	//	cout<<fac_cnt[i]<<endl;
	//}

	//fac_cnt[1]=n;
	for(int i=0;i<n;++i){
		cnt[i]=n;
		for(int j=0;j<fac[i].size();++j){
			cnt[i]+=mu[fac[i][j]]*fac_cnt[fac[i][j]];
		}
	}

	//cout<<endl;
	//for(int i=0;i<10;++i){
	//	cout<<cnt[i]<<endl;
	//}

	LL ans=0;
	for(int i=0;i<n;++i){
		ans+=(LL)cnt[i]*(n-1-cnt[i]);
	}
	printf("%lld\n",ans/2);
	//cout<<ans/2<<endl;
}
int main(){
	int T;
	int n;
	//cin>>T;
	scanf("%d",&T);
	getMu();
	while(T--){
	//	cin>>n;
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			//cin>>a[i];
			scanf("%d",&a[i]);
		}
		gao(n);
	}
}
