#include<iostream>
using namespace std;
struct LNode{
	int coef,exp;
	LNode *next;
};
LNode *create(){
	int coef,exp;
	LNode *h,*p;
	h=p=new LNode;
	h->coef=h->exp=0;
	cout<<"输入多项式(以0 0结束): "<<endl;
	while(cin>>coef>>exp && (coef || exp)){
		p->next=new LNode;
		p=p->next;
		p->coef=coef;
		p->exp=exp;
	}
	p->next=h;
	return h;
}
int cmp(int a,int b){
	if(a>b) return -1;
	else if(a==b) return 0;
	else return 1;
}
LNode *add(LNode *h1,LNode *h2){
	int tmp;
	LNode *h,*p1,*p2,*q,*r;
	p1=h1->next;
	p2=h2->next;
	h=q=r=new LNode;
	h->coef=h->exp=0;
	while(p2!=h2){
		r->next=new LNode;
		q=r->next;
		switch(cmp(p1->exp,p2->exp)){
			case -1:
				q->exp=p1->exp;
				q->coef=p1->coef;
				p1=p1->next;
				break;
			case 0:
				tmp=p1->coef+p2->coef;
				if(tmp==0){
					delete q;
					p1=p1->next;
					p2=p2->next;
					continue;
				}
				q->exp=p1->exp;
				q->coef=tmp;
				p1=p1->next;
				p2=p2->next;
				break;
			case 1:
				q->exp=p2->exp;
				q->coef=p2->coef;
				p2=p2->next;
				break;
		}
		r=q;
	}
	r->next=h;
	return h;
}
void print(LNode *h){
	LNode *p=h->next;
	while(p!=h){
		if(p->exp==0){
			cout<<p->coef;
		}
		else if(p->exp==1){
			if(p->coef!=1) cout<<p->coef;
			cout<<"x";
		}
		else{
			if(p->coef!=1) cout<<p->coef;
			cout<<"x^"<<p->exp;
		}
		if(p->next!=h && p->next->coef>0) cout<<"+";
		p=p->next;
	}
	cout<<endl;
	return ;
}
LNode *mul(LNode *h1,LNode *h2){
	int coef,exp;
	LNode *h,*p1,*p2,*q,*r,*tmp;
	p1=h1->next;
	h=new LNode;
	h->coef=h->exp=0;
	h->next=h;
	while(p1!=h1){
		p2=h2->next;
		tmp=q=r=new LNode;
		tmp->coef=tmp->exp=0;
		while(p2!=h2){
			r->next=new LNode;
			q=r->next;
			coef=p1->coef*p2->coef;
			exp=p1->exp+p2->exp;
			if(coef==0){
				delete q;
				p2=p2->next;
				continue;
			}
			q->coef=coef;
			q->exp=exp;
			r=q;
			p2=p2->next;
		}
		r->next=tmp;
		h=add(h,tmp);
		p1=p1->next;
	}
	return h;
}
int main(){
	LNode *h,*h1,*h2;
	h1=create();
	h2=create();
	h=mul(h1,h2);
	cout<<"结果: "<<endl;
	print(h);
	return 0;
}
