#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;
int s[11] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
int sg[1010];

int getsg(int x)
{
	int i;
	if(sg[x] != -1)
		return sg[x];
	bool hash[110];
	memset(hash, 0, sizeof(hash));
	for(i = 0; i < 11; i++)
	{
		if(x >= s[i])
		{
			sg[x - s[i]] = getsg(x - s[i]);
			hash[sg[x - s[i]]] = 1;
		}
	}
	for(i = 0; i < 110; i++)
	{
		if(hash[i] == 0)
			break;
	}
	return i;
}

int main (void)
{
	int i;
	memset(sg, -1, sizeof(sg));
	sg[0] = 0;
	for(i = 1; i < 1010; i++)
		sg[i] = getsg(i);
	for(int i=0;i<10;++i){
		cout<<sg[i]<<' ';
	}
	cout<<endl;
	int n;
	while(scanf("%d", &n) != EOF)
	{
		if(sg[n] == 0)
			printf("Cici\n");
		else
			printf("Kiki\n");		
	}
	return 0;
}
