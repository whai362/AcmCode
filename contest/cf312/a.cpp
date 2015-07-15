#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
#define LL __int64
struct Dt{
	int x;
	LL a;
}z[N],f[N];
int z_cnt;
int f_cnt;
bool cmp(Dt a,Dt b){
	return a.x<b.x;
}
int main(){
	int n;
	cin>>n;
	int x,a;
	for(int i=0;i<n;++i){
		cin>>x>>a;
		if(x>0){
			z[z_cnt].x=x;
			z[z_cnt++].a=a;
		}
		else{
			f[f_cnt].x=-x;
			f[f_cnt++].a=a;
		}
	}
	sort(z,z+z_cnt,cmp);
	sort(f,f+f_cnt,cmp);
	LL ans=0;
	if(z_cnt==f_cnt){
		for(int i=0;i<z_cnt;++i)
			ans+=z[i].a+f[i].a;
	}
	else{
		int min_cnt=min(z_cnt,f_cnt);
		for(int i=0;i<min_cnt;++i){
			ans+=z[i].a+f[i].a;
		}
		if(z_cnt>min_cnt) ans+=z[min_cnt].a;
		else ans+=f[min_cnt].a;
	}
	cout<<ans<<endl;
	return 0;
}
