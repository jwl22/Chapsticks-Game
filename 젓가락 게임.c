#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

void print_hand(int userleft, int userright, int comleft, int comright);
void menu(void);
int RSP(void);
void game(int Luser, int Ruser, int Lcom, int Rcom);

int main()
{
	srand((unsigned)time(NULL));

	menu();		//메뉴 출력
	int Lcom = 1, Rcom = 1, Luser = 1, Ruser = 1;
	if (RSP() == 0)		//가위바위보 후 리턴값이 0일 때(졌을 때)
	{
		if (rand() % 2 + 1 == 1)
		{
			Luser += 1;
			printf("컴퓨터가 유저의 왼쪽 손을 공격했습니다.\n");
		}
		else
		{
			Ruser += 1;
			printf("컴퓨터가 유저의 오른쪽 손을 공격했습니다.\n");
		}
	}	 // 2개 중 하나의 랜덤 숫자를 부여하여 공격
	game(Luser, Ruser, Lcom, Rcom);

	system("pause");
	return 0;
}

void print_hand(int userleft, int userright, int comleft, int comright)
{
	int lefthand[6][7][10] = {			//3차원 배열을 통한 손 모양 그림 만들기
		{
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 2, 3, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
			{ 2, 3, 2, 3, 2, 3, 1, 1, 0, 0 },
			{ 1, 4, 5, 4, 5, 4, 5, 1, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0, 4, 3, 0 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0 }
		},
		{
			{ 0, 0, 0, 0, 2, 3, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 1, 1, 2, 3, 0, 0 },
			{ 0, 0, 0, 0, 1, 1, 1, 1, 0, 0 },
			{ 2, 3, 2, 3, 1, 1, 1, 1, 0, 0 },
			{ 1, 4, 5, 4, 5, 4, 5, 1, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0, 4, 3, 0 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0 }
		},
		{
			{ 0, 0, 2, 3, 2, 3, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 1, 1, 2, 3, 0, 0 },
			{ 0, 0, 1, 1, 1, 1, 1, 1, 0, 0 },
			{ 2, 3, 1, 1, 1, 1, 1, 1, 0, 0 },
			{ 1, 4, 5, 4, 5, 4, 5, 1, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0, 4, 3, 0 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0 }
		},
		{
			{ 0, 0, 2, 3, 2, 3, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 1, 1, 2, 3, 0, 0 },
			{ 2, 3, 1, 1, 1, 1, 1, 1, 0, 0 },
			{ 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
			{ 1, 4, 5, 4, 5, 4, 5, 1, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0, 4, 3, 0 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0 }
		},
		{
			{ 0, 0, 2, 3, 2, 3, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 1, 1, 2, 3, 0, 0 },
			{ 2, 3, 1, 1, 1, 1, 1, 1, 0, 0 },
			{ 1, 1, 1, 1, 1, 1, 1, 1, 2, 3 },
			{ 1, 4, 5, 4, 5, 4, 5, 1, 1, 1 },
			{ 1, 0, 0, 0, 0, 0, 0, 4, 5, 1 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 }
		}
	};
	int righthand[6][7][10] = {
		{
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 2, 3, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 2, 3, 2, 3, 2, 3 },
			{ 0, 0, 1, 4, 5, 4, 5, 4, 5, 1 },
			{ 0, 2, 5, 0, 0, 0, 0, 0, 0, 1 },
			{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 }
		},
		{
			{ 0, 0, 0, 0, 2, 3, 0, 0, 0, 0 },
			{ 0, 0, 2, 3, 1, 1, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 1, 1, 2, 3, 2, 3 },
			{ 0, 0, 1, 4, 5, 4, 5, 4, 5, 1 },
			{ 0, 2, 5, 0, 0, 0, 0, 0, 0, 1 },
			{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 }
		},
		{
			{ 0, 0, 0, 0, 2, 3, 2, 3, 0, 0 },
			{ 0, 0, 2, 3, 1, 1, 1, 1, 0, 0 },
			{ 0, 0, 1, 1, 1, 1, 1, 1, 0, 0 },
			{ 0, 0, 1, 1, 1, 1, 1, 1, 2, 3 },
			{ 0, 0, 1, 4, 5, 4, 5, 4, 5, 1 },
			{ 0, 2, 5, 0, 0, 0, 0, 0, 0, 1 },
			{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 }
		},
		{
			{ 0, 0, 0, 0, 2, 3, 2, 3, 0, 0 },
			{ 0, 0, 2, 3, 1, 1, 1, 1, 0, 0 },
			{ 0, 0, 1, 1, 1, 1, 1, 1, 2, 3 },
			{ 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 0, 0, 1, 4, 5, 4, 5, 4, 5, 1 },
			{ 0, 2, 5, 0, 0, 0, 0, 0, 0, 1 },
			{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 }
		},
		{
			{ 0, 0, 0, 0, 2, 3, 2, 3, 0, 0 },
			{ 0, 0, 2, 3, 1, 1, 1, 1, 0, 0 },
			{ 0, 0, 1, 1, 1, 1, 1, 1, 2, 3 },
			{ 2, 3, 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 4, 5, 4, 5, 4, 5, 1 },
			{ 1, 4, 5, 0, 0, 0, 0, 0, 0, 1 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 }
		}
	};
	int comlefthand[6][7][10], comrighthand[6][7][10];  //컴퓨터의 손
	int i, j, k;
	for (i = 0; i < 6; i++)
		for (j = 0; j < 7; j++)
			for (k = 0; k < 10; k++)
			{
				comlefthand[i][6 - j][k] = righthand[i][j][k];
				comrighthand[i][6 - j][k] = lefthand[i][j][k];	//컴퓨터의 손을 유저의 손울 180도 돌린모습으로 만들기 위해 줄 바꾸기
			}
	for (i = 0; i < 6; i++)
		for (j = 0; j < 7; j++)
			for (k = 0; k < 10; k++)
			{						//손을 돌렸을 때 맞지 않는 격자 무늬 교체
				if (comlefthand[i][j][k] == 2)
					comlefthand[i][j][k] = 4;
				else if (comlefthand[i][j][k] == 3)
					comlefthand[i][j][k] = 5;
				else if (comlefthand[i][j][k] == 4)
					comlefthand[i][j][k] = 2;
				else if (comlefthand[i][j][k] == 5)
					comlefthand[i][j][k] = 3;
				if (comrighthand[i][j][k] == 2)
					comrighthand[i][j][k] = 4;
				else if (comrighthand[i][j][k] == 3)
					comrighthand[i][j][k] = 5;
				else if (comrighthand[i][j][k] == 4)
					comrighthand[i][j][k] = 2;
				else if (comrighthand[i][j][k] == 5)
					comrighthand[i][j][k] = 3;
			}
	for (j = 0; j < 7; j++)		 //문자별로 격자 또는 띄어쓰기 입력.
	{	
		i = comright;
		printf("\n");
		for (k = 0; k < 10; k++)
		{
			switch (comrighthand[i][j][k]) 
			{
			case 1:printf("│"); break;
			case 2:printf("┌"); break;
			case 3:printf("┐"); break;
			case 4:printf("└"); break;
			case 5:printf("┘"); break;
			default: printf(" "); break;
			}
		}
		printf(" ");
		i = comleft;
		for (k = 0; k < 10; k++)
		{
			switch (comlefthand[i][j][k])
			{
			case 1:printf("│"); break;
			case 2:printf("┌"); break;
			case 3:printf("┐"); break;
			case 4:printf("└"); break;
			case 5:printf("┘"); break;
			default: printf(" "); break;
			}
		}
	}
	for (j = 0; j < 7; j++)
	{
		i = userleft;
		printf("\n");
		for (k = 0; k < 10; k++)
		{
			switch (lefthand[i][j][k])
			{
			case 1:printf("│"); break;
			case 2:printf("┌"); break;
			case 3:printf("┐"); break;
			case 4:printf("└"); break;
			case 5:printf("┘"); break;
			default: printf(" "); break;
			}
		}
		printf(" ");
		i = userright;
		for (k = 0; k < 10; k++)
		{
			switch (righthand[i][j][k])
			{
			case 1:printf("│"); break;
			case 2:printf("┌"); break;
			case 3:printf("┐"); break;
			case 4:printf("└"); break;
			case 5:printf("┘"); break;
			default: printf(" "); break;
			}
		}
	}
	printf("\n");
}
void menu(void)
{
	printf("-----------------------------------------젓가락 게임-----------------------------------------\n\n");
	printf("게임 규칙 : 공격받으면 친 사람이 편 손가락 개수+원래 펴진 손가락 개수대로 손가락을 핀다.\n");
	printf("            시작은 1 - 1이며 한 손에서 모든 손가락을 펴면 그 손은 아웃. \n");
	printf("            개수 총합이 2 이상이면 손가락 재배열을 할 수 있지만 공격권을 상대에게 넘겨준다.\n");
	printf("            두 손이 모두 아웃 처리되면 패배와 동시에 게임 끝.\n");
	printf("            주의 사항 : 한 손만 살았을 때 위치만 바꾸기는 금지이다.\n\n");
	printf("                             < ENTER키를 눌러 게임을 시작합니다.> ");

	while (1)
	{
		char ch = _getch();
		if (ch == 13)		//엔터키 입력 시
		{			
			system("cls");	//화면 청소
			break;
		}
	}
}
int RSP(void)
{
	printf("선을 정하기 위해 가위바위보를 합니다.\n");
	Sleep(2000);	//2초 정지
	system("cls");
	printf("가위, 바위, 보 중 하나를 고르세요 : ");
	char usersel[20];
	int ruser, rcom, user;
A:	scanf("%s", usersel);
	if (strcmp(usersel, "바위") == 0)
		ruser = 1;
	else if (strcmp(usersel, "보") == 0)
		ruser = 2;
	else if (strcmp(usersel, "가위") == 0)
		ruser = 3;
	else
	{
		printf("잘못 입력하셨습니다.\n다시 입력하십시오 : ");
		goto A;
	}
	rcom = rand() % 3 + 1;
	if (rcom == 1)
		printf("컴퓨터 : 바위\n");
	else if (rcom == 2)
		printf("컴퓨터 : 보\n");
	else
		printf("컴퓨터 : 가위\n"); //3개중 하나의 랜덤숫자 지정하여 컴퓨터의 가위,바위,보 선택

	if (rcom == ruser)
	{
		printf("비겼습니다.\n다시 내주십시오 : ");
		goto A;
	}
	else if (rcom - ruser == 1 || (ruser == 3 && rcom == 1)) //바위,보,가위 를 순서대로 1,2,3이라 할 때 유저숫자가 컴퓨터보다 1 작으면 지는 걸 이용. 단 4는 없으므로 3일때는 따로 조건 생성
	{
		printf("졌습니다.\n컴퓨터가 먼저 공격합니다.\n");
		user = 0;
	}
	else
	{
		printf("이겼습니다.\n");
		user = 1;
	}
	Sleep(2000);
	system("cls");
	return user;
}
void game(int Luser, int Ruser, int Lcom, int Rcom)
{
	while (!(Luser == 0 && Ruser == 0 || Lcom == 0 && Rcom == 0)) //유저의 공격차례에서 공통 반복문 이용. 컴퓨터나 유저가 양손이 모두 펴졌을 때 반복문 종료
	{
	B:	print_hand(Luser, Ruser, Lcom, Rcom); //현재 내 손과 컴퓨터의 손 프린트
		char sel1[15], sel2[15];
		if (Luser != 0 && Ruser != 0) //유저의 양손 모두 펴지지 않은 경우
		{
		E:	printf("1. 공격\n2. 손 재배치\n선택 : ");
			int attsel0;
			scanf("%d", &attsel0);
			if (attsel0 == 1) //공격
			{
				if (Lcom != 0 && Rcom != 0) //컴퓨터가 양손 모두 있을 때
				{
					printf("컴퓨터의 왼손과 오른손 중 공격할 손 : ");
					scanf("%s", sel1);
					printf("유저의 왼손과 오른손 중 공격할 손 : ");
					scanf("%s", sel2);
				}
				else if (Lcom == 0)  //컴퓨터의 왼손이 모두 펴졌을 때
				{
					printf("컴퓨터의 오른손을 공격합니다.\n");
					strcpy(sel1, "오른손");
					printf("유저의 왼손과 오른손 중 공격할 손 : ");
					scanf("%s", sel2);
				}
				else if (Rcom == 0)  //컴퓨터의 오른손이 모두 펴졌을 때
				{
					printf("컴퓨터의 왼손을 공격합니다.\n");
					strcpy(sel1, "왼손");
					printf("유저의 왼손과 오른손 중 공격할 손 : ");
					scanf("%s", sel2);
				}
				if (strcmp(sel1, "왼손") == 0)  //입력받은 공격할 손이 왼손일 때
				{
					if (strcmp(sel2, "왼손") == 0)
						Lcom += Luser;
					else if (strcmp(sel2, "오른손") == 0)
						Lcom += Ruser;
					else
					{
						system("cls");
						printf("잘못 입력하셨습니다.\n");
						Sleep(1000);
						system("cls");
						goto B;
					}
				}
				else if (strcmp(sel1, "오른손") == 0)
				{
					if (strcmp(sel2, "왼손") == 0)
						Rcom += Luser;
					else if (strcmp(sel2, "오른손") == 0)
						Rcom += Ruser;
					else
					{
						system("cls");
						printf("잘못 입력하셨습니다.\n");
						Sleep(1000);
						system("cls");
						goto B;
					}
				}
				else
				{
					system("cls");
					printf("잘못 입력하셨습니다.\n");
					Sleep(1000);
					system("cls");
					goto B;
				}
			}
			else if (attsel0 == 2) //재배치
			{
				printf("1. 왼손에서 오른손으로\n2. 오른손에서 왼손으로\n선택 : ");
				int crossnum;
				scanf("%d", &crossnum);
				if (crossnum == 1)
				{
					int movenum01;
					while (1)
					{
						printf("왼손에서 오른손으로 얼마나 이동시키겠습니까? : ");
						scanf("%d", &movenum01);
						if (movenum01 >= 1 && movenum01 <= Luser && movenum01 + Ruser < 5) //입력한 수가 1~왼손가락수 이내, 입력수+오른손가락수가 5개미만일 때
						{
							Luser -= movenum01;
							Ruser += movenum01;
							break;	//반복문 탈출
						}
						else
							printf("잘못 입력하셨습니다.\n");
					}
				}
				else if (crossnum == 2)
				{
					int movenum02;
					while (1)
					{
						printf("오른손에서 왼손으로 얼마나 이동시키겠습니까? : ");
						scanf("%d", &movenum02);
						if (movenum02 >= 1 && movenum02 <= Ruser && movenum02 + Luser < 5) //입력한 수가 1~오른손가락수 이내, 입력수+왼손가락수가 5개미만일 때
						{
							Luser += movenum02;
							Ruser -= movenum02;
							break;
						}
						else
							printf("잘못 입력하셨습니다.\n");
					}
				}
			}
			else
			{
				printf("잘못 입력하셨습니다.\n다시 입력해주십시오 : \n");
				goto E;
			}
		}
		else if (Luser == 0) //유저의 왼손이 모두 펴진경우
		{
		C:	printf("1. 공격\n2. 손 재배치\n선택 : ");
			int attsel;
			scanf("%d", &attsel);
			if (attsel == 1) //공격
			{
				if (Lcom == 0)
				{
					printf("컴퓨터의 오른손을 공격합니다.\n");
					strcpy(sel1, "오른손");
					printf("유저의 오른손으로 공격합니다.\n");
					strcpy(sel2, "오른손");
				}
				else if (Rcom == 0)
				{
					printf("컴퓨터의 왼손을 공격합니다.\n");
					strcpy(sel1, "왼손");
					printf("유저의 오른손으로 공격합니다.\n");
					strcpy(sel2, "오른손");
				}
				else
				{
					printf("컴퓨터의 왼손과 오른손 중 공격할 손 : ");
					scanf("%s", sel1);
					printf("유저의 오른손으로 공격합니다.\n");
					strcpy(sel2, "오른손");
				}
				if (strcmp(sel1, "왼손") == 0)
				{
					if (strcmp(sel2, "왼손") == 0)
						Lcom += Luser;
					else if (strcmp(sel2, "오른손") == 0)
						Lcom += Ruser;
					else
					{
						system("cls");
						printf("잘못 입력하셨습니다.\n");
						Sleep(1000);
						system("cls");
						goto B;
					}
				}
				else if (strcmp(sel1, "오른손") == 0)
				{
					if (strcmp(sel2, "왼손") == 0)
						Rcom += Luser;
					else if (strcmp(sel2, "오른손") == 0)
						Rcom += Ruser;
					else
					{
						system("cls");
						printf("잘못 입력하셨습니다.\n");
						Sleep(1000);
						system("cls");
						goto B;
					}
				}
				else
				{
					system("cls");
					printf("잘못 입력하셨습니다.\n");
					Sleep(1000);
					system("cls");
					goto B;
				}
			}
			else if (attsel == 2) //재배치
			{
				if (Ruser == 1)
				{
					printf("손가락 개수가 2개 이상이여야 합니다.\n"); //규칙상 손가락 하나일 때 위치이동만 불가능.
					goto C;
				}
				int movenum001;
				while (1)
				{
					printf("오른손에서 왼손으로 얼마나 이동시키겠습니까? : ");
					scanf("%d", &movenum001);
					if (movenum001 == Ruser)
						printf("%d보다 낮은 숫자만 이동시킬 수 있습니다.\n", Ruser);           //규칙상 위치만 이동 금지이므로 모든 손가락 이동 차단
					else if (movenum001 >= 1 && movenum001 <= Ruser && movenum001 + Luser < 5) //입력한 수가 1~오른손가락수 이내, 입력수+왼손가락수가 5개미만일 때
					{
						Luser += movenum001;
						Ruser -= movenum001;
						break;
					}
					else
						printf("잘못 입력하셨습니다.\n");
				}
			}
			else
			{
				printf("잘못 입력하셨습니다.\n ");
				goto C;
			}
		}
		else if (Ruser == 0)
		{
		D:	printf("1. 공격\n2. 손 재배치\n선택 : ");
			int attsel2;
			scanf("%d", &attsel2);
			if (attsel2 == 1) //공격
			{
				if (Lcom == 0)
				{
					printf("컴퓨터의 오른손을 공격합니다.\n");
					strcpy(sel1, "오른손");
					printf("유저의 왼손으로 공격합니다.\n");
					strcpy(sel2, "왼손");
				}
				else if (Rcom == 0)
				{
					printf("컴퓨터의 왼손을 공격합니다.\n");
					strcpy(sel1, "왼손");
					printf("유저의 왼손으로 공격합니다.\n");
					strcpy(sel2, "왼손");
				}
				else
				{
					printf("컴퓨터의 왼손과 오른손 중 공격할 손 : ");
					scanf("%s", sel1);
					printf("유저의 왼손으로 공격합니다.\n");
					strcpy(sel2, "왼손");
				}
				if (strcmp(sel1, "왼손") == 0)
				{
					if (strcmp(sel2, "왼손") == 0)
						Lcom += Luser;
					else if (strcmp(sel2, "오른손") == 0)
						Lcom += Ruser;
					else
					{
						system("cls");
						printf("잘못 입력하셨습니다.\n");
						Sleep(1000);
						system("cls");
						goto B;
					}
				}
				else if (strcmp(sel1, "오른손") == 0)
				{
					if (strcmp(sel2, "왼손") == 0)
						Rcom += Luser;
					else if (strcmp(sel2, "오른손") == 0)
						Rcom += Ruser;
					else
					{
						system("cls");
						printf("잘못 입력하셨습니다.\n");
						Sleep(1000);
						system("cls");
						goto B;
					}
				}
				else
				{
					system("cls");
					printf("잘못 입력하셨습니다.\n");
					Sleep(1000);
					system("cls");
					goto B;
				}
			}
			else if (attsel2 == 2) //재배치
			{
				if (Luser == 1)
				{
					printf("손가락 개수가 2개 이상이여야 합니다.\n");
					goto D;
				}
				int movenum2;
				while (1)
				{
					printf("왼손에서 오른손으로 얼마나 이동시키겠습니까? : ");
					scanf("%d", &movenum2);
					if (movenum2 == Luser)
						printf("%d보다 낮은 숫자만 이동시킬 수 있습니다.\n", Luser);
					else if (movenum2 >= 1 && movenum2 <= Luser && movenum2 + Ruser < 5) //입력한 수가 1~왼손가락수 이내, 입력수+오른손가락수가 5개미만일 때
					{
						Luser -= movenum2;
						Ruser += movenum2;
						break;
					}
					else
						printf("잘못 입력하셨습니다.\n");
				}
			}
			else
			{
				printf("잘못 입력하셨습니다.\n");
				goto D;
			}
		}
		system("cls");
		if (Rcom >= 5)
			Rcom = 0;
		else if (Lcom >= 5)
			Lcom = 0;
		else if (Luser >= 5)
			Luser = 0;
		else if (Ruser >= 5)
			Ruser = 0;
		if (Luser == 0 && Ruser == 0 || Lcom == 0 && Rcom == 0)  //유저의 순서가 끝난 후, 컴퓨터의 턴 전에 while문의 조건을 만족하지 못하는 경우 while문 탈출
			break;
		print_hand(Luser, Ruser, Lcom, Rcom);
		Sleep(2000);
		system("cls");
		if (Lcom == 0)	//컴퓨터 왼손이 모두 펴졌을 때
		{
			if (Luser == 0 && Rcom + Ruser >= 5) //유저의 왼손만 모두 펴진상태에서 유저의 오른손 공격 시 모두 펼 수 있을 때(컴퓨터의 승리 조건)
			{
				printf("컴퓨터가 오른쪽 손으로 유저의 오른쪽 손을 공격했습니다.\n");
				Ruser += Rcom;
			}
			else if (Ruser == 0 && Rcom + Luser >= 5) //유저의 오른손만 모두 펴진상태에서 유저의 왼손 공격 시 모두 펼 수 있을 때(컴퓨터의 승리 조건)
			{
				printf("컴퓨터가 오른쪽 손으로 유저의 왼쪽 손을 공격했습니다.\n");
				Luser += Rcom;
			}
			else if ((Rcom + Luser >= 5 || Rcom + Ruser >= 5 || Rcom + Rcom + Ruser >= 5 || Rcom + Rcom + Luser >= 5) && Rcom >= 2)
			{	//컴퓨터의 오른손가락이 두개이상이며, 현재 컴퓨터의 손이 위험하거나 컴퓨터가 공격한 후 컴퓨터의 손이 위험할 때.	
				printf("컴퓨터가 오른쪽 손에서 왼쪽 손으로 %d만큼 이동시켰습니다.\n", Rcom / 2);
				Lcom = Lcom + Rcom / 2; //반만큼 손가락 이동
				Rcom = Rcom - Rcom / 2;
			}
			else if (Luser == 0) //컴퓨터의 승리 조건은 만족 못하고 위의 조건 아래 안전할 때 공격
			{
				printf("컴퓨터가 오른쪽 손으로 유저의 오른쪽 손을 공격했습니다.\n");
				Ruser += Rcom;
			}
			else if (Ruser == 0)
			{
				printf("컴퓨터가 오른쪽 손으로 유저의 왼쪽 손을 공격했습니다.\n");
				Luser += Rcom;
			}
			else
			{
				printf("컴퓨터가 오른쪽 손으로 ");
				if (Rcom + Luser >= 5 && Rcom + Ruser < 5) //컴퓨터가 유저 공격 시 손가락을 모두 펼 수 있고 다음 턴에 안전한 경우
				{
					printf("유저의 왼쪽 손을 공격했습니다.\n");
					Luser += Rcom;
				}
				else if (Rcom + Ruser >= 5 && Rcom + Luser < 5)
				{
					printf("유저의 오른쪽 손을 공격했습니다.\n");
					Ruser += Rcom;
				}
				else
				{
					if (rand() % 2 + 1 == 1)
					{
						printf("유저의 왼쪽 손을 공격했습니다.\n");
						Luser += Rcom;
					}
					else
					{
						printf("유저의 오른쪽 손을 공격했습니다.\n");
						Ruser += Rcom;
					}
				}
			}
		}
		else if (Rcom == 0) //컴퓨터 오른손이 모두 펴졌을 때
		{
			if (Luser == 0 && Lcom + Ruser >= 5) //컴퓨터의 승리 조건
			{
				printf("컴퓨터가 왼쪽 손으로 유저의 오른쪽 손을 공격했습니다.\n");
				Ruser += Lcom;
			}
			else if (Ruser == 0 && Lcom + Luser >= 5) //컴퓨터의 승리 조건
			{
				printf("컴퓨터가 왼쪽 손으로 유저의 왼쪽 손을 공격했습니다.\n");
				Luser += Lcom;
			}
			else if ((Lcom + Luser >= 5 || Lcom + Ruser >= 5 || Lcom + Lcom + Ruser >= 5 || Lcom + Lcom + Luser >= 5) && Lcom >= 2)
			{	//컴퓨터의 왼손가락이 두개이상이며, 현재 컴퓨터의 손이 위험하거나 컴퓨터가 공격한 후 컴퓨터의 손이 위험할 때.	
				printf("컴퓨터가 왼쪽 손에서 오른쪽 손으로 %d만큼 이동시켰습니다.\n", Lcom / 2);
				Rcom = Rcom + Lcom / 2;
				Lcom = Lcom - Lcom / 2;
			}
			else if (Ruser == 0)
			{
				printf("컴퓨터가 왼쪽 손으로 유저의 왼쪽 손을 공격했습니다.\n");
				Luser += Lcom;
			}
			else if (Luser == 0)
			{
				printf("컴퓨터가 왼쪽 손으로 유저의 오른 손을 공격했습니다.\n");
				Ruser += Lcom;
			}
			else
			{
				printf("컴퓨터가 왼쪽 손으로 ");
				if (Lcom + Luser >= 5 && Lcom + Ruser < 5)
				{
					printf("유저의 왼쪽 손을 공격했습니다.\n");
					Luser += Lcom;
				}
				else if (Lcom + Ruser >= 5 && Lcom + Luser < 5)
				{
					printf("유저의 오른쪽 손을 공격했습니다.\n");
					Ruser += Lcom;
				}
				else
				{
					if (rand() % 2 + 1 == 1)
					{
						printf("유저의 왼쪽 손을 공격했습니다.\n");
						Luser += Lcom;
					}
					else
					{
						printf("유저의 오른쪽 손을 공격했습니다.\n");
						Ruser += Lcom;
					}
				}
			}
		}
		else //컴퓨터의 양손이 모두 살아있을 때
		{
			if (Lcom + Luser >= 5 && Lcom + Ruser < 5) //컴퓨터가 왼손으로 안전하게 유저의 왼손가락을 모두 펼 수 있을 때
			{
				printf("컴퓨터가 왼쪽 손으로 유저의 왼쪽 손을 공격했습니다.\n");
				Luser += Lcom;
			}
			else if (Lcom + Ruser >= 5 && Lcom + Luser < 5) //컴퓨터가 왼손으로 안전하게 유저의 오른손가락을 모두 펼 수 있을 때
			{
				printf("컴퓨터가 왼쪽 손으로 유저의 오른쪽 손을 공격했습니다.\n");
				Ruser += Lcom;
			}
			else if (Rcom + Ruser >= 5 && Rcom + Luser < 5) //컴퓨터가 오른손으로 안전하게 유저의 오른손가락을 모두 펼 수 있을 때
			{
				printf("컴퓨터가 오른쪽 손으로 유저의 오른쪽 손을 공격했습니다.\n");
				Ruser += Rcom;
			}
			else if (Rcom + Luser >= 5 && Rcom + Ruser < 5) //컴퓨터가 오른손으로 안전하게 유저의 왼손가락을 모두 펼 수 있을 때
			{
				printf("컴퓨터가 오른쪽 손으로 유저의 왼쪽 손을 공격했습니다.\n");
				Luser += Rcom;
			}
			else if ((Luser + Lcom >= 5 && Luser <= 3 || Ruser + Lcom >= 5 && Ruser <= 3) && Rcom + Lcom / 2 < 5)
			{	//현재 위험하고, 옮겼을 때 만약 유저의 한 손의 손가락이 4개이상이면 손가락 하나도 잡히기 때문에 위험하겠지만 3개 이하로 재배치해도 안전한 경우. 또한 오른손이 받아도 5개 이하인 경우.
				printf("컴퓨터가 왼쪽 손에서 오른쪽 손으로 %d만큼 이동시켰습니다.\n", Lcom / 2);
				Rcom = Rcom + Lcom / 2;
				Lcom = Lcom - Lcom / 2;
			}
			else if ((Luser + Rcom >= 5 && Luser <= 3 || Ruser + Rcom >= 5 && Ruser <= 3) && Lcom + Rcom / 2 < 5)
			{	//현재 위험하고, 유저 손가락이 3개 이하로 재배치해도 안전한 경우. 또한 왼손이 받아도 5개 이하인 경우.
				printf("컴퓨터가 오른쪽 손에서 왼쪽 손으로 %d만큼 이동시켰습니다.\n", Rcom / 2);
				Lcom = Lcom + Rcom / 2;
				Rcom = Rcom - Rcom / 2;
			}
			else
			{
				if (Lcom + Luser + Rcom < 5 && Lcom + Luser + Lcom < 5 && Luser != 0) //유저의 왼쪽손을 공격하고 이후에 공격받아도 안전할 때
				{
					printf("컴퓨터가 왼쪽 손으로 유저의 왼쪽 손을 공격했습니다.\n");
					Luser += Lcom;
				}
				else if (Lcom + Ruser + Rcom < 5 && Lcom + Ruser + Lcom < 5 && Ruser != 0) //유저의 오른쪽손을 공격하고 이후에 공격받아도 안전할 때
				{
					printf("컴퓨터가 왼쪽 손으로 유저의 오른쪽 손을 공격했습니다.\n");
					Ruser += Lcom;
				}
				else if (Rcom + Ruser + Rcom < 5 && Rcom + Ruser + Lcom < 5 && Ruser != 0) //유저의 오른쪽손을 공격하고 이후에 공격받아도 안전할 때
				{
					printf("컴퓨터가 오른쪽 손으로 유저의 오른쪽 손을 공격했습니다.\n");
					Ruser += Rcom;
				}
				else if (Rcom + Luser + Rcom < 5 && Rcom + Luser + Lcom < 5 && Luser != 0) //유저의 왼쪽손을 공격하고 이후에 공격받아도 안전할 때
				{
					printf("컴퓨터가 오른쪽 손으로 유저의 왼쪽 손을 공격했습니다.\n");
					Luser += Rcom;
				}
				else
				{
					if (rand() % 2 + 1 == 1) //랜덤 공격
					{
						printf("컴퓨터가 왼쪽 손으로 ");
						if (Ruser == 0)
						{
							printf("유저의 왼쪽 손을 공격했습니다.\n");
							Luser += Lcom;
						}
						else if (Luser == 0)
						{
							printf("유저의 오른 손을 공격했습니다.\n");
							Ruser += Lcom;
						}
						else
						{
							if (rand() % 2 + 1 == 1)
							{
								printf("유저의 왼쪽 손을 공격했습니다.\n");
								Luser += Lcom;
							}
							else
							{
								printf("유저의 오른쪽 손을 공격했습니다.\n");
								Ruser += Lcom;
							}
						}
					}
					else
					{
						printf("컴퓨터가 오른쪽 손으로 ");
						if (Luser == 0)
						{
							printf("유저의 오른쪽 손을 공격했습니다.\n");
							Ruser += Rcom;
						}
						else if (Ruser == 0)
						{
							printf("유저의 왼쪽 손을 공격했습니다.\n");
							Luser += Rcom;
						}
						else
						{
							if (rand() % 2 + 1 == 1)
							{
								printf("유저의 왼쪽 손을 공격했습니다.\n");
								Luser += Rcom;
							}
							else
							{
								printf("유저의 오른쪽 손을 공격했습니다.\n");
								Ruser += Rcom;
							}
						}
					}
				}
			}
		}
		if (Rcom >= 5)
			Rcom = 0;
		else if (Lcom >= 5)
			Lcom = 0;
		else if (Luser >= 5)
			Luser = 0;
		else if (Ruser >= 5)
			Ruser = 0;
	}

	if (Luser == 0 && Ruser == 0) //유저의 양손이 모두 펴졌을 때
	{
		print_hand(Luser, Ruser, Lcom, Rcom);
		printf("패배하였습니다.\n");
	}
	else if (Lcom == 0 && Rcom == 0) //컴퓨터의 양손이 모두 펴졌을 때
	{
		print_hand(Luser, Ruser, Lcom, Rcom);
		printf("승리하였습니다.\n");
	}
}