#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1e4+5;

int p[maxn],c[maxn][2],rev[maxn];
int isroot(int x){return ((c[p[x]][0]!=x)&&(c[p[x]][1]!=x));}
int n,m;

void pushdown(int x){
    if(rev[x]){
        rev[c[x][0]]^=1,rev[c[x][1]]^=1;
        swap(c[x][0],c[x][1]);
        rev[x]^=1;
    }
}

void rotate(int x){
    int y=p[x],d=(c[y][0]==x?0:1);
    p[c[x][d^1]]=y,c[y][d]=c[x][d^1],c[x][d^1]=y;
    if(!isroot(y)) c[p[y]][c[p[y]][1]==y]=x;
    p[x]=p[y],p[y]=x;
}

void deal(int x){
    if(!isroot(x)) deal(p[x]);
    pushdown(x);
}

void splay(int x){
    deal(x);
    while(!isroot(x)){
        int y=p[x],z=p[y];
        if(!isroot(y)){
            if(c[y][0]==x^c[z][0]==y)rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
}

void access(int x){
    int last=0;
    while(x){
        splay(x);
        c[x][1]=last;
        last=x;
        x=p[x];
    }
}

void mroot(int x){
    access(x),splay(x);
    rev[x]^=1;
}

void cut(int x,int y){
    mroot(x);
    access(y),splay(y);
    c[y][0]=p[x]=0;
}

void link(int x,int y){
    mroot(x);
    p[x]=y;
}

int find(int x){
    access(x),splay(x);
    while(c[x][0]) x=c[x][0];
    return x;
}

int main(){
    scanf("%d%d",&n,&m);
    char s[10];
    for(int i=1,x,y;i<=m;i++){
        scanf("%s%d%d",s,&x,&y);
        if(s[0]=='Q'){
            x=find(x),y=find(y);
            if(x==y) printf("Yes\n");
            else printf("No\n");
        }
        else if(s[0]=='C') link(x,y);
        else cut(x,y);
    }
    return 0;
}
