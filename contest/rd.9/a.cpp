#include<cstdio>
#include<algorithm>
using namespace std;
struct rank{
	int p,t;
}r[55];
bool cmp(rank r1,rank r2){
	if(r1.p>r2.p) return 1;
	else if(r1.p==r2.p && r1.t<r2.t) return 1;
	return 0;
}

int main(){
	int count=0,i,n,k,p,t;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;++i)
	  scanf("%d%d",&r[i].p,&r[i].t);
	sort(r,r+n,cmp);
	p=r[k-1].p,t=r[k-1].t;
	for(i=0;i<n;++i)
	  if(r[i].p==p && r[i].t==t) ++count;
	printf("%d\n",count);
	return 0;
}
