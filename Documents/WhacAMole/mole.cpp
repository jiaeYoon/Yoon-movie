#include "mole.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <sysinfoapi.h>
#include <process.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
//#define LIMIT_TIME (clock() - start) / CLOCKS_PER_SEC < 20.0f
//#define INPUT_LIMIT (clock() - start) / CLOCKS_PER_SEC < 2.0f

int dudeoji_choice; // 보스 두더지, 일반 두더지 구분
int score = 0;
int timeover = 0;

/*
	1. 타이머 함수
	2. 시작 화면 함수(메인화면 함수)
*/
void timer(int time) { //타이머 함수
	int start = GetTickCount64();

	while (1) {
		gotoxy(40, 9); printf("┌------------------------------┐\n");
		gotoxy(40, 10); printf("│                              │\n");
		gotoxy(40, 11); printf("│          time : %3d          │\n", time / 1000 - (int)((GetTickCount64() - start) / 1000));
		gotoxy(40, 12); printf("│                              │\n");
		gotoxy(40, 13); printf("└------------------------------┘\n");
		if (GetTickCount64() - start >= time) break;
	}
	return;
};

void clear_screen()
{
	system("cls");
}

void title() {
	int n = 13;
	gotoxy(n, 5); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	gotoxy(n, 6); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	gotoxy(n, 7); printf("■■□□□□□■□□□□□■□□□□□■□□□□□■□■■■□■■\n");
	gotoxy(n, 8); printf("■■□■■■■■□■■■□■■■□■■■□■■■■■□■■■□■■\n");
	gotoxy(n, 9); printf("■■□■■■■■□□□□□■■■□■■■□■■■■■□□□□□■■\n");
	gotoxy(n, 10); printf("■■□■■■■■□■■■□■■■□■■■□■■■■■□■■■□■■\n");
	gotoxy(n, 11); printf("■■□□□□□■□■■■□■■■□■■■□□□□□■□■■■□■■\n");
	gotoxy(n, 12); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	gotoxy(n, 13); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	gotoxy(n, 14); printf("■■□□■□□■■□□□■■□■■■■■□□□□□■■□□□□■■\n");
	gotoxy(n, 15); printf("■■□■□■□■□■■■□■□■■■■■□■■■■■□■■■■■■\n");
	gotoxy(n, 16); printf("■■□■□■□■□■■■□■□■■■■■□□□□□■■□□□■■■\n");
	gotoxy(n, 17); printf("■■□■■■□■□■■■□■□■■■■■□■■■■■■■■■□■■\n");
	gotoxy(n, 18); printf("■■□■■■□■■□□□■■□□□□□■□□□□□■□□□□■■■\n");
	gotoxy(n, 19); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	gotoxy(n, 20); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
}


void start_screen() {
	int state = 0;
	system("mode con cols=90 lines=40");

	title();
	gotoxy(38, 30); printf("▶ how to\n");
	gotoxy(38, 31); printf("  game start\n");
	int input_key = 0;
	while (1) {
		input_key = _getch();
		if (input_key == 72) { //위
			clear_screen();
			title();
			gotoxy(38, 30); printf("▶ how to\n");
			gotoxy(38, 31); printf("   game start\n");
			input_key = _getch();
			if (input_key == 13) {
				clear_screen();
				how_to();
				break;
			}
		}
		else if (input_key == 80) { //아래
			clear_screen();
			title();
			gotoxy(38, 30); printf("   how to\n");
			gotoxy(38, 31); printf("▶ game start\n");
			input_key = _getch();
			if (input_key == 13) {
				clear_screen();
				break;
			}
		}
		else if (input_key == 13) {
			clear_screen();
			how_to();
			break;
		}
	}
};


/*
	1. 두더지 그리는 함수 -> 두더지, 보스 두더지
	2. 점수가 마이너스 or 제한 시간이 되면 게임 오버되는 기능
	3. 점수계산 함수
*/
void dudeoji(int n, int m, int position) {		//두더지 그리는 함수
	gotoxy(n, m + 2); printf("  _____  \n");
	gotoxy(n, m + 3); printf(" /    ★ \n");
	gotoxy(n, m + 4); printf("l       l\n");
	gotoxy(n, m + 5); printf("l ∂ ∂ l\n");
	gotoxy(n, m + 6); printf("l       l\n");
	gotoxy(n, m + 7); printf("l   ▽  l\n");
	gotoxy(n, m + 8); printf("l_______l\n");
	gotoxy(n, m + 9); printf("%9d", position);
}
void boss_dudeoji(int n, int m, int position) {	//보스 두더지 그리는 함수
	gotoxy(n, m + 2); printf("  _____  \n");
	gotoxy(n, m + 3); printf(" /    ♨ \n");
	gotoxy(n, m + 4); printf("l       l\n");
	gotoxy(n, m + 5); printf("l ■-■ l\n");
	gotoxy(n, m + 6); printf("l ,,,,, l\n");
	gotoxy(n, m + 7); printf("l   ㅡ  l\n");
	gotoxy(n, m + 8); printf("l_______l\n");
	gotoxy(n, m + 9); printf("%9d", position);
}

/*
	1. 카운트 다운 함수
	2. 총점 나타내는 함수
	3. 일반 두더지, 보스 두더지 랜덤 발생 함수
	4. 입력에 따른 색 변화 함수
	5. 두더지 화면
	6. 두더지 위치 행, 열 함수
	7. 게임 방법
*/

void how_to() {
	char string1[100] = "게임은 총 20초동안 진행되며 20초가 지나면 게임은 종료됩니다.";
	char string2[100] = "두더지는 일반 두더지와 보스 두더지로 나뉘고, 각각 10점과 20점이 할당됩니다.";
	char string3[100] = "2초 안에 입력하지 못하거나, 숫자를 잘못 입력하면 점수는 5점 떨어집니다.";
	char string4[100] = "준비 되셨다면, enter 키를 눌러 게임을 시작해주세요!";

	int i = 0;
	int x, y;


	gotoxy(3, 3); printf("▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ ~ how to ~ ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");

	gotoxy(14, 8);
	while (string1[i] != '\0') {
		printf("%c", string1[i]);
		Sleep(30);
		i++;
	}

	gotoxy(7, 10);
	i = 0;
	Sleep(500);
	while (string2[i] != '\0') {
		printf("%c", string2[i]);
		Sleep(30);
		i++;
	}

	gotoxy(8, 12);
	i = 0;
	Sleep(500);
	while (string3[i] != '\0') {
		printf("%c", string3[i]);
		Sleep(30);
		i++;
	}

	gotoxy(19, 16);
	i = 0;
	Sleep(500);
	while (string4[i] != '\0') {
		printf("%c", string4[i]);
		Sleep(30);
		i++;
	}

	gotoxy(3, 20); printf("▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
	gotoxy(38, 31); printf("▶ game start\n");

	int input_key = _getch();
	if (input_key == 13)
		clear_screen();

}

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void beep() {
	printf("\a");
}

void countdown()
{
	gotoxy(45, 20); printf("3");
	beep();
	Sleep(1000);

	gotoxy(45, 20); printf("2");
	beep();
	Sleep(1000);

	gotoxy(45, 20); printf("1");
	beep();
	Sleep(1000);

	beep();
	gotoxy(43, 20); printf("start!");
	Sleep(500);
	system("cls");
}


int finalScore()
{
	gotoxy(40, 2); printf("┌------------------------------┐\n");
	gotoxy(40, 3); printf("│                              │\n");
	gotoxy(40, 4); printf("│          score : %3d         │\n", score);
	gotoxy(40, 5); printf("│                              │\n");
	gotoxy(40, 6); printf("└------------------------------┘\n");

	return score;
}

// 일반 두더지, 보스 두더지 랜덤 발생
void rand_dudeoji(int n, int m, int position) {
	srand((unsigned int)time(NULL));
	dudeoji_choice = (rand() % 5);
	if (dudeoji_choice == 0) {
		boss_dudeoji(n, m, position);
	}
	else {
		dudeoji(n, m, position);
	}
}

// 입력에 따른 색 변화  - 색 변환 함수 참고했습니다!
void print_check_arr(int color, int row, int column)
{
	if (color == 4)
	{
		gotoxy(column, row + 3);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		printf("time over!");
	}
	else if (color == 10)
	{
		gotoxy(column, row + 3);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		printf("corret!");
	}
	else if (color == 9)
	{
		gotoxy(column, row + 3);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		printf("wrong!");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	Sleep(100);
}

void dudeoji_screen() {
	int i = 0;
	gotoxy(0, 3);
	printf("┌-----------------------------------┐\n");
	while (i < 2)
	{
		for (int i = 0; i < 9; i++)
			printf("│           │           │           │\n");
		printf("├-----------------------------------┤\n");
		i++;
	}
	for (int i = 0; i < 9; i++)
		printf("│           │           │           │\n");
	printf("└-----------------------------------┘\n");
}

int position_row(int n)
{
	if (n <= 3)
		return 22;
	else if (4 <= n && n <= 6)
		return 12;
	else if (7 <= n && n <= 9)
		return 2;
}

int position_column(int n)
{
	if (n % 3 == 1)
		return 2;
	else if (n % 3 == 2)
		return 14;
	else if (n % 3 == 0)
		return 26;
}

/*
	1. 글자색 변경
	2. 게임오버 화면
*/
//rand_mole.c
//두더지 랜덤 발생
int rand_mole() {
	srand((unsigned int)time(NULL));
	int num = rand();
	return (((int)num % 9));
}

//랜덤하게 발생한 값과 사용자 입력값이 일치하는지 확인
int check(char n) {
	char m = user_input();

	//2초 안에 입력한 경우
	if (m != NULL) {
		//랜덤 발생 == 입력값 경우, 글씨를 노란색으로 변경
		if (n == m) {
			if (dudeoji_choice == 0)
				score += 20;
			else
				score += 10;
			return 10;
		}
		//랜덤 발생 != 입력값 경우, 글씨를 검은색으로 변경
		else {
			score -= 5;
			return 9;
		}
	}
	else {
		score -= 5;
		return 4;
	}
}


char user_input() {
	clock_t start = clock();
	char m = NULL;

	while (INPUT_LIMIT && m == NULL) {
		if (_kbhit())
			break;
	}
	while (_kbhit()) {
		m = _getch();
	}
	return m;
}

//랜덤 두더지 출력
/*void print_arr(int n, char* arr) {
	for (int i = 0; i < 9; i++) {
		if (i == n) { setcolor(arr[i], 6); }
		else { setcolor(arr[i], 15); }
	}
}*/


void game_over(int score) {
	gotoxy(26, 5); printf(" ######  #######  ##   ##  ######\n"); Sleep(100);
	gotoxy(26, 6); printf(" #    #  #     #  # # # #  #    \n"); Sleep(100);
	gotoxy(26, 7); printf(" #    #  #     #  #  #  #  #    \n"); Sleep(100);
	gotoxy(26, 8); printf(" #       #######  #     #  ######\n"); Sleep(100);
	gotoxy(26, 9); printf(" #  ###  #     #  #     #  #    \n"); Sleep(100);
	gotoxy(26, 10); printf(" #    #  #     #  #     #  #    \n"); Sleep(100);
	gotoxy(26, 11); printf(" ######  #     #  #     #  ######\n\n"); Sleep(100);

	gotoxy(26, 12); printf(" ######  #    #  #######  ######\n"); Sleep(100);
	gotoxy(26, 13); printf(" #    #  #    #  #        #    #\n"); Sleep(100);
	gotoxy(26, 14); printf(" #    #  #    #  #        #   # \n"); Sleep(100);
	gotoxy(26, 15); printf(" #    #  #    #  #######  ##### \n"); Sleep(100);
	gotoxy(26, 16); printf(" #    #  #    #  #        #    # \n"); Sleep(100);
	gotoxy(26, 17); printf(" #    #   #  #   #        #     # \n"); Sleep(100);
	gotoxy(26, 18); printf(" ######    #     #######  #      # \n\n"); Sleep(100);

	gotoxy(26, 22); printf("┌------------------------------┐\n");
	gotoxy(26, 23); printf("│                              │\n");
	gotoxy(26, 24); printf("│          score : %3d         │\n", score);
	gotoxy(26, 25); printf("│                              │\n");
	gotoxy(26, 26); printf("└------------------------------┘\n");
}

void update_time(clock_t start)
{
	gotoxy(40, 8); printf("┌------------------------------┐\n");
	gotoxy(40, 9); printf("│                              │\n");
	gotoxy(40, 10); printf("│          time : %3d          │\n", 20 - (clock() - start) / CLOCKS_PER_SEC);
	gotoxy(40, 11); printf("│                              │\n");
	gotoxy(40, 12); printf("└------------------------------┘\n");
}