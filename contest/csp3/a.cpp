//Memory Time
//2236K  32MS 

#include<iostream>
using namespace std;

int mod[524286];

int main()
{
	int i;
	int n;
	while(cin>>n)
	{
		if(!n)
			break;

		mod[1]=1%n;

		for(i=2;mod[i-1]!=0;i++)
			mod[i]=(mod[i/2]*10+i%2)%n;
		             
		i--;
		int pm=0;
		while(i)
		{
			mod[pm++]=i%2;
			i/=2;
		}
		while(pm)
			cout<<mod[--pm];
		cout<<endl;
	}
	return 0;
}

