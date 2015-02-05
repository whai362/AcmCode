#include<cstdio>
#include<queue>
using namespace std;
#define N 100005
//int q[N],a[N];
int main(){
	int a,ans=0,i,n,m,q,mq=0x3f3f3f3f;
	priority_queue<int> aq;
	scanf("%d",&m);
	for(i=0;i<m;++i){
		scanf("%d",&q);
		if(q<mq) mq=q;
	}
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",&a);
		aq.push(a);
	}
	while(!aq.empty()){
		for(i=0;i<mq;++i){
			if(!aq.empty()){
				ans+=aq.top();
				aq.pop();
			}
			else break;
		}
		for(i=0;i<2;++i){
			if(!aq.empty())
				aq.pop();
			else break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
