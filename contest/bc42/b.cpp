#include<iostream>
#include<cstdio>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
const int N=1e5+5;
struct Dt{
	int x;
	int i;
}h[N],q[N];
bool cmp(Dt a,Dt b){
	return a.x<b.x;
}
bool cmp1(Dt a,Dt b){
	if(a.x!=b.x) return a.x<b.x;
	return a.i<b.i;
}
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
void Out(int x){
	if(x<0){ x=-x; putchar('-');}
	if(x>9)
        Out(x/10);
    putchar(x%10+'0');
}
int ans[N];
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int tot=1;
		int H,Q;
		for(int i=0;i<n;++i){
			In(H);
			h[i].x=H;
			h[i].i=i;
		}
		for(int i=0;i<m;++i){
			In(Q);
			q[i].x=Q;
			q[i].i=i;
		}
		sort(h,h+n,cmp1);
		sort(q,q+m,cmp1);
		int cnt=0;
		for(int i=0;i<m;++i){
			if(i && q[i].x!=q[i-1].x){
				cnt=0;
			}
			int xb=lower_bound(h,h+n,q[i],cmp)-h;
			xb+=cnt;
			if(xb>=0 && xb<n && h[xb].x==q[i].x){
				ans[q[i].i]=h[xb].i+1;
			}
			else
				ans[q[i].i]=-1;
			++cnt;
		}
		for(int i=0;i<m;++i){
			Out(ans[i]);
			puts("");
		}
	}
	return 0;
}
