#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char hash[256];
int main(){
	char code[30],word[100];
	int i;
	scanf("%s",code);
	getchar();
	memset(hash,0,sizeof(hash));
	for(i='a';i<='z';++i)
	  hash[i]=code[i-'a'];
	cin.getline(word,sizeof(word));
	for(i=0;i<strlen(word);++i){
		if(word[i]!=' '){
			if(word[i]>='a' && word[i]<='z')
			  printf("%c",hash[word[i]]);
			else
			  printf("%c",hash[word[i]-'A'+'a']-'a'+'A');
		}
		else printf(" ");
	}
	printf("\n");
	return 0;
}
