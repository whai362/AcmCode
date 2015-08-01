#include <iostream>

int const maxn = 10000;

int gcd(int x, int y)
{
	return ((y == 0) ? x : gcd(y, x % y));
}

bool judge(int x)
{
	int a = 1, b = 0, d = 0, t = 1;
	for (b = 2; b < x; b++) { t++; if (gcd(b, x) == 1) break; }
	if (t == 1) return true;
	d = b - a;
	for (int i = b + 1; i < x; i++) {
		if (gcd(i, x) == 1) {
			if (i - b != d) return false;
			b = i;
		}
	}
	return true;
}

int main()
{

	for (int i = 0; i < maxn; i++) {
		if (judge(i)) std::cout << i << '\n';
	}
}
