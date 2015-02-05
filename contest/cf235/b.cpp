#include<cstdio>
using namespace std;
int cf[4005];
int main(){
	int _max,_min,c1,c2,i,j,x,k,op;
	scanf("%d%d",&x,&k);
	_max=_min=0;
	cf[x]=1;
	for(i=0;i<k;++i){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&c1,&c2);
			cf[c1]=cf[c2]=1;
		}
		else{
			scanf("%d",&c1);
			cf[c1]=1;
		}
	}
	int cnt;
	for(i=1;i<=x;++i){
		cnt=0;
		for(j=i;cf[j]!=1 && j<=x;++j)
			++cnt;
		_max+=cnt;
		if(cnt%2) _min+=cnt/2+1;
		else _min+=cnt/2;
		i=j;
	}
	printf("%d %d\n",_min,_max);
	return 0;
}
