#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000005;
int a[N],b[N],q[N],h[N],du[N];
int ans[N];
// 0 1 2 0
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d%d",&a[i],&b[i]);
		q[b[i]]=a[i];
		h[a[i]]=b[i];
		++du[a[i]];
		++du[b[i]];
	}
	ans[1]=h[0];
	int seq=1,now=h[0];
	while(h[now]){
		seq+=2;
		ans[seq]=h[now];
		now=h[now];
	}

	for(int i=0;i<n;++i){
		if(du[a[i]]==1){
			ans[0]=a[i];
			break;
		}
	}
	seq=0,now=ans[0];
	while(h[now]){
		seq+=2;
		ans[seq]=h[now];
		now=h[now];
	}
	for(int i=0;i<n;++i){
        printf("%d%c",ans[i],i!=n-1?' ':'\n');
    }
	return 0;
}
