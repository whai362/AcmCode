#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
const int N=1e6+5;
int a[N];
stack<int> s;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
		if(i<n-2) s.push(a[i]);
	}
	if(a[n-1]){ puts("NO"); return 0; }
	int flag=1;
	if(n>1 && a[n-2]==0){
		flag=0;
		while(!s.empty()){
			if(s.top()==0){
				flag=1;
				break;
			}
			s.pop();
		}
	}
	if(flag==0){ puts("NO"); return 0; }
	puts("YES");
	if(n==1){ puts("0"); return 0; }
	printf("(");
	for(int i=0;i<n-2;++i){
		printf("(%d->",a[i]);
	}
	printf("%d",a[n-2]);
	for(int i=0;i<n-2;++i){
		printf(")");
	}
	printf("->%d)",a[n-1]);
	return 0;
}
