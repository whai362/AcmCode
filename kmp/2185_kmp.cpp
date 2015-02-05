#include<iostream>
#include<cstdio>
using namespace std;
const int R=10005,
	  C=100;
char str[R][C];
int r,c,
	nex1[R],
	nex2[C];
bool ok1(int a,int b){
	bool flag=true;
	for(int i=0;i<c;++i){
		if(str[a][i]!=str[b][i]){
			flag=false;
			break;
		}
	}
	return flag;
}
bool ok2(int a,int b){
	bool flag=true;
	for(int i=0;i<r;++i){
		if(str[i][a]!=str[i][b]){
			flag=false;
			break;
		}
	}
	return flag;
}
int main(){
	scanf("%d%d",&r,&c);
	for(int i=0;i<r;++i){
		scanf("%s",str[i]);
	}
	int i,j,ans;
	i=0;
	j=nex1[0]=-1;
	while(i<r){
		if(j==-1 || ok1(i,j))
			nex1[++i]=++j;
		else
			j=nex1[j];
	}
	ans=r-nex1[r];
	i=0;
	j=nex2[0]=-1;
	while(i<c){
		if(j==-1 || ok2(i,j))
			nex2[++i]=++j;
		else
			j=nex2[j];
	}
	ans*=(c-nex2[c]);
	printf("%d\n",ans);
	return 0;
}
