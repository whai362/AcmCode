#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define N 10005
struct jia{
	int p,f;
}ji[N];
bool cmp(jia a,jia b){
	return a.p>b.p;
}
int main(){
	int cnt,i,n,p,f;
	scanf("%d",&n);
	cnt=0;
	priority_queue<int> q;
	for(i=0;i<n;++i){
		scanf("%d%d",&ji[i].p,&ji[i].f);
	}
	scanf("%d%d",&p,&f);
	sort(ji,ji+n,cmp);
	i=0;
	int flag=1;
	while(p-f>0 && i<n){
		p=p-f;
		f=0;
		for(;i<n;++i){
			if(ji[i].p<p) break;
			else q.push(ji[i].f);
		}
		if(!q.empty()) f=q.top(),q.pop();
		else{
			flag=0;
			break;
		}
		++cnt;
	}
	if(flag) printf("%d\n",cnt);
	else printf("-1\n");
	return 0;
}
