#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define MAX 101
#define INF 1000000000
using namespace std;

int cost[MAX][MAX];

int main(void) {
	freopen("input.txt", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);

	// 0-1. cost배열 INF 초기화
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cost[i][j] = (i == j) ? 0 : INF;
		}
	}
	// 0-2. 입력
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		cost[a][b] = min(cost[a][b], c);
	}

	// floydwarshall //
	/* 1. 출발 노드 선택 X
	   2. 3중 포문 */  
	
	// 1. k = 거쳐가는 노드
	for (int k = 1; k <= n; k++) {
		// 2. i = 출발 노드
		for (int i = 1; i <= n; i++) {
			// 3. j = 도착 노드
			for (int j = 1; j <= n; j++) {
				if (cost[i][j] > cost[i][k] + cost[k][j]) {
					cost[i][j] = cost[i][k] + cost[k][j];
				}
			}
		}		
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", cost[i][j] == INF ? 0 : cost[i][j]);
		}
		puts("");
	}
}
