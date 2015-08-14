#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <complex>
#include <cassert>
//#pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
#define LL __int64
#define LS (2*n)
#define RS (2*n + 1)
#define X first
#define Y second

//LL gcd(LL a, LL b) {
//	return b == 0 ? a : gcd(b, a % b);
//}

const int N = 1e4 + 5;
int a[N];

struct Seg {
	int l, r;
	LL sum;
	int g;
	map<int, int> lg, rg;
}seg[N * 4];

map<int, int> :: iterator it, iti, itj;

void up(int n) {
	//cout<<n<<endl;
	seg[n].sum = seg[LS].sum + seg[RS].sum;
	seg[n].g = __gcd(seg[LS].g, seg[RS].g);

	seg[n].lg = seg[LS].lg;
	it = seg[RS].lg.begin();
	for(; it != seg[RS].lg.end(); ++it) {
		seg[n].lg[__gcd(seg[LS].g, (*it).X)] += (*it).Y;
	}

	seg[n].rg = seg[RS].rg;
	it = seg[LS].rg.begin();
	for(; it != seg[LS].rg.end(); ++it) {
		seg[n].rg[__gcd(seg[RS].g, (*it).X)] += (*it).Y;
	}
	for(iti = seg[LS].rg.begin(); iti != seg[LS].rg.end(); ++iti) {
		int g1 = (*iti).X;
		LL c1 = (*iti).Y;
		for(itj = seg[RS].lg.begin(); itj != seg[RS].lg.end(); ++itj) {
			int g2 = (*itj).X;
			LL c2 = (*itj).Y;
			seg[n].sum += c1 * c2 * __gcd(g1, g2);
		}
	}
}

void build(int l, int r, int n) {
	//cout<<l<<' '<<r<<' '<<n<<endl;
	seg[n].l = l; seg[n].r = r; seg[n].lg.clear(); seg[n].rg.clear();
	if(l == r) {
		seg[n].sum = seg[n].g = a[l];
		++seg[n].lg[a[l]];
		++seg[n].rg[a[l]];
		//cout<<l<<' '<<r<<' '<<seg[n].sum<<endl;
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, LS);
	build(mid + 1, r, RS);
	up(n);
	//cout<<l<<' '<<r<<' '<<seg[n].sum<<endl;
}

Seg query(int l, int r, int n) {
	//cout<<l<<' '<<r<<' '<<n<<endl;
	if(seg[n].l == l && seg[n].r == r) {
		return seg[n];
	}
	int mid = (seg[n].l + seg[n].r) >> 1;
	if(r <= mid) return query(l, r, LS);
	else if(l > mid) return query(l, r, RS);
	else {
		//cout<<l<<' '<<mid<<' '<<mid + 1<<' '<<r<<endl;
		Seg L = query(l, mid, LS);
		Seg R = query(mid + 1, r, RS);

		//cout<<L.l<<' '<<L.r<<' '<<L.sum<<endl;
		//cout<<R.l<<' '<<R.r<<' '<<R.sum<<endl;

		Seg ret;
		ret.sum = L.sum + R.sum;
		ret.g = __gcd(L.g, R.g);
		ret.lg = L.lg;
		it = R.lg.begin();
		for(; it != R.lg.end(); ++it) {
			ret.lg[__gcd(L.g, (*it).X)] += (*it).Y;
		}
		ret.rg = R.rg;
		it = L.rg.begin();
		for(; it != L.rg.end(); ++it) {
			ret.rg[__gcd(R.g, (*it).X)] += (*it).Y;
		}
		for(iti = L.rg.begin(); iti != L.rg.end(); ++iti) {
			int g1 = (*iti).X;
			LL c1 = (*iti).Y;
			for(itj = R.lg.begin(); itj != R.lg.end(); ++itj) {
				int g2 = (*itj).X;
				LL c2 = (*itj).Y;
				ret.sum += c1 * c2 * __gcd(g1, g2);
			}
		}
		return ret;
	}
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

void Out(LL x){
	if(x<0){ x=-x; putchar('-');}
	if(x>9)
        Out(x/10);
    putchar(x%10+'0');
}


int main() {
	int T;
	//scanf("%d", &T);
	In(T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			//scanf("%d", &a[i]);
			In(a[i]);
		}
		build(0, n-1, 1);
		//cout<<"!"<<endl;
		int m;
		scanf("%d", &m);
		for(int i = 0; i < m; ++i) {
			int l, r;
			//scanf("%d%d", &l, &r);
			In(l);
			In(r);
			--l; --r;
			//cout<<l<<' '<<r<<endl;
			Seg ans = query(l, r, 1);
			Out(ans.sum);
			puts("");
			//printf("%d\n", ans.sum);
		}
	}
	return 0;
}
