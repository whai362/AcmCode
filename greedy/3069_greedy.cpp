#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1005;
int r,n;
int a[N];
int main(){
	while(scanf("%d%d",&r,&n) && (r!=-1 || n!=-1)){
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		int i=0,ans=0;
		while(i<n){
			int s=a[i++];
			while(i<n && a[i]<=s+r) ++i;
			int p=a[i-1];
			while(i<n && a[i]<=p+r) ++i;
			++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}
