#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s1[]="***********  ******  ******  **** **** ** *  * ** *  * *********";
char ans[20][1050][1050];
int hash[2000];
int main(){
	int n;
	memset(ans,' ',sizeof(ans));
	memset(hash,0,sizeof(hash));
	for(int i=0;i<8;++i){
		for(int j=0;j<8;++j){
			ans[0][i][j]=s1[i*8+j];
		}
		ans[0][i][8]=0;
	}	
	int lim=8;
	hash[8]=0;
	for(int i=1;i<8;++i){
		lim*=2;
		hash[lim]=i;
		for(int j=0;j<lim;++j){
			ans[i][0][j]=ans[i][lim-1][j]=ans[i][j][0]=ans[i][j][lim-1]='*';
			ans[i][j][lim]=0;
		}
		for(int j=lim/2;j<lim;++j){
			for(int k=lim/4;k<lim*3/4;++k){
				if(ans[i-1][lim-j-1][k-lim/4]=='*')ans[i][j][k]=ans[i-1][lim-j-1][k-lim/4];
			}
		}
		for(int j=lim/8;j<lim/8+lim/4-1;++j){
			ans[i][lim/8][j]=ans[i][lim/8+lim/4][j]='*';
		}
		for(int j=lim/8+lim/4+lim/4;j<lim/8+lim/2+lim/4-1;++j){
			ans[i][lim/8][j]=ans[i][lim/8+lim/4][j]='*';
		}
		for(int j=lim/8;j<=lim/8+lim/4;++j){
			ans[i][j][lim/8]=ans[i][j][lim/8+lim/4-1]=ans[i][j][lim/8+lim/2]=ans[i][j][lim/8+lim/2+lim/4-1]='*';
		}
	}
	while(scanf("%d",&n)){
		if(n<8) break;
		int id=hash[n];
		for(int i=0;i<n;++i){
			puts(ans[id][i]);
		}
		puts("");
	}
	return 0;
}
