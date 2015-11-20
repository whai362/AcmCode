#include <iostream>
#include <string>

int n, m, k;
std::string magic = "AABABB";

int main()
{
	std::ios::sync_with_stdio(false);
	int T; std::cin >> T;
	for (int ti = 1; ti <= T; ti++) {
		std::cout << "Case #" << ti << ":\n";
		std::cin >> n >> m >> k;
		if (k == 1) {
			if (n == m) {
				for (int i = 0; i < n; i++) std::cout << "A";
				std::cout << '\n';
			} else
				std::cout << "Impossible\n";
			continue;
		}

		if (k >= 3) {
			if (n == 1) {
				if (m > 1)
					std::cout << "Impossible\n";
				else
					std::cout << "A\n";
			} else if (n == 2) {
				if (m > 2 || m == 1)
					std::cout << "Impossible\n";
				else
					std::cout << "AB\n";
			} else if (n == 3) {
				if (m > 3 || m == 1 || m == 2)
					std::cout << "Impossible\n";
				else
					std::cout << "ABC\n";
			}
			else {
				if (m <= 2)
					std::cout << "Impossible\n";
				else {
					int ta = m - 2;
					for (int i = 0; i < ta - 1; i++)
						std::cout << "A";
					n -= ta - 1;
					for (int i = 0; i < n; i++)
						std::cout << char('A' + (i % 3));
					std::cout << '\n';
				}
			}
			continue;
		}

		if (k == 2) {
			if (m > n) {
				std::cout << "Impossible\n";
			} else if (n <= 7) {
				if (n != m) {
					std::cout << "Impossible\n";
				} else {
					for(int i = 0; i < n; ++i)
						std::cout << 'A';
					std::cout << '\n';
				}
			} else if(n == 8) {
				if(m == 7) {
					std::cout << "AABABBAA" << '\n';
				} else if (m == 8) {
					for(int i = 0; i < n; ++i)
						std::cout << 'A';
					std::cout << '\n';
				} else {
					std::cout << "Impossible\n";
				}
			} else{
				std::string ans = "";
				for(int i = 0; i < n; ++i) {
					ans += magic[i % 6];
				}
				int minn = 8;
				if(m < 8) {
					std::cout << "Impossible\n";
				} else {
					int move = m - minn;
					if(move >= n - 8) ++move;
					for(int i = 0; i < move; ++i) {
						std::cout << 'A';
					}
					for(int i = move; i < n; ++i) {
						std::cout << ans[i - move];
					}
					std::cout << '\n';
				}
			}
			continue;
		}
	}
}

