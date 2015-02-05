#include <cstdio>
#include <iostream>
using namespace std;
char S[100001];
long long C[2][2],E,O;

int main()
{
	scanf ("%s",S);
	for (int i=0;S[i];i++){
		int p = S[i] - 'a', q = i % 2;
		C[p][q]++;
		cout<<C[0][0]<<' '<<C[0][1]<<' '<<C[1][0]<<' '<<C[1][1]<<endl;
		E += C[p][!q];
		O += C[p][q];
	}
	printf ("%lld %lld",E,O);
	return 0;
}
