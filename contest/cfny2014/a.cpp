#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int N=1000005;
int to[N];
int main(){
	int n,t;
	scanf("%d%d",&n,&t);
	int a;
	for(int i=1;i<n;++i){
		scanf("%d",&a);
		to[i]=i+a;
	}
	int p=1;
	int flag=0;
	while(to[p]){
		if(to[p]==t){
			flag=1;
			break;
		}
		else p=to[p];
		//cout<<p<<endl;
	}
	if(flag) puts("YES");
	else puts("NO");
	return 0;
}
