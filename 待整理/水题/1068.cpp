#include<stdio.h>
#include<stack>
#include<queue>
using namespace std;
int main(){
	int i,j,n,p,sum,t,tmp;
	stack<int> s;
	queue<int> ans;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		tmp=0;
		for(i=0;i<n;++i){
			scanf("%d",&p);
			for(j=0;j<p-tmp;++j) s.push(0);
			if(s.top()==0) s.pop(),s.push(1);
			else{
				sum=0;
				while(s.top()){
					sum=sum+s.top();
					s.pop();
				}
				s.pop();
				s.push(sum+1);
			}
			tmp=p;
			ans.push(s.top());
		}
		s.pop();
		while(!ans.empty()) printf("%d ",ans.front()),ans.pop();
		printf("\n");
	}
	return 0;
}
