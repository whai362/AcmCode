#include<cstdio>
#include<stack>
using namespace std;
int main(){
	int i,j,n,arr[100005],T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		while(1){
			stack<int> s;
			for(i=0;i<n;++i){
				scanf("%d",&arr[i]);
				if(!arr[i]) break;
			}
			if(!arr[0]) break;
			j=0;
			for(i=1;i<=n;++i){
				s.push(i);
				while(!s.empty() && s.top()==arr[j]) s.pop(),++j;
			}
			if(s.empty()) printf("Yes\n");
			else printf("No\n");
		}
		printf("\n");
	}
	return 0;
}
