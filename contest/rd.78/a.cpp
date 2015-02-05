#include<cstdio>
#include<cstring>
using namespace std;
char a[15][15];
int main(){
	int i,j,r,c,cnt=0;
	scanf("%d%d",&r,&c);
	for(i=0;i<r;++i){
		scanf("%s",a[i]);
	}
	for(i=0;i<r;++i){
		for(j=0;j<c;++j){
			if(a[i][j]=='S') break;
		}
		if(j==c){
			for(j=0;j<c;++j){
				if(a[i][j]) ++cnt,a[i][j]=0;
			}
		}
	}
	for(i=0;i<c;++i){
		for(j=0;j<r;++j){
			if(a[j][i]=='S') break;
		}
		if(j==r){
			for(j=0;j<r;++j){
				if(a[j][i]) ++cnt,a[j][i]=0;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}
