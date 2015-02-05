/*Problem Description
Ignatius最近遇到一个难题,老师交给他很多单词(只有小写字母组成,不会有重复的单词出现),现在老师要他统计出以某个字符串为前缀的单词数量(单词本身也是自己的前缀).
Input
输入数据的第一部分是一张单词表,每行一个单词,单词的长度不超过10,它们代表的是老师交给Ignatius统计的单词,一个空行代表单词表的结束.第二部分是一连串的提问,每行一个提问,每个提问都是一个字符串.
注意:本题只有一组测试数据,处理到文件结束.
Output
对于每个提问,给出以该字符串为前缀的单词的数量.*/
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXB=26;	//修改处1
struct Node{
    struct Node *br[MAXB];
    int num;
};
Node *head;
void Tree_insert(char str[]){	//插入单词
    Node *t,*s=head;
    int i,j;
    int len=strlen(str);
    for(i=0;i<len;i++){
        int id=str[i]-'a'; //修改处2
        if(s->br[id]==NULL){
            t=new Node;
            for(j=0;j<MAXB;j++){
                t->br[j]=NULL;
            }    
            t->num=0;	//修改处3
            s->br[id]=t;
        }    
        s=s->br[id];
        s->num++;	//修改处4
    }    
}    
int Tree_Find(char str[]){
    Node *s=head;
    int count,i;
    int len=strlen(str);
    for(i=0;i<len;i++){
        int id=str[i]-'a';	//修改处5
        if(s->br[id]==NULL){
            return 0;
        }    
        else{
            s=s->br[id];
            count=s->num;	//修改处6
        }    
    }    
    return count;
}
int main(){
    int i;
    head=new Node;
    for(i=0;i<MAXB;i++){
        head->br[i]=NULL;
        head->num=0;	//修改处7
    }    
    char str[12];
    while(gets(str)&&str[0])  Tree_insert(str);
    while(gets(str))  printf("%d\n",Tree_Find(str));
    return 0;
}

