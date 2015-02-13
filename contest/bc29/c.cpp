/*hdu 5172
  题意：
  给出n个数, a[1],a[2],...a[n], m个询问, 对于每个询问[l,r], 问a[l],a[l+1],...,a[r]是不是集合{1,2,...,r-l+1}
  限制：
  1 <= n,m <= 1e6; 1 <= l,r,a[i] <= n
  思路：
  预处理出，对于每个位置，它前一个相同的数对的位置。
  如：
  给出的数组：       1  2 1 2 3
  预处理出来的数组：-1 -1 0 1 1
  上面的数组是用来判断区间元素是否唯一。
  接下来就用线段树或者rmq(rmq比较好)，求区间最大最小就行了。
 */
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define N 1000005
int L[3*N],R[3*N],Max[3*N],Min[3*N];
int a[N],p[N];
void up(int n){
    Max[n]=max(Max[n<<1],Max[n<<1|1]);
    Min[n]=min(Min[n<<1],Min[n<<1|1]);
}
void build(int l,int r,int n){
    L[n]=l,R[n]=r;
    int mid=(l+r)>>1;
    if(l==r){
        Max[n]=Min[n]=a[l-1];
        return ;
    }
    build(l,mid,n<<1);
    build(mid+1,r,n<<1|1);
    up(n);
}
struct Dt{
    int a,b;
    Dt();
    Dt(int _a,int _b){
        a=_a;
        b=_b;
    }
};
Dt getAns(int l,int r,int n){
    if(L[n]==l && R[n]==r) return Dt(Max[n],Min[n]);
    int mid=(L[n]+R[n])>>1;
    if(r<=mid) return getAns(l,r,n<<1);
    else if(l>mid) return getAns(l,r,n<<1|1);
    else{
        Dt d1=getAns(l,mid,n<<1),
           d2=getAns(mid+1,r,n<<1|1);
        return Dt(max(d1.a,d2.a),min(d1.b,d2.b));
    }
}
void gao(int l,int r){
	if(p[r-1]+1>=l){ puts("NO"); return; }
    Dt ans=getAns(l,r,1);
    int _max=ans.a;
    int _min=ans.b;
    if(_max==r-l+1 && _min==1) puts("YES");
    else puts("NO");
}
int pre[N];
int cnt[N];
void predo(int n){
    memset(pre,-1,sizeof(int)*(n+1));
    memset(cnt,0,sizeof(int)*(n+1));
    int cur=-1;
    for(int i=0;i<n;++i){
        ++cnt[a[i]];
        if(cnt[a[i]]>=2) cur=max(cur,pre[a[i]]);
        p[i]=cur;
        pre[a[i]]=i;
    }
}
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;++i)
            scanf("%d",&a[i]);
        predo(n);
        build(1,n,1);
        int l,r;
        for(int i=0;i<m;++i){
            scanf("%d%d",&l,&r);
            gao(l,r);
        }
    }
    return 0;
}
