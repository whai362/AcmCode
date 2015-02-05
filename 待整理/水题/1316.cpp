#include<fstream>
//#include<stdio.h>
#include<string.h>
using namespace std;
ofstream fout("out.txt"); 
int j(int n){
	int sum;
	char a[10];
	for(int i=n/2;i<n;++i){
		sprintf(a,"%d",i);
		//printf("%s\n",a);
		sum=i;
		for(int j=0;j<strlen(a);++j){
			sum=sum+a[j]-48;
		}
		//printf("%d\n",sum);
		if(sum==n) return 0;
	}
	return 1;
}
int main(){
	int i;
	for(i=1;i<1000000;++i) if(j(i)) fout<<i<<',';
	return 0;
}
