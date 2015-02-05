#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int ans,d,n,m,flag;
	vector<int> v;
	while(scanf("%d%d",&n,&m)!=EOF){
	ans=0;
	flag=0;
	v.clear();
	for(int i=0;i<n;++i){
		scanf("%d",&d);
		if(d==0){
			flag=1;
		}
		v.push_back(d);
		v.push_back(2000+2000-d);
	}
	if(flag==0){
		v.push_back(4000);
	}
	int sz=v.size();
	sort(v.begin(),v.begin()+sz);
	if(flag==0){
		ans=v[0];
	}
	for(int i=1;i<sz;++i){
		if(v[i]-v[i-1]>200){
			ans+=v[i]-v[i-1]-200;
		}
	}
	if(ans>m){
		printf("HeHe~\n");
	}
	else{
		printf("HaHa~\n");
	}
	}
	return 0;
}
