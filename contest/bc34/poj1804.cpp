#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define LL __int64
vector<int> A;
LL merge_count(vector<int> &a){
	int n=a.size();
	if(n<=1) return 0;
	LL cnt=0;
	vector<int> b(a.begin(),a.begin()+n/2);
	vector<int> c(a.begin()+n/2,a.end());
	cnt+=merge_count(b);
	cnt+=merge_count(c);
	int ai=0,bi=0,ci=0;
	while(ai<n){
		if(bi<b.size() && (ci==c.size() || b[bi]<=c[ci]))
			a[ai++]=b[bi++];
		else{
			cnt+=(LL)(n/2-bi);
			a[ai++]=c[ci++];
		}
	}
	return cnt;
}
int main(){
	int T;
	int n;
	int a;
	int cas=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		A.clear();
		for(int i=0;i<n;++i){
			scanf("%d",&a);
			A.push_back(a);
		}
		LL ans=merge_count(A);
		printf("Scenario #%d:\n",++cas);
		cout<<ans<<endl<<endl;
	}
	return 0;
}
