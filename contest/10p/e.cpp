#include<iostream>
#include<cstdio>
using namespace std;
#define N 100005
long long h[N],w[N],max1[N],max2[N];
int main(){
	int cnt,n;
	long long ll;
	long long tmp,ans;
	while(scanf("%d%lld",&n,&ll)!=EOF){
	cnt=0;
	ans=0;
	for(int i=0;i<n;++i){
		scanf("%lld",&h[i]);
	}
	for(int i=0;i<n;++i){
		scanf("%lld",&w[i]);
	}
	max1[0]=h[0];
	for(int i=1;i<n;++i){
		max1[i]=max(max1[i-1],h[i]);
	}
	max2[n-1]=h[n-1];
	for(int i=n-2;i>=0;--i){
		max2[i]=max(max2[i+1],h[i]);
	}
	for(int i=0;i<n;++i){
		if(max1[i]>h[i] && max2[i]>h[i]){
			int l,r;
			if(max1[i]>=max2[i]){
				for(l=i;l>=0;--l){
					if(h[l]>=max2[i]){
						break;
					}
				}
				for(r=i;r<n;++r){
					if(h[r]==max2[r]){
						break;
					}
				}
			}
			else{
				for(l=i;l>=0;--l){
					if(h[l]==max1[i]){
						break;
					}
				}
				for(r=i;r<n;++r){
					if(h[r]>=max1[r]){
						break;
					}
				}
			}
			tmp=0;
			long long _min=min(max1[i],max2[i]);
			//cout<<"!!!"<<i<<' '<<max1[i]<<' '<<max2[i]<<endl;
			for(int j=l+1;j<r;++j){
				//cout<<l<<' '<<r<<' '<<_min<<' '<<h[j]<<' '<<w[j]<<' '<<ll<<endl;
				tmp+=(_min-h[j])*w[j]*ll;
			}
			ans+=tmp;
			i=r;
		}
	}
	cout<<ans<<endl;
	}
	return 0;
}
