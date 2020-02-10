/*
¼­¿ï 15¹Ý ÇÏ½Â¹Î
3¹ø¹®Á¦-¼¶ÀÇ °³¼ö ±¸ÇÏ±â
*/

#include<stdio.h>
#include<iostream>
#include<string.h>

#define MAX 20
using namespace std;

int map[MAX][MAX];
int map2[MAX][MAX];
int ans, n;

int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };

void count_map(int x, int y) {
	map2[x][y] = ans;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			if (map[nx][ny] != -1 && map2[nx][ny] == 0) {
				count_map(nx, ny);
			}
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 0; t < tc; t++) {
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			memset(map[i], -1, sizeof(int)*n);
			memset(map2[i], -1, sizeof(int)*n);
		}
	
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &map[i][j]);

				if (map[i][j] != 0) {
					map2[i][j]++; //-1: ¹Ù´Ù, 0:¼¶
				}
			}
		}

		
		ans=1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map2[i][j] == 0) {
					count_map(i, j);
					ans++;
				}
				
			}
		}
		
		printf("#%d %d\n", t + 1, ans-1);
	}
	//system("pause");
	return 0;
}