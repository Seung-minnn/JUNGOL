/*
서울 15반 하승민
2번문제-개미의 이동거리
*/
#include<stdio.h>
#include<iostream>

#define MAX 100
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 0; t < tc; t++) {
		int n;
		scanf("%d", &n);

		int map[MAX][MAX];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		int ans = 0;
		int d = 0; //0: 오른쪽, 1: 왼쪽, 2: 위, 3: 아래
		int x = 0, y = 0;
		while (1) {
			if (x >= n || y >= n || x < 0 || x < 0) {
				break;
			}

			if (d == 0) {
				for (int i = 0; i < n; i++) {
					if (x >= n || y >= n || x < 0 || y < 0) {
						break;
					}

					if (map[x][y] == 0) {
						y++;
						ans++;
						continue;
					}
					else if (map[x][y] == 1) {
						x--;
						d = 2;
						ans++;
						break;
					}
					else if (map[x][y] == 2) {
						x++;
						d = 3;
						ans++;
						break;
					}
				}
			}

			else if (d == 1) {
				for (int i = 0; i < n; i++) {
					if (x >= n || y >= n || x < 0 || y < 0) {
						break;
					}

					if (map[x][y] == 0) {
						y--;
						ans++;
						continue;
					}
					else if (map[x][y] == 1) {
						x++;
						d = 3;
						ans++;
						break;
					}
					else if (map[x][y] == 2) {
						x--;
						d = 2;
						ans++;
						break;
					}
				}
			}
				
			else if (d == 2) {
				for (int i = 0; i < n; i++) {
					if (x >= n || y >= n || x < 0 || y < 0) {
						break;
					}

					if (map[x][y] == 0) {
						x--;
						ans++;
						continue;
					}
					else if (map[x][y] == 1) {
						y++;
						d = 0;
						ans++;
						break;
					}
					else if (map[x][y] == 2) {
						y--;
						d = 1;
						ans++;
						break;
					}
				}
			}

			else if (d == 3) {
				for (int i = 0; i < n; i++) {
					if (x >= n || y >= n || x < 0 || y < 0) {
						break;
					}

					if (map[x][y] == 0) {
						x++;
						ans++;
						continue;
					}
					else if (map[x][y] == 1) {
						y--;
						d = 1;
						ans++;
						break;
					}
					else if (map[x][y] == 2) {
						y++;
						d = 0;
						ans++;
						break;
					}
				}
			}
	
		}

		printf("#%d %d\n", t + 1, ans-1);
	}
	//system("pause");
	return 0;
}