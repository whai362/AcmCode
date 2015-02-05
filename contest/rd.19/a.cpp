#include<cstdio>
#include<stack>
using namespace std;
int main(){
	int a0,a1,n;
	stack<int> s;
	scanf("%d",&n);
	if(n==0) printf("%d %d %d\n",0,0,0);
	else if(n==1) printf("%d %d %d\n",1,0,0);
	else if(n==2) printf("%d %d %d\n",1,1,0);
	else{
	a0=0,a1=1;
	s.push(0);
	s.push(1);
	while(a0+a1<n){
		s.push(a0+a1);
		a0=a1;
		a1=s.top();
	}
	if(a0+a1==n){
	printf("%d ",s.top());
	s.pop();
	s.pop();
	printf("%d ",s.top());
	s.pop();
	printf("%d\n",s.top());
	}
	else printf("I'm too stupid to solve this problem\n");
	}
	return 0;
}
