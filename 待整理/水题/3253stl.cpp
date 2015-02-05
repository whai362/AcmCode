#include<stdio.h>
#include<queue>
using namespace std;
struct stick{
	__int64 l;
	bool operator < (const stick &other) const{
		return l>other.l;
	}
};
int main(){
	int i,n;
	__int64 sum;
	stick s,a,b;
	priority_queue<stick> q;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;++i) scanf("%I64d",&s.l),q.push(s);
		sum=0;
		while(q.size()!=1){
			a=q.top();
			q.pop();
			b=q.top();
			q.pop();
			a.l=a.l+b.l;
			sum=sum+a.l;
			q.push(a);
		}
		printf("%I64d\n",sum);
		while(!q.empty()) q.pop();
	}
	return 0;
}
