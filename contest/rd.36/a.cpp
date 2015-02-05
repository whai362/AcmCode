#include<cstdio>
#include<algorithm>
using namespace std;
struct data{
	int x,y;
}d[1005];
bool cmp(data a,data b){
	return a.x<b.x;
}
int main(){
	int i,s,n;
	scanf("%d%d",&s,&n);
	for(i=0;i<n;++i)
	  scanf("%d%d",&d[i].x,&d[i].y);
	sort(d,d+n,cmp);
	for(i=0;i<n;++i){
		if(s>d[i].x) s+=d[i].y;
		else break;
	}
	if(i==n) printf("YES\n");
	else printf("NO\n");
	return 0;
}
