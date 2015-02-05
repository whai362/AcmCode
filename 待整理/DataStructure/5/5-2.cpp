#include<iostream>
#include<cstring>
using namespace std;
struct btnode{
	char data;
	btnode *lchild,*rchild;
};
bool cmp(char a,char b,char s[]){
	if(b==0) return true;
	int i,j,len;
	len=strlen(s);
	for(i=0;i<len;++i){
		if(s[i]==a) break;
	}
	for(j=0;j<len;++j){
		if(s[j]==b) break;
	}
	if(i<j) return true;
	return false;
}
btnode *create(int &i,char pre,char s1[],char s2[]){
	char c=s1[i++];
	if(c){
		btnode *p=new btnode();
		p->data=c;
		if(cmp(c,pre,s2)){
			p->lchild=create(i,c,s1,s2);
			if(p->lchild==NULL) --i;
			p->rchild=create(i,pre,s1,s2);
			if(p->rchild==NULL) --i;
		}
		else{
			delete p;
			return NULL;
		}
		return p;
	}
	return NULL;
}
void print(btnode *p){
	if(p){
		cout<<p->data;
		print(p->lchild);
		print(p->rchild);
		return ;
	}
	cout<<'*';
	return ;
}
int main(){
	char s1[]="ABCDEFG",s2[]="CBDAEGF";
	int i=0;
	btnode *root=create(i,0,s1,s2);
	cout<<"DLR(º¬NULL): ";
	print(root);
	cout<<endl;
	return 0;
}
