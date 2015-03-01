#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
const int N=1e5+5;
int pos[N];
int a[N];
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
		pos[a[i]]=i;
	}
	LL ans=0;
	int l;
	for(int i=0;i<m;++i){
		scanf("%d",&l);
		int p=pos[l];
		ans=ans+p/k+1;
		if(p){
		int pre=a[p-1];
		pos[pre]=p;
		pos[l]=p-1;
		swap(a[p],a[p-1]);
		}
		//for(int j=0;j<n;++j){
		//	cout<<a[j]<<' '<<pos[a[j]]<<endl;
		//}
		//cout<<"---"<<endl;
	}
	printf("%I64d\n",ans);
	return 0;
}
