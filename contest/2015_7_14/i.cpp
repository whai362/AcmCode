#include <iostream>
#include <cstdio>
#include <cmath>

int main()
{
	int T;
	std::cin >> T;
	while (T--) {
		int n;
		std::string s;
		std::cin >> n >> s;
		double b;
		if (s == "nat") b = M_E; //M_PI
		if (s == "bit") b = 2;
		if (s == "dit") b = 10;

		double ans = 0;
		for (int i = 0, t; i < n; i++) {
			std::cin >> t;
			if (!t) continue;
			ans += t/double(100)  * std::log(double(t)/double(100)) / std::log(double(b));
		}
		std::printf("%.12f\n", std::fabs(ans));
	}
}
