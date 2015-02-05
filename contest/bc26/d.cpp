#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
typedef __int64 lld;
const int MAX=65536*4;
const int MOD=1000000007;
void outmat(int a[],int len)
{
    return;
    for(int i=0;i<len;i++)printf("%d ",a[i]);
    puts("");
}
int P[3],g[3];
int r[3][MAX],tb[MAX];
bool isprime(int n)
{
    int i;
    for(i=2;i*i<=n;i++)if(n%i==0)return false;
    return true;
}
lld mod(lld a,lld b,lld m)
{
    lld ret=1;
    a%=m;
    while(b)
    {
        if(b&1)ret=ret*a%m;
        a=a*a%m;
        b>>=1;
    }
    return ret;
}
bool isroot(int g,int P)
{
    int p1=P-1,i;
    for(i=1;i*i<=p1;i++)
    {
        if(p1%i==0)
        {
            if(mod(g,i,P)==1)return false;
            if(p1/i<p1&&mod(g,p1/i,P)==1)return false;
        }
    }
    return true;
}
void init(int lim)
{
    int cnt=0,k=1;
    for(cnt=0;cnt<3;cnt++)
    {
        while(true)
        {
            P[cnt]=k<<21|1;
            if(P[cnt]>lim&&isprime(P[cnt]))
            {
                for(g[cnt]=1;isroot(g[cnt],P[cnt])==false;g[cnt]++)
                    ;
                    k++;
                break;
            }
            k++;
        }
    }
}
int rev(int n,int bitcnt)
{
    int ret=0;
    while(bitcnt--)
    {
        ret=ret<<1|(n&1);
        n>>=1;
    }
    return ret;
}
void buildleaf(int a[],int bitcnt)
{
    int full=1<<bitcnt;
    int i,j;
    for(i=0;i<full;i++)
    {
        j=rev(i,bitcnt);
        if(j<i)swap(a[i],a[j]);
    }
}
void FFT(int a[],int bitcnt,int mode,int P,int g)
{
    buildleaf(a,bitcnt);
    int s,half;
    int i,k,full=1<<bitcnt;
    for(s=2;s<=full;s<<=1)
    {
        half=s>>1;
        lld wn=mod(g,(P-1)/s,P);
        if(mode==-1)wn=mod(wn,s-1,P);
        for(i=0;i<full;i+=s)
        {
            lld w=1;
            for(k=0;k<half;k++)
            {
                lld u=a[k+i];
                lld v=w*a[k+i+half];
                if(v>=P)v%=P;
                if(u+v>=P)a[k+i]=u+v-P;
                else a[k+i]=u+v;

                a[k+i+half]=u-v;
                if(a[k+i+half]<0)a[k+i+half]+=P;
                w=w*wn%P;
            }
        }
    }
    if(mode==-1)
    {
        lld iv=mod(full,P-2,P);
        lld tmp;
        for(i=0;i<full;i++)
        {
            tmp=iv*a[i];
            if(tmp>=P)tmp%=P;
            a[i]=tmp;
        }
    }
}
lld CRT(lld r0,lld r1,lld r2,lld p0,lld p1,lld p2)
{

    lld invp0p1=423765473;
    lld invp0=253231225;

    lld t0=(r1-r0)*invp0;
    if(t0>=p1||t0<=-p1)t0%=p1;
    if(t0<0)t0+=p1;
    lld y=t0*p0+r0;

    lld k=(r2-y);
    if(k>=p2||k<=-p2)k%=p2;
    k*=invp0p1;
    if(k>=p2||k<=-p2)k%=p2;
    if(k<0)k+=p2;

    lld res=k*p0;
    if(res>=MOD)res%=MOD;
    res=(res*p1+y)%MOD;

    return res;
}
bool zero(int a[],int n)
{
    for(int i=0;i<n;i++)if(a[i])return false;
    return true;
}
bool one(int a[],int n)
{
    if(a[0]!=1)return false;
    return zero(a+1,n);
}
int conv(int a[],int b[],int n,int m,int up)
{
    int bitcnt=0;
    int i,j;
    if(zero(a,n))
    {
        return n;
    }
    else if(zero(b,m))
    {
        a[0]=0;
        return 1;
    }
    else if(one(b,m))return n;
    else if(one(a,n))
    {
        memcpy(a,b,sizeof(int)*m);
        return m;
    }
    while((1<<bitcnt)<n+m)bitcnt++;
    int full=1<<bitcnt;

    for(i=n;i<full;i++)a[i]=0;
    for(i=m;i<full;i++)b[i]=0;
    for(i=0;i<3;i++)
    {
        memcpy(r[i],a,sizeof(int)*full);
        memcpy(tb,b,sizeof(int)*full);
        FFT(r[i],bitcnt,1,P[i],g[i]);
        FFT(tb,bitcnt,1,P[i],g[i]);
        lld tmp=0;
        for(j=0;j<full;j++)
        {
            tmp=(lld)tb[j]*r[i][j];
            if(tmp>=P[i])tmp%=P[i];
            r[i][j]=tmp;
        }
        FFT(r[i],bitcnt,-1,P[i],g[i]);
    }
    for(i=0;i<full&&i<up;i++)
    {
        a[i]=CRT(r[0][i],r[1][i],r[2][i],P[0],P[1],P[2]);
    }
    while(i>0&&a[i-1]==0)i--;
    return i;
}

lld inv[MAX],invfac[MAX],fac[MAX];


lld B[MAX];
int A[MAX],B0[MAX];
int TA[MAX],TB[MAX];
void minu(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        a[i]=-a[i]+MOD;
        if(a[i]==MOD)a[i]=0;
    }
    a[0]+=2;
    if(a[0]>=MOD)a[0]-=MOD;
}
int main()
{
    init(1000000000);
    int i,j;

    int up=65536;

    inv[0]=inv[1]=1;
    invfac[0]=invfac[1]=1;
    fac[0]=fac[1]=1;
    for(i=2;i<MAX;i++)
    {
        inv[i]=-inv[MOD%i]*(MOD/i)%MOD+MOD;
        invfac[i]=invfac[i-1]*inv[i]%MOD;
        fac[i]=fac[i-1]*i%MOD;
    }


    for(i=0;i<up;i++)
    {
        A[i]=invfac[i+1];
    }
    B0[0]=1;
    int m=up;
    for(m=2;m<=up;m<<=1)
    {
        memcpy(TA,A,sizeof(int)*m);
        memcpy(TB,B0,sizeof(int)*(m>>1));
        conv(TA,TB,m,m>>1,m);
        minu(TA,m);
        conv(B0,TA,m>>1,m,m);
    }

    for(i=0;i<up;i++)
    {
        lld tmp=fac[i]*B0[i];
        if(tmp>=MOD)tmp%=MOD;
        B[i]=tmp;
    }
    lld n;
    while(scanf("%I64d",&n)!=EOF)
    {
        printf("%I64d\n",B[n]);
    }

    return 0;
}
