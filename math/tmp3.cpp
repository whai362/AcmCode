#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
typedef long long LL;

const int N = 1 << 18;
const int P = 995622913;
const int G = 88560779;
const int NUM = 20;

LL  wn[NUM];
LL  a[N], b[N];
char A[N], B[N];

LL quick_mod(LL a, LL b, LL m)
{
    LL ans = 1;
    a %= m;
    while(b)
    {
        if(b & 1)
        {
            ans = ans * a % m;
            b--;
        }
        b >>= 1;
        a = a * a % m;
    }
    return ans;
}

void GetWn()
{
    for(int i=0; i<NUM; i++)
    {
        int t = 1 << i;
        wn[i] = quick_mod(G, (P - 1) / t, P);
    }
}
LL Ext_gcd(LL a,LL b,LL &x,LL &y){
    if(b==0) { x=1, y=0; return a; }
    LL ret= Ext_gcd(b,a%b,y,x);
    y-= a/b*x;
    return ret;
}

LL Inv(LL a,int m){   //ÇóÄæÔª
    LL d,x,y,t= (LL)m;
    d= Ext_gcd(a,t,x,y);
    if(d==1) return (x%t+t)%t;
    return -1;
}

void Prepare(char A[], char B[], LL a[], LL b[], int &len)
{
    len = 1;
    int len_A = 1;
    int len_B = 1;
    while(len <= 2 * len_A || len <= 2 * len_B) len <<= 1;
	a[0]=Inv(2,P);
	b[0]=1;
	for(int i=len_A;i<len;++i){
		a[i]=b[i]=0;
	}
}

void Rader(LL a[], int len)
{
    int j = len >> 1;
    for(int i=1; i<len-1; i++)
    {
        if(i < j) swap(a[i], a[j]);
        int k = len >> 1;
        while(j >= k)
        {
            j -= k;
            k >>= 1;
        }
        if(j < k) j += k;
    }
}

void NTT(LL a[], int len, int on)
{
    Rader(a, len);
    int id = 0;
    for(int h = 2; h <= len; h <<= 1)
    {
        id++;
        for(int j = 0; j < len; j += h)
        {
            LL w = 1;
            for(int k = j; k < j + h / 2; k++)
            {
                LL u = a[k] % P;
                LL t = w * (a[k + h / 2] % P) % P;
                a[k] = (u + t) % P;
                a[k + h / 2] = ((u - t) % P + P) % P;
                w = w * wn[id] % P;
            }
        }
    }
    if(on == -1)
    {
        for(int i = 1; i < len / 2; i++)
            swap(a[i], a[len - i]);
        LL Inv = quick_mod(len, P - 2, P);
        for(int i = 0; i < len; i++)
            a[i] = a[i] % P * Inv % P;
    }
}

void Conv(LL a[], LL b[], int n)
{
    NTT(a, n, 1);
    NTT(b, n, 1);
    for(int i = 0; i < n; i++)
        a[i] = a[i] * b[i] % P;
    NTT(a, n, -1);
}

void Transfer(LL a[], int n)
{
    int t = 0;
    for(int i = 0; i < n; i++)
    {
        a[i] += t;
        if(a[i] > 9)
        {
            t = a[i] / 10;
            a[i] %= 10;
        }
        else t = 0;
    }
}

void Print(LL a[], int n)
{
	for(int i=0;i<n;++i){
		cout<<a[i]<<' ';
	}
}

int main()
{
    GetWn();
	int len;
	Prepare(A, B, a, b, len);
	Conv(a, b, len);
	Print(a, len);
    return 0;
}

