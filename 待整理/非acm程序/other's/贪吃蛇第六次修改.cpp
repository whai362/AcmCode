#include <iostream.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>  //使用当前时间做种子;
#include <iomanip.h>
#pragma  comment(lib,"winmm.lib")
enum dir{up,down,left,right};  //枚举类型enum dir;
char pp=0;
int aa=0,bb=0;
float tt=0;
class player{
public:
	char name[2][20];
	int scordrember[2][100];
	char woner[100];
}p;
class Fence{
public:
	void InputFence();
	void OutputFence();
public:
	char game[20][20];
}f; //定义对象;
//画框框;
void Fence::InputFence()
{
	for(int i=0; i<20; i++)
		for(int j=0; j<20; j++)
		{
			if(i==0||i==19)
				game[i][j]= '-';
			else 
				if(j==0||j==19)
					game[i][j]='|';
				else 
					game[i][j]=' ';
		}
	game[8][8]='*';game[8][9]='*';game[8][10]='*';game[9][10]='*';game[10][10]='*';game[11][10]='*';
}
//蛇结点;
class SnakeNode1{
private:
	int x1,y1;
	SnakeNode1 *prior1,*next1;
public:
	int Scord1;
	void add_head1(int x1,int y1);
	int get_x1();
	int get_y1();
	void delete_tail1();
	void SCORD1();
	void Delete1(SnakeNode1 *root);
}player1,*head1=NULL,*tail1=NULL;
void SnakeNode1::Delete1(SnakeNode1 *root)
{
	if (root!=NULL)
		Delete1(root->next1);
	delete root;
} 
class SnakeNode2{
private:
	int x2,y2;
	SnakeNode2 *prior2,*next2;
public:
	int Scord2;
	void add_head2(int x2,int y2);
	int get_x2();
	int get_y2();
	void delete_tail2();
	void SCORD2();
	void Delete2(SnakeNode2 *root);
}player2,*head2=NULL,*tail2=NULL;
void SnakeNode2::Delete2(SnakeNode2 *root)
{
	if (root!=NULL)
		Delete2(root->next2);
	delete root;
}
//显示框框;
void Fence::OutputFence(){
	for(int i=0; i<20; i++)
	{
		for(int j=0; j<=20; j++)
			if (j!=20)
				cout<<game[i][j]<<' ';
			else
			{
				if (i==2)
					cout<<"剩余时间："<<tt;
				if (i==3)
					cout<<p.name[0]<<"的当前分数是::"<<player1.Scord1;
				if (i==4)
					cout<<p.name[1]<<"的当前分数是::"<<player2.Scord2;
			}
		cout<<endl;
	}
}
void SnakeNode1::SCORD1()
{
	player1.Scord1=0;
}
void SnakeNode2::SCORD2()
{
	player2.Scord2=0;
}
//插入头结点;
void SnakeNode1::add_head1(int x,int y){
	SnakeNode1 *q=new SnakeNode1;

	q->x1 =x; q->y1 =y;
	q->next1 =head1;
	q->prior1 =NULL;
	if(head1) head1->prior1 =q;
	head1=q;
	if(!tail1) tail1 =head1;
	f.game[x][y]= '*';  //f对象可以在定义Fence类时定义; 且Fence类在SnakeNode类前定义;
}
void SnakeNode2::add_head2(int x,int y){
	SnakeNode2 *q=new SnakeNode2;
	q->x2 =x; q->y2 =y;
	q->next2 =head2;
	q->prior2 =NULL;
	if(head2) head2->prior2 =q;
	head2=q;
	if(!tail2) tail2 =head2;
	f.game[x][y]= '*';  //f对象可以在定义Fence类时定义; 且Fence类在SnakeNode类前定义;
}

int SnakeNode1::get_x1(){
	return x1;
}
int SnakeNode2::get_x2(){
	return x2;
}

int SnakeNode1::get_y1(){
	return y1;
}
int SnakeNode2::get_y2(){
	return y2;
}

//删除尾结点;
void SnakeNode1::delete_tail1(){
	SnakeNode1 *p =tail1;
	f.game[tail1->get_x1()][tail1->get_y1()]= ' ';//把尾结点的坐标表示的'*'置为空格;
	if(tail1==head1)
	tail1=head1=NULL;
	else{
		tail1=tail1->prior1;
		tail1->next1=NULL;
	}
	delete p;
}
void SnakeNode2::delete_tail2(){
	SnakeNode2 *p =tail2;
	f.game[tail2->get_x2()][tail2->get_y2()]= ' ';//把尾结点的坐标表示的'*'置为空格;
	if(tail2==head2)
	tail2=head2=NULL;
	else{
		tail2=tail2->prior2;
		tail2->next2=NULL;
	}
	delete p;
}

//move移动;
class move1{
public:
	dir point1,point2;    //枚举变量point: 控制方向;
	int food_x1;
	int food_y1;
	move1()
	{
		point1=down;
		point2=up;
	}
	int moving1();
	int moving2();
	void change_point1(int &);  //改变方向;	//改
	void get_food1();
};
int move1::moving1(){
	int a,b;
	a= head1->get_x1();  //取得头结点横坐标
	b= head1->get_y1();  //头结点纵坐标
	switch(point1)
	{
		case up: --a; 
			break;
		case down: ++a;
			break;
		case left: --b; 
			break;
		case right: ++b; 
			break;
	}
	if(a==19||b==19||a==0||b==0||f.game[a][b]=='*'){//判断是否撞墙;
		for(int i=0;i<100;i++){
			if(p.scordrember[0][i]==0){
				p.scordrember[0][i]=player1.Scord1;}
		}
		for(int j=0;j<100;j++)
			{
				if(p.scordrember[1][j]==0)
					p.scordrember[1][j]=player2.Scord2;
			}
	//	player2.Scord2=0;
	//	player1.Scord1=0;
		player1.Scord1-=5;
		cout<<p.name[0]<<"撞死!!!减5分"<<endl;
		cout<<p.name[1]<<"请再接再励!!!"<<endl;
		if(tt>0){
		while(1){
		cout<<"请键入y继续第二轮游戏:";
		cin>>pp;
		if(pp=='y'||pp=='Y'){
			return 1;
		    break;}
		else
			cout<<"输入错误，请重新输入...";
		}
		}
		/*if(tt<=0)
			return 0;*/
	}
	if(a==food_x1 && b==food_y1){					//吃food;
		head1->add_head1(a,b);
		player1.Scord1++;
		get_food1();
		return 3;
	}
	else if(a==aa&&b==bb){
	head1->add_head1(a,b);
	player1.Scord1+=4;
	return 3;
	}
	else{
		head1->add_head1(a,b); //插入头结点;
	    head1->delete_tail1(); //删除尾结点;
		return 3;
	}
}
int move1::moving2()
{
	int a;int b;
	a= head2->get_x2();  //取得头结点横坐标
	b= head2->get_y2();  //头结点纵坐标
	switch(point2)
	{	
		case up: --a; 
			break;
		case down: ++a;
			break;
		case left: --b; 
			break;
		case right: ++b; 
			break;
		case 'n':break; 
	}
	if(a==19||b==19||a==0||b==0||f.game[a][b]=='*'){//判断是否撞墙;	
		for(int i=0;i<100;i++){
			if(p.scordrember[0][i]==0){
				p.scordrember[0][i]=player1.Scord1;}
		}
		for(int j=0;j<100;j++)
			{
				if(p.scordrember[1][j]==0)
					p.scordrember[1][j]=player2.Scord2;
			}
		//player2.Scord2=0;
		//player1.Scord1=0;
		player2.Scord2-=5;
		cout<<p.name[1]<<"撞死!!!减5分"<<endl;
		cout<<p.name[0]<<"请再接再励!!!"<<endl;
		if(tt>0){
		while(1){
		cout<<"请键入y继续第二轮游戏:";
		cin>>pp;
		if(pp=='y'||pp=='Y'){
			return 1;
		    break;}
		else
			cout<<"输入错误，请重新输入...";
		}
		}
	/*	if(tt<=0)
			return 0;*/
	}
	if(a==food_x1 && b==food_y1){					//吃food;
		head2->add_head2(a,b);
		player2.Scord2++;
		get_food1();
		return 3;
	}
	else if(a==aa&&b==bb){
	head2->add_head2(a,b);
	player2.Scord2+=4;
	return 3;}
	else{
		head2->add_head2(a,b); //插入头结点;
	    head2->delete_tail2(); //删除尾结点;
		return 3;
	}
}

void move1::change_point1(int &flag)	//改
{
	switch(getch())
	{
		case 'W':	case 'w':if (point1!=down)
								point1=up;
							break;
		case 'S':	case 's':if (point1!=up)
								point1=down;
							break;
		case 'A':	case 'a':if (point1!=right)
								point1=left;
							break;
		case 'D':	case 'd':if (point1!=left)
								point1=right;
							break;
				case 72:if (point2!=down)
							point2=up;
						break;
				case 80:if (point2!=up)
							point2=down;
						break;
				case 75:if (point2!=right)
							point2=left;
						break;
				case 77:if (point2!=left)
							point2=right;
						break;
				case 'n':flag=1;	//改
						 break; 
	}
}
void move1::get_food1(){
	while(1)
	{
		srand((unsigned int) time(NULL)); //做种子(程序运行时间); 
		food_x1= rand()%18+1; 
		food_y1= rand()%18+1;
		if(f.game[food_x1][food_y1]==' ')
		{
			f.game[food_x1][food_y1]=3;
			if((food_x1==3||food_y1==18||food_x1==4||food_x1==5)&&f.game[aa][bb]!=4)
			{
				aa=rand()%18+1;
				bb=rand()%18+1;
				if(f.game[aa][bb]==' ')
					f.game[aa][bb]=4;
			}
			break;
		}
		else
			continue;
	}
}
void judgewoner()
{
	int a,b;
	a=player1.Scord1;
	b=player2.Scord2;
	if(a>b)
		cout<<p.name[0]<<"略胜一筹";
    if(a<b)
		cout<<p.name[1]<<"略胜一筹";
    if(a=b)
	   cout<<p.name[0]<<"和"<<p.name[1]<<"棋逢对手";
}
int main(){
	char x,y;
	int cc=4,dd=4;
	int flag;	//改
	cout<<"********************************************************"<<endl;
	cout<<"     *****   *        *       *       *   *   ******    "<<endl;
	cout<<"    *        * *      *     *   *     *  *    *         "<<endl;
	cout<<"      ***    *   *    *    *******    * *     *****     "<<endl;
	cout<<"          *  *     *  *   *       *   * *     *         "<<endl;
	cout<<"    ******   *        *  *         *  *    *  ******    "<<endl;
	cout<<"********************************************************"<<endl;
	cout<<"玩家1使用"<<"w,s,a,d"<<"来控制小蛇的方向!!!"<<endl;
	cout<<"玩家2使用方向键来控制小蛇的方向!!!"<<endl;
	void SnakeNode1::SCORD1();
	void SnakeNode2::SCORD2();
	cout<<"请输入玩家姓名："<<endl;
	cout<<"玩家1:";
	cin>>p.name[0];
	cout<<"玩家2:";
	cin>>p.name[1];
	cout<<"请键入游戏时间(单位：s):";
	char ttp[1000];
	while (cin>>ttp)
	{
		int i=0;
		for (i=0;i<strlen(ttp);i++)
			if (ttp[i]>'9' || ttp[i]<'0')
				break;
		if (i==strlen(ttp))
			break;
		else
			cout<<"你输入的不是整型数据，请重新输入："<<endl;
	}
	sscanf(ttp,"%f",&tt);
	flag=0;	//改
	while(1)
	{
	mciSendString("play 1.mp3 repeat",NULL,0,NULL);
	move1 m;
	f.InputFence();
	player1.add_head1(4,3);
	player1.add_head1(4,4);
	player1.add_head1(4,5);
	
	player2.add_head2(14,14);
	player2.add_head2(14,15);
	player2.add_head2(14,16);
	
	m.get_food1();
	f.OutputFence();
	while (true)
	{
		if (kbhit())
		{
			m.change_point1(flag);	//改
			if(flag) break;	//改
		}
		if (!kbhit())//判断有没有按键落下;
		{
			if(tt<=0){
				cout<<p.name[0]<<"的分数是"<<player1.Scord1<<endl;
				cout<<p.name[1]<<"的分数是"<<player2.Scord2<<endl;
				if(player1.Scord1>player2.Scord2){
					cout<<p.name[0]<<"略胜一筹"<<endl;}
				else if(player1.Scord1<player2.Scord2){
					cout<<p.name[1]<<"略胜一筹"<<endl;}
				else if(player1.Scord1==player2.Scord2){
					cout<<p.name[0]<<"和"<<p.name[1]<<"棋逢对手"<<endl;}
				exit(0);
				}
			system("cls");  //清屏函数;
			cc=m.moving1();
		   if(cc==1)
			{
			   dd=1;
			   break;
			}
			cc=m.moving2();
			if(cc==1)
			{
				dd=1;
				break;
			}
			f.OutputFence();
			Sleep(500);//暂停时间，控制游戏速度；
			tt-=0.5;
		}
	}
	if(flag) break;
    if(dd==1){
	head1=NULL;
	head2=NULL;
	tail1=NULL;
	tail2=NULL;
	continue;
	}
	else
		break;
	}
	return 0;
}
//void T_game::savegame(void)//保存游戏
//{
//	freopen("Save\\savegame.txt","w",stdout);
	
//	printf("%d %d\n",pr,pl);
//	for (int i=0;i<=high;i++)
//	{
//		for (int j=0;j<=width;j++)
//			if (j!=width)
//				printf("%d ",scr[i][j]);
//			else
//				printf("%d",scr[i][j]);
//		printf("\n");
//	}
//	printf("%d\n",score);
//	printf("%d\n",life);
//	FINISH=clock();
//	double totaltime=(double)(FINISH-START)/CLOCKS_PER_SEC;			
//	printf("%.2lf\n",totaltime);

//	fclose(stdout);
//}
//*void T_game::loadgame()//载入游戏进度
//{
//	freopen("Save\\savegame.txt","r",stdin);
//	scanf("%d%d",pr,pl);
//	for (int i=0;i<=high;i++)
//	{
//		for (int j=0;j<=width;j++)
//			scanf("%d",scr[i][j]);
//	}
//	scanf("%d",score);
//	scanf("%d",life);
//	printf("%.2lf",START);
//	
//	fclose(stdin);
//}