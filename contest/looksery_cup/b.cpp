#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
char str[105][105];
int a[105];
int b[105];
vector<int> ans;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%s",str[i]);
	}
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	memset(b,0,sizeof(b));
	ans.clear();
	while(1){
		int id=-1;
		for(int i=0;i<n;++i){
			if(b[i]==a[i]){
				id=i;
				break;
			}
		}
		if(id==-1) break;
		ans.push_back(id+1);
		for(int j=0;j<n;++j){
			if(str[id][j]=='1')
				b[j]++;
		}
	}
	sort(ans.begin(),ans.end());
	int sz=ans.size();
	printf("%d\n",sz);
	for(int i=0;i<sz;++i)
		printf("%d ",ans[i]);
	return 0;
}


