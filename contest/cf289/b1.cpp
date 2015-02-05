#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int _max[105],_min[105],tab[105],ans[105][105],a[105];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	memset(_min,0x3f,sizeof(_min));
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
		int cnt=0;
		memset(tab,0,sizeof(tab));
		for(int j=0;j<a[i];++j){
			ans[i][j]=cnt+1;
			++tab[cnt+1];
			++cnt;
			cnt%=m;
		}
		for(int i=1;i<=m;++i){
			_max[i]=max(_max[i],tab[i]);
			_min[i]=min(_min[i],tab[i]);
		}
	}
	int flag=1;
	for(int i=1;i<=m;++i){
		if(_max[i]-_min[i]>1){ flag=0; break; }
	}
	if(flag){
		puts("YES");
		for(int i=0;i<n;++i){
			for(int j=0;j<a[i];++j){
				printf("%d%c",ans[i][j],j==a[i]-1?'\n':' ');
			}
		}
	}
	else puts("NO");
	return 0;
}
