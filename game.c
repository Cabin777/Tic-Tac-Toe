#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <game.h>
//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		//打印数据
		//printf(" %c | %c | %c\n", board[i][0], board[i][1], board[i][2]);
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		//打印分割线//printf("---|---|---\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}

			}
			printf("\n");
		}
	}
}
//玩家下棋
void Playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家请下棋:>\n");
	while (1)
	{
		printf("请输入坐标（左上角为（3,3）右下角为（3,3）\n");
		scanf("%d %d", &x, &y);
		/*scanf("%d", &x);
		scanf("%d", &y);*/
		//printf("测试代码1值%d %d\n", x,y);
		//坐标范围合法性的判断
		if (x >= 1 && x <= row && y <= col && y >= 1)
		{
			//printf("测试代码2值%d %d\n", x,y);
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;//用于跳出while循环
			}
			else
			{
				printf("坐标被占用，不能落子，请选择其他位置\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}

	}


}
//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋:>\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;//0~2任何数除以3余数范围
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}

	}


}
/*
判断输赢
	玩家赢-*
	电脑赢-#
	平局-E
	继续-C
*/
char Winer(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)//行
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][0];
		}
	}
	for (j = 0; j < col; j++)//列
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[0][j];
		}
	}
	//对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[2][2] && board[2][2] == board[2][0] && board[1][1] != ' ')
	{
		return board[0][2];
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] != ' ')
			{
				return 'C';
			}
		}
	}
}

