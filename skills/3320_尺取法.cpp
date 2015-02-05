#include<iostream>
#include<cstdio>
#include<set>
#include<map>
using namespace std;
const int P=1000005,
	  INF=0x3f3f3f3f;
int p;
int a[P];
void gao(){
	set<int> _set;
	for(int i=0;i<p;++i){
		_set.insert(a[i]);
	}
	int n=_set.size();
	int ans=INF,i=0,j=0,sum=0;
	map<int,int> _count;
	while(1){
		while(i<p && sum<n){
			if(_count[a[i]]==0){
				++sum;
			}
			++_count[a[i++]];
		}
		if(sum<n) break;
		ans=min(ans,i-j);
		--_count[a[j]];
		if(_count[a[j++]]==0)
			--sum;
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&p);
	for(int i=0;i<p;++i){
		scanf("%d",&a[i]);
	}
	gao();
	return 0;
}
