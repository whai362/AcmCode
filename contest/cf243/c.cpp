#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
#define N 105
int n,k;
int a[N];
int gao(int l,int r){
	int i,sum=0;
	priority_queue< int,vector<int>,less<int> > h1;
	priority_queue< int,vector<int>,greater<int> > h2;
	priority_queue< int,vector<int>,greater<int> > h3;
	for(i=0;i<l;++i){
		h1.push(a[i]);
	}
	for(i=r+1;i<n;++i){
		h1.push(a[i]);
	}
	for(i=l;i<=r;++i){
		sum+=a[i];
		h2.push(a[i]);
	}
	int tmp,cnt=0;
	while(cnt<k && !h1.empty() && !h2.empty()){
		tmp=h1.top();
		sum+=tmp;
		h3.push(tmp);
		tmp=h2.top();
		h3.push(tmp);
		h1.pop();
		h2.pop();
		++cnt;
	}
	int _max=sum;
	for(i=0;i<cnt;++i){
		sum-=h3.top();
		if(sum>_max) _max=sum;
		h3.pop();
	}
	return _max;
}
int main(){
	int i;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	int ans=-100005,l,r;
	for(l=0;l<n;++l){
		for(r=l;r<n;++r){
			ans=max(ans,gao(l,r));
		}
	}
	printf("%d\n",ans);
	return 0;
}
