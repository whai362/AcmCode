#include<cstdio>
#include<iostream>
using namespace std;
int gao(char o[]){
	if(o[0]=='+' || o[0]=='-') return 1;
	else return 2;
}
int cal(int a,int b,char o[]){
	switch(o[0]){
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
		case '%':
			return a%b;
	}
}
int main(){
	char o1[15],o2[15];
	int n1,n2,n3,y1,y2,t;
	cin>>t;
	while(t--){
	cin>>n1>>o1>>n2>>o2>>n3;
	y1=gao(o1);
	y2=gao(o2);
	if(y1>=y2){
		cout<<cal(cal(n1,n2,o1),n3,o2)<<endl;
	}
	else{
		cout<<cal(n1,cal(n2,n3,o2),o1)<<endl;
	}
	}
	return 0;
}
