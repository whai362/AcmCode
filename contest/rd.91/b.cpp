#include<cstdio>
#include<cmath>
void to( int x, int* a ){
    int t,i;
    for(i=0;i<100;i++) a[i]=0;
    i=0;
    while(x){
        t=x/3;
        if(t==0) a[i++]=x;
        else a[i++]=x%3;
        x=t;
    }
}
int main(){
    int a,b,c,i,A[100],B[100],C[100],hash[10][10];
    hash[0][0]=0;
    hash[0][1]=1;
    hash[0][2]=2;
    hash[1][0]=2;
    hash[1][1]=0;
    hash[1][2]=1;
    hash[2][0]=1;
    hash[2][1]=2;
    hash[2][2]=0;
    scanf("%d%d",&a,&c);
    to(a,A);
    to(c,C);
    for(i=0;i<100;i++)
        B[i]=hash[A[i]][C[i]];
    b=0;
    for(i=99;i>=0;i--)
        if(B[i]) b+=B[i]*(int)pow(3.0,i);
    printf("%d\n",b);
    return 0;
}

