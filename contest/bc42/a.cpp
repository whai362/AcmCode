#include<iostream>
#include<cstdio>
using namespace std;
int a[35][35];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int ans=0;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j){
				scanf("%d",&a[i][j]);
				if(a[i][j]) ++ans;
			}
		ans+=2*n;
		printf("%d\n",ans);
	}
	return 0;
}
