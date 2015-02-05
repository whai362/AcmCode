#include<cstdio>
using namespace std;
char a[105][105],c[105],r[105];
int main(){
	int i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%s",a[i]);
	}
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			if(a[i][j]=='.') c[i]=r[j]=1;
		}
	}
	for(i=0;i<n;++i){
		if(!c[i]) break;
	}
	if(i==n){
		for(i=0;i<n;++i){
			for(j=0;j<n;++j){
				if(a[i][j]=='.' && c[i]==1) printf("%d %d\n",i+1,j+1),c[i]=0;
			}
		}
	}
	else{
		for(i=0;i<n;++i){
			if(!r[i]) break;
		}
		if(i==n){
			for(i=0;i<n;++i){
				for(j=0;j<n;++j){
					if(a[i][j]=='.' && r[j]==1) printf("%d %d\n",i+1,j+1),r[j]=0;
				}
			}
		}
		else printf("-1\n");
	}
	return 0;
}
