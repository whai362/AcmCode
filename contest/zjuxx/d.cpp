#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
struct emp{
	string id,date;
	int s,i;
}e[2005];
int ans[2005],rank[7];
bool cmp(emp e1,emp e2){
	if(e1.s>e2.s || (e1.s==e2.s && e1.date<e2.date)) return 1;
	return 0;
}
int main(){
	int i,j,n,cnt,t;
	cin>>t;
	while(t--){
		cin>>n;
		cnt=0;
		for(i=0;i<n;++i){
			cin>>e[i].id>>e[i].date>>e[i].s;
			e[i].i=i;
		}
		for(i=0;i<n;++i){
			if(e[i].s>0) ++cnt;
		}
		rank[6]=cnt*0.03;
		rank[5]=rank[6]+cnt*0.07;
		rank[4]=rank[5]+cnt*0.2;
		rank[3]=rank[4]+cnt*0.3;
		sort(e,e+n,cmp);
		j=0;
		for(i=6;i>=3;--i){
			for(;j<rank[i];++j){
				ans[e[j].i]=i;
			}
		}
		for(;j<n;++j){
			if(e[j].s>0) ans[e[j].i]=2;
			else ans[e[j].i]=1;
		}
		for(i=0;i<n;++i){
			cout<<"LV"<<ans[i]<<endl;
		}
	}
	return 0;
}
