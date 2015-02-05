#include<cstdio>
#include<iostream>
using namespace std;
char m[305][305];
int main(){
	int i,j,n,flag=1;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%s",m[i]);
	}
	if(m[0][0]==m[0][1]) flag=0;
	char c=m[0][0];
	for(i=0;i<n;++i){
		if(m[i][i]!=c){
			flag=0;
			break;
		}
		if(m[i][n-i-1]!=c){
			flag=0;
			break;
		}
	}
	c=m[0][1];
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			if(i==j || i==n-j-1) continue;
			if(m[i][j]!=c){
				//cout<<i<<' '<<j<<endl;
				flag=0;
				break;
			}
		}
	}
	if(flag) printf("YES\n");
	else printf("NO\n");
	return 0;
}
