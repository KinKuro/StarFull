#include <stdio.h>
#include <conio.h>
#include <Windows.h>

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

void drawMap();
int checkClear();
void keyProcess();
int checkOver();
int checkZero();

char Map[10][10] = {						//�Լ��� ���ǵ�, ���������� �迭�� ����� �����͸� �˾ƾߵ�
					{ 2,2,2,2,2,2,2,2,2,2 },		//���� �ʱ�ȭ�� ������
					{ 2,1,0,0,2,2,0,0,0,2 },
					{ 2,0,0,0,2,2,0,0,0,2 },
					{ 2,0,0,0,2,2,0,0,0,2 },
					{ 2,0,0,0,2,2,0,0,0,2 },
					{ 2,0,0,0,0,0,0,0,2,2 },
					{ 2,2,2,0,0,0,0,0,0,2 },
					{ 2,2,2,0,0,0,0,0,0,2 },
					{ 2,0,0,0,2,2,2,0,0,2 },
					{ 2,2,2,2,2,2,2,2,2,2 },
				   };
int posY = 1, posX = 1;		// BOX�� ó�� [y][x]���� [1],[1]


void main()
{
	while (1)		//���� ������ ����ä�
	{
		// ȭ�� ����(dos ������� 'cls'�� ����)
		system("cls");		// <Windows.h>�� �־�

		// �� �׸���
		drawMap();

		// ������ Ŭ���� �Ǿ����� �˻�
		if (checkClear() == 1)
		{
			printf("--Stage Clear!!--\n");
			break;
		}

		// ���ӿ����������� �˻�
		if (checkOver())
		{
			printf("--Game Over!!--\n");
			break;
		}

		//����ڷκ��� �Է¹ޱ�
		keyProcess();
	}
	getch();
}	// main ������


void drawMap()	// �� �׸��� �Լ�
{
	
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			switch (Map[y][x])
			{
			case 0:	printf("��");	break;
			case 1:	printf("��");	break;
			case 2: printf("��");
			}
		}
		printf("\n");
	}
	printf("���� ��ġ :Y[%d] X[%d]\n", posY, posX);
	printf("���� ��ĭ : [%d]\n",checkZero());
}	// drawMap �Լ� ������

int checkClear()		
{
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (Map[y][x] == 0) return 0;
		}
	}
	return 1;
}	// checkClear �Լ� ������

int checkOver()		// ���ӿ��� Ȯ��
{
	if ((Map[posY - 1][posX] == 1 || Map[posY - 1][posX] == 2) &&
		(Map[posY + 1][posX] == 1 || Map[posY + 1][posX] == 2) &&
		(Map[posY][posX - 1] == 1 || Map[posY][posX - 1] == 2) &&
		(Map[posY][posX + 1] == 1 || Map[posY][posX + 1] == 2))
		return 1;
	return 0;
}	// checkOver �Լ� ������


void keyProcess()	//Ű���� ����Ű �Է� �� ó�� �Լ�
{
	int key;
	key = getch();		// <conio.h> �ȿ� �־�
	if (key == 224) key = getch();		// ����Ű�� ��쿡�� �ѹ� �� �Է¹���(�̷��� 72,75,77,80�� ������)


	switch (key)
	{
	case LEFT:		//LEFT
		//Ȥ�� ����ĭ�� ��ĭ�� �ƴϳ�? �׷� ������
		if (Map[posY][posX - 1] != 0)	break;
		posX--;
		Map[posY][posX] = 1;
		break;
	case RIGHT:		//RIGHT
		if (Map[posY][posX + 1] != 0)	break;
		posX++;
		Map[posY][posX] = 1;
		break;
	case UP:		//UP
		if (Map[posY - 1][posX] != 0)	break;
		posY--;
		Map[posY][posX] = 1;
		break;
	case DOWN:		//DOWN
		if (Map[posY + 1][posX] != 0)	break;
		posY++;
		Map[posY][posX] = 1;
		break;
	}
}


int checkZero()
{
	int cz=0;
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (Map[y][x] == 0) cz++;
		}
	}
	return cz;
}