/*主席树
  题目大意:
  给定一个整数序列a[N]，询问区间ai到aj之间第k大的数是多少。共m次询问，对每次询问输出结果。
  题目限制：
  n, m <= 10000
 */
#include<cstdio>
#include<algorithm>
#define N 100010
using namespace std;
struct node{
	int l,r,sum;
}nd[20*N];
int tot;
int a[N],sorted[N],root[N];
void build(int l,int r,int &rt){
	rt=++tot;
	nd[rt].sum=0;
	if(l==r) return ;
	int mid=(l+r)>>1;
	build(l,mid,nd[rt].l);
	build(mid+1,r,nd[rt].r);
}
void update(int pre,int &rt,int l,int r,int mir){
	rt=++tot;
	nd[rt]=nd[pre];
	++nd[rt].sum;
	if(l==r) return ;
	int mid=(l+r)>>1;
	if(mir<=mid) update(nd[pre].l,nd[rt].l,l,mid,mir);
	else update(nd[pre].r,nd[rt].r,mid+1,r,mir);
}
int query(int r1,int r2,int l,int r,int k){
	if(l==r)
		return l;
	int mid,lsum,root;
	mid=(l+r)>>1;
	lsum=nd[nd[r2].l].sum-nd[nd[r1].l].sum;
	if(k<=lsum)
		return query(nd[r1].l,nd[r2].l,l,mid,k);
	else
		return query(nd[r1].r,nd[r2].r,mid+1,r,k-lsum);
}
int main(){
	int i,n,m,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;++i){
			scanf("%d",&a[i]);
			sorted[i]=a[i];
		}
		tot=0;
		sort(sorted+1,sorted+n+1);
		int num=unique(sorted+1,sorted+n+1)-sorted-1;
		build(1,num,root[0]);
		for(i=1;i<=n;++i){
			int mir=lower_bound(sorted+1,sorted+num+1,a[i])-sorted;
			update(root[i-1],root[i],1,num,mir);
		}
		for(i=0;i<m;++i){
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			int id=query(root[l-1],root[r],1,num,k);
			printf("%d\n",sorted[id]);
		}
	}
	return 0;
}
