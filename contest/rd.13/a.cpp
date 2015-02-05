#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int hash[205];
struct zhiling{
	int a,b;
}z;
queue<zhiling> q;
void in(int a){
	int i;
	for(i=a+1;i<205;++i){
		if(hash[i]){
			z.a=i;
			z.b=a;
			q.push(z);
			hash[i]=0;
			return ;
		}
	}
	return ;
}
void swap(int a){
	int i,j,tmp;
	for(i=a+1;i<205;++i){
		if(hash[i] && hash[i]==hash[a-1]){
			for(j=a+1;j<205;++j) if(!hash[j]) break;
			tmp=hash[i];
			hash[i]=hash[a];
			hash[a]=tmp;
			z.a=a;
			z.b=j;
			q.push(z);
			z.a=i;
			z.b=a;
			q.push(z);
			z.a=j;
			z.b=i;
			q.push(z);
			return ;
		}
	}
	return ;
}
int main(){
	int d,i,j,m,n,ni;
	scanf("%d%d",&n,&m);
	memset(hash,0,sizeof(hash));
	for(i=0;i<m;++i){
		scanf("%d",&ni);
		for(j=0;j<ni;++j){
			scanf("%d",&d);
			hash[d]=ni;
		}
	}
	for(i=1;i<205;++i){
		if(!hash[i]) in(i);
		else{
			if(i!=1 && hash[i]!=hash[i-1]) swap(i);
		}
	}
	printf("%d\n",q.size());
	while(!q.empty()){
		z=q.front();
		q.pop();
		printf("%d %d\n",z.a,z.b);
	}
	return 0;
}
