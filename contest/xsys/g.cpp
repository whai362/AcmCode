#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define N 3005
struct stack{
	int v,id;
}s[N];
int top=-1;
struct data{
	int v,l,r;
}d[N];
char pre[N],now[N];
int main(){
	int ans,m,n;
	int i,j;
	while(~scanf("%d%d",&n,&m)){
	ans=0;
	if(n>0 && m>0){
	for(i=1;i<=m;++i){
		d[i].v=1;
	}
	scanf("%s",pre);
	for(i=1;i<n;++i){
		scanf("%s",now);
		for(j=0;j<m;++j){
			if(pre[j]!=now[j]) ++d[j+1].v;
			else d[j+1].v=1;
		}
		top=-1;
		s[++top].v=0;
		s[top].id=0;
		for(j=1;j<=m;++j){
			while(d[j].v<s[top].v){
				d[s[top].id].r=j-1;
				--top;
			}
			if(d[j].v>s[top].v)
				d[j].l=s[top].id;
			else
				d[j].l=d[s[top].id].l;
			s[++top].v=d[j].v;
			s[top].id=j;
		}
		for(j=0;j<=top;++j){
			d[s[j].id].r=m;
		}
		/*for(j=1;j<=m;++j){
			cout<<d[j].v<<' '<<d[j].l<<' '<<d[j].r<<endl;
		}*/
		int tmp=0;
		for(j=1;j<=m;++j){
			if(d[j].r-d[j].l>=d[j].v){
				tmp=max(tmp,d[j].v);
			}
		}
		ans=max(ans,tmp);
		strcpy(pre,now);
	}
	}
	printf("%d\n",ans);
	}
	return 0;
}
