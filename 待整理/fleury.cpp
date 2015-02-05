#include <cstdio>
#include <iostream>
using namespace std;
const int Ni = 505;
const int n = 500;
int eg[Ni][Ni];
int deg[Ni],pos;
int path[Ni*5];
void dfs(int s){
    if(deg[s]){
		for(int i=1;i<=n;i++){
			if(eg[s][i]){
				eg[s][i]--;
				eg[i][s]--;
				deg[s]--;
				deg[i]--;
				dfs(i);
			}
		}
	}
    path[++pos]=s;
}
int main(){
    int i,s,m,u,v;
    while(~scanf("%d",&m)){
        pos=-1;
        for(i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            deg[u]++;deg[v]++;
            eg[u][v]++;
            eg[v][u]++;
        }
        for(i=1;i<=n;i++){
			if(deg[i]){
				s=i;
				break;
			}
		}
        for(;i<=n;i++){
			if(deg[i]&1){
				s=i;
				break;
			}
		}
        dfs(s);
        for(i=pos;i>0;i--)
			printf("%d ",path[i]);
        printf("%d\n",path[0]);
    }
    return 0;
}
