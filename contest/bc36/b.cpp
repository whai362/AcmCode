#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
const int N=1000005;
using namespace std;
#define LL __int64
struct Dt{
	int a,x,i;
}a[2*N];
void In(int &x){
	char c; x=0; c=getchar();
	int sign=1;
	while(!(c>='0'&&c<='9' || c=='-')) c=getchar();
	if(c=='-') sign=-1,c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	x*=sign;
}

void In(LL &x){
	char c; x=0; c=getchar();
	int sign=1;
	while(!(c>='0'&&c<='9' || c=='-')) c=getchar();
	if(c=='-') sign=-1,c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	x*=sign;
}

void Out(int x){
	if(x<0){ x=-x; putchar('-');}
	if(x>9)
        Out(x/10);
    putchar(x%10+'0');
}
bool cmp1(Dt a,Dt b){
	return a.x<b.x;
}
bool cmp2(Dt a,Dt b){
	return a.i<b.i;
}
int h[N];
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int cnt=0;
		for(int i=0;i<n;++i){
			//scanf("%d",&a[cnt].x);
			In(a[cnt].x);
			a[cnt++].i=i;
		}
		for(int i=0;i<m;++i){
			//scanf("%d",&a[cnt].x);
			In(a[cnt].x);
			a[cnt].i=cnt;
			++cnt;
		}
		sort(a,a+cnt,cmp1);
		a[0].a=1;
		for(int i=1;i<cnt;++i){
			a[i].a=a[i-1].a;
			if(a[i].x!=a[i-1].x) ++a[i].a;
		}
		sort(a,a+cnt,cmp2);
		memset(h,0,sizeof(h));
		for(int i=0;i<n;++i){
			++h[a[i].a];
		}
		for(int i=n;i<cnt;++i){
			Out(h[a[i].a]);
			puts("");
			h[a[i].a]=0;
		}
	}
	return 0;
}
