#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int i,flag,t;	//进位标志 
    char a[105];	//一般开大一点，防止越界 
    cin>>t;
    while(t--){
    	cin>>a;		//getchar()会读空格，回车，不要轻易用。 
    	flag=1;
 		for(i=strlen(a)-1;i>=0;--i){
 			a[i]=a[i]+flag;
 			flag=0;
 			if(a[i]>'9'){
 				a[i]='0';
 				flag=1;
 			}
 		}
    	if(flag==1) cout<<flag;
    	cout<<a<<endl;
    }
    return 0;
}
