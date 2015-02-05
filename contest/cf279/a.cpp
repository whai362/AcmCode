#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> v[4];
int main(){
	int n;
	int a;
	scanf("%d",&n);
	int cnt=0x3f3f3f3f;
	for(int i=1;i<=n;++i){
		scanf("%d",&a);
		v[a].push_back(i);
	}
	for(int i=1;i<=3;++i){
		int sz=v[i].size();
		cnt=min(sz,cnt);
	}
	printf("%d\n",cnt);
	for(int i=0;i<cnt;++i){
		printf("%d %d %d\n",v[1][i],v[2][i],v[3][i]);
	}
	return 0;
}
