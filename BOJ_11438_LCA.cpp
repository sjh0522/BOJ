#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#define MAX 100001
#define LOG 21 // 2^20 = 1,000,000
using namespace std;

vector<int> adj[MAX];
int parent[MAX][LOG];
bool visited[MAX];
int depth[MAX];
int N;

void getDepth(int currnode, int dep) {
	// 1. 재귀함수 들어오면 
	depth[currnode] = dep;
	visited[currnode] = true;

	// 2. adj 탐색
	for (int j = 0; j < adj[currnode].size(); j++) {
		int nextnode = adj[currnode][j];
		// 2-1. 방문한적 있으면 skip
		if (visited[nextnode]) continue;
		parent[nextnode][0] = currnode;
		getDepth(nextnode, dep + 1);
	}
}

int lca(int a, int b) {
	// 1. b가 더 깊도록 
	if (depth[a] > depth[b]) swap(a, b);

	// 2. 깊이(depth)가 같아 질 때까지
	for (int j = LOG - 1; j >= 0; j--) {
		if (depth[b] - depth[a] >= (1 << j)) {
			b = parent[b][j];
		}
	}

	// 3. lca return
	// 3-1. a와 b가 같으면
	if (a == b) return a;
	
	// 3-2. 부모가 같아질 때 까지
	for (int j = LOG - 1; j >= 0; j--) {
		if (parent[a][j] != parent[b][j]) {
			a = parent[a][j];
			b = parent[b][j];
		}
	}

	// 3-3. 부모 노드 return
	return parent[a][0];
}

int main(void) {
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);

	// 0. 입력
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// 1 . depth 구하기
	getDepth(1, 0);

	// 2. parent 배열 채우기
	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= N; i++) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}

	// 3. 출력
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", lca(s, e));
	}
}


