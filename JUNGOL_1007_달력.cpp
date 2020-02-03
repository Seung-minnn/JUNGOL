#include<stdio.h>
#include<iostream>

using namespace std;

int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

bool check_yun(int y) {
	if (y % 400 == 0) {
		return true;
	}
	else if (y % 4 == 0 && y % 100 != 0) {
		return true;
	}
	else {
		return false;
	}
}
void print(int y, int m, int d) {
	int sum = 0;
	for (int i = 2000; i < y; i++) {
		if (check_yun(i) == true) {
			sum += 2;
		}
		else if (check_yun(i) == false) {
			sum += 1;
		}
	}

	//일:0 월:1 ...토:6
	int week = 6;
	week = (week + sum) % 7; //y년 1월 1일의 요일

	for (int i = 1; i < m; i++) {
		week = (week + month[i - 1]) % 7; //y년 m-1월 마지막일까지의 요일
	}
	int mw = (week + 1) % 7;
	week = (week + d - 1) % 7; //해당 날짜의 요일

	printf("%d. %d\n", y, m);
	printf("sun mon tue wed thu fri sat\n");
	for (int i = 0; i < month[m - 1]; i++) {
		if (i == 0) {
			if (mw == 0) {
				printf("%3d ", i + 1);
				if (mw == 0) printf("\n");
				mw = (mw + 1) % 7;
				continue;
			}
			else {
				for (int i = 1; i < mw; i++) {
					printf("    ");
				}
				printf("%3d ", i + 1);
				if (mw == 0) printf("\n");
				mw = (mw + 1) % 7;
				continue;
			}
		}
		printf("%3d ", i + 1);
		if (mw == 0) printf("\n");
		mw = (mw + 1) % 7;
	}

	printf("\n");
	switch (week) {
	case 0: printf("Sunday\n"); break;
	case 1: printf("Monday\n"); break;
	case 2: printf("Tuesday\n"); break;
	case 3: printf("Wednesday\n"); break;
	case 4: printf("Thursday\n"); break;
	case 5: printf("Friday\n"); break;
	case 6: printf("Saturday\n"); break;
	default: printf("Input Error!\n"); break;
	}

	

}

bool check(int y, int m, int d) {
	if (y < 2000 || y>2010) return false;
	if (m < 1 || m > 12) return false;
	if (check_yun(y) == true) {
		month[1] = 29;
		if (d < 1 || d > month[m - 1]) {
			return false;
		}
	}
	else if (check_yun(y) == false) {
		month[1] = 28;
		if (d < 1 || d > month[m - 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	int y, m, d;
	while (true) {
		scanf("%d %d %d", &y, &m, &d);
		if (check(y, m, d) == false) {
			printf("INPUT ERROR!\n");
			continue;
		}
		else if (check(y, m, d) == true) {
			print(y, m, d);
			break;
		}
	}
	return 0;
}