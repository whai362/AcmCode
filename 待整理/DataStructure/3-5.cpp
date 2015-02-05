#include<iostream>
using namespace std;
struct LNode{
	int data;
	LNode *next;
};
struct queue{
	LNode *front,*rear;
	queue(){
		front=rear=new LNode;
		rear->next=front;
	}
	bool empty();
	void push(int x);
	int pop();
};
bool queue::empty(){
	if(front==rear)
		return true;
	return false;
}
void queue::push(int x){
	LNode *p=new LNode;
	p->data=x;
	rear->next=p;
	rear=p;
	rear->next=front;
}
int queue::pop(){
	int x=front->next->data;
	LNode *p=front->next;
	if(front->next==rear)
		rear=front;
	else
		front->next=p->next;
	delete p;
	return x;
}
int main(){
	int op,x;
	queue q;
	while(1){
		cout<<"1.入队 2.出队 3.退出: ";
		cin>>op;
		if(op==3) break;
		else if(op==1){
			cout<<"输入入队的数: ";
			cin>>x;
			q.push(x);
		}
		else{
			if(!q.empty()){
				cout<<"出队: ";
				cout<<q.pop()<<endl;
			}
			else
				cout<<"队空"<<endl;
		}
	}
	return 0;
}
