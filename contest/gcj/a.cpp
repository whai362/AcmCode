#include<iostream>
#include<cstdio>
using namespace std;
char str[1005];
int main(){
	int T;
	int cas=0;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		scanf("%s",str);
		int ans=0;
		int st=0;
		for(int i=0;i<=n;++i){
			if(st>=i){
				st+=str[i]-'0';
			}
			else{
				ans+=i-st;
				st=i+str[i]-'0';
			}
			//cout<<st<<endl;
		}
		printf("Case #%d: %d\n",++cas,ans);
	}
	return 0;
}
