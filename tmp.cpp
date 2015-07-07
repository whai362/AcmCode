#include<iostream>
#include<bitset>
using namespace std;
int main(){
	bitset<100> bits,tmp;
	bits[1]=1;
	tmp[10]=1;
	cout<<bits<<endl;
	cout<<tmp<<endl;
	cout<<(bits | tmp)<<endl;
	cout<<(bits & tmp)<<endl;
	return 0;
}
