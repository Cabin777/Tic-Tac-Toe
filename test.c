#define _CRT_SECURE_NO_WARNINGS 1
#include <game.h>
//��Ϸ�˵�
void menu()
{
	printf("**************************\n");
	printf("**************************\n");
	printf("******1.play  0.exit******\n");
	printf("**************************\n");
	printf("**************************\n");
}
//��Ϸ����
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//��ʼ�����̵ĺ���
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	//����		
	while (1)
	{
		Playermove(board, ROW, COL);//�������
		DisplayBoard(board, ROW, COL);
		ret = Winer(board, ROW, COL);//�ж���Ӯ
		if (ret != 'C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);//��������
		DisplayBoard(board, ROW, COL);
		ret = Winer(board, ROW, COL);//�ж���Ӯ
		if (ret != 'C')
		{
			break;
		}

	}
	if (ret == '*')
	{
		printf("��ϲ��һ�ʤ��\n------��Ϸ����------");
	}
	else if (ret == '#')
	{
		printf("��ϲ���Ի�ʤ��\n******��Ϸ����******");
	}
	else
	{
		printf("ƽ�֣�����\n******��Ϸ����******");
	}
}
int main()
{
	srand((unsigned int)(time(NULL)));//������������������,unsigned����ȡ����
	int input = 0;
	do
	{
		menu();//��ӡ�˵�
		printf("��ѡ��:->>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("������\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����!\n");
			break;
		}


	} while (input);


	return 0;
}

