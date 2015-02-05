#include<iostream>
#include<string.h>
using namespace std;
char str[1010];
int main(){
	int i;
	while(cin.getline(str,sizeof(str))){
		for(i=0;i<strlen(str);++i){
			if(str[i]=='y'&&str[i+1]=='o'&&str[i+2]=='u') cout<<"we",i=i+2;
			else cout<<str[i];
		}
		cout<<endl;
	}
	return 0;
}
