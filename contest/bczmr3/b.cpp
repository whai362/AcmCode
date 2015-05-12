#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define PB push_back
const int N=1005;
const int INF=1000000005;
int S;
vector<int> B[N];
int a[N*N];
int bcnt;
int _abs(int x){
	if(x<0) return -x;
	return x;
}
int get_ans(int i,int k){
	int p=lower_bound(B[i].begin(),B[i].end(),k)-B[i].begin();
	if(0<p && p<B[i].size()){
		return min(_abs(k-B[i][p]),_abs(k-B[i][p-1]));
	}
	else if(p==0){
		return _abs(k-B[i][p]);
	}
	else{
		return _abs(k-B[i][p-1]);
	}
}
void gao(int l,int r,int k){
	int lr=(l/S+1)*S;
	int ans=INF;
	//cout<<l<<' '<<lr-1<<endl;
	for(int i=l;i<min(r,lr);++i){
		ans=min(ans,_abs(a[i]-k));
	}
	int rl=(r/S)*S;
	//cout<<rl<<' '<<r<<endl;
	for(int i=max(l,rl);i<=r;++i){
		ans=min(ans,_abs(a[i]-k));
	}
	int L=l/S+1;
	int R=r/S;
	for(int i=L;i<R;++i){
		ans=min(ans,get_ans(i,k));
	}
	printf("%d\n",ans);
}
void init(){
	for(int i=0;i<N;++i){
		B[i].clear();
	}
}
int main(){
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		int n,q;
		init();
		scanf("%d%d",&n,&q);
		S=sqrt(n);
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
			int bl=i/S;
			B[bl].PB(a[i]);
		}
		bcnt=(n-1)/S;
		//for(int i=0;i<=bcnt;++i){
		//	for(int j=0;j<B[i].size();++j){
		//		cout<<B[i][j]<<' ';
		//	}
		//	cout<<endl;
		//}
		for(int i=0;i<=bcnt;++i){
			sort(B[i].begin(),B[i].end());
		}
		int l,r,k;
		printf("Case #%d:\n",++cas);
		for(int i=0;i<q;++i){
			scanf("%d%d%d",&l,&r,&k);
			gao(l-1,r-1,k);
		}
	}
	return 0;
}
