#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1005;
const int INF=1100000000;
struct Dt{
	int a,b;
}a[N];
int n;
int ans=INF;
bool cmp(Dt a,Dt b){
	return a.a-a.b>b.a-b.b;
}
bool vis[N];
bool deal(int i,int &w,int &h,int lim){
	//cout<<"lim"<<lim<<endl;
	int ok=1;
	int cnt=0;
	memset(vis,0,sizeof(vis));
	for(int j=0;j<n;++j){
		if(ok && j!=i){
			int _min=min(a[j].a,a[j].b);
			int _max=max(a[j].a,a[j].b);
			if(_min>h){ ok=0; break; }
			if(a[j].b>h){ ++cnt; vis[j]=1; w+=a[j].b; }
		}
		if(cnt>lim){ ok=0; break; }
	}
	for(int j=0;j<n;++j){
		if(ok && j!=i && vis[j]==0){
			int _min=min(a[j].a,a[j].b);
			int _max=max(a[j].a,a[j].b);
			if(cnt<lim){
				if(_min<=h && h<_max){ w+=_max; if(_max!=a[j].a && _max==a[j].b) ++cnt; }
				else{ w+=_min; if(_min!=a[j].a && _min==a[j].b) ++cnt; }
			}
			else w+=a[j].a;
		}
	}
	if(ok) return true;
	return false;
}
void gao(){
	int w,h;
	for(int i=0;i<n;++i){
		w=a[i].a;
		h=a[i].b;
		if(deal(i,w,h,n/2)){
			//cout<<w*h<<' '<<w<<' '<<h<<endl;
			ans=min(ans,w*h);
		}
		h=a[i].a;
		w=a[i].b;
		if(deal(i,w,h,n/2-1)){
			//cout<<w*h<<' '<<w<<' '<<h<<endl;
			ans=min(ans,w*h);
		}
	}
}
int main(){
	scanf("%d",&n);
	int w,h;
	for(int i=0;i<n;++i){
		scanf("%d%d",&w,&h);
		a[i].a=w;
		a[i].b=h;
	}
	sort(a,a+n,cmp);
	gao();
	printf("%d\n",ans);
	return 0;
}
