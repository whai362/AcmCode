/*whai*/
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	if(n<=3) puts("NO");
	else{
		puts("YES");
		if(n%2){
			puts("4 * 5 = 20");
			puts("2 - 1 = 1");
			puts("3 + 1 = 4");
			puts("20 + 4 = 24");
			for(int i=6;i<=n;i+=2){
				printf("%d - %d = 1\n",i+1,i);
				puts("24 * 1 = 24");
			}
		}
		else{
			puts("1 * 2 = 2");
			puts("2 * 3 = 6");
			puts("4 * 6 = 24");
			for(int i=5;i<=n;i+=2){
				printf("%d - %d = 1\n",i+1,i);
				puts("24 * 1 = 24");
			}
		}
	}
	return 0;
}
