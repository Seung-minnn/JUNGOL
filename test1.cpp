/*
서울 15반 하승민
1번문제-사각 띠 최대합 구하기
*/

#include<stdio.h>
#include<iostream>

#define MAX 20
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 0; t < tc; t++) {
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		
		int map[MAX][MAX];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		int ans = -1;
		for (int i = 0; i < n - k + 1; i++) {
			for (int j = 0; j < m - k + 1; j++) {
				int big = 0; 
				int small = 0;

				for (int x = i; x < i + k; x++) {
					for (int y = j; y < j + k; y++) {
						big += map[x][y];
					}
				}
				
				for (int x = i + 1; x < i + k - 1; x++) {
					for (int y = j + 1; y < j + k - 1; y++) {
						small += map[x][y];
					}
				}
				
				if (ans <= (big - small)) {
					ans = (big - small);
				}
			}
		}
		printf("#%d %d\n", t+1, ans);
	}
	//system("pause");
	return 0;
}