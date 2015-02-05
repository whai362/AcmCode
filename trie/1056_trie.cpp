#include<cstdio>
#include<cstring>
using namespace std;
bool flag;
const int MAXB=2;
struct Node
{
	struct Node *br[MAXB];
	int num;
};
Node *head;
void Tree_insert(char str[])//≤Â»Îµ•¥  
{
	if(!flag) return ;
	Node *t,*s=head;
	int i,j;
	int len=strlen(str);
	for(i=0;i<len;i++)
	{
		int id=str[i]-'0';
		if(s->br[id]==NULL)
		{
			t=new Node;
			for(j=0;j<MAXB;j++)
			{
				t->br[j]=NULL;
			}
			t->num=0;
			s->br[id]=t;
		}
		else if(s->br[id]->num>0){
			flag=false;
			return ;
		}
		s=s->br[id];
	}
	++s->num;
}
int Tree_Find(char str[])
{
	Node *s=head;
	int count,i;
	int len=strlen(str);
	for(i=0;i<len;i++)
	{
		int id=str[i]-'0';
		if(s->br[id]==NULL)
		{
			return 0;
		}    
		else
		{
			s=s->br[id];
			count=s->num;
		}    
	}    
	return count;
}    
int main(){
	int cas=0;
	char str[15];
	while(scanf("%s",str)!=EOF){
		head=new Node;
		for(int i=0;i<MAXB;++i){
			head->br[i]=NULL;
			head->num=0;
		}
		flag=true;
		Tree_insert(str);
		while(scanf("%s",str) && str[0]!='9') Tree_insert(str);
		if(flag){
			printf("Set %d is immediately decodable\n",++cas);
		}
		else{
			printf("Set %d is not immediately decodable\n",++cas);
		}
	}
	return 0;
}


