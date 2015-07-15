#include<iostream>
#include<cstdio>
#include<cstring>
#include<tr1/unordered_map>
using namespace std;
using namespace std::tr1;
#define LL __int64
const int INF=0x3f3f3f3f;
const int N=17;
int ans=INF;
unordered_map<LL,int> used,vis,op_cnt;
void gao(int id,LL x,int n){
	int pre_cnt=0;
	while(x){
		LL tmp_x=x;
		for(int i=0;i<=N;++i){
			if(used[tmp_x]==id) break;
			used[tmp_x]=id;
			if(vis[tmp_x]+1<id) break;
			++vis[tmp_x];
			op_cnt[tmp_x]+=i+pre_cnt;
			if(id==n && vis[tmp_x]==n){
				//cout<<tmp_x<<endl;
				ans=min(op_cnt[tmp_x],ans);
			}
			tmp_x*=2;
		}
		x/=2;
		++pre_cnt;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	int n;
	LL a;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a;
		gao(i+1,a,n);
	}
	cout<<ans<<endl;
	return 0;
}
