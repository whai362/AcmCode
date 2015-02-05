#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
int size;
struct node{
	node *left,*right;
	int pri,num;
};
node *splay(int pri,node *rt){
	node h,*l,*r,*p;
	if(rt==NULL)
		return rt;
	h.left=h.right=NULL;
	l=r=&h;
	while(1){
		if(pri<rt->pri){
			if(rt->left==NULL)
				break;
			//如果成立，说明是“一字型”旋转
			if(pri<rt->left->pri){
				p=rt->left;	/*rotate right*/
				rt->left=p->right;
				p->right=rt;
				rt=p;
				if(rt->left==NULL)
					break;
			}
			//动态的将中间树的“当前节点”追加到 R 树中，同时备份在header中
			r->left=rt;	/*link right*/
			r=rt;
			rt=rt->left;
		}
		else if(pri>rt->pri){
			if(rt->right==NULL)
				break;
			if(pri>rt->right->pri){
				p=rt->right;
				rt->right=p->right;
				p->left=rt;
				rt=p;
				if(rt->right==NULL)
					break;
			}
			l->right=rt;
			l=rt;
			rt=rt->right;
		}
		else
			break;
	}
	l->right=rt->left;
	r->left=rt->right;
	rt->left=h.right;
	rt->right=h.left;
	return rt;
}
node *insert(int pri,int num,node *rt){
	node *p=new node();
	p->pri=pri;
	p->num=num;
	if(rt==NULL){
		p->left=p->right=NULL;
		size=1;
		return p;
	}
	rt=splay(pri,rt);
	if(pri<rt->pri){
		p->left=rt->left;
		p->right=rt;
		rt->left=NULL;
		++size;
		return p;
	}
	else if(pri>rt->pri){
		p->right=rt->right;
		p->left=rt;
		rt->right=NULL;
		++size;
		return p;
	}
	else{
		delete p;
		return rt;
	}
}
node *gao(){
	node *head=NULL,*p,*q;
	int i;
	for(i=6;i>=2;--i){
		p=new node();
		p->pri=i;
		cout<<i<<endl;
		p->right=NULL;
		if(head==NULL){
			head=p;
		}
		else{
			q->left=p;
		}
		q=p;
	}
	p=NULL;
	return head;
}
void print(node *p){
	if(p){
		cout<<p->pri;
		print(p->left);
		print(p->right);
	}
	else cout<<'*';
}
int main(){
	int n,num,pri;
	node *rt=NULL;
	int i;
	rt=gao();
	print(rt);
	cout<<endl;
	size=5;
	rt=insert(1,5,rt);
	print(rt);
	cout<<endl;
	/*while(scanf("%d",&n) && n){
		switch(n){
			case 1:
				scanf("%d%d",&num,&pri);
				root=insert(pri,num,rt);
				break;
			case 2:
		}
	}*/
	return 0;
}

