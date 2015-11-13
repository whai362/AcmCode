#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

int a[105];

int main() {
	srand(time(NULL));
	int T = 100;
	cout<<T<<endl;
	while(T--) {
	int n = 10;
	cout<<n<<endl;
	for(int i = 0; i < n; ++i) {
		cout<<rand() % 16<<' ';
	}
	cout<<endl;
	}
	cout<<endl;
}
