#include<cstdio>
#include<cstring>
using namespace std;
bool pa[700];
int main(){
	int i,flag=0,x,t,a,b,da,db,tmp;
	scanf("%d%d%d%d%d%d",&x,&t,&a,&b,&da,&db);
	memset(pa,0,sizeof(pa));
	pa[0]=1;
	for(i=0;i<t;++i)
	  pa[a-da*i]=1;
	for(i=0;i<t;++i){
		tmp=x-(b-db*i);
		if(tmp>=0 && tmp<=x && pa[x-(b-db*i)] || pa[x]){
			flag=1;
			break;
		}
	}
	if(flag) printf("YES\n");
	else if(x==0) printf("YES\n");
	else printf("NO\n");
	return 0;
}
