#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3

//void game();
//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);//ROW形参，row实参
//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);
//玩家下棋
void Playermove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
char Winer(char board[ROW][COL], int row, int col);
