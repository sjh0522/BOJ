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
	// 2-0. currnode = N+1 �̸� ����
	if (currnode == N + 1) return;

	// 2-1. ������, visited üũ
	visited[currnode] = true;
	printf("%d ", currnode);

	// 2-2. adj ��� Ž��
	for (int j = 0; j < adj[currnode].size(); j++) {
		int nextnode = adj[currnode][j];
		if (!visited[nextnode]) {
			dfs(nextnode);
		}
	}
}

void bfs(int start) {
	// 2-1. ������, queue�� ���� + visited üũ
	queue<int> q;
	q.push(start), visited[start] = true;

	// 2-2. queue�� �� ������
	while (!q.empty()) {
		int currnode = q.front(); q.pop();
		printf("%d ", currnode);

		for (int j = 0; j < adj[currnode].size(); j++) {
			int nextnode = adj[currnode][j];
			// 2-3. �湮�� ���� ������ queue�� ����
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
	
	// 0. �Է�
	int u, v;
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	// 1. �ڷᱸ�� �ʱ�ȭ
	fill(visited, visited + N + 1, false);
	dfs(V);
	puts("");
	fill(visited, visited + N + 1, false);
	bfs(V);
}