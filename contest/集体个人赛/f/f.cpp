#include<stdio.h>
#include<string.h>
int f[110][110];
int main(){
	int i,j,l,a,b,t,n,m,k,cmp=0,count=0,ans=0;
	scanf("%d",&t);
	while(t--){
		cmp=0,count=0,ans=0;
		memset(f,0,sizeof(f));
		scanf("%d%d%d",&n,&m,&k);
		for(i=0;i<m;++i){
			scanf("%d%d",&a,&b);
			f[a][b]=1;
			f[b][a]=1;
		}
		while(1){
			for(i=0;i<n-1;++i){
				for(j=i+1;j<n;++j){
					if(f[i][j]) continue;
					count=0;
					for(l=0;l<n;++l){
						if(f[i][l]&&f[j][l]) ++count;
					}	
					if(count>=k){
						++ans;
						f[i][j]=1;
						f[j][i]=1;	
					}
				}
			}
			if(ans==cmp) break;
			cmp=ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}
