#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int main(){
	int n,m,T;
	long long a;
	while(scanf("%d%d",&n,&m)!=EOF){
	priority_queue< long long,vector<long long>,greater<long long> > q1;
	priority_queue< long long,vector<long long>,less<long long> > q2;
	for(int i=0;i<n;++i){
		scanf("%lld",&a);
		q1.push(a);
		q2.push(a);
	}
	long long t1,t2,t3;
	while(q.size()>m){
		t1=q1.top();
		q1.pop();
		t2=q1.top();
		q1.pop();
		t3=q2.top();
		q2.pop();
		if(t1+t2<q1.top()){
			q1.push(t2);
			q1.push(
		}
	}
	printf("%lld\n",q.top());
	}
	return 0;
}
