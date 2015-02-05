#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int M=123456;
int main(){
	int n,T;
	int a;
	scanf("%d",&T);
	while(T--){
	scanf("%d",&n);
	priority_queue< int,vector<int>,greater<int> > q;
	for(int i=0;i<n;++i){
		scanf("%d",&a);
		q.push(a);
	}
	int ans=0,tmp;
	while(q.size()>1){
		tmp=q.top();
		q.pop();
		tmp+=q.top();
		q.pop();
		ans=(ans+tmp)%M;
		q.push(tmp);
	}
	printf("%d\n",ans);
	}
	return 0;
}
