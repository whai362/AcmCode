#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=25;
int a[N];
int s[N],cnt;
bool prim(int x){
	int lim=sqrt(x);
	if(x==1) return 0;
	for(int i=2;i<=lim;++i){
		if(x%i==0) return 0;
	}
	return 1;
}
bool ok(int i,int j){
	int A=a[i];
	int B=a[j];
	if(A<B) swap(A,B);
	if(A%B) return 1;
	else{
		if(prim(A/B)) return 0;
		return 1;
	}
}
int deal(int x,int n){
	cnt=0;
	for(int i=0;i<n;++i){
		if((x & (1<<i))) s[cnt++]=i;
	}
	//cout<<"!"<<endl;
	//for(int i=0;i<cnt;++i){
	//	cout<<a[s[i]]<<' ';
	//}
	//cout<<endl;
	for(int i=0;i<cnt;++i){
		for(int j=i+1;j<cnt;++j){
			if(!ok(s[i],s[j])) return 0;
		}
	}
	return cnt;
}
void gao(int n){
	int lim=(1<<n);
	int ans=0;
	for(int i=0;i<lim;++i){
		int tmp=deal(i,n);
		//cout<<tmp<<endl;
		ans=max(tmp,ans);
	}
	printf("%d\n",ans);
}
int cas=0;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		printf("Case #%d: ",++cas);
		gao(n);
	}
	return 0;
}
