#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[5005],b[5005];
int f(int x){
	int i,f1=0,f2=0,t;
	if(x==1) return 0;
	for(i=2;i*i<=x;++i){
		if(x%i==0){
			f1=1;
			t=i;
			break;
		}
	}
	if(f1==0){
		for(i=0;i<m;++i){
			if(x==b[i]){
				f2=1;
				break;
			}
		}
		if(f2) return -1;
		else return 1;
	}
	else{
		for(i=0;i<m;++i){
			if(t==b[i]){
				f2=1;
				break;
			}
		}
		if(f2) return f(x/t)-1;
		return f(x/t)+1;
	}
}
bool ok(int t){
	int i,flag=0;
	for(i=0;i<m;++i){
		if(t==b[i]){
			flag=1;
			break;
		}
	}
	return flag;
}
int main(){
	int ans,i,j,p1;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	p1=0;
	for(i=0;i<m;++i){
		scanf("%d",&b[i]);
	}
	for(i=2;i*i<=a[0];++i){
		if(a[0]%i==0 && ok(i)){
			for(j=0;j<n;++j){
				if(a[j]%i==0)
					a[j]/=i;
				else break;
			}
			--i;
		}
	}
	if(n>1){
	int tmp;
	while((tmp=__gcd(a[0],a[1]))!=1){
		if(!ok(tmp)) break;
		for(i=0;i<n;++i){
			if(a[i]%tmp==0) a[i]/=tmp;
			else break;
		}
	}
	}
	ans=0;
	for(i=0;i<n;++i){
		ans+=f(a[i]);
	}
	printf("%d\n",ans);
	return 0;
}
