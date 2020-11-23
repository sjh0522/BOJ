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
	// 1. ����Լ� ������ 
	depth[currnode] = dep;
	visited[currnode] = true;

	// 2. adj Ž��
	for (int j = 0; j < adj[currnode].size(); j++) {
		int nextnode = adj[currnode][j];
		// 2-1. �湮���� ������ skip
		if (visited[nextnode]) continue;
		parent[nextnode][0] = currnode;
		getDepth(nextnode, dep + 1);
	}
}

int lca(int a, int b) {
	// 1. b�� �� ���� 
	if (depth[a] > depth[b]) swap(a, b);

	// 2. ����(depth)�� ���� �� ������
	for (int j = LOG - 1; j >= 0; j--) {
		if (depth[b] - depth[a] >= (1 << j)) {
			b = parent[b][j];
		}
	}

	// 3. lca return
	// 3-1. a�� b�� ������
	if (a == b) return a;
	
	// 3-2. �θ� ������ �� ����
	for (int j = LOG - 1; j >= 0; j--) {
		if (parent[a][j] != parent[b][j]) {
			a = parent[a][j];
			b = parent[b][j];
		}
	}

	// 3-3. �θ� ��� return
	return parent[a][0];
}

int main(void) {
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);

	// 0. �Է�
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// 1 . depth ���ϱ�
	getDepth(1, 0);

	// 2. parent �迭 ä���
	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= N; i++) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}

	// 3. ���
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", lca(s, e));
	}
}


