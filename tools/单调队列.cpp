/*单调队列
  题目大意：
  给定从左到右n个矩形，已知这此矩形的宽度都为1，长度不完全相等。这些矩形相连排成一排，求在这些矩形包括的范围内能得到的面积最大的矩形，打印出该面积。
  题目限制：
  1<=n<=100000
 */
#include<cstdio>
#include<iostream>
using namespace std;
#define LL long long
#define N 100005
struct stack {
	int id;
	LL v;
} s[N];
int top = -1;
struct node {
	int l, r;
	LL h;
} a[N];
int main() {
	int i, j, n;
	LL ans, tmp;
	while (scanf("%d", &n) && n) {
		ans = 0;
		top = -1;
		s[++top].v = -1;
		s[top].id = 0;
		for (i = 1; i <= n; ++i) {
			scanf("%I64d", &a[i].h);
			for (j = top; j >= 0; --j) {
				if (a[i].h >= s[j].v) break;
				else a[s[j].id].r = i - 1;
			}
			if (a[i].h > s[j].v) a[i].l = s[j].id;
			else a[i].l = a[s[j].id].l;
			top = j;
			s[++top].v = a[i].h;
			s[top].id = i;
		}
		for (i = 0; i <= top; ++i) {
			a[s[i].id].r = n;
		}
		/*for(i=1;i<=n;++i){
		  cout<<a[i].l<<' '<<a[i].r<<endl;
		  }*/
		for (i = 1; i <= n; ++i) {
			tmp = (a[i].r - a[i].l) * a[i].h;
			if (tmp > ans) ans = tmp;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
