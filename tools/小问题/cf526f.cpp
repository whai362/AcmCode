/*codeforces 526 f
  题意：
  给出n个数a1,a2,...,an，ai范围为1~n，且互不相同，现在求有多少个区间[l,r]，使得[l,r]之间的元素是连续的，比如{3,5,4}就是连续的，{3,5,2}就是不连续的。
  限制：
  1 <= n <= 3*1e5
  1 <= ai <= n
  思路：
  分治
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL __int64
const int N=300005;
int n,a[N],lmax[N],rmax[N],lmin[N],rmin[N],cnt[2*N];
LL ans;
void gao(int l,int r){
	//cout<<l<<' '<<r<<endl;
	if(l==r){
		++ans;
		return ;
	}

	int mid = (l+r)>>1;

	lmin[mid] = lmax[mid] = a[mid];
	for(int i=mid-1; i>=l; --i){
		lmin[i] = min(a[i], lmin[i+1]);
		lmax[i] = max(a[i], lmax[i+1]);
	}

	rmin[mid+1] = rmax[mid+1] = a[mid+1];
	for(int i=mid+2; i<=r; ++i){
		rmin[i] = min(a[i], rmin[i-1]);
		rmax[i] = max(a[i], rmax[i-1]);
	}

	for(int i=l; i<=mid; ++i){
		int R = lmax[i] - lmin[i] + i;
		if(mid<R && R<=r && rmin[R]>lmin[i] && rmax[R]<lmax[i])
			++ans;
	}

	for(int i=mid+1; i<=r; ++i){
		int L = i - (rmax[i] - rmin[i]);
		if(l<=L && L<=mid && lmin[L]>rmin[i] && lmax[L]<rmax[i])
			++ans;
	}

	int j=r,k=r;
	for(int i=l; i<=mid; ++i){
		while(j>mid && rmax[j]>lmax[i]){
			++cnt[ rmax[j]-j+N ];
			--j;
		}
		while(k>j && rmin[k]<lmin[i]){
			--cnt[ rmax[k]-k+N ];
			--k;
		}
		ans+=cnt[ lmin[i]-i+N ];
	}

	for(; k>j; --k)
		--cnt[ rmax[k]-k+N ];

	j=k=r;
	for(int i=l; i<=mid; ++i){
		while(j>mid && rmin[j]<lmin[i]){
			++cnt[ rmin[j]+j ];
			--j;
		}
		while(k>j && rmax[k]>lmax[i]){
			--cnt[ rmin[k]+k ];
			--k;
		}
		ans+=cnt[ lmax[i]+i ];
	}

	for(; k>j; --k)
		--cnt[ rmin[k]+k ];

	gao(l,mid);
	gao(mid+1,r);
}
int main(){
	int x,y;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d%d",&x,&y);
		a[y]=x;
	}
	gao(1,n);
	printf("%I64d",ans);
	return 0;
}
