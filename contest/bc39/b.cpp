#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int N=10005;
int tab[N];
int a[N];
void fc(int x,int id){
	int lim=sqrt(x);
	for(int i=1;i<=lim;++i){
		if(x%i==0){
			tab[i]=id;
			tab[x/i]=id;
		}
	}
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(tab,0,sizeof(tab));
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		int ans=0;
		for(int i=n-1;i>=0;--i){
			ans+=tab[a[i]];
			fc(a[i],i+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}
