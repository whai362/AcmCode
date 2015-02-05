#include<stdio.h>
#include<queue>
using namespace std;
int main(){
	int ans,i,g,gg,l1,l2,l3,max,n,size,c[15];
	while(scanf("%d",&n)&&n){
		priority_queue<int> l;
		max=0;
		for(i=0;i<n;++i){
			scanf("%d",&c[i]);
			if(c[i]>max) max=c[i];
		}
		scanf("%d",&g);
		ans=max/50;
		if(max%50!=0) ++ans,max=ans*50;
		for(i=0;i<n;++i) l.push(max-c[i]);
		l1=l.top();
		l.pop();
		l2=l.top();
		l.pop();
		l3=l.top();
		l.pop();
		gg=0;
		while(gg<g){
			if(l3==0){
				size=l.size();
				for(i=0;i<size;++i){
					c[i]=l.top();
					l.pop();
				}
				for(i=0;i<size;++i)
				  l.push(c[i]+50);
				l1+=50;
				l2+=50;
				l3+=50;
				++ans;
			}
			gg=gg+1;
			l.push(l1-1);
			l.push(l2-1);
			l.push(l3-1);
			l1=l.top();
			l.pop();
			l2=l.top();
			l.pop();
			l3=l.top();
			l.pop();
		}
		printf("%d\n",ans);
	}
	return 0;
}
