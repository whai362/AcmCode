#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;

int level(char opt){
	switch (opt){
		case ')': return 0;
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
		case '(': return 3;
	}
}

int slevel(char opt){
	switch (opt){
		case '(': return 0;
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
	}
}

int calculate(int a,int b,char op){
	switch (op){
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		case '/': return a/b;
	}
}

int main(){
	int i,a,b,num=0;
	char op,str[1000];
	stack<int> n;
	stack<char> opt;
	scanf("%s",str);
	for(i=0;i<strlen(str);++i){
		if(str[i]>='0'&&str[i]<='9'){
			num=num*10+str[i]-48;
			if(str[i+1]<'0'||str[i+1]>'9'){
				n.push(num);
				num=0;
			}
		}
		else{
			if(opt.empty()||level(str[i])>slevel(opt.top())) opt.push(str[i]);
			else{			
				while(level(str[i])<=slevel(opt.top())){
					op=opt.top();
					opt.pop();
					if(op=='(') break;
					b=n.top();
					n.pop();
					a=n.top();
					n.pop();
					a=calculate(a,b,op);
					n.push(a);
					if(opt.empty()) break;
				}
				if(str[i]!=')') opt.push(str[i]);
			}
		}
	}
	while(!opt.empty()){
		op=opt.top();
		opt.pop();
		b=n.top();
		n.pop();
		a=n.top();
		n.pop();
		a=calculate(a,b,op);
		n.push(a);
	}
    printf("%d\n",a);
	return 0;
}
