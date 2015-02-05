#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str[100005];
int main(){
	scanf("%s",str);
	int len=strlen(str);
	int p=len-1;
	int pos=-1;
	int flag=0;
	for(int i=0;i<len-1;++i){
		if((str[i]-'0')%2==0){
			pos=i;
			if(str[p]>str[i]){
				flag=1;
				swap(str[i],str[p]);
				break;
			}
		}
	}
	if(pos==-1){
		puts("-1");
	}
	else{
		if(flag==0)
			swap(str[pos],str[p]);
		puts(str);
	}
	return 0;
}
