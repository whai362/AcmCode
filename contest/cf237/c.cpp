#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct data{
	int p,id;
}d[100005];
bool cmp(data a,data b){
	return a.p<b.p;
}
int ok(int a,int b){
	if(a%b==0) return a/b;
	else return a/b+1;
}
int ans[100005][2],hash[100005];
int main(){
	int i,j,k1,l,_max,n,k,flag=1;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;++i){
		scanf("%d",&d[i].p);
		d[i].id=i+1;
	}
	sort(d,d+n,cmp);
	int cnt=0,p=0;
	hash[0]=1;
	for(i=1;i<n;++i){
		++hash[d[i].p];
	}
	_max=d[n-1].p;
	int tmp,tmp1=0,count=0;
	for(i=1;i<=_max;++i){
		if(hash[i-1]){
			tmp=ok(hash[i],hash[i-1]);
			if(tmp<=k){
				for(j=tmp1,k1=tmp1+hash[i-1];j<tmp1+hash[i-1],k1<tmp1+hash[i-1]+hash[i];++j){
					for(l=0;l<tmp;++l){
						ans[count][0]=d[j].id;
						ans[count++][1]=d[k1++].id;
						if(k1>=tmp1+hash[i-1]+hash[i]) break;
					}
				}
				tmp1=tmp1+hash[i-1];
			}
			else flag=0;
		}
		else flag=0;
		if(flag==0) break;
	}
	if(flag && count){
		printf("%d\n",count);
		for(i=0;i<count;++i){
			printf("%d %d\n",ans[i][0],ans[i][1]);
		}
	}
	else printf("-1\n");
	return 0;
}
