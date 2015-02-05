#include<iostream>
#include<string.h>
using namespace std;
int main(){
	char str[30];
	int i,j,n,sum,max,a[20];
	while(cin>>n&&n){
		cin.get();
		sum=0,max=0;
		memset(a,0,sizeof(a));
		for(i=0;i<n;++i){
			cin.getline(str,sizeof(str));
			for(j=0;j<strlen(str);++j) if(str[j]=='X') ++a[i];
		}
		for(i=0;i<n;++i) if(a[i]>max) max=a[i];
		for(i=0;i<n;++i) sum=sum+max-a[i];
		cout<<sum<<endl;
	}
	return 0;
}
