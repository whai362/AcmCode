#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int ans=(m-1)%n;
		printf("%d\n",ans);
	}
	return 0;
}
