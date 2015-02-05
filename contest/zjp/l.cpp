#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct data{
	int t,id;
}d[20005];
int ans[20005];
bool cmp(data d1,data d2){
	return d1.t<d2.t;
}
int main(){
	int cnt,bef,cur,h,m,s,n,l,T;
	int i;
	char t[50];
	scanf("%d",&T);
	while(T--){
	scanf("%d%d",&n,&l);
	cnt=0;
	for(i=0;i<n;++i){
		scanf("%s",t);
		sscanf(t,"%d:%d:%d",&h,&m,&s);
		d[i].t=h*60*60+m*60+s;
		d[i].id=i+1;
	}
	sort(d,d+n,cmp);
	for(i=0;i<n;++i){
		cur=d[i].t;
		if(i==0 || cur>=bef+l){
			ans[cnt++]=d[i].id;
			bef=cur;
		}
	}
	sort(ans,ans+cnt);
	printf("%d\n",cnt);
	printf("%d",ans[0]);
	for(i=1;i<cnt;++i){
		printf(" %d",ans[i]);
	}
	printf("\n");
	}
	return 0;
}
