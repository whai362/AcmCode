#include<stdio.h>
#include<string.h>
const int MAXB=10;
struct Node
{
    struct Node *br[MAXB];
    int num;
};
Node *head;
void Tree_insert(char str[])//≤Â»Îµ•¥  
{
    Node *t,*s=head;
    int i,j;
    int len=strlen(str);
    for(i=0;i<len;i++)
    {
        int id=str[i]-'a';
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
        s=s->br[id];
        s->num++;
    }    
}    
int Tree_Find(char str[])
{
    Node *s=head;
    int count,i;
    int len=strlen(str);
    for(i=0;i<len;i++)
    {
        int id=str[i]-'a';
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
int main()
{
    int i;
    head=new Node;
    for(i=0;i<MAXB;i++)
    {
        head->br[i]=NULL;
        head->num=0;
    }    
    char str[12];
    while(gets(str)&&str[0])  Tree_insert(str);
    while(gets(str))  printf("%d\n",Tree_Find(str));
    return 0;
}
