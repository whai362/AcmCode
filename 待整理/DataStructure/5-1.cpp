#include<iostream>
#include<stack>
using namespace std;
struct btnode{
	char data;
	int ltag,rtag;
	btnode *lchild,*rchild;
};
char getChar(char str[]){
	static int i=0;
	return str[i++];
}
btnode *createbt(char str[]){
	char c=getChar(str);
	if(c!='*'){
		btnode *p=new btnode();
		p->data=c;
		p->lchild=createbt(str);
		p->rchild=createbt(str);
		return p;
	}
	return NULL;
}
void DLR(btnode *p){
	if(p){
		cout<<p->data;
		DLR(p->lchild);
		DLR(p->rchild);
	}
}
void LDR(btnode *p){
	if(p){
		LDR(p->lchild);
		cout<<p->data;
		LDR(p->rchild);
	}
}
void LRD(btnode *p){
	if(p){
		LRD(p->lchild);
		LRD(p->rchild);
		cout<<p->data;
	}
}
int count(btnode *p){
	int cnt;
	if(p){
		cnt=count(p->lchild);
		cnt+=count(p->rchild);
		if(!cnt) return 1;
		else return cnt;
	}
	return 0;
}
int high(btnode *p){
	if(p){
		return max(high(p->lchild),high(p->rchild))+1;
	}
	return 0;
}
void swap(btnode *p){
	if(p){
		btnode *q;
		q=p->lchild;
		p->lchild=p->rchild;
		p->rchild=q;
		swap(p->lchild);
		swap(p->rchild);
	}
}
btnode *copy(btnode *p){
	if(p){
		btnode *q=new btnode();
		q->data=p->data;
		q->lchild=copy(p->lchild);
		q->rchild=copy(p->rchild);
		return q;
	}
	return NULL;
}
//选做题
void LRD1(btnode *root){	//非递归后序遍历
	btnode *p=copy(root),*q;	//为了不破坏二叉树的结构，复制了一棵二叉树
	stack<btnode *> s;
	while(p || !s.empty()){
		for(;p;p=p->lchild) s.push(p);
		p=s.top();
		if(p->rchild){
			q=p->rchild;
			p->rchild=NULL;
			p=q;
			continue;
		}
		s.pop();
		cout<<p->data;
		p=NULL;
	}
}
void InThr(btnode *p,btnode *&pre){
	if(p){
		InThr(p->lchild,pre);
		if(p->lchild==NULL){
			p->ltag=1;
			p->lchild=pre;
		}
		if(pre->rchild==NULL){
			pre->rtag=1;
			pre->rchild=p;
		}
		pre=p;
		InThr(p->rchild,pre);
	}
}
btnode *InorderThread(btnode *p){
	btnode *thrt=new btnode();
	thrt->ltag=0;
	thrt->rtag=1;
	thrt->rchild=thrt;
	if(p==NULL) thrt->lchild=thrt;
	else{
		thrt->lchild=p;
		btnode *pre=thrt;
		InThr(p,pre);
		pre->rchild=thrt;
		pre->rtag=1;
		thrt->rchild=pre;
	}
	return thrt;
}
void LDR2(btnode *head){	//线索二叉树中序遍历
	btnode *p=head->lchild;
	while(p!=head){
		while(p->ltag==0) p=p->lchild;
		cout<<p->data;
		while(p->rtag==1 && p->rchild!=head){
			p=p->rchild;
			cout<<p->data;
		}
		p=p->rchild;
	}
}
int main(){
	char str[]="ABD*F***CE***";
	btnode *root=createbt(str);
	cout<<"DLR: ";
	DLR(root);
	cout<<endl<<"LDR: ";
	LDR(root);
	cout<<endl<<"LRD: ";
	LRD(root);
	cout<<endl;
	cout<<count(root)<<endl;
	cout<<high(root)<<endl;
	swap(root);
	cout<<"DLR: ";
	DLR(root);
	cout<<endl<<"LDR: ";
	LDR(root);
	cout<<endl<<"LRD: ";
	LRD(root);
	cout<<endl<<"LRD1: ";
	LRD1(root);
	cout<<endl;
	btnode *head=InorderThread(root);
	cout<<"LDR2: ";
	LDR2(head);
	cout<<endl;
	return 0;
}
