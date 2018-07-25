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

char Map[10][10] = {						//함수를 쓸건데, 지역변수로 배열을 만들면 포인터를 알아야되
					{ 2,2,2,2,2,2,2,2,2,2 },		//맵을 초기화를 해주자
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
int posY = 1, posX = 1;		// BOX의 처음 [y][x]값인 [1],[1]


void main()
{
	while (1)		//언제 끝날지 몰라ㅓㅏ
	{
		// 화면 정리(dos 명령으로 'cls'를 실행)
		system("cls");		// <Windows.h>에 있어

		// 맵 그리기
		drawMap();

		// 게임이 클리어 되었는지 검사
		if (checkClear() == 1)
		{
			printf("--Stage Clear!!--\n");
			break;
		}

		// 게임오버상태인지 검사
		if (checkOver())
		{
			printf("--Game Over!!--\n");
			break;
		}

		//사용자로부터 입력받기
		keyProcess();
	}
	getch();
}	// main 마지막


void drawMap()	// 맵 그리기 함수
{
	
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			switch (Map[y][x])
			{
			case 0:	printf("　");	break;
			case 1:	printf("■");	break;
			case 2: printf("□");
			}
		}
		printf("\n");
	}
	printf("현재 위치 :Y[%d] X[%d]\n", posY, posX);
	printf("남은 빈칸 : [%d]\n",checkZero());
}	// drawMap 함수 마지막

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
}	// checkClear 함수 마지막

int checkOver()		// 게임오버 확인
{
	if ((Map[posY - 1][posX] == 1 || Map[posY - 1][posX] == 2) &&
		(Map[posY + 1][posX] == 1 || Map[posY + 1][posX] == 2) &&
		(Map[posY][posX - 1] == 1 || Map[posY][posX - 1] == 2) &&
		(Map[posY][posX + 1] == 1 || Map[posY][posX + 1] == 2))
		return 1;
	return 0;
}	// checkOver 함수 마지막


void keyProcess()	//키보드 방향키 입력 및 처리 함수
{
	int key;
	key = getch();		// <conio.h> 안에 있어
	if (key == 224) key = getch();		// 방항키인 경우에는 한번 더 입력받자(이래야 72,75,77,80을 저장함)


	switch (key)
	{
	case LEFT:		//LEFT
		//혹시 왼쪽칸이 빈칸이 아니냐? 그럼 하지마
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