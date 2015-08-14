#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
	int n = 100;
	srand(time(NULL));
	for(int j = 0; j < 5; ++j) {
		for(int i = 0; i < n; ++i) {
			cout<<(char)('a' + rand() % 10);
		}
		cout<<endl;
	}
}
