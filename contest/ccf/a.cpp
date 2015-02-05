#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int hash[10005];
int main(){
	int n;
	int a;
	scanf("%d",&n);
	int _max=0,ans=10005;
	for(int i=0;i<n;++i){
		scanf("%d",&a);
		++hash[a];
		if(hash[a]>_max){
			_max=hash[a];
			ans=a;
		}
		else if(hash[a]==_max && a<ans){
			ans=a;
		}
	}
	printf("%d\n",ans);
	return 0;
}
