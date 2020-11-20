#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;

int N, M, V;
bool visited[MAX];
vector<int> adj[MAX];
int arry[MAX][MAX];


void dfs(int currnode) {
	// 1. 종료 조건
	// 2. 시작점, 재귀함수로 들어오면서 visited 체크
	visited[currnode] = true;
	printf("%d ", currnode);

	// 3. (DFS) adj 탐색
	for (int j = 0; j < adj[currnode].size(); j++) {
		int nextnode = adj[currnode][j];
		if (!visited[nextnode]) {
			dfs(nextnode);
		}
	}
}

void bfs(int start) {
	// 1. queue 생성
	queue<int> q;

	// 2. 시작점, queue에 넣으면서 visited 체크
	q.push(start); visited[start] = true;	

	// 3. (BFS) queue가 빌 때까지
	while (!q.empty()) {
		int currnode = q.front(); q.pop();
		printf("%d ", currnode);
		// 3-1. adj 탐색
		for (int j = 0; j < adj[currnode].size(); j++) {
			int nextnode = adj[currnode][j];
			if (!visited[nextnode]) {
				q.push(nextnode); visited[nextnode]=true;
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
