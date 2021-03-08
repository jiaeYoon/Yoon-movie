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
#define LIMIT_TIME (clock() - start) / CLOCKS_PER_SEC < 20.0f
#define INPUT_LIMIT (clock() - start) / CLOCKS_PER_SEC < 2.0f

int main() {
	system("mode con cols=90 lines=40");
	char arr[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	int row, column;
	int position_num;
	int score;

	start_screen();
	countdown();
	clock_t start = clock();

	PlaySound(TEXT("timevoice.wav"), NULL, SND_ASYNC);
	while (LIMIT_TIME) {		//20초 동안 진행
		//랜덤 두더지 발생
		dudeoji_screen();
		int n = rand_mole();
		position_num = n + 1; // 두더지 위치
		score = finalScore();
		update_time(start);
		// timer(20000);

		// 두더지 번호 위치 출력
		row = position_row(position_num);
		column = position_column(position_num);
		rand_dudeoji(column, row, position_num);

		// 번호 위치 출력
		int check_color = check(arr[n]);
		print_check_arr(check_color, row, column);

	}
	clear_screen();
	game_over(score);
	gotoxy(34, 28); printf("▷▷▷ END ◁◁◁\n");
}