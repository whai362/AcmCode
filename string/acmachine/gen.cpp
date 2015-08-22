#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;
int main() {
	srand(time(NULL));
	int n = 60, m = 3;
	cout<<n<<' '<<m<<endl;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 1; ++j) {
			cout<<char(rand() % 26 + 'A');
		}
		cout<<endl;
	}
}
