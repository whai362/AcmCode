#include<iostream>
#include<string.h>
using namespace std;
int main(){
	int i,hash[500];
	char str[1000],a[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	for(i=0;i<strlen(a);++i) hash[a[i]]=i;
	while(cin.getline(str,sizeof(str))){
		for(i=0;i<strlen(str);++i) if(str[i]!=' ') str[i]=a[hash[str[i]]-1];
		cout<<str<<endl;
	}
	return 0;
}
