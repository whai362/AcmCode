#include <cstdio>
#include <string.h>
using namespace std;
int fa[50];
int findfa(int x){
	if(fa[x]!=x){
		fa[x]=findfa(fa[x]);
	}
	return fa[x];
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		fa[a]=findfa(a);
		fa[b]=findfa(b);
		if(fa[a]!=fa[b]){
			fa[fa[a]]=fa[b];
		}
	}
	for(int i=1;i<=n;i++){
		fa[i]=findfa(i);
	}
	int cnt[50]={0};
	bool vis[50];
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		  if(fa[j]==i) cnt[i]++;
	}
	bool ok=true;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		if(ok){
			if(!vis[fa[i]]){
			if(cnt[fa[i]]>3){
				ok=false;
				break;
			}
			else if(cnt[fa[i]]<3){
				if(cnt[fa[i]]==2){
					bool ok1=false;
					for(int k=1;k<=n;k++){
						if(!vis[fa[k]]&&cnt[fa[k]]==1){
							vis[fa[k]]=true;
							fa[k]=fa[i];
							ok1=true;
							break;
						}
					}
					if(!ok1){
						ok=false;
						break;
					}
					else{
						cnt[fa[i]]=3;
						vis[fa[i]]=true;
					}
				}
				if(cnt[fa[i]]==1){
					bool ok2=false;
					for(int k=1;k<=n;k++){
						if(!vis[k]&&cnt[k]==2){
							for(int kk=1;kk<=n;kk++){
								if(fa[kk]==k){
									fa[kk]=fa[i];
								}
							}
							vis[k]=true;
							ok2=true;
							break;
						}
					}
					if(!ok2){
						int mm=0;
						for(int k=1;k<=n;k++){
							if(k==i) continue;
							if(cnt[fa[k]]==1&&!vis[fa[k]]){
								vis[fa[k]]=true;
								fa[k]=fa[i];
								mm++;
							}
							if(mm==2){
								ok2=true;
								break;
							}
						}
					}
					if(!ok2){
						ok=false;
						break;
					}
					else{
						cnt[fa[i]]=3;
						vis[fa[i]]=true;
					}
				}
			}
			}
		}
	}
	if(!ok){
		printf("-1\n");
	}
	else{
		for(int i=1;i<=n;i++){
			if(cnt[i]==3){
				int a[3];
				int nn=0;
				for(int j=1;j<=n;j++){
					if(fa[j]==i) a[nn++]=j;
				}
				printf("%d %d %d\n",a[0],a[1],a[2]);
			}
		}
	}
}

