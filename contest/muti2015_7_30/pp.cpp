#include <iostream>
#include <fstream>
using namespace std;
ifstream in1("out.txt");
ifstream in2("o.txt");
int main() {
	int a, b;
	int cnt = 0;
	while(in1 >> a) {
		in2 >> b;
		++cnt;
		if(a != b) {
			cout<<cnt<<endl;
			return 0;
		}
	}
}
