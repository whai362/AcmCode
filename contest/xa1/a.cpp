#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string str,
	   ap[4]={"Apple", "iPhone", "iPod", "iPad"},
	   so="Sony";
int main(){
	ios_base::sync_with_stdio(false);
	while(cin>>str){
		int flag=0,len=str.length();
		for(int i=0;i<4;++i){
			int it=str.find(ap[i]);
			if(it>=0 && it<len){
				flag=1;
				break;
			}
		}
		if(flag){
			puts("MAI MAI MAI!");
		}
		//cout<<str.find(so)<<endl;
		int it=str.find(so);
		if(it>=0 && it<len){
			puts("SONY DAFA IS GOOD!");
		}
	}
	return 0;
}
