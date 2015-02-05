#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <conio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")
#define N 35
using namespace std;
clock_t START,FINISH;
const char gameover[10][57]={
							{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                            {' ',' ','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*',' ',' '},
							{'*',' ',' ','.','.','.',' ',' ',' ',' ',' ','.',' ',' ',' ',' ',' ',' ','.',' ','.',' ',' ',' ','.','.','.','.','.',' ',' ','.','.','.',' ','.',' ',' ',' ',' ',' ',' ',' ','.','.','.','.','.','.',' ','.','.','.','.',' ',' ','*'},
							{'*',' ','.',' ',' ',' ','.',' ',' ',' ','.',' ','.',' ',' ',' ',' ','.',' ','.',' ','.',' ',' ','.',' ',' ',' ',' ',' ',':',' ',' ',' ',':',' ','.',' ',' ',' ',' ',' ','.',' ','.',' ',' ',' ',' ',' ','.',' ',' ',' ','.',' ','*'},
							{'*',' ','.',' ','.','.','.',' ',' ','.','.','.','.','.',' ',' ','.',' ',' ','.',' ',' ','.',' ','.','.','.','.','.',' ',':',' ',' ',' ',':',' ',' ','.',' ',' ',' ','.',' ',' ','.','.','.','.','.',' ','.',' ','.','.',' ',' ','*'},
							{'*',' ','.',' ',' ',' ','.',' ','.',' ',' ',' ',' ',' ','.',' ','.',' ',' ','.',' ',' ','.',' ','.',' ',' ',' ',' ',' ',':',' ',' ',' ',':',' ',' ',' ','.',' ','.',' ',' ',' ','.',' ',' ',' ',' ',' ','.',' ',' ','.',' ',' ','*'},
							{'*',' ',' ','.','.','.',' ','.',' ',' ',' ',' ',' ',' ',' ','.','.',' ',' ','.',' ',' ','.',' ','.','.','.','.','.',' ',' ','.','.','.',' ',' ',' ',' ',' ','.',' ',' ',' ',' ','.','.','.','.','.',' ','.',' ',' ',' ','.',' ','*'},
							{' ',' ','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*',' ',' '},
							{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}, 
							{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							};
const char startgame[10][57]={
							{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                            {' ',' ','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*',' ',' '},
							{'*',' ',' ','.','.','.',' ',' ',' ',' ',' ','.',' ',' ',' ',' ',' ',' ','.',' ','.',' ',' ',' ','.','.','.','.','.',' ',' ','.','.','.',' ','.',' ',' ',' ',' ',' ',' ',' ','.','.','.','.','.','.',' ','.','.','.','.',' ',' ','*'},
							{'*',' ','.',' ',' ',' ','.',' ',' ',' ','.',' ','.',' ',' ',' ',' ','.',' ','.',' ','.',' ',' ','.',' ',' ',' ',' ',' ',':',' ',' ',' ',':',' ','.',' ',' ',' ',' ',' ','.',' ','.',' ',' ',' ',' ',' ','.',' ',' ',' ','.',' ','*'},
							{'*',' ','.',' ','.','.','.',' ',' ','.','.','.','.','.',' ',' ','.',' ',' ','.',' ',' ','.',' ','.','.','.','.','.',' ',':',' ',' ',' ',':',' ',' ','.',' ',' ',' ','.',' ',' ','.','.','.','.','.',' ','.',' ','.','.',' ',' ','*'},
							{'*',' ','.',' ',' ',' ','.',' ','.',' ',' ',' ',' ',' ','.',' ','.',' ',' ','.',' ',' ','.',' ','.',' ',' ',' ',' ',' ',':',' ',' ',' ',':',' ',' ',' ','.',' ','.',' ',' ',' ','.',' ',' ',' ',' ',' ','.',' ',' ','.',' ',' ','*'},
							{'*',' ',' ','.','.','.',' ','.',' ',' ',' ',' ',' ',' ',' ','.','.',' ',' ','.',' ',' ','.',' ','.','.','.','.','.',' ',' ','.','.','.',' ',' ',' ',' ',' ','.',' ',' ',' ',' ','.','.','.','.','.',' ','.',' ',' ',' ','.',' ','*'},
							{' ',' ','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*',' ',' '},
							{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}, 
							{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
							};     
int new_or_continue;//1为new,0为continue; 
int new_or_exit;////1为new,0为exit;                
char name[1000];
class T_game
{
private:
	int scr[22][N],pl,pr,width,high,speed,density,score,life,pp,dp;
	int num,nm,nu,np,npt,nl; 
	int pll,plr,pru,prd;
public:
	T_game()
	{
		memset(scr,0,sizeof(scr));
		/*scr[22][N]={0};*/
		width=24;high=21;speed=3;density=15;score=0;life=3;pp=0;dp=0;
		pr=21;pl=width/2;
		num=0;nm=0;nu=0;np=0;npt=100/*20控制三机时间*/;nl=0; 
		pll=0;plr=width-2;pru=0;prd=high;
		scr[21][pl]=1;
		scr[0][5]=3;
	}
	void printstartgame(void);//输出游戏开始函数
	void printgameover(void);//输出游戏结束函数 
	void print(int [][N]);//输出函数
	void movebul(int [][N]);//子弹移动函数 
	void movepla(int [][N]);//敌机移动函数 
	void setting();//设置函数 
	void menu(void);//菜单函数
	void Up(void);//上的操作
	void Down(void);//下的操作
	void Left(void);//左的操作
	void Right(void);//右的操作
	void Black(void);//空格键操作
	void Play(void);//游戏全局控制
	void savegame(void);//保存游戏
	void loadgame(void);//载入游戏进度
	void newrank(void);//更新排行榜
	void loadrank(void);//载入排行榜
	void setnewgame(void);//新游戏重置
	void nowtime(void);//显示当前时间 
};
void T_game::Up()//上的操作
{
	if (dp==0) 
		pru=0;
	else
		pru=1;
	if(pr>pru) 
	{
		if (scr[pr-1][pl]==3)
		{
			scr[pr-1][pl]=0;
			scr[pr][pl]=0;
			life--;
			pr=21;pl=9;
			scr[pr][pl]=1;
		}
		else
		{
			scr[pr][pl]=0,scr[--pr][pl]=1;
			if (dp==1)
			{
				scr[pr+2][pl-1]=0,scr[pr+2][pl+1]=0;//
				scr[pr+1][pl-1]=1,scr[pr+1][pl+1]=1;
				np++;
				if (np>npt) np=0,dp=0;
			}
			else//消除飞机消失时留下的残影
			{
				if (scr[pr+2][pl-1]==1) scr[pr+2][pl-1]=0;
				if (scr[pr+2][pl+1]==1) scr[pr+2][pl+1]=0;
			}
		}
	}
	return;
	//mciSendString("play fj.wav",NULL,0,NULL);
}
void T_game::Down()//下的操作
{
	
	if (dp==0)	
		prd=high;
	else
		prd=high-1;
	if (pr<prd) 
	{
		if (scr[pr+1][pl]==3)
		{
			scr[pr+1][pl]=0;
			scr[pr][pl]=0;
			life--;
			pr=21;pl=9;
			scr[pr][pl]=1;
		}
		else
		{
			scr[pr][pl]=0,scr[++pr][pl]=1;
			if (dp==1)
			{
				scr[pr][pl-1]=0,scr[pr][pl+1]=0;//
				scr[pr+1][pl-1]=1,scr[pr+1][pl+1]=1;
				np++;
				if (np>npt) np=0,dp=0;
			}
			else//消除飞机消失时留下的残影
			{
				if (scr[pr][pl-1]==1) scr[pr][pl-1]=0;
				if (scr[pr][pl+1]==1) scr[pr][pl+1]=0;
			}
		}
	}
	//mciSendString("play fj.wav",NULL,0,NULL);
}
void T_game::Left()//左的操作
{
	if (dp==0) 
		pll=0;
	else 
		pll=1;
	if(pl>pll)
	{
		if (scr[pr][pl-1]==3)
		{
			scr[pr][pl-1]=0;
			scr[pr][pl]=0;
			life--;
			pr=21;pl=9;
			scr[pr][pl]=1;
		}
		else
		{
			scr[pr][pl]=0,scr[pr][--pl]=1;
			if (dp==1)
			{
				scr[pr+1][pl]=0,scr[pr+1][pl+2]=0;//
				scr[pr+1][pl-1]=1,scr[pr+1][pl+1]=1;
				np++;
				if (np>npt) np=0,dp=0;
			}
			else//消除飞机消失时留下的残影
			{
				if (scr[pr+1][pl]==1) scr[pr+1][pl]=0;
				if (scr[pr+1][pl+2]==1) scr[pr+1][pl+2]=0;
			}
		}
	}
	//mciSendString("play fj.wav",NULL,0,NULL);
}
void T_game::Right()//右的操作
{
	if (dp==0) 
		plr=width-2;
	else 
		plr=width-3;
	if(pl<plr) 
	{
		if (scr[pr][pl+1]==3)
		{
			scr[pr][pl+1]=0;
			scr[pr][pl]=0;
			life--;
			pr=21;pl=9;
			scr[pr][pl]=1;
		}
		else
		{
			scr[pr][pl]=0,scr[pr][++pl]=1;
			if (dp==1)
			{
				scr[pr+1][pl]=0,scr[pr+1][pl-2]=0;//
				scr[pr+1][pl-1]=1,scr[pr+1][pl+1]=1;
				np++;
				if (np>npt) np=0,dp=0;
			}
			else//消除飞机消失时留下的残影
			{
				if (scr[pr+1][pl]==1) scr[pr+1][pl]=0;
				if (scr[pr+1][pl-2]==1) scr[pr+1][pl-2]=0;
			}
		}
	}
	//mciSendString("play fj.wav",NULL,0,NULL);
}
void T_game::Black()//空格键操作
{
	if (dp==1)   //三架飞机时产生三弹
	{
		scr[pr-1][pl]=2;
		scr[pr][pl-1]=2,scr[pr][pl+1]=2;
	}
	else
	{
		if (pp==1)//产生双弹
		{
			scr[pr-1][pl-1]=2,scr[pr-1][pl+1]=2,num++;
			if (num>20) 
				pp=0,num=0;
		}
		else
			scr[pr-1][pl]=2;
	}
}
void T_game::printstartgame()//输出游戏结束函数
{
	system("cls");
	for (int i=0;i<10;i++)
	{
		for (int j=0;j<57;j++)
			printf("%c",startgame[i][j]);
		printf("\n");
	}
	nowtime();
	printf("          NEW GAME [N]    OR     CONTINUE [C]\n");
	bool c=true;
	while (c)
	{
		switch (getch())
		{
			case 67:case 99:
				new_or_continue=0;
				c=false;
				break;
			case 78:case 110:
				new_or_continue=1;
				c=false;
				break;
			default:c=true;
		}
	}
}
void T_game::printgameover()//输出游戏结束函数
{
	system("cls");
	for (int i=0;i<10;i++)
	{
		for (int j=0;j<57;j++)
			printf("%c",gameover[i][j]);
		printf("\n");
	}
	printf("          NEW GAME [N]    OR     EXIT [E]\n");
	bool c=true;
	while (c)
	{
		switch (getch())
		{
			case 78:case 110:
				new_or_exit=1;
				c=false;
				break;
			case 69:case 101:
				new_or_exit=0;
				c=false;
				break;
			default:c=true;
		}
	}
	return;
}
void T_game::print(int a[][N])//输出函数
{
	system("cls"); 
	int i,j;
	for (i=0;i<=high;i++)
	{
		a[i][width-1]=4;
		for(j=0;j<width;j++) 
		{
			if (a[i][j]==-1)
			{
				printf("+");
			}
			if (a[i][j]==-2)
			{
				printf("D");
			}
			if (a[i][j]==-3)
			{
				printf("L");
			}
			if (a[i][j]==-4)
			{
				printf("P");
			}
			if (a[i][j]==0)
				printf(" ");
			if (a[i][j]==1)
				printf("\5");//输出我机的符号
			if (a[i][j]==2)
			{
				//mciSendString("play 1.mp3",NULL,0,NULL);
				printf(".");//子弹
			}
			if (a[i][j]==3)
				printf("\3"); //输出敌机符号 
			if (a[i][j]==4)
				printf("|"); 
			if (i==0 && j==width-1) 
				printf("Score: %d",score);//右上角显示得分
			if (i==1 && j==width-1)
				printf("Life: %d",life);
			if (i==2 && j==width-1)
				printf("Set: Esc");
			if (i==3 && j==width-1)
			{
				FINISH=clock();
				double totaltime=(double)(FINISH-START)/CLOCKS_PER_SEC;
				printf("Time: %.2lf",totaltime);
			}
		}
		printf("\n");
	}
	return;
}
void T_game::movebul(int a[][N])//子弹移动函数
{
	int i,j;
	for (i=0;i<=high;i++)
		for(j=0;j<width;j++)
		{
			if(i==0 && a[i][j]==2)//
				a[i][j]=0;
			if (a[i][j]==2)
			{
				if(a[i-1][j]==3)  //3代表敌机
				{
					score+=10;//,printf("\7");防止子弹出底界
					mciSendString("play 1.mp3",NULL,0,NULL);
					//Sleep(200);
				}
				/*if (a[i-1][j]==-1)
				{
					a[i][j]=-1,a[i-1][j]=2;      //+和子弹互换位置
				}
				else
				{
					a[i][j]=0,a[i-1][j]=2;
				}*/
				if (a[i-1][j]==-1)
				{
					a[i][j]=-1,a[i-1][j]=2;      //+和子弹互换位置
					//mciSendString("play 1.mp3",NULL,0,NULL);
				}
				else
					if (a[i-1][j]==-2)
					{
						a[i][j]=-2,a[i-1][j]=2;
						//mciSendString("play 1.mp3",NULL,0,NULL);
					}
					else
						if (a[i-1][j]==-3)
						{
							a[i][j]=-3,a[i-1][j]=2;
							//mciSendString("play 1.mp3",NULL,0,NULL);
						}
						else
						{
							a[i][j]=0,a[i-1][j]=2;
							//mciSendString("play 1.mp3",NULL,0,NULL);
						}
			}
		}
	return;
} 
void T_game::movepla(int a[][N])//敌机移动函数
{
	int i,j;
	for (i=high;i>=0;i--)//从最后一行往上是为了避免把敌机直接冲出数组。
		for(j=0;j<width;j++)
		{
			if (i==high && a[i][j]==3)
				a[i][j]=0;//底行赋值0以免越界。
			if (a[i][j]==3)
			{
				a[i][j]=0;
				if (i!=high)
					a[i+1][j]=3;
			}
			 /*if (a[i][j]==3)
				 if (rand()%3==0 && j>=1 && a[i][j-1]!=3 && a[i][j-1]!=-1 && a[i][j-1]!=-2 && a[i][j-1]!=-3 && a[i][j-1]!=1)
					 a[i][j]=0,a[i][j-1]=3;
				 else
					 if (rand()%3==1 && j+1<width && a[i][j+1]!=3 && a[i][j+1]!=-1 && a[i][j+1]!=-2 && a[i][j+1]!=-3 && a[i][j+1]!=1)
						 a[i][j]=0,a[i][j+1]=3;
					 else
						 a[i][j]=0,a[i+1][j]=3;
			 if (a[i][j]==-1)
				 if (rand()%3==0 && j>=1 && a[i][j-1]!=3 && a[i][j-1]!=-1 && a[i][j-1]!=-2 && a[i][j-1]!=-3 && a[i][j-1]!=1)
					 a[i][j]=0,a[i][j-1]=-1;
				 else
					 if (rand()%3==1 && j+1<width && a[i][j+1]!=3 && a[i][j+1]!=-1 && a[i][j+1]!=-2 && a[i][j+1]!=-3 && a[i][j+1]!=1)
						 a[i][j]=0,a[i][j+1]=-1;
					 else
						 a[i][j]=0,a[i+1][j]=-1;
			 if (a[i][j]==-2)
				 if (rand()%3==0 && j>=1 && a[i][j-1]!=3 && a[i][j-1]!=-1 && a[i][j-1]!=-2 && a[i][j-1]!=-3 && a[i][j-1]!=1)
					 a[i][j]=0,a[i][j-1]=-2;
				 else
					 if (rand()%3==1 && j+1<width && a[i][j+1]!=3 && a[i][j+1]!=-1 && a[i][j+1]!=-2 && a[i][j+1]!=-3 && a[i][j+1]!=1)
						 a[i][j]=0,a[i][j+1]=-2;
					 else
						 a[i][j]=0,a[i+1][j]=-2;
			 if (a[i][j]==-3)
				 if (rand()%3==0 && j>=1 && a[i][j-1]!=3 && a[i][j-1]!=-1 && a[i][j-1]!=-2 && a[i][j-1]!=-3 && a[i][j-1]!=1)
					 a[i][j]=0,a[i][j-1]=-3;
				 else
					 if (rand()%3==1 && j+1<width && a[i][j+1]!=3 && a[i][j+1]!=-1 && a[i][j+1]!=-2 && a[i][j+1]!=-3 && a[i][j+1]!=1)
						 a[i][j]=0,a[i][j+1]=-3;
					 else
						 a[i][j]=0,a[i+1][j]=-3;*/
			 if (a[i][j]==-1)
			 {
				 a[i][j]=0;
				 if (i!=high) a[i+1][j]=-1;
			 }
			 if (a[i][j]==-2)
			 {
				 a[i][j]=0;
				 if (i!=high) a[i+1][j]=-2;
			 }
			 if (a[i][j]==-3)
			 {
				 a[i][j]=0;
				 if (i!=high) a[i+1][j]=-3;
			 }
		 }
	if (dp==0 && a[pr-1][pl]==3 && a[pr][pl]==1)//是1架飞机
	{
		a[pr-1][pl]=0;
		a[pr][pl]=0;
		life--;//death++;
		//if (a[pr+1][pl-1]==1) a[pr+1][pl-1]=0;//飞机被击落时消除飞机残影左
		//if (a[pr+1][pl+1]==1) a[pr+1][pl+1]=0;//飞机被击落时消除飞机残影右
		pr=high;pl=width/2;//飞机重新出现的位置
		if (life!=0) a[pr][pl]=1;//飞机重新出现的位置产生飞机
	}
	if (dp==1 && a[pr-1][pl]==3 && a[pr][pl]==1 && a[pr+1][pl-1]==1 && a[pr+1][pl+1]==1)//3架飞机中的中架
	{
		life--;//death++;
		a[pr-1][pl]=0;
		a[pr][pl]=0;
		if (a[pr+1][pl-1]==1) a[pr+1][pl-1]=0;//飞机被击落时消除飞机残影左
		if (a[pr+1][pl+1]==1) a[pr+1][pl+1]=0;//飞机被击落时消除飞机残影右
		pr=high;pl=width/2;//飞机重新出现的位置
		if (life!=0) a[pr][pl]=1;//飞机重新出现的位置产生飞机
	}
	if (dp==1 && a[pr-1][pl]==3 && a[pr][pl]==1 && a[pr][pl+2]==1 && a[pr-1][pl+1]==1)//是3架飞机中的左架
	{
		a[pr-1][pl]=0,a[pr+1][pl]=3;
	}
	if (dp==1 && a[pr-1][pl]==3 && a[pr][pl]==1 && a[pr][pl-2]==1 && a[pr-1][pl-1]==1)//是3架飞机中的右架
	{
		a[pr-1][pl]=0,a[pr+1][pl]=3;
	}
	if (a[pr-1][pl]==-1 && a[pr][pl]==1)
	{
		pp=1;
		a[pr-1][pl]=0;//把+吃掉
	}
	if (a[pr-1][pl]==-2 && a[pr][pl]==1)
	{
		dp=1;
		a[pr-1][pl]=0,a[pr][pl]=1,a[pr+1][pl-1]=1,a[pr+1][pl+1]=1;//把D吃掉
	}
	if (a[pr-1][pl]==-3 && a[pr][pl]==1)
	{
		life++;
		a[pr-1][pl]=0;//把L吃掉
	}
	return;
} 
void T_game::savegame(void)//保存游戏
{
	
	ofstream fout("Save\\savegame.txt");
	/*printf("%d %d\n",pr,pl);
	for (int i=0;i<=high;i++)
	{
		for (int j=0;j<=width;j++)
			if (j!=width)
				printf("%d ",scr[i][j]);
			else
				printf("%d",scr[i][j]);
		printf("\n");
	}
	printf("%d\n",score);
	printf("%d\n",life);

	FINISH=clock();
	double totaltime=(double)(FINISH-START)/CLOCKS_PER_SEC;			
	printf("%.2lf\n",totaltime);*/
	//fclose(stdout);
	fout<<pr<<' '<<pl<<endl;
	for (int i=0;i<=high;i++)
	{
		for (int j=0;j<=width;j++)
			if (j!=width)
				fout<<scr[i][j]<<' ';
			else
				fout<<scr[i][j]<<endl;
	}
	fout<<score<<endl<<life<<endl;
	FINISH=clock();
	double totaltime=(double)(FINISH-START)/CLOCKS_PER_SEC;			
	fout<<setprecision(2)<<totaltime;
	
	fout.close();
	return;
}
void T_game::loadgame()//载入游戏进度
{
	freopen("Save\\savegame.txt","r",stdin);
	
	scanf("%d%d",&pr,&pl);
	for (int i=0;i<=high;i++)
	{
		for (int j=0;j<=width;j++)
			scanf("%d",&scr[i][j]);
	}
	scanf("%d",&score);
	scanf("%d",&life);
	printf("%.2lf",&START);
	
	fclose(stdin);
}
void T_game::newrank()//更新排行榜
{
	freopen("Rank\\newrank.txt","r",stdin);
	freopen("Rank\\oldrank.txt","w",stdout);//打开文件输出流
	
	int rank[10],i;
	for (i=1;i<=3;i++)
		scanf("%d",&rank[i]);
	for (i=1;i<=3;i++)
		if (score>rank[i])
		{
			rank[i]=score;
		}
	for (i=1;i<=3;i++)
		printf("%d\n",rank[i]);
	
	fclose(stdin);
	fclose(stdout);//关闭文件输出流
	system("copy Rank\\oldrank.txt Rank\\newrank.txt");//把文本文件oldrank.txt里面的内容复制到文本文件newrank.txt里面
}
void T_game::loadrank()//载入排行榜
{
	freopen("Rank\\newrank.txt","r",stdin);
	
	int rank[10],i;
	for (i=1;i<=3;i++)
		scanf("%d",&rank[i]);

	for (i=1;i<=3;i++)
		printf("%d\n",rank[i]);

	fclose(stdin);
	printf("           BACK [B]\n");
	bool c=true;
	while (c)
	{
		switch (getch())
		{
			case 66:case 98:
				loadgame();
				c=false;
				break;
			default:c=true;
		}
	}
	//fclose(stdin);
	return;
}
void T_game::setnewgame(void)//新游戏重置
{
	START=clock();
	life=3;
	score=0;
	memset(scr,0,sizeof(scr));
	pl=9;pr=21;width=24;high=21;speed=3;density=15;score=0;life=3;pp=0;dp=0;
	num=0;nm=0;nu=0;np=0;npt=100;nl=0;//npt==20控制三机时间 
	pll=0;plr=width-2;pru=0;prd=high;
	scr[pr][pl]=1;
	scr[0][5]=3;
}
void T_game::nowtime(void)//显示当前时间 
{
	time_t curtime=time(0); 
	tm tim =*localtime(&curtime); 
	int day,mon,year,hour,minute,second; 
	day=tim.tm_mday;
	mon=tim.tm_mon;
	year=tim.tm_year;
	hour=tim.tm_hour;
	minute=tim.tm_min;
	second=tim.tm_sec;
	printf("%d年%d月%d日%d时%d分%d秒\n",year+1900,mon+1,day,hour,minute,second);
}
void T_game::setting(void)//设置函数
{
	int sw=0,i,j;
	system("cls");
	do {
		sw=0;
		printf("\nThe size of the screen: 1.Big 2.Small >> ");
		switch(getche()) 
		{
		case '1':width=34;
			break; 
		case '2':width=24;
			;break;
		default:printf("\nError,Please re select...\n"); 
			sw=1; 
		} 
	}while(sw); 
	do {
		sw=0; 
		printf("\nPlease select the density: 1.Big 2.Middle 3.Small >> ");
		switch(getche()) 
		{
			case '0':density=10;
				break; 
			case '1':density=20;
				break;
			case '2':density=30;
				break; 
			case '3':density=40;
				break; 
			default:printf("\nError,Please re select...\n"); 
				sw=1;
		} 
	}while(sw);
	do {
		sw=0;
		printf("\nThe enemy planes flying speed: 1.Quick 2.Middle 3.Slow >> ");
		switch(getche()) 
		{
			case '1':speed=2;
				break; 
			case '2':speed=3;
				break; 
			case '3':speed=4;
				break;
			default:printf("\nError,Please re select...\n"); 
				sw=1;
		}
	}while(sw);
	for(i=0;i<22;i++)
		for(j=0;j<45;j++)
			scr[i][j]=0;
	scr[high][pl=width/2]=1;
	printf("\nSave the press any key...\n");
	getch();
} 
void T_game::menu(void)//菜单函数
{
	printf("\n");
	if (new_or_continue==0)
		printf("        You Choice CONTINUE\n");
	else
		printf("        You Choice NEW GAME\n");
	printf("\n");
	printf("Explain:\n");
	printf("UP   : %c Control Plane UP\n",24);//Press  %c %c %c %c Control Plane\nSet: Press Esc\n",24,25,27,26,5);
	printf("DOWN : %c Control Plane DOWN\n",25);
	printf("LEFT : %c Control Plane LETF\n",27);
	printf("RIGHT: %c Control Plane RIGHT\n",26);
	printf("BLOCK: %c Control Bullets\n",220);
	printf("\n");
	printf("  ESC: Set Game\n");
	printf("    S: Save the Game\n ");
	printf("\n");
	printf("Strat Game: Any key\n");
	if (getch()==27)
		setting();
	system("cls");
}
void T_game::Play()//游戏全局控制
{
	new_or_continue=1;
	new_or_exit=0;
	printstartgame();
	system("cls");
	menu(); 
	int i=0,j=0;
	if (new_or_continue==0)
		loadgame();
	else
	{
		printf("Your name : ");
		scanf("%s",name);
	}
	
	START=clock();
	time_t cc;
	int count=0;
	while(1) 
	{
		count++;
		//cc=clock();
		//Sleep(10);
		mciSendString("play c3.mp3 repeat",NULL,0,NULL);
		//Sleep(300);
		if (life==0) 
		{
			printgameover();
			if (new_or_exit==1)
			{
				setnewgame();
			}
			else
			{
				break;
			}
		}
		if (kbhit())
			switch(getch())   //控制上下左右移动和进入菜单
			{
				case 72:Up();
						break;
				case 80:Down();
						break;
				case 75:Left();
						break;
				case 77:Right();
						break;
				case 32:Black();				
						break; 
				case 27:setting();    //ecs ASCII
						break;
				case 82:case 114:system("cls");
								loadrank();
								break;
				case 83:case 115:savegame();
								break;
								//exit(0);
					break;
			}
		if (++j%density==0)//控制生产敌机的速度
		{
			j=0;
			nm++;//控制+
			nu++;//控制D
			nl++;//控制L
			srand(time(NULL));
			if (nm==9 && dp==0)
				scr[0][rand()%width]=-1;//产生+
			else
				if (nu==15 && dp==0)
					scr[0][rand()%width]=-2;//产生D
				else
					if (nl==20)
						scr[0][rand()%width]=-3;//产生L
					else
						scr[0][rand()%width]=3;//产生敌机
			if (nm>10) nm=0;
			if (nu>16) nu=0;
			if (nl>20) nl=0;
		}
		if (++i%speed==0)//控制敌机移动速度，相对于子弹移动速度 
			movepla(scr);
		movebul(scr);
		print(scr); 
		printf("%6d %6d\n",clock(),count);
		Sleep(max(count*50-(clock()-START),0));
		if (i==30000) i=0;//以免i越界
		//if (j==30000) j=0;//以免j越界
	}
	printf("\n");
}
int main()
{
	T_game T;
	T.Play();
	return 0;
}
