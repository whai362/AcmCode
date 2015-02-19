#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
char str[20];
int tab[10];
int ans[105],cnt;
void get_fac(int x){
	if(x<2) return ;
	int tmp=1;
	for(int i=2;i<=x;++i){
		tmp*=i;
	}
	x=tmp;
	for(int i=2;i<=7;++i){
		while(x%i==0){
			++tab[i];
			x/=i;
		}
	}
	if(x!=1) ++tab[x];
}
void del(int x){
	int lim=sqrt(x);
	for(int i=2;i<=lim;++i){
		while(x%i==0){
			--tab[i];
			x/=i;
		}
	}
	if(x!=1) --tab[x];
}
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",str);
	int len=strlen(str);
	for(int i=0;i<len;++i){
		get_fac(str[i]-'0');
	}
	//for(int i=1;i<10;++i){
	//	cout<<tab[i]<<' ';
	//}
	//cout<<endl;
	for(int j=9;j>=2;--j){
		//cout<<j<<endl;
		for(int k=0;k<tab[j];++k){
			ans[cnt++]=j;
			for(int l=j-1;l>1;--l) del(l);
		}

	}
	for(int i=0;i<cnt;++i){
		printf("%d",ans[i]);
	}
	puts("");
	return 0;
}
