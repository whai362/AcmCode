#include <stdio.h>
#include <conio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")
#define N 35
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
class T_game
{
private:
	int pl,pr,width,high,speed,density,score,life;
	int scr[22][N],v[22][N];
	int pll,plr,pru,prd;
	int pp;
public:
	T_game()
	{
		memset(scr,0,sizeof(scr));
		width=24;high=21;speed=3;density=15;score=0;life=3;
		pr=21;pl=9;
		pll=0;plr=width-2;pru=0;prd=high;
		scr[pr][pl]=1;
		pp=0;
	}
	void printgameover();//输出游戏结束函数 
	void print(int [][N]);//输出函数
	void movebul(int [][N]);//子弹移动函数 
	void movepla(int [][N]);//敌机移动函数 
	void setting();//设置函数 
	void menu();//菜单函数
	void Up();//上的操作
	void Down();//下的操作
	void Left();//左的操作
	void Right();//右的操作
	void Play();//游戏全局控制
};
void T_game::Up()//上的操作
{
	if(pr>pru) 
	{
		scr[pr][pl]=0;
		scr[--pr][pl]=1;
	}
}
void T_game::Down()//下的操作
{
	if (pr<prd) 
	{
		scr[pr][pl]=0;
		scr[++pr][pl]=1;
	}
}
void T_game::Left()//左的操作
{
	if(pl>pll)
	{
		scr[pr][pl]=0;
		scr[pr][--pl]=1;
	}
}
void T_game::Right()//右的操作
{
	if(pl<plr) 
	{
		scr[pr][pl]=0;
		scr[pr][++pl]=1;
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
	printf("\n");
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
			if (a[i][j]==0)
				printf(" ");
			if (a[i][j]==1)
				printf("\5");//输出我机的符号
			if (a[i][j]==3)
				printf(".");//printf("\3"); //输出敌机符号 
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
}
void T_game::movepla(int a[][N])//敌机移动函数
{
	int i,j;
	memset(v,0,sizeof(v));
	for (i=high;i>=0;i--)//从最后一行往上是为了避免把敌机直接冲出数组。
		for(j=0;j<width;j++)
		{
			if (a[i][j]==3)
			{
				a[i][j]=0;
				int k=rand()%3;
				if (k==0 && i<high && a[i+1][j]!=3 && v[i+1][j]==0)
					a[i+1][j]=3,v[i+1][j]=1;
				else
					if (k==1 && j>1 && a[i][j-1]!=3 && v[i][j-1]==0)
						a[i][j-1]=3,v[i][j-1]=1;
					else
						if (k==2 && j<width-1 && a[i][j+1]!=3 && a[i][j+1]!=4 && v[i][j+1]==0)
							a[i][j+1]=3,v[i][j+1]==1;
						else
							a[i][j]=3;
				if (i==high && k==0)
					a[i][j]=0;
			}
		}
	if (pp==0)
		for (i=high;i>=0;i--)
			for (j=0;j<width;j++)
			{
				if (v[i][j]==1 && a[i][j]==1)
				{
					life--;
					a[i][j]=0;
					pr=21; pl=9;
					a[pr][pl]=1;
					//print(a);
				}
			}
	if (a[pr-1][pl]==3)
	{
		a[pr-1][pl]=0;
		a[pr][pl]=0;
		life--;
		pr=21; pl=9;
		a[pr][pl]=1;
		//print(a);
	}
	if (a[pr+1][pl]==3)
	{
		a[pr+1][pl]=0;
		a[pr][pl]=0;
		life--;
		pr=21; pl=9;
		a[pr][pl]=1;
		//print(a);
	}
	if (a[pr][pl-1]==3)
	{
		a[pr][pl-1]=0;
		a[pr][pl]=0;
		life--;
		pr=21; pl=9;
		a[pr][pl]=1;
		//print(a);
	}
	if (a[pr][pl+1]==3)
	{
		a[pr][pl+1]=0;
		a[pr][pl]=0;
		life--;
		pr=21; pl=9;
		a[pr][pl]=1;
		//print(a);
	}
	//飞机被击落
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
	scr[high][pl=((width+1)>>1)]=1;
	printf("\nSave the press any key...");
	getch();
} 
void T_game::menu(void)//菜单函数
{
	printf("Explain: Press %c %c %c %c Control Plane,%c Bullets\nSet: Press Esc\nStrat Game: Any key",1,2,3,4,5);
	if (getch()==27)
		setting();
}
void T_game::Play()//游戏全局控制
{
	START=clock();
	menu(); 
	int i=0,j=0;
	while(1) 
	{
		mciSendString("play c3.mp3 repeat",NULL,0,NULL);
		if (life==0) 
		{
			printgameover();
			//Sleep(100);
			//FINISH=clock();
			break;
		}
		if (kbhit())
			switch(getch())   //控制上下左右移动和进入菜单
			{
				case 72:pp=1,Up();
						break;
				case 80:pp=2,Down();
						break;
				case 75:pp=3,Left();
						break;
				case 77:pp=4,Right();
						break;
				case 27:setting();    //ecs ASCII
						break; 
			}
		else
			pp=0;
		if (++j%density==0)//控制生产敌机的速度
		{
			srand(time(NULL));
			scr[0][rand()%width]=3;//产生敌机
		}
		if (++i%speed==0)//控制敌机移动速度，相对于子弹移动速度 
			movepla(scr);
		//movebul(scr);
		print(scr); 
		if (i==30000) i=0;//以免i越界
		if (j==30000) j=0;//以免i越界
	}
}
int main()
{
	T_game T;
	T.Play();
	return 0;
}