#ifndef dudeoji_game
#define dudeoji_game
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

void timer(int time);
void clear_screen();
void start_screen();
void how_to();
void dudeoji(int n, int m, int position);
void boss_dudeoji(int n, int m, int position);
void gotoxy(int x, int y);
void beep();
void countdown();
int finalScore();
void update_time(clock_t start);
int rand_mole();
void rand_dudeoji(int n, int m, int position);
int check(char n);
char user_input();
void print_check_arr(int color, int row, int column);
void game_over(int score);
void dudeoji_screen();
int position_row(int n);
int position_column(int n);
#endif

