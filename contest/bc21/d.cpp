#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define LL __int64
const int N=1000005;
int n,un;
int a[N],sorted[N];
struct Tree{
    int lp,len;
    Tree(){}
    Tree(int _lp,int _len){
        lp=_lp;
        len=_len;
    }
}tr[N],dp[N];
Tree max(Tree a,Tree b){
    if(a.len>b.len) return a;
    else if(a.len<b.len) return b;
    else{
        if(a.lp>b.lp) return a;
        else return b;
    }
}
Tree get(int k){
    Tree ret=Tree(0,0);
    for(; k; k-=k&-k)
        ret=max(ret,tr[k]);
    return ret;
}
void add(int k,Tree t){
    for(; k<=un; k+=k&-k)
        tr[k]=max(tr[k],t);
}
void init(){
    memset(tr,0,sizeof(tr));
}
int main(){
    while(scanf("%d",&n)!=EOF){
        init();
        for(int i=0;i<n;++i){
            scanf("%d",&a[i]);
            sorted[i]=a[i];
        }
        sort(sorted,sorted+n);
        un=unique(sorted,sorted+n)-sorted;
        for(int i=0;i<n;++i)
            a[i]=lower_bound(sorted,sorted+un,a[i])-sorted+1;
        Tree lis=Tree(0,0);
        for(int i=0;i<n;++i){
            Tree tmp;
            Tree pre=get(a[i]-1);
            if(pre.len==0) tmp.lp=i;
            else tmp.lp=pre.lp;
            tmp.len=pre.len+1;
            add(a[i],tmp);
            dp[i]=lis=max(lis,tmp);
        }
        LL ans=0;
        for(int i=0;i<n;++i)
            if(dp[i].len==lis.len)
                ans+=(LL)dp[i].lp+1;
        printf("%I64d\n",ans);
    }
    return 0;
}
