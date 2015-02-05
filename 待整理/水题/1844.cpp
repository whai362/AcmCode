#include<iostream>
#include<math.h>
using namespace std;
int main(){
	long long n,temp,num;
	cin>>num;
	if(num<0) num=-num;
	n=sqrt(2*num);
	temp=(n+1)*n/2;
	while(temp<num){
		++n;
		temp=(n+1)*n/2;			
	}
	if(num%2==0){
		if(temp%2==0) cout<<n<<endl;
		else{
			while(temp%2!=0){
				++n;
				temp=(n+1)*n/2;			
			}
			cout<<n<<endl;
		}
	}
	else{
		if(temp%2==1) cout<<n<<endl;
		else{
			while(temp%2!=1){
				++n;
				temp=(n+1)*n/2;			
			}
			cout<<n<<endl;
		}
	}
	return 0;
}

