#include<stdio.h>
#include<queue>
using namespace std;
int main(){
    int i,n;
	long long ans,a,b,s;
	priority_queue<long long> q;
	scanf("%d",&n);
	ans=0;
	for(int i=0;i<n;++i){
		scanf("%lld",&s);
	    q.push(-s);
	}
	while (q.size()>1){
		a=q.top();
		q.pop();
	    b=q.top();
	    q.pop();
	    ans+=a+b;
	    q.push(a+b);
	}
	printf("%lld\n",-ans);
	return 0;
}

