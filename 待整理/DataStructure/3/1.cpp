#include<iostream>
using namespace std;
#define MAXSIZE 5
struct stack{
	private:
		int top[2],data[MAXSIZE];
	public:
		stack(){
			top[0]=-1;
			top[1]=MAXSIZE;
		}
		void clear(int);
		bool empty(int);
		void push(int,int);
		void pop(int &,int);
};
void stack::clear(int i){
	if(i==1) top[0]=-1;
	else top[1]=MAXSIZE;
}
bool stack::empty(int i){
	if(i==1){
		if(top[0]==-1) return true;
		else return false;
	}
	else{
		if(top[1]==MAXSIZE) return true;
		else return false;
	}
}
void stack::push(int x,int i){
	if(top[0]+1==top[1])
		cout<<"¶ÑÂú"<<endl;
	else if(i==1)
		data[++top[0]]=x;
	else
		data[--top[1]]=x;
}
void stack::pop(int &x,int i){
	if(i==1){
		if(top[0]==-1)
			cout<<"Õ»¿Õ"<<endl;
		else{
			x=data[top[0]];
			--top[0];
		}
	}
	else{
		if(top[1]==MAXSIZE)
			cout<<"Õ»¿Õ"<<endl;
		else{
			x=data[top[1]];
			++top[1];
		}
	}
}
int main(){
	int x;
	stack s;
	s.push(1,1);
	s.push(4,2);
	s.push(9,1);
	s.push(7,1);
	s.push(3,2);
	s.push(1,1);
	while(!s.empty(1)){
		s.pop(x,1);
		cout<<x<<endl;
	}
	while(!s.empty(2)){
		s.pop(x,2);
		cout<<x<<endl;
	}
	return 0;
}
