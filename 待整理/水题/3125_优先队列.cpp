#include<stdio.h>
#include<queue>
using namespace std;
int main(){
	int a,i,m,n,t,tmp,time;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		queue<int> q;
		priority_queue<int> pq;
		for(i=0;i<n;++i){
			scanf("%d",&a);
			q.push(a);
			pq.push(a);
		}
		time=1;
		while(1){
			tmp=q.front();
			q.pop();
			if(tmp==pq.top()){
				pq.pop();
				if(m==0) break;
				++time;
			}
			else q.push(tmp);
			--m;
			if(m<0) m=q.size()-1;
		}
		printf("%d\n",time);
	}
	return 0;
}
