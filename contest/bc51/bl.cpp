#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;
int main() {
	int p = 12345 * 12443;
	srand(time(NULL));
	int T = 300;
	cout<<T<<endl;
	while(T--) {
		cout<<rand()%p<<' '<<rand()%p * rand()%p<<' '<<rand()%p * rand()%p<<' '<<p<<endl;
	}
}
