/*hdu 5204 Rikka with sequence
  题意：
  众所周知，萌萌哒六花不擅长数学，所以勇太给了她一些数学问题做练习，其中有一道是这样的：
  如果一个无重边无自环的无向图的每个联通块都存在一条回路经过这个联通分量所有边一次且仅一次，那么就称这个无向图是优美的。请问有n个点且边数不少于m的优美的图有多少个？（在这题中，我们认为这n个点是本质不同的）
  当然，这个问题对于萌萌哒六花来说实在是太难了，你可以帮帮她吗？
  限制：
  1 <= n <= 1e5; 1 <= L <= R <= 1e18; 1 <= w <= 1e9。
  思路：
  其实就60左右个不同的数。
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define LL __int64
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
void Out(LL x){
	if(x<0){ x=-x; putchar('-');}
	if(x>9)
        Out(x/10);
    putchar(x%10+'0');
}

LL add[100005];
int cnt;
struct Dt{
	LL x;
	LL cnt;
}ele[100005];
bool cmp(Dt a,Dt b){
	return a.x<b.x;
}
LL getC(LL x){
	if(x<0) return 0;
	LL ret=x/2;
	if(x%2) ++ret;
	return ret;
}

void gao(LL l,LL r,LL k){
	for(int i=cnt-1;i>=max(0,cnt-65);--i){
		ele[cnt-1-i].x=add[i];
		ele[cnt-1-i].cnt=getC(r)-getC(l-1);
		r/=2;
		l=(l+1)/2;
	}
	sort(ele,ele+min(cnt,65),cmp);
	LL ans=0;
	for(int i=0;i<min(cnt,65);++i){
		if(ele[i].cnt<k){
			k-=ele[i].cnt;
		}
		else{
			ans=ele[i].x;
			break;
		}
	}
	Out(ans);
	puts("");
}

int main(){
	int n;
	int op;
	LL w,l,r,k;
	while(scanf("%d",&n)!=EOF){
		cnt=0;
		for(int i=0;i<n;++i){
			In(op);
			if(op==1){
				In(w);
				add[cnt++]=w;
			}
			else{
				In(l);
				In(r);
				In(k);
				gao(l,r,k);
			}
		}
	}
	return 0;
}
