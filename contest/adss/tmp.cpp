#include<stdio.h>
#include<string.h>
//#include<iostream>
//using namespace std;
int father[100000],r[100000];
int getFather(int x){
	if(father[x]!=x){
		getFather(father[x]);
		r[x]=r[x]^r[father[x]];
		father[x]=father[father[x]];
	}
	return father[x];
}
int main(){
	int i,n,m,a,b,c,fa,fb;
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(father,0,sizeof(father));
		memset(r,0,sizeof(r));
		for(i=1;i<=n;++i) father[i]=i;
		for(i=0;i<m;++i){
			scanf("%d%d%d",&a,&b,&c);
			if(c==0){
				fa=getFather(a);
				fb=getFather(b);
				if(fa!=fb){
					//r[fb]=r[a]^r[b];
					father[fb]=fa;
					if(r[b]==1)r[fb]=r[a]^1;
					else r[fb]=r[a]^0;
				}
				else if(r[a]^r[b]==1) printf("da pian zi\n");
			}
			else if(c==1){
				fa=getFather(a);
				fb=getFather(b);
				if(fa!=fb){
					father[fb]=fa;
					if(r[b]==1) r[fb]=r[a]^0;
					else r[fb]=r[a]^1;
				}
				else if(r[a]^r[b]==0) printf("da pian zi\n");
			}
			else if(c==2){
				fa=getFather(a);
				fb=getFather(b);
				if(fa==fb){
					if(r[a]^r[b]==0) printf("we are a team\n");
					else printf("we are not a team\n");
				}
				else printf("not sure yet\n");
			}
		}
	}
	return 0;
}

