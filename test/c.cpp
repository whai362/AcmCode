#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	//整型的输出
	int a = 123;
	cout<<a<<endl;
	printf("%d\n", a);

	//长整型的输出
	long long b = 12345678910LL;
	__int64 c = 12345678911LL;
	cout<<b<<' '<<c<<endl;
	printf("%lld %I64d\n", b, c);

	//字符串输出
	char str[] = "asdas sadas";
	cout<<str<<endl;
	printf("%s", str);
	
	return 0;
}
