#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
	int n = 200000;
	srand(time(NULL));
		for(int i = 0; i < n; ++i) {
			cout<<(char)('a' + rand() % 26);
		}
		cout<<endl;
}
