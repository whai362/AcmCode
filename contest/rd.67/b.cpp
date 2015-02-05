#include<cstdio>
#include<stack>
#include<iostream>
using namespace std;
int a[50],c[50],g[50][50];
int main(){
	int i,j,n,m,p1,p2,cnt=0,cnt1=1,f=0;
	stack<int> s;
	scanf("%d%d",&n,&m);
	if(m==0){
		for(i=1;i<=n;++i){
			if(i%3) printf("%d ",i);
			else printf("%d\n",i);
		}
	}
	else{
	for(i=0;i<m;++i){
		scanf("%d%d",&p1,&p2);
		if(!f){
			if(!a[p1] && !a[p2]) a[p1]=a[p2]=cnt1++;
			else if(!a[p1] && a[p2]) a[p1]=a[p2];
			else if(a[p1] && !a[p2]) a[p2]=a[p1];
			else if(a[p1]!=a[p2]) f=1;
		}
	}
	for(i=1;i<=n;++i)
	  if(a[i]==0) s.push(i);
	for(i=1;i<cnt1;++i){
		for(j=1;j<=n;++j){
			if(a[j]==i) ++g[i][0],g[i][g[i][0]]=j;
		}
		++c[g[i][0]];
	}
	for(i=4;i<=n;++i)
	  if(c[i]){
		  f=1;
		  break;
	  }
	if(f || (cnt1-1)*3>n) printf("-1\n");
	else{
		for(i=1;i<cnt1;++i){
			if(g[i][0]==3) printf("%d %d %d\n",g[i][1],g[i][2],g[i][3]);
			else if(g[i][0]==2) printf("%d %d %d\n",g[i][1],g[i][2],s.top()),s.pop();
			else if(g[i][0]==1){
				printf("%d ",g[i][1]);
				printf("%d ",s.top()),s.pop();
				printf("%d\n",s.top()),s.pop();
			}
		}
	}
	}
	return 0;
}
