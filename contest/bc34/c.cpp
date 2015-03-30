/*hdu 5192
  题意：
  乐乐又开始搭积木了。
  他想在昨天搭完的积木上，重新搭建，使得其中有连续W堆积木具有相同的高度，同时他希望高度最少为H。
  乐乐的积木都这了，也就是说不能添加新的积木，只能移动现有的积木。
  他可以把一个积木从一堆移动到另一堆或者新的一堆，但是不能移动到两堆之间。比如，一次移动之后，"3 2 3" 可以变成 "2 2 4" 或者 "3 2 2 1",但是不能变成"3 1 1 3".
  请你帮他算算，当搭建的高度h为多少时，需要移动的积木最少，如果有多个h满足条件，输出h的最大值。 
  限制：
  所有数据的范围[1,50000]
  思路：
  尺取+树状数组
  对于每个划窗都可以O(1)算出合适的高度h,h1或h2
  然后对于每个高度用树状数组维护和查询：在划窗内有多少个数小于等于这个高度，及其和。然后大于该高度的也就可以求出来，然后就可以得到对于每个高度至少移动多少次了，求一个最小值即可。
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL __int64
const int N=50005;
const LL INF=100000000000LL;
LL a[3*N];
int n;
LL w,h;
LL BIT[N],c[N];
int lowbit(int x){ return x&-x; }
LL _sum(int x){
	++x;
	LL s=0;
	while(x>0){
		s+=BIT[x];
		x-=lowbit(x);
	}
	return s;
}
LL _count(int x){
	++x;
	LL s=0;
	while(x>0){
		s+=c[x];
		x-=lowbit(x);
	}
	return s;
}
void update(int x,LL _c,LL w){
	++x;
	while(x<N){
		c[x]+=_c;
		BIT[x]+=w;
		x+=lowbit(x);
	}
}
int main(){
	while(scanf("%d%I64d%I64d",&n,&w,&h)!=EOF){
		memset(a,0,sizeof(a));
		memset(BIT,0,sizeof(BIT));
		memset(c,0,sizeof(c));
		LL sum=0;
		for(int i=0;i<n;++i){
			scanf("%I64d",&a[i+w]);
			sum+=a[i+w];
		}
		if(sum<w*h){ puts("-1"); continue; }
		int p=0,q=0;
		LL xy=0,nb=0,s=0;
		LL ans=INF,ansh=0;
		while(q<2*w+n){
			while(q-p+1<=w){
				if(a[q]>h) nb+=a[q]-h;
				else xy+=h-a[q];
				s+=a[q];
				update(a[q],1,a[q]);
				++q;
			}
			if(max(xy,nb)==ans) ansh=max(ansh,h);
			else if(max(xy,nb)<ans){ ans=max(xy,nb); ansh=h; }
			LL h1=s/w;
			LL h2=h1+1;
			if(h1>=h){
				LL sl,zs;
				if(sum>=w*h1){
					sl=_count(h1);
					zs=_sum(h1);
					LL xy1=h1*sl-zs;
					LL nb1=s-zs-h1*(w-sl);
					if(max(xy1,nb1)==ans) ansh=max(ansh,h1);
					else if(max(xy1,nb1)<ans){ ans=max(xy1,nb1); ansh=h1; }
				}
				if(sum>=w*h2){
					sl=_count(h2);
					zs=_sum(h2);
					LL xy2=h2*sl-zs;
					LL nb2=s-zs-h2*(w-sl);
					if(max(xy2,nb2)==ans) ansh=max(ansh,h2);
					else if(max(xy2,nb2)<ans){ ans=max(xy2,nb2); ansh=h2; }
				}
			}
			if(a[p]>h) nb-=a[p]-h;
			else xy-=h-a[p];
			s-=a[p];
			update(a[p],-1,-a[p]);
			++p;
		}
		printf("%I64d %I64d\n",ansh,ans);
	}
	return 0;
}
