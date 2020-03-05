#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int i = 0, j = 0;
int map[7][8] =
{
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 3, 1, 0, 1, 1, 3, 1,
	1, 4, 0, 0, 4, 0, 3, 1,
	1, 0, 1, 0, 1, 1, 4, 1,
	1, 0, 0, 5, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1
};
void drawMap()
{
	system("cls");
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 8; j++)
		{
			switch (map[i][j])
			{
			case 0:
				printf("  ");
				break;
			case 1:
				printf("¡ö");
				break;
			case 3:
				printf("¡î");
				break;
			case 4:
				printf("¡ï");
				break;
			case 5:
				printf("¡ù");
				break;
			case 7:
				printf("¡ò");
				break;
			case 8:
				printf("¡ù");
				break;

			}
		}
		printf("\n");
	}
}

void keyDown()
{

	for (i = 0; i < 7; i++)
	{
		for (j = 0; j<8; j++){
			if (map[i][j] == 5 || map[i][j] == 8)
				break;
		}
		if (map[i][j] == 5 || map[i][j] == 8)
			break;
	}
	char ch = getchar();

	switch (ch)
	{
	case 'w':
	case 'W':
	case 72:
		if (map[i - 1][j] == 0 || map[i - 1][j] == 3)
		{
			map[i - 1][j] += 5;
			map[i][j] -= 5;
		}
		else if (map[i - 1][j] == 4 || map[i - 1][j] == 7)
		{
			if (map[i - 2][j] == 0 || map[i - 2][j] == 3)
			{
				map[i - 2][j] += 4;
				map[i - 1][j] += 1;
				map[i][j] -= 5;
			}
		}
		break;
	case 's':
	case 'S':
	case 80:
		if (map[i + 1][j] == 0 || map[i + 1][j] == 3)
		{
			map[i + 1][j] += 5;
			map[i][j] -= 5;
		}
		else if (map[i + 1][j] == 4 || map[i + 1][j] == 7)
		{
			if (map[i + 2][j] == 0 || map[i + 2][j] == 3)
			{
				map[i + 2][j] += 4;
				map[i + 1][j] += 1;
				map[i][j] -= 5;
			}
		}
		break;
	case 'a':
	case 'A':
	case 75:
		if (map[i][j - 1] == 0 || map[i][j - 1] == 3)
		{
			map[i][j - 1] += 5;
			map[i][j] -= 5;
		}
		else if (map[i][j - 1] == 4 || map[i][j - 1] == 7)
		{
			if (map[i][j - 2] == 0 || map[i][j - 2] == 3)
			{
				map[i][j - 2] += 4;
				map[i][j - 1] += 1;
				map[i][j] -= 5;
			}
		}
		break;
	case 'd':
	case 'D':
	case 77:
		if (map[i][j + 1] == 0 || map[i][j + 1] == 3)
		{
			map[i][j + 1] += 5;
			map[i][j] -= 5;
		}
		else if (map[i][j + 1] == 4 || map[i][j + 1] == 7)
		{
			if (map[i][j + 2] == 0 || map[i][j + 2] == 3)
			{
				map[i][j + 2] += 4;
				map[i][j + 1] += 1;
				map[i][j] -= 5;
			}
		}
		break;
	}
}

int gameOver()
{
	int count = 0;
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (map[i][j] == 7)
				count++;
		}
	}
	return count;
}
int main()
{
	while (1){
		if (gameOver() == 3)
			break;
		drawMap();
		keyDown();
	}
	printf("hh");
	return 0;
}