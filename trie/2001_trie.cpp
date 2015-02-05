#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXB=26;	//修改处1
struct Node{
    struct Node *br[MAXB];
    int num;
};
Node *head;
void Tree_insert(char str[]){ //插入单词
	//cout<<"!"<<str<<endl;
    Node *t,*s=head;
    int len=strlen(str);
    for(int i=0;i<len;i++){
        int id=str[i]-'a'; //修改处2
        if(s->br[id]==NULL){
            t=new Node;
            for(int j=0;j<MAXB;j++){
                t->br[j]=NULL;
            }    
            t->num=0;	//修改处3
            s->br[id]=t;
        }    
        s=s->br[id];
        s->num++;	//修改处4
    }    
}    
void gao(char str[]){
	char ans[25];
	memset(ans,0,sizeof(ans));

	Node *s=head;
	int len=strlen(str);
	for(int i=0;i<len;++i){
		int id=str[i]-'a';
		if(s->br[id]==NULL || s->br[id]->num<2){
			ans[i]=str[i];
			printf("%s %s\n",str,ans);
			return ;
		}
		else{
			s=s->br[id];
			ans[i]=str[i];
		}
	}
	printf("%s %s\n",str,ans);
	return ;
}
char str[1005][25];
int main(){
    head=new Node;
    for(int i=0;i<MAXB;i++){
        head->br[i]=NULL;
        head->num=0;	//修改处7
    }
	int cnt=0;
    while(scanf("%s",str[cnt])!=EOF){
		Tree_insert(str[cnt++]);
	}
	for(int i=0;i<cnt;++i){
		gao(str[i]);
	}
    return 0;
}

