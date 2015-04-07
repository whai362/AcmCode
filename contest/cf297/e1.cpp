#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<tr1/unordered_map>
using namespace std;
using namespace std::tr1;
#define PB push_back
#define LL __int64
LL S;
LL fac[50];
int a[30];
int n,k,lim;
LL ans=0;
unordered_map<LL,int> mp;
vector<LL> res1[30];
vector<LL> res2[30];
void gao(int cur,LL sum,int e){
	if(sum>S) return ;
	if(e>k) return ;
	if(cur==lim)
		res1[e].PB(sum);
	else{
		gao(cur+1,sum,e);
		gao(cur+1,sum+a[cur],e);
		if(a[cur]<19)
			gao(cur+1,sum+fac[a[cur]],e+1);
	}
}
int main(){
	fac[0]=1;
	for(int i=1;i<19;++i){
		fac[i]=fac[i-1]*i;
	}
	scanf("%d%d%I64d",&n,&k,&S);
	for(int i=0;i<n;++i)
		scanf("%d",&a[i]);
	lim=n/2;
	gao(0,0,0);
	//for(int i=0;i<30;++i){
	//	cout<<i<<':';
	//	for(int j=0;j<res1[i].size();++j)
	//		cout<<res1[i][j]<<' ';
	//	cout<<endl;
	//}
	reverse(a,a+n);
	lim=n-lim;
	swap(res1,res2);
	gao(0,0,0);
	for(int i=k;i>=0;--i){
		for(int j=0;j<res2[k-i].size();++j){
			++mp[S-res2[k-i][j]];
		}
		for(int j=0;j<res1[i].size();++j){
			ans+=mp[res1[i][j]];
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
