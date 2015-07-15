#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e6+4;
int a[N];
int L[N],R[N];
int vis[N];
int cnt[N];
void gao(int n){
	int _max=0;
	for(int i=0;i<n;++i){
		++cnt[a[i]];
		_max=max(_max,cnt[a[i]]);
		if(vis[a[i]]==0){
			L[a[i]]=R[a[i]]=i+1;
			vis[a[i]]=1;
		}
		else{
			R[a[i]]=i+1;
		}
	}
	//for(int i=0;i<5;++i){
	//	cout<<L[i]<<' '<<R[i]<<endl;
	//}
	int ans_L,ans_R,_min=N;
	for(int i=0;i<N;++i){
		if(L[i]==0) continue;
		if(cnt[i]!=_max) continue;
		if(R[i]-L[i]<_min){
			_min=R[i]-L[i];
			ans_L=L[i];
			ans_R=R[i];
		}
	}
	cout<<ans_L<<' '<<ans_R<<endl;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	gao(n);
	return 0;
}
