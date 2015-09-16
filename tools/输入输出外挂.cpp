//关闭流同步
//注意用了这个，就不要用puts，scanf，printf等东西了。
ios_base::sync_with_stdio(false);

#include<iostream>
#include<cstdio>
using namespace std;
#define LL __int64
//输入输出外挂
void In(int &x) {
	char c; x = 0; c = getchar();
	int sign = 1;
	while (!(c >= '0' && c <= '9' || c == '-')) c = getchar();
	if (c == '-') sign = -1, c = getchar();
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	x *= sign;
}

void In(LL &x) {
	char c; x = 0; c = getchar();
	int sign = 1;
	while (!(c >= '0' && c <= '9' || c == '-')) c = getchar();
	if (c == '-') sign = -1, c = getchar();
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	x *= sign;
}

void Out(int x) {
	if (x < 0) { x = -x; putchar('-');}
	if (x > 9)
		Out(x / 10);
	putchar(x % 10 + '0');
}

void Out(LL x) {
	if (x < 0) { x = -x; putchar('-');}
	if (x > 9)
		Out(x / 10);
	putchar(x % 10 + '0');
}


//大数据读入外挂
const int BZ = 120 * (1 << 20);
char Buf[BZ + 1], *buf = Buf;

template <class T>
inline void scan(T &a) {
	for (a = 0; *buf < '0' || *buf > '9'; ++buf);
	while (*buf >= '0' && *buf <= '9') {
		a = a * 10 + (*buf - '0');
		++buf;
	}
}

int main() {
	fread(Buf, 1, BZ, stdin);
	return 0;
}