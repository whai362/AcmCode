#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1005;
const int INF=1100000000;
struct Dt{
	int a,b;
}a[N];
int n;
int ans=INF;
bool cmp1(Dt a,Dt b){
	if(a.a==b.a) return a.b<b.b;
	return a.a<b.a;
}
void gao(){
	int w,h;
	for(int i=0;i<n;++i){
		h=a[i].a;
		w=a[i].b;
		int ok=1;
		for(int j=0;j<n;++j){
			if(ok==1 && j!=i){
				if(min(a[j].a,a[j].b)>h) ok=0;
				else if(min(a[j].a,a[j].b)<=h<max(a[j].a,a[j].b)) w+=max(a[j].a,a[j].b);
				else w+=min(a[j].a,a[j].b);
			}
		}
		if(ok)
			ans=min(ans,w*h);
	}
}
int main(){
	scanf("%d",&n);
	int w,h;
	for(int i=0;i<n;++i){
		scanf("%d%d",&w,&h);
		if(w>h) swap(w,h);
		a[i].a=w;
		a[i].b=h;
	}
	sort(a,a+n,cmp1);
	gao();
	for(int i=0;i<n;++i){
		swap(a[i].a,a[i].b);
	}
	sort(a,a+n,cmp1);
	gao();
	printf("%d\n",ans);
	return 0;
}
