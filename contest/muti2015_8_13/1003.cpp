#include <iostream>
#include <iomanip>
int n = 100;
int gcd(int x, int y)
{
	return (!y) ? x : gcd(y, x % y);
}

int lcm(int x, int y)
{
	return x * y / gcd(x, y);
}

int f(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			sum += int(lcm(i, j) + gcd(i, j) >= n);
		}
	return sum ;
}

int main()
{
	for (int i = 1; i <= n; i++) {
		std::cout << f(i)<< '\n';
	}
}

