#include<iostream>
#include<string.h>
using namespace std;
int main(){
	int i,hash[100];
	char imf[250],s[10],s1[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ",s2[]="VWXYZABCDEFGHIJKLMNOPQRSTU";
	for(i=0;i<strlen(s1);++i) hash[s1[i]]=i; 
	while(cin>>s&&strlen(s)!=10){
		cin.get();
		cin.getline(imf,sizeof(imf));
		for(i=0;i<strlen(imf);++i){
			if(imf[i]>='A'&&imf[i]<='Z') imf[i]=s2[hash[imf[i]]];
			cout<<imf[i];
		}
		cout<<endl;
		cin>>s;
	}
	return 0;
}
