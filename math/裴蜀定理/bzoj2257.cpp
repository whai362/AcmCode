#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include<cstring>
using namespace std;
const int MOD=1717;
map<int,int> val[MOD];
struct Hash{
	void insert(int x){
		int bl=x%MOD;
		++val[bl][x];
	}
	int query(int x){
		int bl=x%MOD;
		return val[bl][x];
	}
}hs;

int ans=1;
void gao(int x,int k){
	int lim=sqrt(x);
	for(int i=1;i<=lim;++i){
		if(x%i==0){
			hs.insert(i);
			int cnt=hs.query(i);
			if(cnt>=k) ans=max(ans,i);
			int tmp=x/i;
			if(tmp!=i){
				hs.insert(tmp);
				cnt=hs.query(tmp);
				if(cnt>=k) ans=max(ans,tmp);
			}
		}
	}
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int a;
	for(int i=0;i<n;++i){
		scanf("%d",&a);
		gao(a,k);
	}
	printf("%d\n",ans);
}
