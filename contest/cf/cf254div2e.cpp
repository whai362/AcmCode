#include<iostream>
#include<cstdio>
using namespace std;
#define N 100005
struct node{
    int l,r,mid;
    __int64 color,add,sum;
}v[3*N];
__int64 abs(__int64 n){
    if(n>=0) return n;
    return -n;
}
void build(int l,int r,int n){
    int mid=(l+r)>>1;
    v[n].l=l,v[n].r=r,v[n].mid=mid,v[n].add=v[n].sum=v[n].color=0;
    if(l==r){
		v[n].color=l;
        return ;
    }
    build(l,mid,2*n);
    build(mid+1,r,2*n+1);
}
void up(int n){
	v[n].color=v[2*n].color==v[2*n+1].color?v[2*n].color:0;
    v[n].sum=v[n*2].sum+v[2*n+1].sum;
}
void down(int n){
	if(v[n].color){
		v[2*n].color=v[2*n+1].color=v[n].color;
		if(v[n].add){
			v[2*n].add+=v[n].add;
			v[2*n+1].add+=v[n].add;
			v[2*n].sum+=v[n].add*(v[n].mid-v[n].l+1);
			v[2*n+1].sum+=v[n].add*(v[n].r-v[n].mid);
			v[n].add=0;
		}
	}
}
__int64 query(int l,int r,int n){
    if(v[n].l==l && v[n].r==r){
        return v[n].sum;
    }
	down(n);
    if(r<=v[n].mid)
        return query(l,r,2*n);
    else if(l>v[n].mid)
        return query(l,r,2*n+1);
    else{
        return query(l,v[n].mid,2*n)+query(v[n].mid+1,r,2*n+1);
    }
}
void print(node nd){
	cout<<nd.l<<' '<<nd.r<<' '<<nd.sum<<' '<<nd.add<<' '<<nd.color<<endl;
}
void update(int l,int r,int n,__int64 col){
    if(v[n].l==l && v[n].r==r &&  v[n].color){
        v[n].sum+=(__int64)(r-l+1)*abs(col-v[n].color);
		v[n].add+=abs(col-v[n].color);
		v[n].color=col;
		//print(v[n]);
        return ;
    }
	down(n);
    if(r<=v[n].mid)
        update(l,r,2*n,col);
    else if(l>v[n].mid)
        update(l,r,2*n+1,col);
    else{
        update(l,v[n].mid,2*n,col);
        update(v[n].mid+1,r,2*n+1,col);
    }
    up(n);
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    build(1,n,1);
    for(int i=0;i<q;++i){
        int op;
        int u,v;
        __int64 w;
        scanf("%d",&op);
        if(op==2){
            scanf("%d%d",&u,&v);
            printf("%I64d\n",query(u,v,1));
        }
        else{
            scanf("%d%d%I64d",&u,&v,&w);
            update(u,v,1,w);
        }
    }
    return 0;
}
