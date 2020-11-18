#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>

#define MAX 101

using namespace std;
int n, s, e;
vector<int> adj[MAX];
bool visited[MAX];
int cost[MAX];

void bfs(int start) {
	// 2-1. 시작점 queue에 삽입, visited 체크
	queue<int> q;
	q.push(start);
	visited[start] = true;

	// 2-2. queue가 빌때까지
	while (!q.empty()) {
		int currnode = q.front(); q.pop();
		for (int j = 0; j < adj[currnode].size(); j++) {
			int nextnode = adj[currnode][j];
			// 2-3. 방문한 적이 없으면 queue에 삽입
			if (visited[nextnode] == false) {
				visited[nextnode] = true;
				q.push(nextnode);
				cost[nextnode] += cost[currnode] + 1;
			}
		}
	}
}

int main(void) {
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &n, &s, &e);
	
	int m;
	scanf("%d", &m);

	// 0. 입력
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// 1. 자료 구조 초기화
	fill(visited, visited + n + 1, false);
	fill(cost, cost + n + 1, 0);

	// 2. bfs
	bfs(s);

	// 3. 결과
	printf("%d", cost[e] == 0 ? -1 : cost[e]);
}