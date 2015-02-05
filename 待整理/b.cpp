#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=45,
		  INF=0x3f3f3f3f;
bool vis[N];
long long a[N],b[N];
int main(){
	int cas=0,n,T;
	scanf("%d",&T);
	while(T--){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	sort(a,a+n);
	int ans=INF;
	for(int i=0;i<n-1;++i){
		for(int j=0;j<n;++j){
			long long d=a[j]-a[i];
			memset(vis,0,sizeof(vis));
			for(int k=0;k<n;++k){
				b[k]=a[i]+(k-i)*d;
			}
			int tmp=0;
			for(int k=0;k<n;++k){
				cout<<b[k]<<' ';
			}
			cout<<endl;
			for(int k=0;k<n;++k){
				for(int l=0;l<n;++l){
					if(a[k]==b[l] && !vis[l]){
						vis[l]=true;
						++tmp;
						break;
					}
				}
			}
			ans=min(ans,n-tmp);
		}
	}
	cout<<"Case #"<<++cas<<": ";
	if(ans!=INF) cout<<ans<<endl;
	else cout<<0<<endl;
	}
	return 0;
}
