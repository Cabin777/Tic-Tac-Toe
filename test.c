#define _CRT_SECURE_NO_WARNINGS 1
#include <game.h>
//游戏菜单
void menu()
{
	printf("**************************\n");
	printf("**************************\n");
	printf("******1.play  0.exit******\n");
	printf("**************************\n");
	printf("**************************\n");
}
//游戏主体
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//初始化棋盘的函数
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	//下棋		
	while (1)
	{
		Playermove(board, ROW, COL);//玩家下棋
		DisplayBoard(board, ROW, COL);
		ret = Winer(board, ROW, COL);//判断输赢
		if (ret != 'C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);//电脑下棋
		DisplayBoard(board, ROW, COL);
		ret = Winer(board, ROW, COL);//判断输赢
		if (ret != 'C')
		{
			break;
		}

	}
	if (ret == '*')
	{
		printf("恭喜玩家获胜！\n------游戏结束------");
	}
	else if (ret == '#')
	{
		printf("恭喜电脑获胜！\n******游戏结束******");
	}
	else
	{
		printf("平局！！！\n******游戏结束******");
	}
}
int main()
{
	srand((unsigned int)(time(NULL)));//设置随机数的生成起点,unsigned用来取正数
	int input = 0;
	do
	{
		menu();//打印菜单
		printf("请选择:->>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("三子棋\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误!\n");
			break;
		}


	} while (input);


	return 0;
}

