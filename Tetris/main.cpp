#include "stdafx.h"

int main()
{
	system("title Tetris V2.6.181125z");
	system("mode con cols=52 lines=22");
	/*获取并隐藏控制台光标*/
	HANDLE p = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(p, &CursorInfo);
	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(p, &CursorInfo);
	msxz();
	start();
	tetris_scxd();
	while (1)
	{
		tetris_dyxd();
		tetris_scxd();
		if (tetris_j()) break;
		if (ms) ai();
		else
		{
			while (1)
				if (cz()) break;
		}
		tetris_qcyh();
	}
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("\n\n\t游戏结束！\n\n\t最终积分：%d\n\n\t按任意键退出游戏", jf);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	system("pause");
	return 0;
}

void start()//开始游戏并初始化
{
	srand((unsigned)time(NULL));//随机数初始化

	int i, j;

	for (i = 0; i <= (GAO - 1); i++)
	{
		for (j = 0; j <= (KUANG - 1); j++)
		{
			if (i == (GAO - 1) || i == (GAO - 2) || j == 0 || j == 1 || j == (KUANG - 1) || j == (KUANG - 2))
				ij[i][j] = -1;
			else
				ij[i][j] = 0;
		}
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	for (i = 0; i <= (GAO - 1); i++)
	{
		for (j = 0; j <= (KUANG - 1); j++)
		{
			switch (ij[i][j])
			{
			case 0:printf("  "); break;
			case -1:printf("■"); break;
			}
		}
		switch (i)
		{
		case 1:printf("\t下一个方块：\t■■"); break;
		case GAO - 15:printf("■■■■■■■■■■■■"); break;
		case GAO - 13:printf("\t等级：\t\t■■"); break;
		case GAO - 12:printf("\t积分：\t\t■■");  break;
		case GAO - 10:printf("■■■■■■■■■■■■"); break;
		case GAO - 8:printf("\t\"↑\"    旋转\t■■"); break;
		case GAO - 7:printf("\t\"↓\"    下移\t■■"); break;
		case GAO - 6:printf("\t\"←\"    左移\t■■"); break;
		case GAO - 5:printf("\t\"→\"    右移\t■■"); break;
		case GAO - 4:printf("\t空格    暂停\t■■"); break;
		case GAO - 2:printf("■■■■■■■■■■■■"); break;
		case GAO - 1:printf("■■■■■■■■■■■■"); break;
		default:printf("\t\t\t■■"); break;
		}
		gotoxy(1, i + 2);
	}
	gotoxy(KUANG * 2 + 13, GAO - 12);
	printf("%d", dj);
	gotoxy(KUANG * 2 + 13, GAO - 11);
	printf("%d", jf);
}

int tetris_j()//判断游戏是否结束（是返回1，否返回0）
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = KUANG / 2 - 2; j < KUANG / 2 + 2; j++)
		{
			if (ij[i][j] > 1) return 1;
		}
	}
	return 0;
}

void tetris_scxd()//生成新的俄罗斯方块到预览
{
	int i, j;
	x = rand() % 19 + 1;
	switch (x)
	{
	case 1:memcpy(yl, tetris1, sizeof(yl)); break;
	case 2:memcpy(yl, tetris2, sizeof(yl)); break;
	case 3:memcpy(yl, tetris3, sizeof(yl)); break;
	case 4:memcpy(yl, tetris4, sizeof(yl)); break;
	case 5:memcpy(yl, tetris5, sizeof(yl)); break;
	case 6:memcpy(yl, tetris6, sizeof(yl)); break;
	case 7:memcpy(yl, tetris7, sizeof(yl)); break;
	case 8:memcpy(yl, tetris8, sizeof(yl)); break;
	case 9:memcpy(yl, tetris9, sizeof(yl)); break;
	case 10:memcpy(yl, tetris10, sizeof(yl)); break;
	case 11:memcpy(yl, tetris11, sizeof(yl)); break;
	case 12:memcpy(yl, tetris12, sizeof(yl)); break;
	case 13:memcpy(yl, tetris13, sizeof(yl)); break;
	case 14:memcpy(yl, tetris14, sizeof(yl)); break;
	case 15:memcpy(yl, tetris15, sizeof(yl)); break;
	case 16:memcpy(yl, tetris16, sizeof(yl)); break;
	case 17:memcpy(yl, tetris17, sizeof(yl)); break;
	case 18:memcpy(yl, tetris18, sizeof(yl)); break;
	case 19:memcpy(yl, tetris19, sizeof(yl)); break;
	}
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			gotoxy(KUANG * 2 + 7 + j * 2, i + 3);
			if (yl[i][j] == 1)
			{
				switch (x)
				{
				case 1:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); break;
				case 2:case 3:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); break;
				case 4:case 5:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); break;
				case 6:case 7:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); break;
				case 8:case 9:case 10:case 11:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); break;
				case 12:case 13:case 14:case 15:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); break;
				case 16:case 17:case 18:case 19:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); break;
				}
				printf("■");
			}
			else
			{
				printf("  ");
			}
		}
	}
}

void tetris_dyxd()//取预览打印新的俄罗斯方块
{
	memcpy(temp, yl, sizeof(temp));
	n = x;
	tetris_x = KUANG / 2 - 2;
	tetris_y = 0;
	tetris_dydqsj(0);
	tetris_dydqta();
}

void tetris_dydqsj(int ai_kg)//打印当前俄罗斯方块数据
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (ai_kg)
			{
				ai_ij[i + ai_tetris_y][j + ai_tetris_x] += ai_temp[i][j];
			}
			else
			{
				ij[i + tetris_y][j + tetris_x] += temp[i][j];
			}
		}
	}
}

void tetris_dydqta()//打印当前俄罗斯方块图案
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			gotoxy((j + tetris_x) * 2 + 1, i + tetris_y + 1);
			if (temp[i][j] == 1)
			{
				switch (n)
				{
				case 1:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); break;
				case 2:case 3:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); break;
				case 4:case 5:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); break;
				case 6:case 7:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); break;
				case 8:case 9:case 10:case 11:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); break;
				case 12:case 13:case 14:case 15:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); break;
				case 16:case 17:case 18:case 19:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); break;
				}
				printf("■");
			}
		}
	}
	//测试用
	/*/
	for (i = 0; i <= (GAO - 1); i++)
	{
	for (j = 0; j <= (KUANG - 1); j++)
	{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(j * 3 + 1, GAO + i + 3);
	printf("%d", ij[i][j]);
	}
	}
	//测试用
	/*/
}

void tetris_qcdq(int ai_kg)//清除当前俄罗斯方块
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (ai_kg)
			{
				if (ai_ij[i + ai_tetris_y][j + ai_tetris_x] == ai_temp[i][j])
				{
					ai_ij[i + ai_tetris_y][j + ai_tetris_x] = 0;
				}
			}
			else
			{
				if (ij[i + tetris_y][j + tetris_x] == temp[i][j])
				{
					ij[i + tetris_y][j + tetris_x] = 0;
					gotoxy((j + tetris_x) * 2 + 1, i + tetris_y + 1);
					printf("  ");
				}
			}
		}
	}
}

void tetris_qcyh()//清除一行俄罗斯方块
{
	int i, j, k, s = 0;
	for (i = tetris_y; i < tetris_y + 4; i++)
	{
		for (j = 2; j < (KUANG - 2); j++)
		{
			if (ij[i][j] == 1) s++;
			else
			{
				s = 0;
				break;
			}
			if (s == KUANG - 4)
			{
				k = i;
				for (; i >= 0; i--)
				{
					for (j = 2; j < (KUANG - 2); j++)
					{
						if (i == 0) ij[i][j] = 0;
						else ij[i][j] = ij[i - 1][j];
					}
				}
				jf += 10;
				dj = jf / 100 + 1;
				s = 0;
				i = k;
			}
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	for (i = 0; i < tetris_y + 4 && i < (GAO - 2); i++)
	{
		for (j = 2; j < (KUANG - 2); j++)
		{
			gotoxy(j * 2 + 1, i + 1);
			switch (ij[i][j])
			{
			case 0:printf("  "); break;
			case 1:printf("■"); break;
			}
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	gotoxy(KUANG * 2 + 13, GAO - 12);
	printf("%d", dj);
	gotoxy(KUANG * 2 + 13, GAO - 11);
	printf("%d", jf);
}

int tetris_xz(int ai_kg)//旋转俄罗斯方块
{
	int i, j;
	int m;
	int t[4][4];
	if (ai_kg) m = ai_n;
	else m = n;
	switch (m)
	{
	case 1:memcpy(t, tetris1, sizeof(t)); m = 1; break;
	case 2:memcpy(t, tetris3, sizeof(t)); m = 3; break;
	case 3:memcpy(t, tetris2, sizeof(t)); m = 2; break;
	case 4:memcpy(t, tetris5, sizeof(t)); m = 5; break;
	case 5:memcpy(t, tetris4, sizeof(t)); m = 4; break;
	case 6:memcpy(t, tetris7, sizeof(t)); m = 7; break;
	case 7:memcpy(t, tetris6, sizeof(t)); m = 6; break;
	case 8:memcpy(t, tetris9, sizeof(t)); m = 9; break;
	case 9:memcpy(t, tetris10, sizeof(t)); m = 10; break;
	case 10:memcpy(t, tetris11, sizeof(t)); m = 11; break;
	case 11:memcpy(t, tetris8, sizeof(t)); m = 8; break;
	case 12:memcpy(t, tetris13, sizeof(t)); m = 13; break;
	case 13:memcpy(t, tetris14, sizeof(t)); m = 14; break;
	case 14:memcpy(t, tetris15, sizeof(t)); m = 15; break;
	case 15:memcpy(t, tetris12, sizeof(t)); m = 12; break;
	case 16:memcpy(t, tetris17, sizeof(t)); m = 17; break;
	case 17:memcpy(t, tetris18, sizeof(t)); m = 18; break;
	case 18:memcpy(t, tetris19, sizeof(t)); m = 19; break;
	case 19:memcpy(t, tetris16, sizeof(t)); m = 16; break;
	}
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (ai_kg)
			{
				if (t[i][j] == 1 && (ai_ij[i + ai_tetris_y][j + ai_tetris_x] != 0 && ai_temp[i][j] == 0))
					return 0;
			}
			else
			{
				if (t[i][j] == 1 && (ij[i + tetris_y][j + tetris_x] != 0 && temp[i][j] == 0))
					return 0;
			}
		}
	}
	tetris_qcdq(ai_kg);
	if (ai_kg) memcpy(ai_temp, t, sizeof(ai_temp));
	else memcpy(temp, t, sizeof(temp));
	if (ai_kg) ai_n = m;
	else n = m;
	tetris_dydqsj(ai_kg);
	if (ai_kg == 0) tetris_dydqta();
	return 1;
}

int tetris_fx(char fx, int ai_kg)//选择旋转或下左右方向移动
{
	switch (fx)
	{
	case 72:return tetris_xz(ai_kg);
	case 80:
	{
		if (tetris_j_fx(fx, ai_kg) == 0) return 0;
		tetris_qcdq(ai_kg);
		if (ai_kg) ai_tetris_y++;
		else tetris_y++;
		break;
	}
	case 75:
	{
		if (tetris_j_fx(fx, ai_kg) == 0) return 0;
		tetris_qcdq(ai_kg);
		if (ai_kg) ai_tetris_x--;
		else tetris_x--;
		break;
	}
	case 77:
	{
		if (tetris_j_fx(fx, ai_kg) == 0) return 0;
		tetris_qcdq(ai_kg);
		if (ai_kg) ai_tetris_x++;
		else tetris_x++;
		break;
	}
	default:return 0;
	}
	tetris_dydqsj(ai_kg);
	if (ai_kg == 0) tetris_dydqta();
	return 1;
}

int tetris_j_fx(char fx, int ai_kg)//判断是否可下左右方向移动（是返回1，否返回0）
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			switch (fx)
			{
			case 80:
			{
				if (i < 3)
				{
					if (ai_kg)
					{
						if (ai_temp[i][j] == 1 && ai_temp[i + 1][j] != 1 && ai_ij[i + ai_tetris_y + 1][j + ai_tetris_x] != 0)
							return 0;
					}
					else
					{
						if (temp[i][j] == 1 && temp[i + 1][j] != 1 && ij[i + tetris_y + 1][j + tetris_x] != 0)
							return 0;
					}
				}
				else
				{
					if (ai_kg)
					{
						if (ai_temp[i][j] == 1 && ai_ij[i + ai_tetris_y + 1][j + ai_tetris_x] != 0)
							return 0;
					}
					else
					{
						if (temp[i][j] == 1 && ij[i + tetris_y + 1][j + tetris_x] != 0)
							return 0;
					}
				}
				break;
			}
			case 75:
			{
				if (j > 0)
				{
					if (ai_kg)
					{
						if (ai_temp[i][j] == 1 && ai_temp[i][j - 1] != 1 && ai_ij[i + ai_tetris_y][j + ai_tetris_x - 1] != 0)
							return 0;
					}
					else
					{
						if (temp[i][j] == 1 && temp[i][j - 1] != 1 && ij[i + tetris_y][j + tetris_x - 1] != 0)
							return 0;
					}
				}
				else
				{
					if (ai_kg)
					{
						if (ai_temp[i][j] == 1 && ai_ij[i + ai_tetris_y][j + ai_tetris_x - 1] != 0)
							return 0;
					}
					else
					{
						if (temp[i][j] == 1 && ij[i + tetris_y][j + tetris_x - 1] != 0)
							return 0;
					}
				}
				break;
			}
			case 77:
			{
				if (j < 3)
				{
					if (ai_kg)
					{
						if (ai_temp[i][j] == 1 && ai_temp[i][j + 1] != 1 && ai_ij[i + ai_tetris_y][j + ai_tetris_x + 1] != 0)
							return 0;
					}
					else
					{
						if (temp[i][j] == 1 && temp[i][j + 1] != 1 && ij[i + tetris_y][j + tetris_x + 1] != 0)
							return 0;
					}
				}
				else
				{
					if (ai_kg)
					{
						if (ai_temp[i][j] == 1 && ai_ij[i + ai_tetris_y][j + ai_tetris_x + 1] != 0)
							return 0;
					}
					else
					{
						if (temp[i][j] == 1 && ij[i + tetris_y][j + tetris_x + 1] != 0)
							return 0;
					}
				}
				break;
			}
			default:return 0;
			}
		}
	}
	return 1;
}

int cz()//键盘操作以及自动下落
{
	kz();
	tetris_fx(80, 0);
	if (tetris_j_fx(80, 0)) return 0;
	else
	{
		kz();
		if (tetris_j_fx(80, 0)) return 0;
		else return 1;
	}
}

void kz()//获取键盘操作控制俄罗斯方块
{
	int i, sj = 0;
	char userHit;
	if (dj > 9) sj = 50;
	else
	{
		for (i = 1; i <= dj; i++)
		{
			sj += i * 10;
		}
		sj = SD - sj;
	}
	for (i = 0; i <= sj; i += 10)
	{
		Sleep(10);
		if (kbhit())
		{
			userHit = getch();
			switch (userHit)
			{
			case 72:case 80:case 75:case 77:tetris_fx(userHit, 0); break;
			case 32:
			{
				userHit = getch();
				while (userHit != 32)
				{
					Sleep(20);
					userHit = getch();
					tetris_fx(userHit, 0);
					Sleep(10);
				}
				break;
			}
			default:break;
			}
		}
	}
}

void gotoxy(int x, int y)//移动光标
{
	COORD p;
	p.X = x - 1;
	p.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void ai()//电脑操作
{
	ai_mn();
	ai_cz();
}

void ai_mn()//模拟所有下落情况并求最大权
{
	int i, j, k;
	int flag = 0;
	int zdxzcs;
	double qz;
	switch (n)
	{
	case 1:zdxzcs = 1; break;
	case 2:case 3:zdxzcs = 2; break;
	case 4:case 5:zdxzcs = 2; break;
	case 6:case 7:zdxzcs = 2; break;
	case 8:case 9:case 10:case 11:zdxzcs = 4; break;
	case 12:case 13:case 14:case 15:zdxzcs = 4; break;
	case 16:case 17:case 18:case 19:zdxzcs = 4; break;
	}
	for (i = 0; i < zdxzcs; i++)
	{
		for (j = -5; j < 5; j++)
		{
			ai_n = n;
			ai_tetris_x = tetris_x;
			ai_tetris_y = tetris_y;
			memcpy(ai_temp, temp, sizeof(temp));
			memcpy(ai_ij, ij, sizeof(ai_ij));
			if (i != 0)
			{
				for (k = 0; k < i; k++)
				{
					tetris_fx(72, 1);//旋转i次
				}
			}
			/*j < 0 左移|j|次，j = 0 不移动，j > 0 右移|j|次*/
			if (j < 0)
			{
				for (k = 0; k > j; k--)
				{
					tetris_fx(75, 1);
					if (tetris_j_fx(75, 1) == 0)
					{
						j = k - 1;
						break;
					}
				}
			}
			else if (j == 0) k = 0;
			else
			{
				for (k = 0; k < j; k++)
				{
					tetris_fx(77, 1);
					if (tetris_j_fx(77, 1) == 0)
					{
						j = k + 1;
						break;
					}
				}
			}
			while (tetris_fx(80, 1));//到底部

			qz = quanzhi();
			if (flag == 0)
			{
				flag = 1;
				ai_qz = qz;
				ai_xz = i;
				ai_lr = j;
			}
			else if (ai_qz < qz)
			{
				ai_qz = qz;
				ai_xz = i;
				ai_lr = j;
			}

			if (j == k + 1) break;
		}
	}
}

void ai_cz()//进行最大权操作
{
	int i;
	for (i = 0; i < ai_xz; i++)
	{
		tetris_fx(72, 0);
	}
	if (ai_lr < 0)
	{
		for (i = 0; i > ai_lr; i--)
		{
			tetris_fx(75, 0);
		}
	}
	else if (ai_lr == 0);
	else
	{
		for (i = 0; i < ai_lr; i++)
		{
			tetris_fx(77, 0);
		}
	}
	while (tetris_fx(80, 0));
}

double quanzhi()//以下函数之和
{
	return LandingHeight() + ErodedPieceCells() + RowTransitions() + ColumTransitions() + NumberOfHoles() + WellSum();
}

double LandingHeight()//(最高+最低)/2*-4.500158825082766
{
	int i, j;
	double max = -1, min = -1;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (ai_temp[i][j] == 1)
			{
				if (max == -1) max = 20 - ai_tetris_y - i;
				min = 20 - ai_tetris_y - i;
				break;
			}
		}
	}
	return (max + min) / 2 * -4.500158825082766;
}

double ErodedPieceCells()//消除行数*方块贡献*3.4181268101392694
{
	int i, j, s = 0;
	int ai_xchs = 0;
	int ai_fkgx = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 2; j < (KUANG - 2); j++)
		{
			if (ai_ij[i + ai_tetris_y][j] == 1) s++;
			else
			{
				s = 0;
				break;
			}
			if (s == KUANG - 4)
			{
				for (j = 0; j < 4; j++)
				{
					if (ai_temp[i][j] == 1) ai_fkgx++;
				}
				s = 0;
				ai_xchs++;
			}
		}
	}
	return ai_xchs * ai_fkgx * 3.4181268101392694;
}

double RowTransitions()//所有行方块有无变化次数*-3.2178882868487753
{
	int i, j, s = 0;
	int flag;
	for (i = 0; i < (GAO - 2); i++)
	{
		flag = 1;
		for (j = 2; j < (KUANG - 2); j++)
		{
			if (ai_ij[i][j] != flag)
			{
				flag = !flag;
				s++;
			}
		}
		if (ai_ij[i][j - 1] != 1) s++;
	}
	return s * -3.2178882868487753;
}

double ColumTransitions()//所有列方块有无变化次数*-9.348695305445199
{
	int i, j, s = 0;
	int flag;
	for (j = 2; j < (KUANG - 2); j++)
	{
		flag = 1;
		for (i = 0; i < (GAO - 2); i++)
		{
			if (ai_ij[i][j] != flag)
			{
				flag = !flag;
				s++;
			}
		}
		if (ai_ij[i - 1][j] != 1) s++;
	}
	return s * -9.348695305445199;
}

double NumberOfHoles()//空洞数*-7.899265427351652
{
	int i, j, s = 0;
	int flag;
	for (j = 2; j < (KUANG - 2); j++)
	{
		flag = 0;
		for (i = 0; i < (GAO - 2); i++)
		{
			if (ai_ij[i][j]) flag = 1;
			else if (flag == 1)
			{
				flag = 0;
				s++;
			}
		}
	}
	return s * -7.899265427351652;
}

double WellSum()//总“井”值*-3.3855972247263626
{
	int i, j, k = 0, s = 0;
	int js[21] = { 0, 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78, 91, 105, 120, 136, 153, 171, 190, 210 };
	for (j = 2; j < (KUANG - 2); j++)
	{
		for (i = 0; i < (GAO - 2); i++)
		{
			if (ai_ij[i][j] == 0 && (ai_ij[i][j - 1] == 1 || ai_ij[i][j - 1] == -1) && (ai_ij[i][j + 1] == 1 || ai_ij[i][j + 1] == -1))
			{
				k++;
			}
			else
			{
				s += js[k];
				k = 0;
			}
		}
	}
	return s * -3.3855972247263626;
}

void msxz()
{
	int ok = 0;
	char userHit;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(11, 7);
	printf("■■■■■■■■■■■■■■■■");
	gotoxy(21, 10);
	printf("电 脑  模 式");
	gotoxy(21, 12);
	printf("玩 家  模 式");
	gotoxy(11, 15);
	printf("■■■■■■■■■■■■■■■■");
	gotoxy(14, 21);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	printf("\"↑\"  \"↓\"选择  \"空格\"开始");

	while (1)
	{
		Sleep(20);
		if (ms != -1 && ok == 1) break;
		else ok = 0;
		if (kbhit())
		{
			userHit = getch();
			switch (userHit)
			{
			case 72:
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				gotoxy(18, 10);
				printf("■ 电 脑  模 式 ■");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
				gotoxy(18, 12);
				printf("   玩 家  模 式   ");
				ms = 1;
				break;
			}
			case 80:
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
				gotoxy(18, 10);
				printf("   电 脑  模 式   ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				gotoxy(18, 12);
				printf("■ 玩 家  模 式 ■");
				ms = 0;
				break;
			}
			case 32:
			{
				ok = 1;
				break;
			}
			default:break;
			}
		}
		Sleep(10);
	}
	system("cls");
}