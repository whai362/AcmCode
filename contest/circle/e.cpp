#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int str[1005];
char s[1005];
int main(){
	for(int i=1;i<=1005;++i){
		str[i]=1;
	}
	for(int i=2;i<=1005;++i){
		for(int j=2;j<=1005;++j){
			if(i*j>1005) break;
			if(str[i*j]) str[i*j]=0;
			else str[i*j]=1;
		}
	}
	int n,T;
	for(int i=1;i<=1000;++i){
		//cout<<str[i]<<endl;
		if(str[i]==0) cout<<i<<' ';
	}
	cout<<endl;
	/*scanf("%d",&T);
	while(T--){
		//scanf("%d",&n);
		scanf("%s",s);
		if(strlen(s)>3) puts("1");
		else{
			sscanf(s,"%d",&n);
			printf("%d\n",str[n]);
		}
	}*/
	return 0;
}
