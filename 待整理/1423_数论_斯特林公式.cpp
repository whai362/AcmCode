//log10(n!) = log10(sqrt(2 * pi * n)) + n * log10(n / e)斯特林公式
#include <iostream>
#include <cmath>
using namespace std;
#define pi acos(-1.0)
#define e exp(1.0) 
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		double temp,ans;
		cin>>temp;
		if(temp==1.0) cout<<1<<endl;
		else{
		ans=log10(sqrt(2*pi*temp))+temp*log10(temp/e);
		cout<<int(ans+1)<<endl;
		}
	}
	return 0;
}

