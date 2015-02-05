#include<iostream>
using namespace std;
struct LNode{
	int data;
	LNode *prior,*next;
};
LNode *create(){
	int num;
	LNode *h=NULL,*p,*q;
	cout<<"输入链表数据(以-1结束): "<<endl;
	while(cin>>num && num!=-1){
		p=new LNode;
		p->data=num;
		if(h==NULL){
			h=p;
			p->prior=NULL;
		}
		else{
			q->next=p;
			p->prior=q;
		}
		q=p;
	}
	p->next=NULL;
	return h;
}
void trans(LNode *&head){
	LNode *p=head,*q;
	while(p){
		q=p->prior;
		p->prior=p->next;
		p->next=q;
		if(p->prior==NULL)
			head=p;
		p=p->prior;
	}
	return ;
}
void print(LNode *head){
	LNode *p=head;
	while(p){
		cout<<p->data<<' ';
		p=p->next;
	}
	cout<<endl;
	return ;
}
int main(){
	LNode *head;
	head=create();
	cout<<"当前链表数据: "<<endl;
	print(head);
	trans(head);
	cout<<"转置后链表数据: "<<endl;
	print(head);
	return 0;
}
