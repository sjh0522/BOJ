#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;

int N, M, V;
int arry[MAX][MAX];
bool visited[MAX];
vector<int> adj[MAX];

void dfs(int currnode) {
	// 2-0. currnode = N+1 이면 종료
	if (currnode == N + 1) return;

	// 2-1. 시작점, visited 체크
	visited[currnode] = true;
	printf("%d ", currnode);

	// 2-2. adj 노드 탐색
	for (int j = 0; j < adj[currnode].size(); j++) {
		int nextnode = adj[currnode][j];
		if (!visited[nextnode]) {
			dfs(nextnode);
		}
	}
}

void bfs(int start) {
	// 2-1. 시작점, queue에 삽입 + visited 체크
	queue<int> q;
	q.push(start), visited[start] = true;

	// 2-2. queue가 빌 때까지
	while (!q.empty()) {
		int currnode = q.front(); q.pop();
		printf("%d ", currnode);

		for (int j = 0; j < adj[currnode].size(); j++) {
			int nextnode = adj[currnode][j];
			// 2-3. 방문한 적이 없으면 queue에 삽입
			if (!visited[nextnode]) {
				visited[nextnode] = true;
				q.push(nextnode);
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &V);
	
	// 0. 입력
	int u, v;
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	// 1. 자료구조 초기화
	fill(visited, visited + N + 1, false);
	dfs(V);
	puts("");
	fill(visited, visited + N + 1, false);
	bfs(V);
}
