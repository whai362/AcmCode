#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;
int a[209][209];

int main()
{
	srand(time(NULL));
	int n;
	int t=50;
	while(t-->0)
	{
		n=rand()%199+2;
		cout<<n<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{
				if(i==j) a[i][j]=0;
				else a[i][j]=a[j][i]=rand()%50+2;
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout<<a[i][j]<<' ';
			cout<<endl;
		}
	}
	return 0;
}